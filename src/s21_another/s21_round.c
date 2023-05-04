#include "s21_another.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int is_error = 0;
  if (isInf(&value)) {
    makeInf(result);
    setSign(result, -1);
    // is_error = 1;
  } else if (isNan(&value)) {
    is_error = 1;
    makeNan(result);
  } else if (result == NULL) {
    is_error = 1;
  }

  if (!is_error) {
    memset(result, 0, sizeof(s21_decimal));
    if ((getPower(value) < 29)) {
      memset(result, 0, sizeof(s21_decimal));
      int sign = 0;
      if (getSign(value) == -1) {
        sign = 1;
        value.bits[3] ^= 1u << 31;
      }

      if (!check_zero(value)) protectedRound(value, result);

      if (sign) {
        result->bits[3] ^= 1u << 31;
      }
      setPower(result, 0);
    }
    is_error = 0;
  }
  return is_error;
}

void protectedRound(s21_decimal value, s21_decimal *result) {
  long double double_value = 0;
  double_value = decimalToDouble(value, double_value);
  double_value = roundl(double_value);

  int i = 0;
  while (double_value >= 1 && i < 96) {
    double_value /= 2;
    if ((double_value - floorl(double_value)) > 0.0) {
      setBit(result, i, 1);
    } else {
      setBit(result, i, 0);
    }
    i++;
    double_value = floorl(double_value);
  }
}
