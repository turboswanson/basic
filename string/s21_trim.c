#include "s21_string.h"
int s21_has_char(const char ch, const char *list);

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) {
    return s21_NULL;
  }

  char *res = s21_NULL;

  if (trim_chars && trim_chars[0]) {
    int str_length = s21_strlen(src);
    int start_trim = 0, end_trim = 0;

    for (; start_trim < str_length && s21_has_char(src[start_trim], trim_chars);
         start_trim++)
      ;
    for (int i = str_length - 1; i >= 0 && s21_has_char(src[i], trim_chars);
         i--, end_trim++)
      ;
    int res_length = str_length - start_trim - end_trim;
    if (res_length < 0) res_length = 0;

    char *tmp = calloc(res_length + 1, sizeof(char));

    if (tmp) {
      for (int i = start_trim, j = 0; i < str_length - end_trim; i++, j++)
        tmp[j] = src[i];
      tmp[res_length] = '\0';
      res = tmp;
    }
  } else {
    res = s21_trim(src, "\t\n ");
  }
  return res;
}

int s21_has_char(const char ch, const char *list) {
  int res = 0;
  for (int i = 0; i < s21_strlen(list); i++)
    if (ch == list[i]) {
      res = 1;
      break;
    }
  return res;
}