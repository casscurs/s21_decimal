#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_arithmetic.h"

void InfDivCase(s21_error_type *error, s21_decimal *result);
void denomZero(s21_decimal value_1, s21_decimal value_2, s21_error_type *error);
s21_decimal Light_mod(s21_decimal delim, s21_decimal delit, s21_decimal chast);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_error_type error = {0};
  if (result == NULL) {
    exit(1);
  }
  memset(result, 0, sizeof(s21_decimal));
  if (checkErrorDiv(value_1, value_2, &error)) {
    s21_powNormilize(&value_1, &value_2);
    if (check_zero(value_2)) {
      denomZero(value_1, value_2, &error);
    } else {
      s21_bit_division(value_1, value_2, result);
    }
  } else if ((error.minus_inf || error.plus_inf) && (!isInf(&value_1))) {
    InfDivCase(&error, result);
  }
  makeResult(error, result);
  return error.plus_inf ? 1 : error.minus_inf ? 2 : error.nan ? 3 : 0;
}

void denomZero(s21_decimal value_1, s21_decimal value_2,
               s21_error_type *error) {
  if ((getSign(value_1) == (-1)) ^ (getSign(value_2) == (-1))) {
    error->minus_inf = 1;
  } else {
    error->plus_inf = 1;
  }
}
void InfDivCase(s21_error_type *error, s21_decimal *result) {
  if (error->minus_inf) {
    setSign(result, -1);
  }
  error->minus_inf = 0;
  error->plus_inf = 0;
}
int s21_bit_division(s21_decimal delim, s21_decimal delit, s21_decimal *chast) {
  if (chast == NULL) {
    exit(1);
  }
  memset(chast, 0, sizeof(s21_decimal));
  int flag = 0;
  if ((getSign(delim) == (-1)) ^ (getSign(delit) == (-1))) {
    flag = 1;
  }
  setSign(&delim, 1);
  setSign(&delit, 1);
  if (is_equal_M(delim, delit)) {  // если числа равны
    chast->bits[0] = 1;
  } else if (!check_zero(delim) && is_greater_M(delim, delit)) {
    s21_decimal delitBuf = {0};
    delitBuf = delit;
    div_first_decrement(delim, delit, &delitBuf,
                        chast);  // первый этап декремента
  }
  if (flag) {
    setSign(chast, -1);
  }
  return 0;
}

void div_first_decrement(s21_decimal delim, s21_decimal delit,
                         s21_decimal *delitBuf, s21_decimal *chast) {
  int count1 = 0;
  while (is_greater_or_equal_M(delim, leftshift(*delitBuf)) &&
         !getBit(leftshift(*delitBuf), 96)) {
    *delitBuf = leftshift(*delitBuf);
    count1++;
  }
  if (count1) {
    degree_of_two(chast, count1);  // запись ответа
    s21_decimal razn = {0};
    Light_sub(delim, *delitBuf, &razn);
    while (is_greater_or_equal_M(razn, delit)) {
      div_second_decrement(delit, delitBuf, chast, &razn);
    }
  } else {
    chast->bits[0] = 1;
  }
}
void div_second_decrement(s21_decimal delit, s21_decimal *delitBuf,
                          s21_decimal *chast, s21_decimal *razn) {
  int count2 = 0;
  *delitBuf = delit;  // вернули буфер к исходнику
  while (is_greater_or_equal_M(*razn, leftshift(*delitBuf))) {
    *delitBuf = leftshift(*delitBuf);
    count2++;
  }
  s21_sub(*razn, *delitBuf, razn);
  memset(delitBuf, 0, sizeof(s21_decimal));
  degree_of_two(delitBuf, count2);
  addition(*chast, *delitBuf, chast, 0);
}
