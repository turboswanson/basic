#include "s21_string.h"

// calculate a string length without a '\0'

s21_size_t s21_strlen(const char *str) {
  const char *s = (const char *)str;
  s21_size_t len = 0;

  while (*s) {
    len++;
    s++;
  }

  return len;
}