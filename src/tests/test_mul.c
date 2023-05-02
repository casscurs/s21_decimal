#include "s21_tests.h"

START_TEST(mul1) {
  s21_decimal var1 = {{100, 0, 0, 0}};
  s21_decimal var2 = {{2, 0, 0, 0}};
  s21_decimal result = {{200, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{200, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul2) {
  s21_decimal var1 = {{5346, 0, 0, 0}};
  s21_decimal var2 = {{5346, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{28579716, 0, 0, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul3) {
  s21_decimal var1 = {{12345678, 0, 0, 196608}};
  s21_decimal var2 = {{3, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);

  s21_decimal answer = {{37037034, 0, 0, 196608}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul4) {
  s21_decimal var1 = {{4294879641, 49999, 0, 917504}};
  s21_decimal var2 = {{4294879641, 49999, 0, 917504}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{3388431729, 4119401889, 2499999997, 1835008}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul5) {
  s21_decimal var1 = {{4294879641, 49999, 0, 2148401152}};
  s21_decimal var2 = {{4294879641, 49999, 0, 2148401152}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{3388431729, 4119401889, 2499999997, 1835008}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul6) {
  s21_decimal var1 = {{4294967295, 3551657983, 116415321, 0}};
  s21_decimal var2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int returned_var = s21_mul(var1, var2, &result);
  s21_decimal answer = {{4294967294, 2808348671, 232830643, 0}};
  ck_assert_int_eq(0, returned_var);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul7) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{5, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "10 0 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul8) {
  s21_decimal x = {{2, 1, 2, 0}};
  s21_decimal y = {{5, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "10 5 10 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul9) {
  s21_decimal x = {{2, 0, 0, 0}};
  s21_decimal y = {{0, 0, 10, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "0 0 20 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul10) {
  s21_decimal x = {{1000000000, 0, 0, 0}};
  s21_decimal y = {{6, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1705032704 1 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul11) {
  s21_decimal x = {{1000000000, 0, 0, 2147483648}};
  s21_decimal y = {{6, 0, 0, 2147483648}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1705032704 1 0 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul12) {
  s21_decimal x = {{1000000000, 0, 0, 2147483648}};
  s21_decimal y = {{6, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1705032704 1 0 2147483648";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul13) {
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal x = {{165, 22, 6587456, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "165 22 6587456 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul15) {
  s21_decimal x = {{1, 0, 0, 655360}};
  s21_decimal y = {{1, 0, 0, 655360}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 0 1310720";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul16) {
  s21_decimal x = {{1, 0, 0, 655360}};
  s21_decimal y = {{1, 0, 0, -2146828288}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);

  char ourRes[1000], expect[1000] = "1 0 0 2148794368";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul17) {
  s21_decimal x = {{1, 0, 1, 917504}};
  s21_decimal y = {{1, 0, 0, -2146828288}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "1 0 1 2149056512";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

START_TEST(mul_1) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{150, 0, 0, 0}};
  s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal value_1 = {{0x26687e73, 0, 0, (4 << 16)}};
  s21_decimal value_2 = {{0xd3, 0, 0, (1 << 16)}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0xa82038c9, 0x1f, 0, (5 << 16)}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal value_1 = {{0x1, 0, 0, ((1 << 31) | (14 << 16))}};
  s21_decimal value_2 = {{0x1, 0, 0, ((1 << 31) | (14 << 16))}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0x1, 0, 0, (28 << 16)}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal value_1 = {{0}};
  memset(&value_1, 0, sizeof(s21_decimal));
  s21_decimal value_2 = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
  s21_decimal result = {{0, 0, 0, 0}};

  s21_decimal answer = {{0, 0, 0, ((1 << 31) | (2 << 16))}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal answer = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
  ck_assert_int_eq(1, s21_is_equal(answer, result));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0x17565d3a, 0x1ade5f, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_mul(value_1, value_2, &result));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{0x17565d3a, 0x1ade5f, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(2, s21_mul(value_1, value_2, &result));
}
END_TEST

START_TEST(mul__1) {
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal value_1 = {{0x17565d3a, 0x1ade5f, 0, 1 << 31}};
  s21_decimal result = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("suite_mul");
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, mul1);
  tcase_add_test(tc, mul2);
  tcase_add_test(tc, mul3);
  tcase_add_test(tc, mul4);
  tcase_add_test(tc, mul5);
  tcase_add_test(tc, mul6);
  tcase_add_test(tc, mul7);
  tcase_add_test(tc, mul8);
  tcase_add_test(tc, mul9);
  tcase_add_test(tc, mul10);
  tcase_add_test(tc, mul11);
  tcase_add_test(tc, mul12);
  tcase_add_test(tc, mul13);
  tcase_add_test(tc, mul15);
  tcase_add_test(tc, mul16);
  tcase_add_test(tc, mul17);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);

  tcase_add_test(tc, mul__1);

  suite_add_tcase(s, tc);
  return s;
}