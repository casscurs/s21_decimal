// #include "s21_tests.h"

// START_TEST(mul1) {
//   s21_decimal var1 = {{100, 0, 0, 0}};
//   s21_decimal var2 = {{2, 0, 0, 0}};
//   s21_decimal result = {{200, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{200, 0, 0, 0}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul2) {
//   s21_decimal var1 = {{5346, 0, 0, 0}};
//   s21_decimal var2 = {{5346, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{28579716, 0, 0, 0}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul3) {
//   s21_decimal var1 = {{12345678, 0, 0, 196608}};
//   s21_decimal var2 = {{3, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);

//   s21_decimal answer = {{37037034, 0, 0, 196608}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul4) {
//   s21_decimal var1 = {{4294879641, 49999, 0, 917504}};
//   s21_decimal var2 = {{4294879641, 49999, 0, 917504}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{3388431729, 4119401889, 2499999997, 1835008}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul5) {
//   s21_decimal var1 = {{4294879641, 49999, 0, 2148401152}};
//   s21_decimal var2 = {{4294879641, 49999, 0, 2148401152}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{3388431729, 4119401889, 2499999997, 1835008}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul6) {
//   s21_decimal var1 = {{4294967295, 3551657983, 116415321, 0}};
//   s21_decimal var2 = {{2, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   int returned_var = s21_mul(var1, var2, &result);
//   s21_decimal answer = {{4294967294, 2808348671, 232830643, 0}};
//   ck_assert_int_eq(0, returned_var);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul7) {
//   s21_decimal x = {{2, 0, 0, 0}};
//   s21_decimal y = {{5, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "10 0 0 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul8) {
//   s21_decimal x = {{2, 1, 2, 0}};
//   s21_decimal y = {{5, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "10 5 10 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul9) {
//   s21_decimal x = {{2, 0, 0, 0}};
//   s21_decimal y = {{0, 0, 10, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "0 0 20 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul10) {
//   s21_decimal x = {{1000000000, 0, 0, 0}};
//   s21_decimal y = {{6, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1705032704 1 0 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul11) {
//   s21_decimal x = {{1000000000, 0, 0, 2147483648}};
//   s21_decimal y = {{6, 0, 0, 2147483648}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1705032704 1 0 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul12) {
//   s21_decimal x = {{1000000000, 0, 0, 2147483648}};
//   s21_decimal y = {{6, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1705032704 1 0 2147483648";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul13) {
//   s21_decimal y = {{1, 0, 0, 0}};
//   s21_decimal x = {{165, 22, 6587456, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "165 22 6587456 0";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul15) {
//   s21_decimal x = {{1, 0, 0, 655360}};
//   s21_decimal y = {{1, 0, 0, 655360}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1 0 0 1310720";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul16) {
//   s21_decimal x = {{1, 0, 0, 655360}};
//   s21_decimal y = {{1, 0, 0, -2146828288}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);

//   char ourRes[1000], expect[1000] = "1 0 0 2148794368";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul17) {
//   s21_decimal x = {{1, 0, 1, 917504}};
//   s21_decimal y = {{1, 0, 0, -2146828288}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1 0 1 2149056512";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

