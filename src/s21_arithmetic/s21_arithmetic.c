#include "s21_arithmetic.h"

// start arithmetic helpers
//
s21_decimal bank_round(s21_decimal bit) {
  s21_decimal ceil = {0};
  s21_decimal mod = {0};
  s21_decimal ten = {0};
  s21_decimal five = {0};
  s21_decimal res = {0};
  ten.bits[0] = 10;
  five.bits[0] = 5;
  s21_bit_division(bit, ten, &ceil);
  res = ceil;
  s21_bit_mod(bit, ten, &mod);
  if (is_uneven(ceil) && is_greater_or_equal_M(mod, five)) {
    s21_decimal one = {0};
    one.bits[0] = 1;
    int a = 0;
    addition(ceil, one, &res, &a);
  }
  return res;
}

int is_uneven(s21_decimal bit) { return (getBit(bit, 0)) ? 1 : 0; }

s21_decimal leftshift(s21_decimal bit) {
  s21_decimal res = {0};
  res = bit;
  for (int i = 95; find_one(bit, &i); --i) {
    setBit(&res, i, 0);
    setBit(&res, i + 1, 1);
  }
  return res;
}
int find_one(s21_decimal bit, int *pos) {
  int flag = 0;
  for (int i = *pos; i >= 0; --i) {
    if (getBit(bit, i) == 1) {
      *pos = i;
      flag = 1;
      break;
    }
  }
  return (flag);
}

// res == 1 decimal == null
// res == 0 decimal != null
int check_zero(s21_decimal decimal) {  // проверка на нулевой decimal
  int res = 0;
  res = 1;
  for (int i = 0; i < 96; ++i) {
    if (getBit(decimal, i) == 1) {
      res = 0;
      break;
    }
  }
  return res;
}
void degree_of_two(s21_decimal *num, int degree) {
  if (degree) {
    num->bits[0] = 1;
    for (int i = 0; i < degree; ++i) {
      *num = leftshift(*num);
    }
  } else {
    s21_decimal one = {0};
    one.bits[0] = 1;
    int a=0;
    addition(*num, one, num, &a);
  }
}

int checkIfOneIsInfSum(const s21_decimal second, int first_sign,
                       s21_error_type *error) {
  int flag = 1, second_sing = getSign(second);
  if (isInf(&second)) {
    if (first_sign == second_sing) {
      if (first_sign == 1) {
        flag = 0;
        error->plus_inf = 1;
      } else {
        flag = 0;
        error->minus_inf = 1;
      }
    } else {
      flag = 0;
      error->nan = 1;
    }
  } else {
    if (first_sign == 1) {
      flag = 0;
      error->plus_inf = 1;
    } else {
      flag = 0;
      error->minus_inf = 1;
    }
  }
  return flag;
}

// функция которая проверяет децималы которые мы хотим сложить
int checkErrorAdd(const s21_decimal value_1, const s21_decimal value_2,
                  s21_error_type *error) {
  int flag = 1;
  if (isNan(&value_1) || isNan(&value_2)) {
    flag = 0;
    error->nan = 1;
  } else if (isInf(&value_1)) {
    flag = checkIfOneIsInfSum(value_2, getSign(value_1), error);
  } else if (isInf(&value_2)) {
    flag = checkIfOneIsInfSum(value_1, getSign(value_2), error);
  }
  return flag;
}

int checkErrorMul(const s21_decimal value_1, const s21_decimal value_2,
                  s21_error_type *error) {
  int flag = 1;
  if (isNan(&value_1) || isNan(&value_2)) {
    flag = 0;
    error->nan = 1;
  } else if (isInf(&value_1) || isInf(&value_2)) {
    if (getSign(value_1) * getSign(value_2) == 1) {
      flag = 0;
      error->plus_inf = 1;
    } else {
      flag = 0;
      error->minus_inf = 1;
    }
  }
  return flag;
}

int checkErrorDiv(const s21_decimal value_1, const s21_decimal value_2,
                  s21_error_type *error) {
  int flag = 1;
  if (isNan(&value_1) || isNan(&value_2)) {
    flag = 0;
    error->nan = 1;
  } else if (isInf(&value_1)) {
    if (isInf(&value_2)) {
      flag = 0;
      error->nan = 1;
    } else {
      if (getSign(value_1) * getSign(value_2) == 1) {
        flag = 0;
        error->plus_inf = 1;
      } else {
        flag = 0;
        error->minus_inf = 1;
      }
    }
  } else if (isInf(&value_2)) {  //  0 или -0
    //  возможно Дане нужно проверять, что первое число не инф
    if (getSign(value_1) * getSign(value_2) == 1) {
      flag = 0;
      error->plus_inf = 1;
    } else {
      flag = 0;
      error->minus_inf = 1;
    }
  }
  return flag;
}

int makeInf(s21_decimal *el) {
  int res = 1;
  if (el != NULL) {
    memset(el, 0, sizeof(s21_decimal));
    setSign(el, 1);
    setPower(el, 255);
    el->bits[2] = 0;
    el->bits[1] = 0;
    el->bits[0] = 0;
  } else {
    res = 0;
  }
  return res;
}

int makeNegInf(s21_decimal *el) {
  int res = 1;
  if (el != NULL) {
    memset(el, 0, sizeof(s21_decimal));
    setSign(el, -1);
    setPower(el, 255);
    el->bits[2] = 0;
    el->bits[1] = 0;
    el->bits[0] = 0;
  } else {
    res = 0;
  }
  return res;
}

int makeNan(s21_decimal *el) {
  int res = 1;
  if (el != NULL) {
    memset(el, 0, sizeof(s21_decimal));
    setPower(el, 255);
    el->bits[2] = 2147483648;
    el->bits[1] = 0;
    el->bits[0] = 0;
  } else {
    res = 0;
  }
  return res;
}
void makeResult(s21_error_type error, s21_decimal *result) {
  if (error.plus_inf) {
    makeInf(result);
  } else if (error.minus_inf) {
    makeNegInf(result);
  } else if (error.nan) {
    makeNan(result);
  }
}
////
// end arithmetic helpers