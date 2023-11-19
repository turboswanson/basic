#include "s21_string.h"

// finds the first match in str1 to any symbol in str2

char *s21_strpbrk(const char *str1, const char *str2) {
  char *s = (char *)str1;
  char *accept = (char *)str2;
  s21_size_t i = 0;
  int match = 0;

  for (; i < s21_strlen(s); i++) {
    for (s21_size_t j = 0; j < s21_strlen(accept); j++) {
      if (s[i] == accept[j]) {
        match++;
      }
    }

    if (match) {
      break;
    }
  }

  return match ? (char *)(s + i) : s21_NULL;
}
