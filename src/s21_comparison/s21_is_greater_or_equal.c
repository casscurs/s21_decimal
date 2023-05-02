#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_comparison.h"

//  el2 >= el1
int s21_is_greater_or_equal(s21_decimal el1, s21_decimal el2) {
  int res = decCmp(el1, el2);
  return (res >= 0) ? 1 : 0;
}
