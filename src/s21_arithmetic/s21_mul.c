#include "../helpers/s21_helpfunc.h"
#include "../s21_decimal.h"
#include "s21_arithmetic.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) {
    exit(1);
  }
  memset(result, 0, sizeof(s21_decimal));
  s21_error_type error = {0};
  if (checkErrorMul(value_1, value_2, &error)) {
    int power_result = makePower(value_1, value_2);
    if (checkForOverflow(value_1, value_2)) {
      int overflow_status = multiplicationBigDecimal(
          decimalToBigDecimal(value_1), decimalToBigDecimal(value_2), result,
          power_result);
      if (overflow_status) {
        if (getSign(value_1) == 1) {
          makeInf(result);
          error.plus_inf++;
        } else {
          makeNegInf(result);
          error.minus_inf++;
        }
      }
    } else {
      multiplication(value_1, value_2, result);
    }
    setPower(result, power_result > 28 ? 28
                     : (!getPower(value_1) || (!getPower(value_2)))
                         ? (getPower(value_1) + getPower(value_2))
                         : power_result);
    if ((getSign(value_1) * getSign(value_2)) == 1) {
      setBit(result, 127, 0);
    } else {
      setBit(result, 127, 1);
    }
  }
  return error.plus_inf ? 1 : error.minus_inf ? 2 : error.nan ? 3 : 0;
}

int makePower(s21_decimal value_1, s21_decimal value_2) {
  int power_1 = getPower(value_1);
  int power_2 = getPower(value_2);
  if (power_1 == 0) {
    power_1++;
  }
  if (power_2 == 0) {
    power_2++;
  }
  int result = power_1 * power_2;
  if (result == 1) {
    result--;
  } else {
    result = power_1 + power_2;
  }
  return result;
}

int checkForOverflow(s21_decimal value_1, s21_decimal value_2) {
  int overflow_status = 0;
  int position_of_value_1 = 96;
  int position_of_value_2 = 96;
  find_one(value_1, &position_of_value_1);
  find_one(value_2, &position_of_value_2);
  if (position_of_value_1 == 96) position_of_value_1 = 0;
  if (position_of_value_2 == 96) position_of_value_2 = 0;
  if ((position_of_value_1 + position_of_value_2) >= 96) {
    overflow_status++;
  }
  return overflow_status;
}

void multiplication(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  memset(result, 0, sizeof(s21_decimal));
  s21_decimal value_2_copied = value_2;
  s21_decimal sum = {0};
  for (int index = 0; index < 96; index++) {
    value_2_copied = value_2;
    if (getBit(value_1, index) == 1) {
      for (int i = 0; i < index; i++) {
        value_2_copied = leftshift(value_2_copied);
        setBit(&value_2_copied, 96, 0);
      }
      memset(result, 0, sizeof(s21_decimal));
      int a=0;
      addition(sum, value_2_copied, result, &a);
      sum = *result;
    }
  }
}

int multiplicationBigDecimal(s21_big_decimal big_value_1,
                             s21_big_decimal big_value_2, s21_decimal *result,
                             int power_result) {
  s21_big_decimal big_result = {0};
  s21_big_decimal value_2_copied = big_value_2;
  s21_big_decimal sum = {0};
  for (int index = 0; index < 224; index++) {
    value_2_copied = big_value_2;
    if (getBitBigDecimal(big_value_1, index) == 1) {
      for (int i = 0; i < index; i++) {
        value_2_copied = leftshiftBigDecimal(value_2_copied);
      }
      nullBigDecimal(&big_result);
      additionBigDecimal(sum, value_2_copied, &big_result);
      sum = big_result;
    }
  }
  // if (power_result > 28) {
  //   while (power_result - 28) {
  //     big_result = bank_roundBigDeicmal(big_result);
  //     power_result--;
  //   }
  // }
  return bigDecimalToDecimal(big_result, result, power_result);
}

s21_big_decimal decimalToBigDecimal(s21_decimal value) {
  s21_big_decimal result = {0};
  result.bits[0] = value.bits[0];
  result.bits[1] = value.bits[1];
  result.bits[2] = value.bits[2];
  return result;
}

