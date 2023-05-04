#include "s21_convertors.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int is_error = 0;
  memset(dst, 0, sizeof(s21_decimal));
  if (src < 0) {
    dst->bits[3] = 1u << 31;
    src *= -1;
  }
  if (src >= INT_MAX || src < INT_MIN) {
    is_error = 1;
  } else {
    dst->bits[0] = src;
  }

  return is_error;
}
