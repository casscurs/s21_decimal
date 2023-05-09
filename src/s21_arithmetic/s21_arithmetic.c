#include "s21_arithmetic.h"

enum s21_result { FALSE, TRUE };

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
    int a = 0;
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

// big decimal

s21_big_decimal decimalToBigDecimal(s21_decimal value) {
  s21_big_decimal result = {0};
  result.bits[0] = value.bits[0];
  result.bits[1] = value.bits[1];
  result.bits[2] = value.bits[2];
  result.bits[7] = value.bits[3];
  return result;
}

int mulbigDecimalToDecimal(s21_big_decimal src, s21_decimal *dst) {
  int rem = 0;
  while (((src.bits[5] > 0 || src.bits[4] > 0 || src.bits[3] > 0) &&
          s21_get_big_fraction(src) > 0) ||
         s21_get_big_fraction(src) > 28) {
    rem = s21_div_ten_nr_big(&src, 1);
  }
  if (rem >= 5) {
    s21_big_decimal one = {{1, 0, 0, 0, 0}};
    addBigDecimal(src, one, &src);
  }
  s21_big_decimal copy = src;
  while (s21_get_big_fraction(src) > 0 && !s21_div_ten_nr_big(&copy, 1)) {
    src = copy;
  }
  dst->bits[0] = src.bits[0];
  dst->bits[1] = src.bits[1];
  dst->bits[2] = src.bits[2];
  dst->bits[3] = src.bits[7];
  return src.bits[5] > 0 || src.bits[4] > 0 || src.bits[3] > 0 ||
         s21_is_big_empty(src);
}

/// @brief Получение знака числа
/// @param nгmber децимал
/// @return 0 - положительное, 1 - отрицательное
unsigned int s21_get_big_sign(s21_big_decimal number) {
  unsigned int options = number.bits[6];
  options >>= 31;
  return options;
}

/// @brief Проверка на равенство нулю
/// @param number децимал
/// @return 0 - не равен нулю, 1 - равен нулю
int s21_is_big_empty(s21_big_decimal number) {
  int result = 1;
  for (int i = 0; result && i < 6; i++) {
    if (number.bits[i] != 0) {
      result = 0;
    }
  }
  return result;
}

/// @brief Получение степени коэффициента масштабирования
/// @param number децимал
/// @return степень коэффициента масштабирования
unsigned int s21_get_big_fraction(s21_big_decimal number) {
  unsigned int options = number.bits[7];
  options <<= 1;
  options >>= 17;
  return options;
}

/// @brief Установка степени коэффициента масштабирования
/// @param number децимал
/// @return степень коэффициента масштабирования
void s21_set_big_fraction(s21_big_decimal *number, unsigned int fraction) {
  fraction <<= 16;
  unsigned int old_fraction = s21_get_big_fraction(*number);
  old_fraction <<= 16;
  unsigned int sign = number->bits[7] - old_fraction;
  number->bits[7] = fraction + sign;
}

/// @brief Смещает биты числа вправо(УМЕНЬШЕНИЕ ЧИСЛА)
/// @param number децимал
/// @param offset смещение
void bigDecRightShift(s21_big_decimal *number, int offset) {
  for (int i = 0; i <= 6; i++) {
    int stop = 1;
    for (int bit = 0; stop && bit < 32; bit++) {
      if (i == 0 || (offset - bit) <= 0) {
        number->bits[i] >>= offset;
        stop = 0;
      } else {
        number->bits[i - 1] ^=
            (-((number->bits[i] >> bit) & 1) ^ number->bits[i - 1]) &
            (1 << (32 - offset + bit));
      }
    }
  }
}

/// @brief Смещает биты числа влево(УВЕЛИЧЕНИЕ ЧИСЛА)
/// @param number децимал
/// @param offset смещение
void bigDecLeftShift(s21_big_decimal *number, int offset) {
  for (int i = 6; i >= 0; i--) {
    int stop = 1;
    for (int bit = 31; stop && bit >= 0; bit--) {
      if (i == 6 || (bit + offset) <= 31) {
        number->bits[i] <<= offset;
        stop = 0;
      } else {
        number->bits[i + 1] ^=
            (-((number->bits[i] >> bit) & 1) ^ number->bits[i + 1]) &
            (1 << (bit + offset - 32));
      }
    }
  }
}

