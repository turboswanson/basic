#include "s21_math.h"

long double s21_sqrt(double x) {
  return (x < 0 || s21_is_nan(x)) ? S21_NAN
         : (s21_is_inf(x))        ? x
                                  : s21_pow(x, 0.5);
}