#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;

  if (!dst) {
    error = 1;
  } else {
    s21_zero_decimal(dst);

    if (src < 0) {
      s21_set_sign(dst);
      src *= -1;
    }

    if (src > INT_MAX) {
      error = 1;
    } else {
      dst->bits[0] = src;
    }
  }

  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;

  if (!dst) {
    error = 1;
  } else {
    int scale = s21_get_scale(src);

    if (src.bits[1] || src.bits[2]) {
      error = 1;
    } else {
      *dst = src.bits[0];
      *dst = *dst / pow(10, scale);
    }

    if (s21_get_sign(src)) *dst *= -1;

    if (!s21_get_sign(src) && s21_f_get_bit(*dst, 31)) {
      error = 1;
    }
  }

  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  /*
   1   1000 0001     011 0000 0000 0000 0000 0000
   31  30  -  23     22                         0
   s   exponent               mantissa

   the   actual mantissa = 1.011 0000 0000 0000 0000 0000 could be calculate:

   1 + 0*2^(-1) + 1*2^(-2) + 1*2^(-3) + 0*2^(-4) ........ + 0*2(-23)
   1 + 0.25 + 0.125 = 1.375

   it's a negative number so -1.375

   E = 1000 0001 = 129

   -1.375*2^(E-127) = -1.375*2^(2) = -5.5

  */

  int error = 0;

  if (!dst) {
    error = 1;
  } else {
    s21_zero_decimal(dst);

    if (isinf(src) || isnan(src)) {
      error = 1;
    } else {
      if (src != 0) {
        int tmp = 0;
        memcpy(
            &tmp, &src,
            sizeof(float));  // copies binary represenatation of a float nummber

        int sign = *(int *)&src >> 31;  // integer operation only

        int mask = 255 << 23;                  // 1111 1111 << 23
        int exp = ((mask & tmp) >> 23) - 127;  // 2^(E - 127)

        double num = (double)fabs(src);

        int off = 0;

        for (; off <= 28 && (int)num / (int)pow(2, 23) == 0;
             num *= 10,
             off++) {  // making num *= 10 until it less 2^(23) = 8 388 608
        }

        num = round(num);

        if (off <= 28 && (exp > -94 && exp < 96)) {
          floatbits mant = {0};
          num = (float)num;

          for (; fmod(num, 10) == 0 && off > 0; off--, num /= 10) {
          }

          /* union elements share memory space and now we have a binary
             representation of num e.g if   mant.fl = 314 then mant.ui =
             1134362624
          */

          mant.fl = num;
          exp = ((*(int *)&mant.fl & ~0x80000000) >> 23) - 127;

          dst->bits[exp / 32] |= 1 << exp % 32;

          for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
            if ((mant.ui & (1 << j)) != 0) dst->bits[i / 32] |= 1 << i % 32;
          }

          dst->bits[3] = (sign << 31) | (off << 16);
        }
      }
    }
  }

  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  if (!dst) {
    error = 1;

  } else {
    *dst = 0.0;
    double tmp = 0.0;
    int sign = s21_get_sign(src);
    int scale = s21_get_scale(src);

    for (int i = 0; i < 96; i++) {
      if (s21_get_bit(src, i)) {
        tmp += pow(2.0, i);
      }
    }

    double power = pow(10, scale);
    tmp /= power;

    if (sign) {
      tmp *= -1.0;
    }

    *dst = (float)tmp;
  }

  return error;
}