// START_TEST(mul_1) {
//   s21_decimal value_1 = {{15, 0, 0, 0}};
//   s21_decimal value_2 = {{10, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal answer = {{150, 0, 0, 0}};
//   s21_mul(value_1, value_2, &result);
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul_2) {
//   s21_decimal value_1 = {{0x26687e73, 0, 0, (4 << 16)}};
//   s21_decimal value_2 = {{0xd3, 0, 0, (1 << 16)}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal answer = {{0xa82038c9, 0x1f, 0, (5 << 16)}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul_3) {
//   s21_decimal value_1 = {{0x1, 0, 0, ((1 << 31) | (14 << 16))}};
//   s21_decimal value_2 = {{0x1, 0, 0, ((1 << 31) | (14 << 16))}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal answer = {{0x1, 0, 0, (28 << 16)}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul_4) {
//   s21_decimal value_1 = {{0}};
//   memset(&value_1, 0, sizeof(s21_decimal));
//   s21_decimal value_2 = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
//   s21_decimal result = {{0, 0, 0, 0}};

//   s21_decimal answer = {{0, 0, 0, ((1 << 31) | (2 << 16))}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul_5) {
//   s21_decimal value_1 = {{1, 0, 0, 0}};
//   s21_decimal value_2 = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal answer = {{0xffffffff, 0, 0, ((1 << 31) | (2 << 16))}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

// START_TEST(mul_7) {
//   s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
//   s21_decimal value_2 = {{0x17565d3a, 0x1ade5f, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   ck_assert_int_eq(1, s21_mul(value_1, value_2, &result));
// }
// END_TEST

// START_TEST(mul_8) {
//   s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
//   s21_decimal value_2 = {{0x17565d3a, 0x1ade5f, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};

//   ck_assert_int_eq(2, s21_mul(value_1, value_2, &result));
// }
// END_TEST

// START_TEST(mul__1) {
//   s21_decimal value_2 = {{0, 0, 0, 0}};
//   s21_decimal value_1 = {{0x17565d3a, 0x1ade5f, 0, 1 << 31}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
// }
// END_TEST

// Suite *suite_mul(void) {
//   Suite *s = suite_create("suite_mul");
//   TCase *tc = tcase_create("mul_tc");

//   tcase_add_test(tc, mul1);
//   tcase_add_test(tc, mul2);
//   tcase_add_test(tc, mul3);
//   tcase_add_test(tc, mul4);
//   tcase_add_test(tc, mul5);
//   tcase_add_test(tc, mul6);
//   tcase_add_test(tc, mul7);
//   tcase_add_test(tc, mul8);
//   tcase_add_test(tc, mul9);
//   tcase_add_test(tc, mul10);
//   tcase_add_test(tc, mul11);
//   tcase_add_test(tc, mul12);
//   tcase_add_test(tc, mul13);
//   tcase_add_test(tc, mul15);
//   tcase_add_test(tc, mul16);
//   tcase_add_test(tc, mul17);
//   tcase_add_test(tc, mul_1);
//   tcase_add_test(tc, mul_2);
//   tcase_add_test(tc, mul_3);
//   tcase_add_test(tc, mul_4);
//   tcase_add_test(tc, mul_5);
//   tcase_add_test(tc, mul_7);
//   tcase_add_test(tc, mul_8);

//   tcase_add_test(tc, mul__1);

//   suite_add_tcase(s, tc);
//   return s;
// }

#include "s21_tests.h"

#define MUL_PIE_TESTS 20
#define MUL_ERR_TESTS 10
#define MUL_ROUND_TESTS 16

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
  // Bin_Print(result);
  // Dec_Print(result);
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
  s21_decimal x = {{1, 0, 0, 0}};
  s21_decimal y = {{165, 22, 6587456, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_mul(x, y, &z);
  char ourRes[1000], expect[1000] = "165 22 6587456 0";
  snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
           z.bits[2], z.bits[3]);
  ck_assert_str_eq(ourRes, expect);
}
END_TEST

// START_TEST(mul14) {
//   s21_decimal x = {{1, 1, 1, 655360}};
//   s21_decimal y = {{1, 1, 1, 655360}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_mul(x, y, &z);
//   char ourRes[1000], expect[1000] = "1652684285 987621807 1844674408 655360";
//   snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u", z.bits[0], z.bits[1],
//            z.bits[2], z.bits[3]);
//   ck_assert_str_eq(ourRes, expect);
// }
// END_TEST

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

// START_TEST(mul_6) {
//   s21_decimal value_1 = {
//       {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, ((1 << 31) | (28 << 16))}};
//   s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, (28 << 16)}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal answer = {
//       {0x96EE456, 0x359A3B3E, 0xCAD2F7F5, ((1 << 31) | (27 << 16))}};
//   ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));
//   ck_assert_int_eq(1, s21_is_equal(answer, result));
// }
// END_TEST

START_TEST(mul_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0x17565d3a, 0x1ade5f, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  // s21_decimal answer = {{0xebedb93d, 0x9c7bbf94, 0xb8cffbed, (17 << 16)}};

  ck_assert_int_eq(1, s21_mul(value_1, value_2, &result));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};
  s21_decimal value_2 = {{
      0x17565d3a,
      0x1ade5f,
      0,
  }};
  s21_decimal result = {{0, 0, 0, 0}};

  ck_assert_int_eq(2, s21_mul(value_1, value_2, &result));
}
END_TEST

