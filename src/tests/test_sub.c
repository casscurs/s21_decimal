#include "s21_tests.h"

START_TEST(sub1) {
  s21_decimal var1 = {{932169, 0, 0, 0}};
  s21_decimal var2 = {{123456}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{808713, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub2) {
  s21_decimal var1 = {{123456, 0, 0, 0}};
  s21_decimal var2 = {{932169, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{808713, 0, 0, NEGATIVE}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub3) {
  s21_decimal var1 = {{987654, 0, 0, NEGATIVE}};
  s21_decimal var2 = {{123456, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{864198, 0, 0, NEGATIVE}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub4) {
  s21_decimal var1 = {{123456, 0, 0, NEGATIVE}};
  s21_decimal var2 = {{987654, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{864198, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub5) {
  s21_decimal var1 = {{456123, 0, 0, 0}};
  s21_decimal var2 = {{123456, 0, 0, NEGATIVE}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_sub(var1, var2, &result);
  s21_decimal answer = {{579579, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(sub6) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub7) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub8) {
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{2, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub9) {
  s21_decimal x = {{2, 0, 0, 2147483648}};
  s21_decimal y = {{2, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub10) {
  s21_decimal x = {{1, 0, 0, 2147483648}};
  s21_decimal y = {{2, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub11) {
  s21_decimal x = {{2, 0, 0, 2147483648}};
  s21_decimal y = {{1, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub12) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "3 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub13) {
  s21_decimal x = {{2, 0, 0, 2147483648}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "3 0 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub14) {
  s21_decimal x = {{1, 1, 1, 65536}};
  s21_decimal y = {{1, 1, 1, -2147418112}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "2 2 2 65536";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub15) {
  s21_decimal x = {{1, 1, 1, -2147418112}};
  s21_decimal y = {{1, 1, 1, -2147418112}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(sub16) {
  s21_decimal x = {{24, 1, 1, -2147418112}};
  s21_decimal y = {{1, 1, 1, 65536}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_sub(x, y, &z);
  char ourRes[1000], expect[1000] = "25 2 2 2147549184";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

Suite *suite_sub(void) {
  Suite *s = suite_create("suite_sub");
  TCase *tc = tcase_create("sub_tc");

  tcase_add_test(tc, sub1);
  tcase_add_test(tc, sub2);
  tcase_add_test(tc, sub3);
  tcase_add_test(tc, sub4);
  tcase_add_test(tc, sub5);
  tcase_add_test(tc, sub6);
  tcase_add_test(tc, sub7);
  tcase_add_test(tc, sub8);
  tcase_add_test(tc, sub9);
  tcase_add_test(tc, sub10);
  tcase_add_test(tc, sub11);
  tcase_add_test(tc, sub12);
  tcase_add_test(tc, sub13);
  tcase_add_test(tc, sub14);
  tcase_add_test(tc, sub15);
  tcase_add_test(tc, sub16);

  suite_add_tcase(s, tc);
  return s;
}