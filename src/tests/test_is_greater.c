#include "s21_tests.h"

START_TEST(is_gr_1) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(5, &val1);
  s21_from_int_to_decimal(5, &val2);

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(is_gr_2) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(5, &val1);
  s21_from_int_to_decimal(2, &val2);
  int s21_res = s21_is_greater(val1, val2);
  ck_assert_int_eq(s21_res, 1);
}
END_TEST

START_TEST(is_gr_3) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(2, &val1);
  s21_from_int_to_decimal(5, &val2);

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(is_gr_4) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(-5, &val1);
  s21_from_int_to_decimal(-5, &val2);

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(is_gr_5) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(-2, &val1);
  s21_from_int_to_decimal(-5, &val2);

  ck_assert_int_eq(s21_is_greater(val1, val2), 1);
}
END_TEST

START_TEST(is_gr_6) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(-5, &val1);
  s21_from_int_to_decimal(-2, &val2);

  ck_assert_int_eq(s21_is_greater(val1, val2), 0);
}
END_TEST

START_TEST(is_greater_1) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 2, 0}};
  int ourRes = s21_is_greater(y, x);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, 0}};
  int ourRes = s21_is_greater(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 2, NEGATIVE}};

  int ourRes = s21_is_greater(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};
  int ourRes = s21_is_greater(y, x);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal x = {{0, 0, 1, NEGATIVE}};
  s21_decimal y = {{0, 0, 1, 0}};

  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal x = {{0, 0, 1, 0}};
  s21_decimal y = {{0, 0, 1, NEGATIVE}};

  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_9) {
  s21_decimal x = {{1, 2, 3, 655360}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_10) {
  s21_decimal x = {{1, 2, 3, -2146828288}};
  s21_decimal y = {{3, 2, 1, -2146828288}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_11) {
  s21_decimal x = {{1, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, -2146959360}};
  int ourRes = s21_is_greater(x, y);
  int expect = 1;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_12) {
  s21_decimal x = {{10, 2, 3, -2146566144}};
  s21_decimal y = {{3, 2, 1, 524288}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_13) {
  s21_decimal x = {{1, 2, 3, 917504}};
  s21_decimal y = {{1, 2, 3, 917504}};
  int ourRes = s21_is_greater(x, y);
  int expect = 0;
  ck_assert_int_eq(ourRes, expect);
}
END_TEST

START_TEST(is_greater_14) {
  s21_decimal num1 = {{-1, -1, -1, -2147483648}};
  s21_decimal num2 = {{0, 0, 100, 0}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_15) {
  s21_decimal num1 = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, -2147483648}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_16) {
  s21_decimal num1 = {{10, 0, 0, -2147483648}};
  s21_decimal num2 = {{9, 0, 0, -2147483648}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_17) {
  s21_decimal num1 = {{9, 90, 0, -2147483648}};
  s21_decimal num2 = {{10, 100, 0, -2147483648}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_18) {
  s21_decimal num1 = {{10, 11, 12, 0}};
  s21_decimal num2 = {{9, 8, 130, 0}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_19) {
  s21_decimal num1 = {{5, 1, 8, -2146041856}};
  s21_decimal num2 = {{5, 1, 8, -2146238464}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 1);
}
END_TEST

START_TEST(is_greater_20) {
  s21_decimal num1 = {{5, 40, 8, -2146238464}};
  s21_decimal num2 = {{500, 1, 3, -2146041856}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_21) {
  s21_decimal num1 = {{10, 11, 12, 65536}};
  s21_decimal num2 = {{9, 8, 13, 65536}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

START_TEST(is_greater_22) {
  s21_decimal num1 = {{6, 0, 0, 589824}};
  s21_decimal num2 = {{0, 0, 10, 0}};
  int flag1 = s21_is_greater(num1, num2);
  ck_assert_int_eq(flag1, 0);
}
END_TEST

Suite *suite_is_greater(void) {
  Suite *s = suite_create("suite_is_greater");
  TCase *tc = tcase_create("is_greater_tc");

  tcase_add_test(tc, is_gr_1);
  tcase_add_test(tc, is_gr_2);
  tcase_add_test(tc, is_gr_3);
  tcase_add_test(tc, is_gr_4);
  tcase_add_test(tc, is_gr_5);
  tcase_add_test(tc, is_gr_6);

  // ref tests
  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_greater_6);
  tcase_add_test(tc, is_greater_7);
  tcase_add_test(tc, is_greater_8);
  tcase_add_test(tc, is_greater_9);
  tcase_add_test(tc, is_greater_10);
  tcase_add_test(tc, is_greater_11);
  tcase_add_test(tc, is_greater_12);
  tcase_add_test(tc, is_greater_13);
  tcase_add_test(tc, is_greater_14);
  tcase_add_test(tc, is_greater_15);
  tcase_add_test(tc, is_greater_16);
  tcase_add_test(tc, is_greater_17);
  tcase_add_test(tc, is_greater_18);
  tcase_add_test(tc, is_greater_19);
  tcase_add_test(tc, is_greater_20);
  tcase_add_test(tc, is_greater_21);
  tcase_add_test(tc, is_greater_22);

  suite_add_tcase(s, tc);
  return s;
}