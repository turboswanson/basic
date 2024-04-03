#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  // unsigned char *d = dest;
  // const unsigned char *s = src;
  // s21_size_t i = 0;

  // for (; i < n; i++) d[i] = s[i];
  // d[i] = '\0';  // is it necessary?
  // return dest;

  char *d = (char *)dest;
  const char *s = (char *)src;

  for (s21_size_t length = 0; length < n; length++) {
    d[length] = s[length];
  }
  return d;
}