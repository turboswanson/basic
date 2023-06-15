#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <unistd.h>
#include <float.h>

#define s21_is_nan(x) (x != x)
#define s21_is_inf(x) (x == S21_INF || x == -S21_INF)
#define S21_NAN 0.0/0.0
#define S21_INF 1.0/0.0
#define S21_NEGZERO -0.0
#define S21_DBL_MAX 1.79769e+308-1

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x,double y);
long double s21_ceil(double x);

#endif