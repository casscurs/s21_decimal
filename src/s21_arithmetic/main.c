// #include "../tests/s21_tests.h"
// enum des_enum { STEPEN, DECIMAL };
// typedef unsigned int d_int;

// void des_str_x2(char* str, char* res);

// int hex_to_int(char* buf, int size) {
//   int sum = 0;
//   for (int i = size - 1, j = 0; i > -1; i--, j++)
//     if (buf[i] == '1') sum += pow(2, j);
//   return sum;
// }
// void des_rev_str(char* str) {
//   d_int len = strlen(str) - 1;
//   for (d_int i = 0, j = len; i <= len / 2; i++, j--) {
//     char tmp = str[i];
//     str[i] = str[j];
//     str[j] = tmp;
//   }
// }
// void des_str1_plus_str2(char* str1, char* str2, char* res) {
//   int len = strlen(str1);
//   int len2 = strlen(str2);
//   int tmp = 0, i = 0, j = 0, ra3 = 0;
//   for (; i < len && j < len2; i++, j++) {
//     tmp = (str1[i] - 48) + (str2[j] - 48) + ra3;
//     if (tmp > 9) ra3 = 1;
//     res[i] = tmp % 10 + 48;
//     if (tmp < 10) ra3 = 0;
//   }
//   if (ra3 > 0 && len == len2) res[i] = ra3-- + 48;
//   if (len < len2) {
//     for (int i = len; i < len2; i++) {
//       tmp = (str2[i] - 48) + ra3;
//       if (tmp > 9) ra3 = 1;
//       res[i] = tmp % 10 + 48;
//       if (tmp < 10) ra3 = 0;
//     }
//   } else if (len > len2) {
//     for (int i = len2; i < len; i++) {
//       tmp = (str1[i] - 48) + ra3;
//       if (tmp > 9) ra3 = 1;
//       res[i] = tmp % 10 + 48;
//       if (tmp < 10) ra3 = 0;
//     }
//   }
//   if (ra3 > 0 && len != len2) {
//     res[strlen(res)] = ra3-- + 48;
//   }
// }
// void des_2_v_pow(char* str, int step) {
//   size_t len = strlen(str);
//   for (size_t i = 0; i < len; i++) str[i] = 0;
//   str[0] = '2';
//   if (step == 0)
//     str[0] = '1';
//   else if (step == 1)
//     str[0] = '2';
//   else
//     for (int i = 0; i < step - 1; i++) des_str_x2(str, str);
// }
// void des_str_x2(char* str, char* res) {
//   int len = strlen(str);
//   int tmp = 0, i = 0, ra3 = 0;
//   for (; i < len; i++) {
//     tmp = (str[i] - 48) * 2 + ra3;
//     if (tmp > 9) ra3 = 1;
//     res[i] = tmp % 10 + 48;
//     if (tmp < 10) ra3 = 0;
//   }
//   if (ra3 > 0) res[i] = ra3 + 48;
// }
// void s21_from_decimal_to_int_mantisa(s21_decimal value) {
//   char* mantis = calloc(100, sizeof(char));
//   des_mantisa_dec_to_str(&value, mantis, DECIMAL);
//   printf("\nDESET MANTISA: %s", mantis);
//   free(mantis);
// }
// void des_mantisa_dec_to_str(s21_decimal* dec, char* str1, int d_enum) {
//   char* str2 = calloc(100, sizeof(char));
//   char* res = calloc(100, sizeof(char));
//   str1[0] = '0';
//   d_int max = 0, min = 0;
//   if (d_enum == STEPEN) {
//     max = 120;  // биты степени
//     min = 112;  // биты степени
//     // s21_printf_decimal(*dec);
//   } else if (d_enum == DECIMAL) {
//     max = 96;  // биты децимал
//     min = 0;   // биты децимал
//   }
//   for (d_int i = min; i < max; i++)
//     if (getBit(*dec, i)) {
//       d_int x = i;
//       if (d_enum == STEPEN) x -= 112;
//       des_2_v_pow(str2, x);
//       des_str1_plus_str2(str1, str2, res);
//       strcpy(str1, res);
//     }
//   des_rev_str(str1);
//   free(res);
//   free(str2);
// }
// //нужен для s21_printf_decimal
// int call_of_me(int row) {
//   int col = 0;
//   if (row == 0) {
//     col = 31;
//   } else if (row == 1) {
//     col = 63;
//   } else if (row == 2) {
//     col = 95;
//   } else if (row == 3) {
//     col = 127;
//   }
//   return col;
// }