// START_TEST(mul_99) {
//   s21_decimal src1, src2, true_result, result, dec_null, dec_max = {0};
//   int val;
//   memset(&dec_null, 0, sizeof(s21_decimal));
//   memset(&true_result, 0, sizeof(s21_decimal));
//   // s21_set_zero(&dec_null);
//   // s21_set_zero(&true_result);
//   dec_max.bits[0] = dec_max.bits[1] = dec_max.bits[2] = 0xffffffff;
//   dec_max.bits[3] = 0;

//   // 57*32= 1824
//   src1.bits[0] = 57;
//   src1.bits[1] = 0;
//   src1.bits[2] = 0;
//   src1.bits[3] = 0;
//   src2.bits[0] = 32;
//   src2.bits[1] = 0;
//   src2.bits[2] = 0;
//   src2.bits[3] = 0;
//   val = s21_mul(src1, src2, &result);

//   true_result.bits[0] = 1824;
//   true_result.bits[1] = 0;
//   true_result.bits[2] = 0;
//   true_result.bits[3] = 0;
//   ck_assert_int_eq(result.bits[0], true_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], true_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], true_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], true_result.bits[3]);
//   ck_assert_int_eq(val, 0);

//   // 79228162514264337593543950335 * (-0.00321)=
//   -254322401670788523675276080.58 src1.bits[0] = 0xffffffff; src1.bits[1] =
//   0xffffffff; src1.bits[2] = 0xffffffff; src1.bits[3] = 0; src2.bits[0] =
//   0b00000000000000000000000101000001; src2.bits[1] = 0; src2.bits[2] = 0;
//   src2.bits[3] = 0b10000000000001010000000000000000;
//   val = s21_mul(src1, src2, &result);

//   true_result.bits[0] = 0b10111100011010100111111011111010;
//   true_result.bits[1] = 0b00000100000110001001001101110100;
//   true_result.bits[2] = 0b01010010001011010000111001010110;
//   true_result.bits[3] = 0b10000000000000100000000000000000;

//   ck_assert_int_eq(result.bits[0], true_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], true_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], true_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], true_result.bits[3]);
//   ck_assert_int_eq(val, 0);

//   // (-89.4730208302234) * (-1834857353874.7273873454897) =
//   // 164170230243722.07187139009243
//   src1.bits[0] = 0b10011100001111000101010010011010;
//   src1.bits[1] = 0b00000000000000110010110111000000;
//   src1.bits[2] = 0;
//   src1.bits[3] = 0b10000000000011010000000000000000;
//   src2.bits[0] = 0b00101001010000111111011100110001;
//   src2.bits[1] = 0b00101010001001011001010110011000;
//   src2.bits[2] = 0b00000000000011110010110101110110;
//   src2.bits[3] = 0b10000000000011010000000000000000;
//   true_result.bits[0] = 0b01100111000001001001101011011011;
//   true_result.bits[1] = 0b01110000001111011110100011110111;
//   true_result.bits[2] = 0b00110101000010111101011111011001;
//   true_result.bits[3] = 0b00000000000011100000000000000000;
//   val = s21_mul(src1, src2, &result);
//   ck_assert_int_eq(result.bits[0], true_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], true_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], true_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], true_result.bits[3]);
//   ck_assert_int_eq(val, 0);

