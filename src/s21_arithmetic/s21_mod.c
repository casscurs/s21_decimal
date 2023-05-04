#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_arithmetic.h"

// int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {

//   return 0;
// }

void s21_bit_mod(s21_decimal delim, s21_decimal delit, s21_decimal *ostatok) {
  // осаток если целая часть ноль
  if (ostatok == NULL) {
    exit(1);
  }
  memset(ostatok, 0, sizeof(s21_decimal));
  if (is_greater_M(delit, delim)) {
    *ostatok = delim;
  } else {
    s21_decimal buf = {0};
    s21_bit_division(delim, delit, &buf);
    multiplication(delit, buf, &buf);
    Light_sub(delim, buf, ostatok);
  }
}