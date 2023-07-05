#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x == S21_INF) {
    res = S21_PI / 2;
  } else if (x == S21_INF_NEG) {
    res = -S21_PI / 2;
  } else if (s21_is_nan(x)) {
    res = S21_NAN;
  } else if (x == 1 || x == -1) {
    res = S21_PI / 4;
    if (x < 0) res = -res;
  } else {
    while (!s21_in_first_diapason(x)) x /= 100;
    while (!s21_in_second_diapason(x)) x /= 10;

    int i = 1, is_in_range = (x > -1 && x < 1);

    long double prev = res = is_in_range ? x : 1.0 / x;

    do {
      prev = res;
      res += s21_pow(-1, i) *
             s21_pow(x, ((1 + 2 * i) * (is_in_range ? 1 : -1))) / (1 + 2 * i);
      i++;
      // printf("res=%Lf\tprev=%Lf\tdiff=%Lf\ti=%d\n", res, prev,
      //        s21_fabs(res - prev), i);
    } while (s21_fabs(res - prev) > .0000001 && i < 10000);

    if (!is_in_range) res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
  }
  return res;
}