//   // 79228162514264337593543950335*1.7=1
//   src1.bits[0] = 0xffffffff;
//   src1.bits[1] = 0xffffffff;
//   src1.bits[2] = 0xffffffff;
//   src1.bits[3] = 0;
//   src2.bits[0] = 17;
//   src2.bits[1] = 0;
//   src2.bits[2] = 0;
//   src2.bits[3] = 0x00010000;
//   val = s21_mul(src1, src2, &result);
//   ck_assert_int_eq(val, 1);

//   // -79228162514264337593543950335 * 10 = -1
//   src1.bits[0] = 0xffffffff;
//   src1.bits[1] = 0xffffffff;
//   src1.bits[2] = 0xffffffff;
//   src1.bits[3] = 0x80000000;
//   src2.bits[0] = 10;
//   src2.bits[1] = 0;
//   src2.bits[2] = 0;
//   src2.bits[3] = 0;
//   val = s21_mul(src1, src2, &result);

//   ck_assert_int_eq(val, 2);

//   // 7.9228162514264337593543950335 * 7.9228162514264337593543950335
//   // = 62.771017353866807638357894230
//   src1.bits[0] = 0xffffffff;
//   src1.bits[1] = 0xffffffff;
//   src1.bits[2] = 0xffffffff;
//   src1.bits[3] = 0b00000000000111000000000000000000;
//   src2.bits[0] = 0xffffffff;
//   src2.bits[1] = 0xffffffff;
//   src2.bits[2] = 0xffffffff;
//   src2.bits[3] = 0b00000000000111000000000000000000;
//   true_result.bits[0] = 158262358;
//   true_result.bits[1] = 899300158;
//   true_result.bits[2] = 3402823669;
//   true_result.bits[3] = 1769472;
//   val = s21_mul(src1, src2, &result);
//   ck_assert_int_eq(result.bits[0], true_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], true_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], true_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], true_result.bits[3]);
//   ck_assert_int_eq(val, 0);

//   // 0.000002514264337593543950335 * 0.9228162514264337593543950335 =
//   // 0.0000023202039911132397835426
//   src1.bits[0] = 0b11011111111111111111111111111111;
//   src1.bits[1] = 0b01001100011011010100110111100101;
//   src1.bits[2] = 0b00000000000000000000000010001000;
//   src1.bits[3] = 0b00000000000110110000000000000000;
//   src2.bits[0] = 0b10001111111111111111111111111111;
//   src2.bits[1] = 0b01001100111111001110111101011000;
//   src2.bits[2] = 0b00011101110100010101101101101100;
//   src2.bits[3] = 0b00000000000111000000000000000000;
//   val = s21_mul(src1, src2, &result);
//   true_result.bits[0] = 0b10111010011100000001010010100010;
//   true_result.bits[1] = 0b11001000111111001001000101111111;
//   true_result.bits[2] = 0b00000000000000000000010011101001;
//   true_result.bits[3] = 0b00000000000111000000000000000000;
//   ck_assert_int_eq(result.bits[0], true_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], true_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], true_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], true_result.bits[3]);
//   ck_assert_int_eq(val, 0);

//   // 7.9228162514264337593543950335 * 0 =0
//   // степень нуля
//   src1.bits[0] = 0xffffffff;
//   src1.bits[1] = 0xffffffff;
//   src1.bits[2] = 0xffffffff;
//   src1.bits[3] = 0b00000000000111000000000000000000;
//   src2.bits[0] = 0;
//   src2.bits[1] = 0;
//   src2.bits[2] = 0;
//   src2.bits[3] = 0;

