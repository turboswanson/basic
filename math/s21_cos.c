#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0;

  if (s21_is_inf(x) || s21_is_nan(x)) {
    res = S21_NAN;
  } else {
    x = s21_normalize(x);
    int num = res = 1;
    long double tmp = 1;

    // Taylor row
    while (s21_fabs(tmp) > S21_EPS) {
      tmp *= (-x * x) / ((2 * num - 1) * (2 * num));
      res += tmp;
      num++;
    }
  }

  return res;
}
