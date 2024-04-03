#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;

  if (s21_is_nan(x) || s21_is_nan(y) || s21_is_inf(x) || y == 0) {
    res = S21_NAN;
  } else if (s21_is_inf(y)) {
    res = x;
  } else if ((x == 0.0 && y != 0) || (s21_fabs(x) == s21_fabs(y))) {
    res = (x < 0) ? S21_NEGZERO : 0;
  } else {
    res = s21_abs(x / y);  // приведение к int

    if ((x < 0 && y >= 0) || (x >= 0 && x < 0)) res = -res;

    res = x - res * y;
  }

  return res;
}
