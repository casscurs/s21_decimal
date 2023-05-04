#include "s21_convertors.h"

#define MAX_FLOAT pow(2, 96)
#define MAX_FLOAT_IN_DECIMAL 99999999
#define MIN_FLOAT 1E-28

void protectedFtD(float src, s21_decimal *dst);
void getMantissa(double *temp, int *power);
void truncMantissa(double *temp, int *power);
void binaryToDecimal(double temp, int power, s21_decimal *dec);
void getBinaryString(long double res, char *bit_str);
void binaryStringToDecimal(char *bit_str, s21_decimal *result);

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int is_error = 0;

  if (!dst) {
    is_error = 1;
  } else {
    memset(dst, 0, sizeof(s21_decimal));
    if ((isnan(src) != 0) || (fabs(src) == INFINITY)) {
      is_error = 1;
    } else if ((fabs(src) > 0 && fabs(src) < 1e-28) ||
               fabs(src) >= pow(2, 96)) {
      is_error = 1;
    } else {
      protectedFtD(src, dst);
    }
  }
  return is_error;
}

void protectedFtD(float src, s21_decimal *dst) {
  int sign = *(int *)&src >> 31;
  if (sign) {
    dst->bits[3] |= 1u << 31;
    *(int *)&src ^= 1u << 31;
  }

  double temp = (double)src;
  int power = 0;

  getMantissa(&temp, &power);

  temp = round(temp);

  truncMantissa(&temp, &power);

  binaryToDecimal(temp, power, dst);
}

void getMantissa(double *temp, int *power) {
  int mantissa_mask = 1111111;

  while (*power < 28) {
    if ((int)*temp / mantissa_mask) {
      break;
    }
    *temp *= 10;
    (*power)++;
  }
}

void truncMantissa(double *temp, int *power) {
  while (*power > 0) {
    if (fmod(*temp, 10)) {
      break;
    }
    (*power)--;
    *temp /= 10;
  }
}

void binaryToDecimal(double temp, int power, s21_decimal *dec) {
  char *bit_str = s21_NULL;
  bit_str = calloc(128, sizeof(char));
  if (bit_str != s21_NULL) {
    getBinaryString(temp, bit_str);
    binaryStringToDecimal(bit_str, dec);
    setPower(dec, power);
    free(bit_str);
  }
}

void getBinaryString(long double res, char *bit_str) {
  long double ostatok = 0;
  int k = 0;
  while (res > 1e-6) {
    res = floorl(res);
    ostatok = fmodl(res, 2);
    res /= 2;
    bit_str[k++] = (ostatok >= 1u) ? '1' : '0';
  }
  bit_str[k] = res == 1 ? '1' : '0';
}

void binaryStringToDecimal(char *bit_str, s21_decimal *result) {
  for (int i = 0; bit_str[i] != '\0'; i++) {
    if (bit_str[i] == '1') {
      setBit(result, i, 1);
    } else if (bit_str[i] == '0') {
      setBit(result, i, 0);
    }
  }
}