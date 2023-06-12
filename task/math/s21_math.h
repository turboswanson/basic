#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <unistd.h>

#define s21_is_nan __builtin_isnan
#define s21_is_inf __builtin_isinf
#define S21_NAN __builtin_nan("")
#define S21_INF __builtin_inf()

int s21_abs(int x);
long double s21_fabs(double x);

#endif