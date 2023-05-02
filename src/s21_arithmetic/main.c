#include "../tests/s21_tests.h"

int main(){
  s21_decimal var1 = {{100, 0, 0, 0}};
  Bin_Print(var1);
  Dec_Print(var1);
  s21_decimal var2 = {{4, 0, 0, 0}};
   Bin_Print(var2);
   Dec_Print(var2);
  s21_decimal result = {{0, 0, 0, 0}};

  //Light_sub(var1,var2,&result);
  s21_bit_division(var1,var2,&result);

   Bin_Print(result);
   Dec_Print(result);
  return 0;
}