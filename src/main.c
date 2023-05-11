#include "tests/s21_tests.h"

int main(void) {
  run_tests();
  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_from_int_to_decimal(),
                         suite_from_decimal_to_int(),
                         suite_from_decimal_to_float(),
                         suite_from_float_to_decimal(),
                         suite_is_greater(),
                         suite_is_greater_or_equal(),
                         suite_is_equal(),
                         suite_is_not_equal(),
                         suite_is_less(),
                         suite_is_less_or_equal(),
                         suite_negate(),
                         suite_truncate(),
                         suite_round(),
                         suite_floor(),
                         suite_add(),
                         suite_mul(),
                         suite_sub(),
                         suite_div(),
                         s21_NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != s21_NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}