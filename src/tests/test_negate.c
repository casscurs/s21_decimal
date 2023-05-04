#include "s21_tests.h"

START_TEST(negate_positive) {
  s21_decimal ours = {{14, 0, 0, 0}};
  s21_decimal expect = {{14, 0, 0, 0}};
  setSign(&expect, -1);
  int error = 0;
  error = s21_negate(ours, &ours);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(ours.bits[i], expect.bits[i]);
  }
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(negate_result_NULL) {
  s21_decimal ours = {{41, 0, 0, 0}};
  int error = 0;
  error = s21_negate(ours, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(negate_total_zero) {
  s21_decimal ours = {0};
  s21_decimal expect = {0};
  int error = 0;
  error = s21_negate(ours, &ours);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(ours.bits[i], expect.bits[i]);
  }
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(negate_isInf) {
  s21_decimal ours = {{0, 0, 0, 0}};
  setPower(&ours, 255);
  // s21_decimal expect = {0};
  int error = 0;
  error = s21_negate(ours, &ours);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(negate_isNan) {
  s21_decimal ours = {{0, 0, 2147483648, 0}};
  setPower(&ours, 255);
  int error = 0;
  error = s21_negate(ours, &ours);

  ck_assert_int_eq(error, 1);
}
END_TEST

Suite *suite_negate(void) {
  Suite *s = suite_create("suite_negate");
  TCase *tc = tcase_create("negate_tc");

  tcase_add_test(tc, negate_positive);
  tcase_add_test(tc, negate_result_NULL);
  tcase_add_test(tc, negate_total_zero);
  tcase_add_test(tc, negate_isInf);
  tcase_add_test(tc, negate_isNan);

  suite_add_tcase(s, tc);
  return s;
}
