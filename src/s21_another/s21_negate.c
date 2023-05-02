#include "s21_another.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int is_error = 1;

  if (result) {
    if (!check_zero(value)) {
      memset(result, 0, sizeof(s21_decimal));
      if (!check_zero(value) || (getSign(value) == -1 || getPower(value))) {
        value.bits[3] ^= 1u << 31;
        *result = value;
        is_error = 0;
      } else if (getSign(value) == -1 || getPower(value)) {
        result->bits[3] = value.bits[3];
      }
    }
  }
  return is_error;
}
