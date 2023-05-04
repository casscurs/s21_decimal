#include "s21_comparison.h"

// start comparation helpers
////
int isInf(const s21_decimal *el) {
  int res = 0;
  if (el != NULL) {
    if (getPower(*el) == 255 && (el->bits[2] == 0) && (el->bits[1] == 0) &&
        (el->bits[0] == 0)) {
      res = 1;
    }

    if (getSign(*el) == -1) {
      res = -res;
    }
  }

  return res;
}

int isNan(const s21_decimal *el) {
  int res = 0;
  if (el != NULL) {
    if (getPower(*el) == 255 && (el->bits[2] == 2147483648) &&
        (el->bits[1] == 0) && (el->bits[0] == 0)) {
      res = 1;
    }
  }
  return res;
}

int decCmp(s21_decimal el1, s21_decimal el2) {
  int res = 0;

  if (check_zero(el1)) {
    setSign(&el1, 1);
  }
  if (check_zero(el2)) {
    setSign(&el2, 1);
  }
  int sign1 = getSign(el1), sign2 = getSign(el2);
  if ((isInf(&el1) == 1 && isInf(&el2) == 0) ||
      (isInf(&el1) == 0 && isInf(&el2) == -1) ||
      (sign1 > sign2)) {  //  первый точно больше
    res = 1;
  } else if ((isInf(&el1) == 0 && isInf(&el2) == 1) ||
             (isInf(&el1) == -1 && isInf(&el2) == 0) ||
             (sign1 < sign2)) {  //  второй точно больше
    res = -1;
  } else {
    res = 0;
    int pow1 = getPower(el1), pow2 = getPower(el2);

    if (pow1 != pow2) s21_powNormilize(&el1, &el2);

    for (int i = 95; i >= 0 && res == 0;
         --i) {  //  сравниваем мантисы побитово, пока равны
      int cur_bit1 = getBit(el1, i), cur_bit2 = getBit(el2, i);
      // if (i >= 0 && i <= 5) printf("%d %d\n", cur_bit1, cur_bit2);
      if (cur_bit1 != cur_bit2) {
        res = cur_bit1 - cur_bit2;
      }
    }
    // printf("res = %d\n", res);
    if (sign1 == -1) {  //  инвертируем, если оба отрицательные
      res = -res;
    }
  }
  // printf("#%d\n", res);
  return res;
}
////
// end comparation helpers