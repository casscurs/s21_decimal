#include "s21_tests.h"

START_TEST(negate_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

START_TEST(negate_1) {
  s21_decimal val = {{2, 0, 0, ~(s21_MAX_UINT / 2)}};
  s21_decimal res = {0};
  ck_assert_int_eq(0, s21_negate(val, &res));
}
END_TEST

// START_TEST(negate_2) {
//   s21_decimal val = {{0, 0, 0, ~(s21_MAX_UINT / 2)}};
//   s21_decimal res = {0};
//   ck_assert_int_eq(0, s21_negate(val, &res));
// }
// END_TEST

START_TEST(negate_3) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  ck_assert_int_eq(1, s21_negate(val, &res));
}
END_TEST

Suite *suite_negate(void) {
  Suite *s = suite_create("suite_negate");
  TCase *tc = tcase_create("negate_tc");

  tcase_add_test(tc, negate_0);
  tcase_add_test(tc, negate_1);
  // tcase_add_test(tc, negate_2);

  tcase_add_test(tc, negate_3);

  suite_add_tcase(s, tc);
  return s;
}