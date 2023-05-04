#include "s21_another.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int is_error = 0;

  if (isInf(&value)) {
    makeInf(result);
    setSign(result, -1);
  } else if (isNan(&value)) {
    is_error = 1;
    makeNan(result);
  } else if (check_zero(value) && !value.bits[3]) {
    is_error = 1;
  } else if (result == NULL) {
    is_error = 1;
  }

  if (!is_error) {
    memset(result, 0, sizeof(s21_decimal));
    for (int i = 0; i < 4; i++) {
      result->bits[i] = value.bits[i];
    }
    result->bits[3] ^= 1u << 31;
  }

  return is_error;
}
