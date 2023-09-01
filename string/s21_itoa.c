#include "s21_string.h"

char *s21_itoa(long long int num, char *str, int base) {
  int i = 0;
  int isneg = 0;

  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }

  if (num < 0 && base == 10) {
    isneg = 1;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    num = num / base;
  }

  if (isneg) {
    str[i++] = '-';
  }

  str[i] = '\0';
  s21_reverse(str, i);

  return str;
}