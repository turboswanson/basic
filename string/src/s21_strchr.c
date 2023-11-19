#include "s21_string.h"
// returns a pointer to a symbol in a string

char *s21_strchr(const char *str, int c) {
  char *src = (char *)str;
  char *res = s21_NULL;

  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      res = (char *)&str[i];
      break;
    }
  }

  return res;
}