// // нужен для s21_printf_decimal
// int call_of_me_stop_me(int row) {
//   int col = 0;
//   if (row == 0) {
//     col = 0;
//   } else if (row == 1) {
//     col = 32;
//   } else if (row == 2) {
//     col = 64;
//   } else if (row == 3) {
//     col = 96;
//   }
//   return col;
// }
// // выводит вид decimal
// void s21_printf_decimal(s21_decimal value) {
//   int row = 0;
//   int col = 31;
//   int MANTISA[96] = {0};
//   for (; row <= 3; row++) {
//     for (col = call_of_me(row); col >= call_of_me_stop_me(row); col--) {
//       printf("%2d ", col);
//       if (col == call_of_me_stop_me(row)) {
//         printf("\n");
//       }
//     }
//     for (col = call_of_me(row); col >= call_of_me_stop_me(row); col--) {
//       if (col >= 100) {
//         if (col == 127) {
//           printf("(");
//           printf("%d", getBit(value, col));
//           printf(")");
//         } else if (col == 119) {
//           printf(" (");
//           printf("%d", getBit(value, col));
//         } else if (col < 119 && col > 112) {
//           printf(" %3d", getBit(value, col));
//         } else if (col == 112) {
//           printf(" %3d", getBit(value, col));
//           printf(")");
//         } else {
//           printf("%3d ", getBit(value, col));
//         }
//       } else {
//         printf("%2d ", getBit(value, col));
//       }
//       if (col == call_of_me_stop_me(row)) {
//         printf("\n");
//       }
//     }
//     printf("\n");
//   }
//   printf("MANTISA: ");
//   for (int bit = 95; bit >= 0; bit--) {
//     MANTISA[bit] = getBit(value, bit);
//     printf("%d", MANTISA[bit]);
//   }
//   s21_from_decimal_to_int_mantisa(value);
//   char* mantis = calloc(100, sizeof(char));
//   // s21_from_decimal_to_int(value,mantis);
//   printf("\nDESET MANTISA: %s", mantis);
//   printf("\nHEX:\t");
//   char* exp = (char*)calloc(10, sizeof(char));
//   for (int bit = 119, j = 0; bit >= 112; bit--, j++) {
//     // printf("%d", getbit(value, bit));
//     exp[j] = getBit(value, bit) + 48;
//   }
//   int int_exp = hex_to_int(exp, 8);
//   printf("%s\tEXP:%d\t", exp, int_exp);
//   printf("\nSIGN:\t%d\t%c\n", getBit(value, 127),
//          getBit(value, 127) > 0 ? '-' : '+');
// }

// int main() {
//   // s21_decimal var1 = {{-1, -1, -1, 0}};
//   // s21_decimal var2 = {{1879048192, -1291644761, -500259693, 0}};
//   // s21_decimal ten = {{10, 0, 0, 0}};
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_decimal var1 = {{-1, -1, -1, 0}};
//   s21_decimal var2 = {{22, 0, 0, 65536}};
//   s21_printf_decimal(var1);
//   s21_printf_decimal(var2);
//   printf("\n%d\n", s21_div(var1, var2, &result));

//   // s21_bit_mod(var1, var2, &result);
//   //  multiplication(result, ten, &result);
//   s21_printf_decimal(result);
//   // printf("\nexpected\n");
//   // s21_decimal exp = {{1019311944, 458670364, 542101085, 2148990976}};
//   // s21_decimal exp = {{1227133513, -1840700270, 613566756, 1835008}};
//   // s21_decimal exp = {{48806447, -1898527489, -1830871450,1835008}};
//   s21_decimal exp = {{1171354717, -780903145, 1952257861, 0}};
//   s21_printf_decimal(exp);
//   return 0;
// }