int checkForOverflowBigDecimal(s21_big_decimal value, int power_result) {
  // while (power_result != 0) {
  // value = bank_roundBigDeicmal(value);
  power_result--;
  // }
  int overflow_status = 0;
  int position = 223;
  find_oneBigDecimal(value, &position);
  if (position == 223) position = 0;
  if (position >= 96) {
    overflow_status++;
  }
  return overflow_status;
}

int bigDecimalToDecimal(s21_big_decimal value, s21_decimal *result,
                        int power_result) {
  int overflow_status = 0;
  if (checkForOverflowBigDecimal(value, power_result)) {
    overflow_status++;
  }
  int position = 223;
  find_oneBigDecimal(value, &position);
  int index_big_decimal = position;
  int index = 95;
  for (; ((index_big_decimal >= position - 95) && (index_big_decimal >= 0));
       index_big_decimal--, index--) {
    if (getBitBigDecimal(value, index_big_decimal) == 1) {
      setBit(result, index, 1);
    } else {
      setBit(result, index, 0);
    }
  }
  return overflow_status;
}

void nullBigDecimal(s21_big_decimal *value) {
  for (int i = 0; i < 7; i++) {
    value->bits[i] = 0;
  }
}

int getBitBigDecimal(s21_big_decimal decimal, int index) {
  return (index >= 0 && index < 224)
             ? !!(decimal.bits[index / 32] & (1u << (index % 32)))
             : -1;
}

int setBitBigDecimal(s21_big_decimal *decimal, int index, int value) {
  if (index >= 0 && index < 224) {
    if (value) {
      decimal->bits[index / 32] |= (1u << (index % 32));
    } else {
      decimal->bits[index / 32] &= ~(1u << (index % 32));
    }
  }
  return (index >= 0 && index < 224) ? 1 : -1;
}

s21_big_decimal leftshiftBigDecimal(s21_big_decimal bit) {
  for (int i = 223; find_oneBigDecimal(bit, &i); i--) {
    setBitBigDecimal(&bit, i, 0);
    setBitBigDecimal(&bit, i + 1, 1);
  }
  return bit;
}

int find_oneBigDecimal(s21_big_decimal bit, int *pos) {
  int flag = 0;
  for (int i = *pos; i >= 0; i--) {
    if (getBitBigDecimal(bit, i) == 1) {
      *pos = i;
      flag = 1;
      break;
    }
  }
  return (flag);
}

void additionBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  for (int index = 0; index < 224; index++) {
    switch (getBitBigDecimal(value_1, index) +
            getBitBigDecimal(value_2, index) +
            getBitBigDecimal(*result, index)) {
      case 0:
        setBitBigDecimal(result, index, 0);
        break;
      case 1:
        setBitBigDecimal(result, index, 1);
        break;
      case 2:
        setBitBigDecimal(result, index, 0);
        setBitBigDecimal(result, index + 1, 1);
        break;
      case 3:
        setBitBigDecimal(result, index, 1);
        setBitBigDecimal(result, index + 1, 1);
        break;
    }
  }
}

// // ОТКРЫВАЙТЕ ФОРТОЧКУ

// s21_big_decimal bank_roundBigDeicmal(s21_big_decimal bit) {
//   s21_big_decimal ceil = {0};
//   s21_big_decimal mod = {0};
//   s21_big_decimal ten = {0};
//   s21_big_decimal five = {0};
//   s21_big_decimal res = {0};
//   ten.bits[0] = 10;
//   five.bits[0] = 5;
//   s21_bit_divisionBigDeicmal(bit, ten, &ceil);
//   res = ceil;
//   s21_bit_modBigDeicmal(bit, ten, &mod);
//   if (is_unevenBigDeicmal(ceil) && is_greater_or_equal_MBigDecimal(mod,
//   five)) {
//     s21_big_decimal one = {0};
//     one.bits[0] = 1;
//     additionBigDecimal(ceil, one, &res);
//   }
//   return res;
// }