//   val = s21_mul(src1, src2, &result);
//   ck_assert_int_eq(0, result.bits[0]);
//   ck_assert_int_eq(0, result.bits[1]);
//   ck_assert_int_eq(0, result.bits[2]);
//   ck_assert_int_eq(0, result.bits[3]);
//   ck_assert_int_eq(val, 0);

//   // -79228162514264337593543950335 * 79228162514264337593543950335
//   // = negativ_inf
//   src1.bits[0] = 0xffffffff;
//   src1.bits[1] = 0xffffffff;
//   src1.bits[2] = 0xffffffff;
//   src1.bits[3] = 0x80000000;
//   src2.bits[0] = 0xffffffff;
//   src2.bits[1] = 0xffffffff;
//   src2.bits[2] = 0xffffffff;
//   src2.bits[3] = 0;

//   val = s21_mul(src1, src2, &result);
//   // ck_assert_int_eq(0, result.bits[0]);
//   // ck_assert_int_eq(0, result.bits[1]);
//   // ck_assert_int_eq(0, result.bits[2]);
//   // ck_assert_int_eq(0, result.bits[3]);
//   ck_assert_int_eq(val, 2);
// }
// END_TEST

// START_TEST(mulX) {
//   s21_decimal x = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 2 << 16}};
//   s21_decimal y = {{2, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};
//   s21_decimal answer = {{858993459, 858993459, 858993459, (2 << 16)}};
//   ck_assert_int_eq(0, s21_mul(x, y, &z));
//   ck_assert_int_eq(1, s21_is_equal(answer, z));
// }
// END_TEST

//

s21_decimal dec_mul_pi_e_src1[MUL_PIE_TESTS] = {
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}}};
s21_decimal dec_mul_pi_e_src2[MUL_PIE_TESTS] = {
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{1, 0, 0, 0}},
    {{1, 0, 0, 1 << 31}},
    {{1, 0, 0, 1 << 31}},
    {{1, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{1, 0, 0, 0}},
    {{1, 0, 0, 1 << 31}},
    {{1, 0, 0, 1 << 31}},
    {{1, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}}};
s21_decimal dec_mul_pi_e_res[MUL_PIE_TESTS] = {
    {{3747862134, 2841889338, 535032326, 27 << 16}},
    {{3747862134, 2841889338, 535032326, 27 << 16}},
    {{399733652, 3580175622, 462939919, (27 << 16) | (1 << 31)}},
    {{399733652, 3580175622, 462939919, (27 << 16) | (1 << 31)}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{399733652, 3580175622, 462939919, 27 << 16}},
    {{399733652, 3580175622, 462939919, 27 << 16}},
    {{3839876251, 2314723989, 4005615337, (28 << 16) | (1 << 31)}},
    {{3839876251, 2314723989, 4005615337, (28 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, 27 << 16}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{3230419695, 825313643, 147358353, (27 << 16) | (1 << 31)}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}}};
