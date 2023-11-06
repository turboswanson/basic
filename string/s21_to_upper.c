#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  char *res = s21_NULL;
  s21_size_t str_len = s21_strlen(str);

  char *tmp = calloc(str_len + 1, sizeof(char));
  if (*str && tmp) {
    for (int i = 0; i <= str_len; i++)
      tmp[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
  }
  res = tmp;

  return res;
}
