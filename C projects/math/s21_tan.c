#include <math.h>

#include "s21_math.h"

long double s21_tan(double x) {
  return (s21_is_inf(x) || s21_is_nan(x)) ? S21_NAN
         : (x == S21_PI / 2)              ? S21_TAN_PI_DIV_2
                                          : s21_sin(x) / s21_cos(x);
}
