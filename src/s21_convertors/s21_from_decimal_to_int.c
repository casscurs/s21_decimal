#include "s21_convertors.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int is_error = 0;
  int power = getPower(src);

  if (src.bits[1] || src.bits[2]) {
    is_error = 1;
  } else {
    *dst = src.bits[0];
    if (power > 0 && power <= 28) {
      *dst /= pow(10, power);
    }

    if ((src.bits[3] >> 31) == 1u) {
      *dst *= -1;
    }
  }

  return is_error;
}
