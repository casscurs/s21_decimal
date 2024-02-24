#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_NULL ((void *)0)

#define s21_MAX_UINT 4294967295

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef struct {
  uint32_t bits[8];
} s21_big_decimal;

typedef struct {
  int plus_inf;
  int minus_inf;
  int nan;
} s21_error_type;

#endif  //  SRC_S21_DECIMAL_H_