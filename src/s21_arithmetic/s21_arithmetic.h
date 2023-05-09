#ifndef SRC_S21_ARITHMETIC_S21_ARITHMETIC_H_
#define SRC_S21_ARITHMETIC_S21_ARITHMETIC_H_

#include "../helpers/s21_helpfunc.h"
#include "../s21_another/s21_another.h"
#include "../s21_comparison/s21_comparison.h"
#include "../s21_decimal.h"

// typedef struct {
//   uint32_t bits[7];
// } s21_big_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// arithmetic helpers
int makeNegInf(s21_decimal *el);

int makeNan(s21_decimal *el);

int makeInf(s21_decimal *el);
void makeResult(s21_error_type error, s21_decimal *result);
//// casscurs

int find_one(s21_decimal bit, int *pos);

s21_decimal leftshift(s21_decimal bit);

s21_decimal bank_round(s21_decimal bit);

int is_uneven(s21_decimal bit);

int check_zero(s21_decimal decimal);

void degree_of_two(s21_decimal *num, int degree);

// sub
int s21_bit_sub(s21_decimal bit1, s21_decimal bit2, s21_decimal *res);

void one_zero_pattern(int *mindone, s21_decimal *res, int j);

void and_pattern(int *mindone, s21_decimal *res, int j);

void zero_one_pattern(int *mindone, s21_decimal *res, int j);

void positive_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
                  int power);
void Light_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// div
int s21_bit_division(s21_decimal delim, s21_decimal delit, s21_decimal *chast);

void div_first_decrement(s21_decimal delim, s21_decimal delit,
                         s21_decimal *delitBuf, s21_decimal *chast);

void div_second_decrement(s21_decimal delit, s21_decimal *delitBuf,
                          s21_decimal *chast, s21_decimal *razn);

// mod
void s21_bit_mod(s21_decimal delim, s21_decimal delit, s21_decimal *ostatok);

//// aquaman

int s21_add_for_mul(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);

void subIn_s21_add(s21_decimal *value_1, s21_decimal *value_2,
                   s21_decimal *result, int power_value1);

void addition_for_mul(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);

void setMaxDecimal(s21_decimal *result);

int addition(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
             int *power);
void multiplication(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);

int checkErrorAdd(const s21_decimal value_1, const s21_decimal value_2,
                  s21_error_type *error);

int checkErrorMul(const s21_decimal value_1, const s21_decimal value_2,
                  s21_error_type *error);

int checkErrorDiv(const s21_decimal value_1, const s21_decimal value_2,
                  s21_error_type *error);

//

int s21_bit_sub(s21_decimal bit1, s21_decimal bit2, s21_decimal *res);

void one_zero_pattern(int *mindone, s21_decimal *res, int j);

void and_pattern(int *mindone, s21_decimal *res, int j);

void zero_one_pattern(int *mindone, s21_decimal *res, int j);

int checkForOverflow(s21_decimal value_1, s21_decimal value_2);

void setSignIn_s21_add(s21_decimal *value_1, s21_decimal *value_2,
                       s21_decimal *result);

void setSign(s21_decimal *decimal, int sign);

void setPowerIn_s21_add(int power_value1, s21_decimal *result,
                        int overflow_status);

int getAroundOverflow_s21_add(s21_decimal *value_1, s21_decimal *value_2,
                              s21_decimal *result, int index, int cases,
                              int *power);

// int makePower(s21_decimal value_1, s21_decimal value_2);

// big decimal

s21_big_decimal decimalToBigDecimal(s21_decimal value);
int mulbigDecimalToDecimal(s21_big_decimal src, s21_decimal *dst);
int s21_is_big_empty(s21_big_decimal number);

unsigned int s21_get_big_fraction(s21_big_decimal number);
void s21_set_big_fraction(s21_big_decimal *number, unsigned int fraction);

void bigDecRightShift(s21_big_decimal *number, int offset);
void bigDecLeftShift(s21_big_decimal *number, int offset);

int addBigDecimal(s21_big_decimal v1, s21_big_decimal v2, s21_big_decimal *r);
int MulBigDecimal(s21_big_decimal v1, s21_big_decimal v2, s21_big_decimal *r);

int s21_div_ten_nr_big(s21_big_decimal *value, int times);
s21_big_decimal s21_div_big_bits(s21_big_decimal v1, s21_big_decimal v2,
                                 s21_big_decimal *r);

void s21_sub_big_bits(s21_big_decimal v1, s21_big_decimal v2,
                      s21_big_decimal *r);

int s21_is_big_equal(s21_big_decimal value_1, s21_big_decimal value_2);

int s21_is_big_greater(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_big_greater_or_equal(s21_big_decimal value_1,
                                s21_big_decimal value_2);

#endif  // SRC_S21_ARITHMETIC_S21_ARITHMETIC_H_