// void s21_bit_modBigDeicmal(s21_big_decimal delim, s21_big_decimal delit,
//                            s21_big_decimal *ostatok) {
//   memset(ostatok, 0, sizeof(s21_big_decimal));
//   if (is_greater_MBigDecimal(delit, delim)) {
//     *ostatok = delim;
//   } else {
//     s21_big_decimal buf = {0};
//     s21_bit_divisionBigDeicmal(delim, delit, &buf);
//     s21_big_decimal big_result = {0};
//     s21_big_decimal value_2_copied = buf;
//     s21_big_decimal sum = {0};
//     for (int index = 0; index < 224; index++) {
//       value_2_copied = delit;
//       if (getBitBigDecimal(delit, index) == 1) {
//         for (int i = 0; i < index; i++) {
//           value_2_copied = leftshiftBigDecimal(value_2_copied);
//         }
//         nullBigDecimal(&big_result);
//         additionBigDecimal(sum, value_2_copied, &big_result);
//         sum = big_result;
//       }
//     }
//     buf = big_result;
//     Light_subBigDecimal(delim, buf, ostatok);
//   }
// }

// int is_unevenBigDeicmal(s21_big_decimal bit) {
//   return (getBitBigDecimal(bit, 0)) ? 1 : 0;
// }

// int s21_bit_divisionBigDeicmal(s21_big_decimal delim, s21_big_decimal delit,
//                                s21_big_decimal *chast) {
//   memset(chast, 0, sizeof(s21_big_decimal));
//   if (is_equal_MBigDecimal(delim, delit)) {  // если числа равны
//     chast->bits[0] = 1;
//   } else if (!check_zeroBigDecimal(delim) &&
//              is_greater_MBigDecimal(delim, delit)) {
//     s21_big_decimal delitBuf = {0};
//     delitBuf = delit;
//     div_first_decrementBigDeicmal(delim, delit, &delitBuf, chast);
//   }
//   return 0;
// }

// int check_zeroBigDecimal(
//     s21_big_decimal decimal) {  // проверка на нулевой decimal
//   int res = 0;
//   res = 1;
//   for (int i = 0; i < 224; ++i) {
//     if (getBitBigDecimal(decimal, i) == 1) {
//       res = 0;
//       break;
//     }
//   }
//   return res;
// }

// void div_first_decrementBigDeicmal(s21_big_decimal delim, s21_big_decimal
// delit,
//                                    s21_big_decimal *delitBuf,
//                                    s21_big_decimal *chast) {
//   int count1 = 0;
//   while (
//       is_greater_or_equal_MBigDecimal(delim, leftshiftBigDecimal(*delitBuf))
//       && !getBitBigDecimal(leftshiftBigDecimal(*delitBuf), 96)) {
//     *delitBuf = leftshiftBigDecimal(*delitBuf);
//     count1++;
//   }
//   if (count1) {
//     degree_of_twoBigDeicmal(chast, count1);  // запись ответа
//     s21_big_decimal razn = {0};
//     Light_subBigDecimal(delim, *delitBuf, &razn);  // BIG DECIMAL !_!_!_!
//     // BIG DECIMAL !_!_!_!
//     while (is_greater_or_equal_MBigDecimal(razn, delit)) {
//       div_second_decrementBigDeicmal(
//           delit, delitBuf, chast,
//           &razn);  // разность по указателю и декремент внутри функции
//     }
//   } else {
//     chast->bits[0] = 1;
//   }
// }

// void div_second_decrementBigDeicmal(s21_big_decimal delit,
//                                     s21_big_decimal *delitBuf,
//                                     s21_big_decimal *chast,
//                                     s21_big_decimal *razn) {
//   int count2 = 0;
//   *delitBuf = delit;
//   // BIG DECIMAL !_!_!_!
//   while (
//       is_greater_or_equal_MBigDecimal(*razn, leftshiftBigDecimal(*delitBuf)))
//       {
//     *delitBuf = leftshiftBigDecimal(*delitBuf);
//     count2++;
//   }
//   Light_subBigDecimal(*razn, *delitBuf, razn);  // BIG DECIMAL !_!_!_!
//   memset(delitBuf, 0, sizeof(s21_big_decimal));
//   degree_of_twoBigDeicmal(delitBuf, count2);
//   additionBigDecimal(*chast, *delitBuf, chast);
// }

