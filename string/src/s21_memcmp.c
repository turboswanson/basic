#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = str1, *s2 = str2;
  int result = 0;

  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      // result = (s1[i] < s2[i]) ? -1 : 1;
      result = s1[i] - s2[i];
      break;
    }
  }

  return result;
}
