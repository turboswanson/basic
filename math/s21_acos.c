#include "s21_math.h"

long double s21_acos(double x) {
  long double res = S21_NAN;

  if ((float)(s21_fabs(x)) == (float)(s21_sqrt(2) / 2)) {
    res = (x < 0) ? 3 * S21_PI / 4 : S21_PI / 4;
  } else if (x < 1 && x >= 0)
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x < 0 && x > -1)
    res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x == 1 || x == -1) {
    res = (x < 0) ? S21_PI : 0;
  }
  return res;
}