// void degree_of_twoBigDeicmal(s21_big_decimal *num, int degree) {
//   if (degree) {
//     num->bits[0] = 1;
//     for (int i = 0; i < degree; ++i) {
//       *num = leftshiftBigDecimal(*num);
//     }
//   } else {
//     s21_big_decimal one = {0};
//     one.bits[0] = 1;
//     additionBigDecimal(*num, one, num);
//   }
// }

// void Light_subBigDecimal(s21_big_decimal value_1, s21_big_decimal value_2,
//                          s21_big_decimal *result) {
//   if (is_greater_MBigDecimal(value_1, value_2)) {
//     s21_bit_subBigDecimal(value_1, value_2, result);
//   }
//   if (is_greater_MBigDecimal(value_2, value_1)) {
//     s21_bit_subBigDecimal(value_2, value_1, result);
//   }
// }

// int is_greater_or_equal_MBigDecimal(s21_big_decimal el1, s21_big_decimal el2)
// {
//   int res = decCmp_MBigDecimal(el1, el2);
//   return (res >= 0) ? 1 : 0;
// }

// int is_greater_MBigDecimal(s21_big_decimal el1, s21_big_decimal el2) {
//   int res = decCmp_MBigDecimal(el1, el2);
//   return res > 0 ? 1 : 0;
// }

// int is_equal_MBigDecimal(s21_big_decimal el1, s21_big_decimal el2) {
//   int res = decCmp_MBigDecimal(el1, el2);
//   return res == 0 ? 1 : 0;
// }

// int decCmp_MBigDecimal(s21_big_decimal el1, s21_big_decimal el2) {
//   int res = 0;
//   for (int i = 223; i >= 0 && res == 0; --i) {
//     int cur_bit1 = getBitBigDecimal(el1, i),
//         cur_bit2 = getBitBigDecimal(el2, i);
//     if (cur_bit1 != cur_bit2) {
//       res = cur_bit1 - cur_bit2;
//     }
//   }
//   return res;
// }

// int s21_bit_subBigDecimal(s21_big_decimal bit1, s21_big_decimal bit2,
//                           s21_big_decimal *res) {
//   if (res == NULL) {
//     exit(1);
//   }
//   memset(res, 0, sizeof(s21_big_decimal));
//   int flag = 0;
//   int mindone = 0;
//   for (int j = 0; j < 96; ++j) {
//     if (getBitBigDecimal(bit1, j) && getBitBigDecimal(bit2, j)) {
//       and_patternBigDecimal(&mindone, res, j);
//     } else if (getBitBigDecimal(bit1, j) == 1 &&
//                getBitBigDecimal(bit2, j) == 0) {
//       one_zero_patternBigDecimal(&mindone, res, j);
//     } else if (getBitBigDecimal(bit1, j) == 0 &&
//                getBitBigDecimal(bit2, j) == 1) {
//       zero_one_patternBigDecimal(&mindone, res, j);
//     } else if (getBitBigDecimal(bit1, j) == 0 &&
//                getBitBigDecimal(bit2, j) == 0) {
//       and_patternBigDecimal(&mindone, res, j);
//     }
//   }
//   return (flag);
// }
// void one_zero_patternBigDecimal(int *mindone, s21_big_decimal *res, int j) {
//   if (*mindone) {
//     setBitBigDecimal(res, j, 0);
//     *mindone = 0;
//   } else {
//     setBitBigDecimal(res, j, 1);
//   }
// }
// void and_patternBigDecimal(int *mindone, s21_big_decimal *res, int j) {
//   if (*mindone) {
//     setBitBigDecimal(res, j, 1);
//   } else {
//     setBitBigDecimal(res, j, 0);
//   }
// }
// void zero_one_patternBigDecimal(int *mindone, s21_big_decimal *res, int j) {
//   if (*mindone) {
//     setBitBigDecimal(res, j, 0);
//   } else {
//     *mindone = 1;
//     setBitBigDecimal(res, j, 1);
//   }
// }