/// @brief Сложение двух
/// @param v1 первый
/// @param v2 второй
/// @param r результат сложения
/// @return есть ли переполнение
int addBigDecimal(s21_big_decimal v1, s21_big_decimal v2, s21_big_decimal *r) {
  int in_mind = 0;
  memset(r, 0, sizeof(s21_big_decimal));

  for (int i = 0; i <= 6; i++) {
    for (int bit = 0; bit < 32; bit++) {
      // Если оба бита равны 0 или 1, то оставим 0
      if (((v1.bits[i] >> bit) & 1) == ((v2.bits[i] >> bit) & 1)) {
        // Если прошлое сложение битов было с избытком, ставим 1
        if (in_mind) {
          r->bits[i] |= 1 << bit;
          // Убираем избыток
          in_mind = 0;
        }
        // Если оба бита равны единице, ставим избыток
        if (((v1.bits[i] >> bit) & 1) == 1) {
          in_mind = 1;
        }
      } else {
        // Если оба бита разные, ставим 1
        r->bits[i] |= 1 << bit;
        // Если прошлое сложение битов было с избытком, ставим 0
        if (in_mind) {
          r->bits[i] &= ~(1 << bit);
          // Избыток оставляем
        }
      }
    }
  }
  return in_mind;
}

int MulBigDecimal(s21_big_decimal v1, s21_big_decimal v2, s21_big_decimal *r) {
  int error = 0;

  memset(r, 0, sizeof(s21_big_decimal));

  int num_is_inf = 0;
  int both_sign = s21_get_big_sign(v1) == s21_get_big_sign(v2) ? 1 : 0;

  for (int i = 0; !error && i <= 6; i++) {
    for (int bit = 0; !error && bit < 32; bit++) {
      if (((v1.bits[i] >> bit) & 1) == 1) {
        error = addBigDecimal(*r, v2, r);
        if (!both_sign && num_is_inf) {
          error = 2;
        } else if (num_is_inf) {
          error = 1;
        }
      }
      if (((v2.bits[6] >> 31) & 1) == 1) {
        num_is_inf = 1;
      }
      bigDecLeftShift(&v2, 1);
    }
  }
  return error;
}

/// @brief Уменьшает точность на times-раз и НЕ проводит округление
/// @param value децимал
/// @param times-раз делить
/// @return остаток
int s21_div_ten_nr_big(s21_big_decimal *value, int times) {
  // Например превратить число 123,129 -> 123,13 (times = 1)

  s21_big_decimal ten = {{10, 0, 0, 0, 0}};
  unsigned int fraction = s21_get_big_fraction(*value);
  unsigned int value_options = value->bits[7];
  value->bits[7] = 0;
  s21_big_decimal reminder = {0};

  reminder.bits[7] = 0;

  while (times-- > 0) {
    fraction--;
    reminder = s21_div_big_bits(*value, ten, value);
  }
  value->bits[7] = value_options;
  s21_set_big_fraction(value, fraction);
  return reminder.bits[0];
}

/// @brief Деление двух децималов
/// @param v1 первый
/// @param v2 второй
/// @param r результат умножения
/// @return децимал - остаток от деления
s21_big_decimal s21_div_big_bits(s21_big_decimal v1, s21_big_decimal v2,
                                 s21_big_decimal *r) {
  memset(r, 0, sizeof(s21_big_decimal));

  int max = 0;
  for (; max < 32 * 7; max++) {
    if ((v2.bits[6] >> 31) & 1) {
      break;
    }
    bigDecLeftShift(&v2, 1);
  }
  for (int i = 0; i < max; i++) {
    if (s21_is_big_greater_or_equal(v1, v2)) {
      s21_sub_big_bits(v1, v2, &v1);
      r->bits[0] |= 1 << 0;
    }
    bigDecRightShift(&v2, 1);
    bigDecLeftShift(r, 1);
  }
  if (s21_is_big_greater_or_equal(v1, v2)) {
    s21_sub_big_bits(v1, v2, &v1);
    r->bits[0] |= 1 << 0;
  }
  s21_set_big_fraction(r, s21_get_big_fraction(v1));
  return v1;
}