int int_mul_pi_e[MUL_PIE_TESTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

s21_decimal dec_mul_error_cases_src1[MUL_ERR_TESTS] = {
    {{0, 0, 1 << 31, 0}},
    {{0, 0, 1 << 31, 1 << 31}},
    {{0, 0, 1 << 31, 0}},
    {{0, 0, 1 << 31, 1 << 31}},
    {{2257730743, 18587456, 170306079, 27 << 16}},
    {{2257730743, 18587456, 170306079, (27 << 16) | (1 << 31)}},
    {{1, 0, 0, 15 << 16}},
    {{1, 0, 0, (1 << 31) | (15 << 16)}},
    {{1, 0, 0, 15 << 16}},
    {{1, 0, 0, (1 << 31) | (15 << 16)}}};
s21_decimal dec_mul_error_cases_src2[MUL_ERR_TESTS] = {
    {{0, 0, 1 << 31, 0}},
    {{0, 0, 1 << 31, 1 << 31}},
    {{0, 0, 1 << 31, 1 << 31}},
    {{0, 0, 1 << 31, 0}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{1, 0, 0, 15 << 16}},
    {{1, 0, 0, (1 << 31) | (15 << 16)}},
    {{1, 0, 0, (1 << 31) | (15 << 16)}},
    {{1, 0, 0, 15 << 16}}

};
s21_decimal dec_mul_error_cases_res[MUL_ERR_TESTS] = {
    {{0, 0, 0, 0}}, {{0, 0, 0, 0}}, {{0, 0, 0, 0}}, {{0, 0, 0, 0}},
    {{0, 0, 0, 0}}, {{0, 0, 0, 0}}, {{0, 0, 0, 0}}, {{0, 0, 0, 0}},
    {{0, 0, 0, 0}}, {{0, 0, 0, 0}}};
int int_mul_error[MUL_ERR_TESTS] = {1, 1, 2, 2, 0, 0, 2, 2, 2, 2};

s21_decimal dec_mul_round_src1[MUL_ROUND_TESTS] = {
    {{268435461, 1042612833, 542101086, 1 << 16}},
    {{268435461, 1042612833, 542101086,
      (1 << 16) | (1 << 31)}},  // 10000...0.5 * 11
    {{268435461, 1042612833, 542101086, 1 << 16}},
    {{268435461, 1042612833, 542101086,
      (1 << 16) | (1 << 31)}},  // 10000...0.5 * 11
    {{268435461, 1042612833, 542101086, 1 << 16}},
    {{268435461, 1042612833, 542101086, (1 << 16) | (1 << 31)}},
    {{268435461, 1042612833, 542101086, 1 << 16}},
    {{268435461, 1042612833, 542101086, (1 << 16) | (1 << 31)}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{5, 0, 0, 28 << 16}},
    {{5, 0, 0, (28 << 16) | (1 << 31)}},
    {{5, 0, 0, 28 << 16}},
    {{5, 0, 0, (28 << 16) | (1 << 31)}}};
s21_decimal dec_mul_round_src2[MUL_ROUND_TESTS] = {
    {{11, 0, 0, 0}},
    {{11, 0, 0, 1 << 31}},
    {{11, 0, 0, 1 << 31}},
    {{11, 0, 0, 0}},
    {{9, 0, 0, 0}},
    {{9, 0, 0, 1 << 31}},
    {{9, 0, 0, 1 << 31}},
    {{9, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{11, 0, 0, 1 << 16}},
    {{11, 0, 0, (1 << 16) | (1 << 31)}},
    {{11, 0, 0, (1 << 16) | (1 << 31)}},
    {{11, 0, 0, 1 << 16}}};

s21_decimal dec_mul_round_res[MUL_ROUND_TESTS] = {
    {{4160749574, 3723854493, 596311194, 0}},
    {{4160749574, 3723854493, 596311194, 0}},
    {{4160749574, 3723854493, 596311194, 1 << 31}},
    {{4160749574, 3723854493, 596311194, 1 << 31}},
    {{671088644, 2656338468, 487890977, 0}},
    {{671088644, 2656338468, 487890977, 0}},
    {{671088644, 2656338468, 487890977, 1 << 31}},
    {{671088644, 2656338468, 487890977, 1 << 31}},
    {{0, 0, 0, 0}},
    {{0, 0, 0, 0}},
    {{6, 0, 0, 28 << 16}},
    {{6, 0, 0, 28 << 16}},
    {{6, 0, 0, (28 << 16) | (1 << 31)}},
    {{6, 0, 0, (28 << 16) | (1 << 31)}}};

int int_mul_round[MUL_ROUND_TESTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

float float_simple_arr_1[12] = {0.0001,   1.34545,  16.123,   2.56,
                                0.07,     3.141689, 10.0002,  -10.24,
                                -2778.55, 94.8550,  -23.4234, 838.860};

float float_simple_arr_2[12] = {-0.00003, 1.345,    16.9999,  256.001,
                                7.00003,  31416.89, 10000.12, -10241.2,
                                -27788.6, 9485.03,  -234.234, 83886.1};

int float_mul_out[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void floatToDecAddAssert(s21_decimal src, s21_decimal dst, int s21_res,
                         int res) {
  ck_assert_int_eq(s21_res, res);
  ck_assert_int_eq(src.bits[0], dst.bits[0]);
  ck_assert_int_eq(src.bits[1], dst.bits[1]);
  ck_assert_int_eq(src.bits[2], dst.bits[2]);
  ck_assert_int_eq(src.bits[3], dst.bits[3]);
}

// START_TEST(s21_mul_pi_e_test) {
//   s21_decimal opt = {0};
//   for (int i = 0; i < MUL_PIE_TESTS; i++) {
//     // s21_init_decimal(&opt);
//     memset(&opt, 0, sizeof(s21_decimal));

//     int s21_res = s21_mul(dec_mul_pi_e_src1[i], dec_mul_pi_e_src2[i], &opt);
//     floatToDecAddAssert(dec_mul_pi_e_res[i], opt, s21_res, int_mul_pi_e[i]);
//   }
// }
// END_TEST

// START_TEST(s21_mul_err_test) {
//   s21_decimal opt = {0};
//   for (int i = 0; i < MUL_ERR_TESTS; i++) {
//     // s21_init_decimal(&opt);
//     memset(&opt, 0, sizeof(s21_decimal));
//     int s21_res =
//         s21_mul(dec_mul_error_cases_src1[i], dec_mul_error_cases_src2[i],
//         &opt);
//     floatToDecAddAssert(dec_mul_error_cases_res[i], opt, s21_res,
//                         int_mul_error[i]);
//   }
// }
// END_TEST

// START_TEST(s21_mul_round_test) {
//   s21_decimal opt = {0};
//   for (int i = 0; i < MUL_ROUND_TESTS; i++) {
//     // s21_init_decimal(&opt);
//     memset(&opt, 0, sizeof(s21_decimal));
//     int s21_res = s21_mul(dec_mul_round_src1[i], dec_mul_round_src2[i],
//     &opt); floatToDecAddAssert(dec_mul_round_res[i], opt, s21_res,
//     int_mul_round[i]);
//   }
// }
// END_TEST

START_TEST(s21_mul_float_test) {
  s21_decimal a = {0}, b = {0}, res = {0};
  float s21_res;
  int out;
  for (int i = 0; i < 12; i++) {
    // s21_init_decimal(&a);
    // s21_init_decimal(&b);
    // s21_init_decimal(&res);
    memset(&a, 0, sizeof(s21_decimal));
    memset(&b, 0, sizeof(s21_decimal));
    memset(&res, 0, sizeof(s21_decimal));
    s21_from_float_to_decimal(float_simple_arr_1[i], &a);
    s21_from_float_to_decimal(float_simple_arr_2[i], &b);
    out = s21_mul(a, b, &res);

    float original = float_simple_arr_1[i] * float_simple_arr_2[i];
    s21_from_decimal_to_float(res, &s21_res);

    ck_assert_float_eq_tol(original, s21_res, 1e6);
    ck_assert_int_eq(out, float_mul_out[i]);
  }
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
  // tcase_add_test(tc, mul14);
  tcase_add_test(tc, mul15);
  tcase_add_test(tc, mul16);
  tcase_add_test(tc, mul17);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  // tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  // tcase_add_test(tc, mul_99);
  // tcase_add_test(tc, mulX);

  //
  tcase_add_test(tc, s21_mul_float_test);
  // tcase_add_test(tc, s21_mul_pi_e_test);
  // tcase_add_test(tc, s21_mul_err_test);
  // tcase_add_test(tc, s21_mul_round_test);
  suite_add_tcase(s, tc);
  return s;
}
