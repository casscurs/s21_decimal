#include "s21_convertors.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;

  for (int i = 0; i < 96; i++) {
    *dst += pow(2, i) * getBit(src, i);
  }
  *dst /= pow(10, getPower(src));
  if (src.bits[3] >> 31) {
    *dst *= -1;
  }

  return 0;
}
