#ifndef S21_MATH_H
#define S21_MATH_H

#include <float.h>
#include <stdio.h>
#include <unistd.h>

#define s21_is_nan(x) (x != x)
#define s21_is_inf(x) (x == S21_INF || x == -S21_INF)
#define s21_is_in_range(x) (x > -1 && x < 1)
#define s21_in_first_diapason(x) \
  (x > -S21_FIRST_DIAPASON && x < S21_FIRST_DIAPASON)
#define s21_in_second_diapason(x) \
  (x > -S21_SECOND_DIAPASON && x < S21_SECOND_DIAPASON)

#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_NEGZERO -0.0
#define S21_EPS 1e-16
#define S21_E 2.71828182845904523536028747
#define S21_PI 3.141592653589793
#define S21_TAN_PI_DIV_2 16331239353195369.755859
#define S21_FIRST_DIAPASON 1000000000
#define S21_SECOND_DIAPASON 10000000

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_normalize(double x);

#endif