#include "s21_math.h"

long double s21_normalize(double x) {
  // приводим к диапазону [-2PI;0] [0;2PI]
  x = s21_fmod(x, 2 * S21_PI);

  // // нормализация х в диапазоне [-PI;PI]
  while (x > S21_PI) x -= 2 * S21_PI;
  while (x < S21_PI) x += 2 * S21_PI;

  return x;
}