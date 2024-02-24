#include "s21_tests.h"

START_TEST(test1) {
  s21_decimal value_1 = {0};
  int a = 0;
  value_1.bits[0] = 21;
  //   value_1.bits[3] = 1u << 31;
  int b = 21;
  s21_from_decimal_to_int(value_1, &a);

  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test2) {
  s21_decimal value_1 = {0};
  int a = 0;
  value_1.bits[0] = 21;
  value_1.bits[3] = 1u << 31;
  int b = -21;
  s21_from_decimal_to_int(value_1, &a);

  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(from_decimal_to_int_0) {
  int res = (int)3.14;
  int s21_int = 0;
  s21_decimal number = {0};
  number.bits[0] = 314;
  number.bits[1] = 0;
  number.bits[2] = 0;
  setPower(&number, 2);
  s21_from_decimal_to_int(number, &s21_int);
  ck_assert_int_eq(res, s21_int);
}
END_TEST

START_TEST(from_decimal_to_int_1) {
  int res = 123456789;
  int s21_int = 0;
  s21_decimal number = {0};
  number.bits[0] = 123456789;
  number.bits[1] = 0;
  number.bits[2] = 0;
  s21_from_decimal_to_int(number, &s21_int);
  ck_assert_int_eq(res, s21_int);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  int res = (int)-4294;
  int s21_int = 0;
  s21_decimal number = {0};
  number.bits[0] = 4294;
  number.bits[1] = 0;
  number.bits[2] = 0;
  setBit(&number, 127, 1);
  s21_from_decimal_to_int(number, &s21_int);
  ck_assert_int_eq(res, s21_int);
}
END_TEST

START_TEST(from_decimal_to_int_error_0) {
  int s21_int = 0;
  s21_decimal number = {0};
  number.bits[0] = 123456789;
  number.bits[1] = 123456789;
  number.bits[2] = 123456789;
  ck_assert_int_eq(1, s21_from_decimal_to_int(number, &s21_int));
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s = suite_create("suite_from_decimal_to_int");
  TCase *tc = tcase_create("from_decimal_to_int_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);

  tcase_add_test(tc, from_decimal_to_int_0);
  tcase_add_test(tc, from_decimal_to_int_1);
  tcase_add_test(tc, from_decimal_to_int_2);
  tcase_add_test(tc, from_decimal_to_int_error_0);

  suite_add_tcase(s, tc);
  return s;
}