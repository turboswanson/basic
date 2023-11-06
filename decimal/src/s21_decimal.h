#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POW28 0x1C0000
#define POW26 0x1A0000
#define POW29 0x1D0000
#define SIGNEDPOW28 0x801C0000
#define SIGN 0x80000000
#define MAX 0xFFFFFFFF
#define MAX_DEC powf(2.0f, 96.0f) - 1.0
#define MIN_DEC -powf(2.0f, 96.0f) + 1.0

typedef struct {
  unsigned int bits[4];  // 4x32=128
} s21_decimal;

typedef struct {
  unsigned int bits[8];  // 8*32=256
} s21_long_decimal;

typedef union {
  int ui;
  float fl;
} floatbits;

// BITWISE
int s21_f_get_bit(int num, int index);
void s21_f_set_bit(int *res, int index, int bit);
int s21_get_bit(s21_decimal src, int index);
int s21_get_sign(s21_decimal src);
void s21_set_bit(s21_decimal *dst, int index, int bit);
void s21_set_sign(s21_decimal *dst);
int s21_get_scale(s21_decimal src);
void s21_set_scale(s21_decimal *dst, int scale);
int s21_shift_decimal_left(s21_decimal *dst, int num);
int s21_shift_decimal_right(s21_decimal *dst, int num);

int s21_shift_long_left(s21_long_decimal *dst, int num);
int s21_shift_long_right(s21_long_decimal *dst, int num);

void s21_short_to_long_decimal(s21_decimal src, s21_long_decimal *dst);
void s21_long_to_short_decimal(s21_long_decimal src, s21_decimal *dst);
int s21_get_bit_long(s21_long_decimal src, int index);
void s21_set_bit_long(s21_long_decimal *dst, int index, int bit);

int s21_is_decimal(s21_decimal num);  // if there bits at all
int s21_is_long_decimal(s21_long_decimal dst);

// ARITHMETIC

int s21_add_int(int x, int y, int *carry);
int s21_mul_int(int x, int y);
int s21_add(s21_decimal x, s21_decimal y, s21_decimal *res);
void s21_add_long(s21_long_decimal value1, s21_long_decimal value2,
                  s21_long_decimal *total);
int s21_sub(s21_decimal x, s21_decimal y, s21_decimal *res);
void s21_sub_long(s21_long_decimal x, s21_long_decimal y,
                  s21_long_decimal *res);
int s21_mul(s21_decimal x, s21_decimal y, s21_decimal *res);
int s21_mul_long(s21_long_decimal value1, s21_long_decimal value2,
                 s21_long_decimal *res);
int s21_div(s21_decimal x, s21_decimal y, s21_decimal *res);
int s21_division_post_normalization(s21_long_decimal *res,
                                    s21_long_decimal *value2,
                                    s21_long_decimal *remainder);
int s21_div_long(s21_long_decimal value1, s21_long_decimal value2,
                 s21_long_decimal *total);
void s21_div_long_int(s21_long_decimal value1, s21_long_decimal value2,
                      s21_long_decimal *total);
int s21_equation_long(s21_long_decimal *value1, s21_long_decimal *value2);
s21_long_decimal division(s21_long_decimal value1, s21_long_decimal value2,
                          s21_long_decimal *remainder);

s21_decimal s21_abs(s21_decimal num);
void s21_zero_decimal(s21_decimal *dst);
void s21_zero_long(s21_long_decimal *res);
void s21_normalization(s21_long_decimal *value1, s21_long_decimal *value2,
                       int diff);
int s21_post_normalization(s21_long_decimal *res, int scale);
void s21_increase_scale_long_decimal(s21_long_decimal *dst, int n);

// COMPARISON

int s21_is_greater(s21_decimal x, s21_decimal y);
int s21_is_equal(s21_decimal x, s21_decimal y);
int s21_is_not_equal(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal(s21_decimal x, s21_decimal y);
int s21_is_greater_or_equal_long(s21_long_decimal x, s21_long_decimal y);
int s21_is_equal_long(s21_long_decimal x, s21_long_decimal y);
int s21_is_greater_long(s21_long_decimal x, s21_long_decimal y);
int s21_equals_zero(s21_decimal x);
int s21_equals_zero_long(s21_long_decimal x);
int s21_is_less(s21_decimal x, s21_decimal y);
int s21_is_less_or_equal(s21_decimal x, s21_decimal y);

// CONVERTERS

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_double(s21_decimal src, long double *dst);

// ADDITIONAL

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
float s21_rand_r(float a, float b);

#endif