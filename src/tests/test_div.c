#include "s21_tests.h"
void s21_set_zero(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
}

START_TEST(div1) {
  s21_decimal var1 = {{200, 0, 0, 2147483648}};
  s21_decimal var2 = {{50, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_div(var1, var2, &result);
  s21_decimal answer = {{4, 0, 0, 2147483648}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(getPower(answer),
                   getPower(result));  // the fraction is different
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(div2) {
  s21_decimal var1 = {{100, 0, 0, 0}};
  s21_decimal var2 = {{4, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_div(var1, var2, &result);
  s21_decimal answer = {{25, 0, 0, 0}};
  ck_assert_int_eq(getPower(answer),
                   getPower(result));  // the fraction is different
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(div3) {
  s21_decimal var1 = {{4294967295, 4294967295, 4294967295, 196608}};
  s21_decimal var2 = {{4294967295, 4294967295, 4294967295, 196608}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_div(var1, var2, &result);
  s21_decimal answer = {{1, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(div4) {
  s21_decimal var1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal var2 = {{1, 0, 0, 65536}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_div(var1, var2, &result);
  ck_assert_int_eq(1, returned_var);
}
END_TEST

START_TEST(div5) {
  s21_decimal x = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal y = {{2, 0, 0, 28 << 16}};
  s21_decimal z = {{0, 0, 0, 0}};
  int err = 0;
  err = s21_div(x, y, &z);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(div6) {
  s21_decimal x = {{0xffffffff, 0xffffffff, 0xffffffff, NEGATIVE}};
  s21_decimal y = {{2, 0, 0, 28 << 16}};
  s21_decimal z = {{0, 0, 0, 0}};
  int err = 0;
  err = s21_div(x, y, &z);
  ck_assert_int_eq(err, 2);
}
END_TEST

Suite *suite_div(void) {
  Suite *s = suite_create("suite_div");
  TCase *tc = tcase_create("div_tc");
  tcase_add_test(tc, div1);
  tcase_add_test(tc, div2);
  tcase_add_test(tc, div3);
  tcase_add_test(tc, div4);
  tcase_add_test(tc, div5);
  tcase_add_test(tc, div6);
  suite_add_tcase(s, tc);
  return s;
}