/// @brief Вычитание двух децималов
/// @param v1 первый
/// @param v2 второй
/// @param r результат вычитания
void s21_sub_big_bits(s21_big_decimal v1, s21_big_decimal v2,
                      s21_big_decimal *r) {
  int borrow = 0;
  memset(r, 0, sizeof(s21_big_decimal));

  for (int i = 0; i <= 6; i++) {
    for (int bit = 0; bit < 32; bit++) {
      // Если оба бита равны 0 или 1, то оставим 0
      if (((v1.bits[i] >> bit) & 1) == ((v2.bits[i] >> bit) & 1)) {
        // Если прошлое вычитание битов было с займом, ставим 1
        if (borrow) {
          r->bits[i] |= 1 << bit;
        }
      } else {
        // Если оба бита разные, ставим 1
        r->bits[i] |= 1 << bit;
        // Если прошлое вычитание битов было с займом, ставим 0
        if (borrow) {
          r->bits[i] &= ~(1 << bit);
          // Если бит v1 == 1, займ убрать
          if ((v1.bits[i] >> bit) & 1) {
            borrow = 0;
          }
        }
        // Если бит v1 == 0, займ взять
        if (!((v1.bits[i] >> bit) & 1)) {
          borrow = 1;
        }
      }
    }
  }
}

/// @brief Равно	==
/// @param value_1 первое значение
/// @param value_2 второе значение
/// @return 0 - FALSE, 1 - TRUE
int s21_is_big_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  enum s21_result result = TRUE;
  // Если в результате потерялась точность - не равны
  if (s21_get_big_fraction(value_1) != s21_get_big_fraction(value_2)) {
    result = FALSE;
  }
  // Если знаки разные - не равны
  if (s21_get_big_sign(value_1) != s21_get_big_sign(value_1) &&
      !s21_is_big_empty(value_1) && !s21_is_big_empty(value_2)) {
    result = FALSE;
  }
  // если хотя бы одна из 4 частей отличается - не равны
  for (int i = 0; result && i <= 6; i++) {
    if (value_1.bits[i] != value_2.bits[i]) {
      result = FALSE;
    }
  }
  return result;
}

// @brief Больше	>
/// @param value_1 первое значение
/// @param value_2 второе значение
/// @return 0 - FALSE, 1 - TRUE
int s21_is_big_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
  enum s21_result result = TRUE;
  int negative_1 = s21_get_big_sign(value_1);
  int negative_2 = s21_get_big_sign(value_2);
  int stop = 1;
  if (s21_is_big_equal(value_1, value_2)) {
    // Если числа равны - ложь
    result = FALSE;
  } else if (negative_1 && !negative_2) {
    // Если первое отрицательное, второе положительно - ложь
    result = FALSE;
  } else if (negative_1 == negative_2) {
    // Если знаки равны, сравниваем остальное
    // if (!s21_set_max_big_fraction(&value_1, &value_2)) {
    for (int i = 6; stop && i >= 0; i--) {
      for (int bit = 31; stop && bit >= 0; bit--) {
        if (((value_1.bits[i] >> bit) & 1) == 1 &&
            ((value_2.bits[i] >> bit) & 1) == 0) {
          stop = !stop;
        } else if (((value_2.bits[i] >> bit) & 1) == 1 &&
                   ((value_1.bits[i] >> bit) & 1) == 0) {
          result = FALSE;
          stop = !stop;
        }
      }
    }

    if (negative_1) {
      result = !result;
    }
  }
  return result;
}

/// @brief Больше или равно	>=
/// @param value_1 первое значение
/// @param value_2 второе значение
/// @return 0 - FALSE, 1 - TRUE
int s21_is_big_greater_or_equal(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  enum s21_result is_error = TRUE;
  if (!s21_is_big_equal(value_1, value_2)) {
    is_error = s21_is_big_greater(value_1, value_2);
  }
  return is_error;
}
