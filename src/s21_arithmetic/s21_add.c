#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    exit(1);
  }
  memset(result, 0, sizeof(s21_decimal));
  s21_error_type error = {0};
  if (checkErrorAdd(value_1, value_2, &error)) {
    s21_powNormilize(&value_1, &value_2);
    int power = getPower(value_1);
    int overflow_status = 0;
    switch (getSign(value_1) * getSign(value_2)) {
      case 1:
        overflow_status = addition(value_1, value_2, result, &power);
        if (overflow_status) {
          if (getSign(value_1) == 1) {
            makeInf(result);
            error.plus_inf++;
          } else {
            makeNegInf(result);
            error.minus_inf++;
          }
        }
        break;
      case -1:
        subIn_s21_add(&value_1, &value_2, result, power);
        break;
    }
    if (!overflow_status) {
      setPowerIn_s21_add(power, result, overflow_status);
      setSignIn_s21_add(&value_1, &value_2, result);
    }
  }
  return error.plus_inf ? 1 : error.minus_inf ? 2 : error.nan ? 3 : 0;
}

void subIn_s21_add(s21_decimal *value_1, s21_decimal *value_2,
                   s21_decimal *result, int power_value1) {
  int sign_1 = getSign(*value_1);
  int sign_2 = getSign(*value_2);
  setSign(value_1, 1);
  setSign(value_2, 1);
  if (is_greater_or_equal_M(*value_1, *value_2)) {
    if (sign_1 == -1) {
      positive_sub(*value_2, *value_1, result, power_value1);
    }
    positive_sub(*value_1, *value_2, result, power_value1);
  } else {
    if (sign_2 == -1) {
      positive_sub(*value_2, *value_1, result, power_value1);
    }
    positive_sub(*value_1, *value_2, result, power_value1);
  }
  setSign(value_1, sign_1);
  setSign(value_2, sign_2);
}

void setPowerIn_s21_add(int power_value1, s21_decimal *result,
                        int overflow_status) {
  if (power_value1 > 0) {
    setPower(result, power_value1 - overflow_status);
  } else {
    if (overflow_status) {
      if (getSign(*result) == 1) {
        makeInf(result);
      } else {
        makeNegInf(result);
      }
    } else {
      setPower(result, power_value1);
    }
  }
}
void setSignIn_s21_add(s21_decimal *value_1, s21_decimal *value_2,
                       s21_decimal *result) {
  if ((getSign(*value_1) > 0) && (getSign(*value_2) > 0)) {
    setSign(result, 1);
  } else if ((getSign(*value_1) < 0) && (getSign(*value_2) < 0)) {
    setSign(result, -1);
  } else if ((getSign(*value_1) > 0) && (getSign(*value_2) < 0)) {
    setSign(value_2, 1);
    if (is_greater_or_equal_M(*value_1, *value_2)) {
      setSign(result, 1);
    } else {
      setSign(result, -1);
    }
    setSign(value_2, -1);
  } else if ((getSign(*value_1) < 0) && (getSign(*value_2) > 0)) {
    setSign(value_1, 1);
    if (is_greater_M(*value_1, *value_2)) {
      setSign(result, -1);
    } else {
      setSign(result, 1);
    }
    setSign(value_1, -1);
  }
}

void setMaxDecimal(s21_decimal *result) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 4294967295;
  }
  setPower(result, 0);
}

int addition(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
             int *power) {
  memset(result, 0, sizeof(s21_decimal));
  int overflow_status = 0;
  for (int index = 0; index < 96; index++) {
    switch (getBit(value_1, index) + getBit(value_2, index) +
            getBit(*result, index)) {
      case 0:
        setBit(result, index, 0);
        break;
      case 1:
        setBit(result, index, 1);
        break;
      case 2:
        if (index != 95) {
          setBit(result, index, 0);
          setBit(result, index + 1, 1);
        } else {
          overflow_status = getAroundOverflow_s21_add(&value_1, &value_2,
                                                      result, index, 2, power);
        }
        break;
      case 3:
        if (index != 95) {
          setBit(result, index, 1);
          setBit(result, index + 1, 1);
        } else {
          overflow_status = getAroundOverflow_s21_add(&value_1, &value_2,
                                                      result, index, 3, power);
        }
        break;
    }
  }
  return overflow_status;
}

int getAroundOverflow_s21_add(s21_decimal *value_1, s21_decimal *value_2,
                              s21_decimal *result, int index, int cases,
                              int *power) {
  int overflow_status = 0;
  if (*power == 0) {
    overflow_status++;
    s21_big_decimal big_result = decimalToBigDecimal(*result);
    setBitBigDecimal(&big_result, index, cases - 2);
    setBitBigDecimal(&big_result, index + 1, 1);
    bigDecimalToDecimal(big_result, result, *power);
  } else {
    memset(result, 0, sizeof(s21_decimal));
    powerValueToXDown(value_1, power, (*power - 1));
    powerValueToXDown(value_2, power, (*power - 1));
    addition(*value_1, *value_2, result, power);
  }
  return overflow_status;
}