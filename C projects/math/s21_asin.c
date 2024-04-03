#include "s21_math.h"

long double s21_asin(double x) {
  long double res = S21_NAN;
  if ((float)(s21_fabs(x)) == (float)(s21_sqrt(2) / 2)) {
    res = S21_PI / 4;
    if (x < 0) res = -res;
  } else if (x == 0) {
    res = 0;
  } else if (x == 1 || x == -1) {
    res = S21_PI / (2 * x);
  } else if (x > -1 && x < 1) {
    res = S21_PI / 2 - s21_acos(x);
  }
  return res;
}