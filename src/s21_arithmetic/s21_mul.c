#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_arithmetic.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    exit(1);
  }
  memset(result, 0, sizeof(s21_decimal));
  s21_error_type error = {0};
  if (checkErrorMul(value_1, value_2, &error)) {
    int oba_znaka = ((getSign(value_1) * getSign(value_2)) == 1);
    //
    setBit(&value_1, 127, 0);
    setBit(&value_2, 127, 0);
    //
    s21_big_decimal big_value_1 = decimalToBigDecimal(value_1);
    s21_big_decimal big_value_2 = decimalToBigDecimal(value_2);
    s21_big_decimal big_res = decimalToBigDecimal(*result);

    int overflow_status = MulBigDecimal(big_value_1, big_value_2, &big_res);

    if (!overflow_status) {
      s21_set_big_fraction(&big_res, s21_get_big_fraction(big_value_1) +
                                         s21_get_big_fraction(big_value_2));

      if (!oba_znaka) {
        result->bits[3] ^= 1u << 31;
      }
      if (mulbigDecimalToDecimal(big_res, result)) {
        if (oba_znaka) {
          error.plus_inf++;
        } else {
          error.minus_inf++;
        }
      }
    } else {
      if (oba_znaka) {
        error.plus_inf++;
      } else {
        error.minus_inf++;
      }
    }
  }
  return error.plus_inf ? 1 : error.minus_inf ? 2 : error.nan ? 3 : 0;
}
