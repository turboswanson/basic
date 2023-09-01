#include "s21_string.h"

// returns a difference between N elements of two strings

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = (const unsigned char *)
      str1;  // s21memcmp compares bytes which are UNSIGNED bytes
  const unsigned char *s2 = (const unsigned char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      result = (int)(s1[i] - s2[i]);
      break;
    }
  }
  return result;
}