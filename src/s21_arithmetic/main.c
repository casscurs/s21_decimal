// #include "../tests/s21_tests.h"

// int main() {
// //   s21_decimal var1 = {{1, 1, 1, 10 << 16}};
// //   s21_decimal var2 = {{1, 10, 1, NEGATIVE + (15 << 16)}};
//   s21_decimal var1 = {{10, 0, 0, 0}};
//   s21_decimal var2 = {{658067456, 1164, 0, 0}};
// //   s21_decimal var1 = {{35, 0, 0, 0}};
// //   s21_decimal var2 = {{8, 0, 0, 0}};
//   setPower(&var1,8);
//   setPower(&var2,1);
// // s21_decimal var1 = {{4294967295, 0, 0, 0}};
// // s21_decimal var2 = {{8, 0, 0, 0}};
//   // setSign(&var1,-1);
//   Bin_Print(var1);
//   Dec_Print(var1);
//   // setSign(&var2,-1);
//   Bin_Print(var2);
//   Dec_Print(var2);
//   s21_decimal result = {{0, 0, 0, 0}};
//   printf("\n%d\n", s21_div(var1, var2, &result));

//   Bin_Print(result);
//   Dec_Print(result);
//   printf("\n\expected\n");
//   //s21_decimal exp = {{1019311944, 458670364, 542101085, 2148990976}};
//   s21_decimal exp = {{2, 0, 0,   786432}};
// //   Bin_Print(exp);
// //   Dec_Print(exp);
//   return 0;
// }

// //   s21_decimal x = {{1, 1, 1, 10 << 16}};
// //   s21_decimal y = {{1, 10, 1, NEGATIVE + (15 << 16)}};
// //   s21_decimal z = {{0, 0, 0, 0}};
// //   s21_div(x, y, &z);
// //   char ourRes[1000], expect[1000] = "1019311944//3 458670364 542101085
// //   2148990976"; snprintf(ourRes, sizeof(char) * 1000, "%u %u %u %u",
// //   z.bits[0], z.bits[1],
// //            z.bits[2], z.bits[3]);
// //   ck_assert_str_eq(ourRes, expect);