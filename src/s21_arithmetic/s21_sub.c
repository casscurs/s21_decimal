#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_arithmetic.h"

void positive_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power);
void v1_equal_v2(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                 int power);
void negative_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  s21_error_type *error);
int v1_greater_v2(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power);
int v2_greater_v1(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power);
void add_flow(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              s21_error_type *error);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_error_type error = {0};
  s21_decimal mv2 = {0};
  mv2 = value_2;
  setSign(&mv2, -1);
  if (checkErrorAdd(value_1, mv2, &error)) {
    s21_powNormilize(&value_1, &value_2);
    int power = getPower(value_1);
    switch (getSign(value_1) * getSign(value_2)) {
      case 1:
        positive_sub(value_1, value_2, result, power);
        break;
      case -1:
        negative_sub(value_1, value_2, result, &error);
        break;
    }
  }
  makeResult(error, result);
  return error.plus_inf ? 1 : error.minus_inf ? 2 : error.nan ? 3 : 0;
}
// Вычитание без учета порядка
void Light_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  memcheck(result);
  int a = 0;
  switch (getSign(value_1) * getSign(value_2)) {
    case 1:
      positive_sub(value_1, value_2, result, 0);
      break;
    case -1:
      if (getSign(value_1) == (-1)) {
        setSign(&value_1, 1);

        addition(value_1, value_2, result, &a);
        setSign(result, -1);
      }
      if (getSign(value_2) == (-1)) {
        setSign(&value_2, 1);
        addition(value_1, value_2, result, &a);
      }
      break;
  }
}

void negative_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  s21_error_type *error) {
  if (getSign(value_1) == (-1)) {
    setSign(&value_1, 1);
    add_flow(value_1, value_2, result, error);
    setSign(result, -1);
  }
  if (getSign(value_2) == (-1)) {
    setSign(&value_2, 1);
    add_flow(value_1, value_2, result, error);
  }
}
void add_flow(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
              s21_error_type *error) {
  switch (s21_add(value_2, value_1, result)) {
    case 1:
      error->plus_inf = 1;
      break;
    case 2:
      error->minus_inf = 2;
      break;
    default:
      break;
  }
}

void positive_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power) {
  if ((getSign(value_1) == (-1)) && (getSign(value_2) == (-1))) {
    setSign(&value_1, 1);
    setSign(&value_2, 1);
    if (v1_greater_v2(value_1, value_2, result, power)) {
      setSign(result, -1);
    }
    if (v2_greater_v1(value_1, value_2, result, power)) {
      setSign(result, 1);
    }
  } else {
    v1_greater_v2(value_1, value_2, result, power);
    v2_greater_v1(value_1, value_2, result, power);
  }
}
int v1_greater_v2(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power) {
  int res = 0;
  if (is_greater_M(value_1, value_2)) {
    s21_bit_sub(value_1, value_2, result);
    setPower(result, power);
    res = 1;
  }
  return res;
}
int v2_greater_v1(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power) {
  int res = 0;
  if (is_greater_M(value_2, value_1)) {
    s21_bit_sub(value_2, value_1, result);
    setPower(result, power);
    setSign(result, -1);
    res = 1;
  }
  return res;
}
void v1_equal_v2(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                 int power) {
  if (is_equal_M(value_1, value_2)) {
    setPower(result, power);
  }
}

int s21_bit_sub(s21_decimal bit1, s21_decimal bit2, s21_decimal *res) {
  int flag = 0;
  int mindone = 0;
  for (int j = 0; j < 96; ++j) {
    if (getBit(bit1, j) && getBit(bit2, j)) {
      and_pattern(&mindone, res, j);
    } else if (getBit(bit1, j) == 1 && getBit(bit2, j) == 0) {
      one_zero_pattern(&mindone, res, j);
    } else if (getBit(bit1, j) == 0 && getBit(bit2, j) == 1) {
      zero_one_pattern(&mindone, res, j);
    } else if (getBit(bit1, j) == 0 && getBit(bit2, j) == 0) {
      and_pattern(&mindone, res, j);
    }
  }
  return (flag);
}
void one_zero_pattern(int *mindone, s21_decimal *res, int j) {
  if (*mindone) {
    setBit(res, j, 0);
    *mindone = 0;
  } else {
    setBit(res, j, 1);
  }
}
void and_pattern(int *mindone, s21_decimal *res, int j) {
  if (*mindone) {
    setBit(res, j, 1);
  } else {
    setBit(res, j, 0);
  }
}
void zero_one_pattern(int *mindone, s21_decimal *res, int j) {
  if (*mindone) {
    setBit(res, j, 0);
  } else {
    *mindone = 1;
    setBit(res, j, 1);
  }
}
