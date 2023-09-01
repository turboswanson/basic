#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  // if (src == s21_NULL || str == s21_NULL || start_index < 0) {
  //   return s21_NULL;
  // }

  // s21_size_t src_len = s21_strlen(src);
  // s21_size_t str_len = s21_strlen(str);

  // if (start_index > src_len) { // insert to the end of src
  //   start_index = src_len;
  // }

  // s21_size_t length = src_len + str_len;
  // char *tmp = calloc(length + 1, sizeof(char));

  // if (tmp == s21_NULL) {
  //   return s21_NULL;
  // }

  // for (s21_size_t i = 0; i < length; i++) {
  //   if (i < start_index)
  //     tmp[i] = src[i];
  //   else if (i >= start_index + str_len)
  //     tmp[i] = src[i - str_len];
  //   else
  //     tmp[i] = str[i - start_index];
  // }

  // return tmp;

  if (src == s21_NULL || str == s21_NULL || s21_strlen(src) < start_index ||
      start_index < 0) {
    return s21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  char *result = (char *)calloc(src_len + str_len + 1, sizeof(char));

  if (result != s21_NULL) {  // if memory actually allocated
    s21_strncpy(result, (char *)src, start_index);
    s21_strncat(result, str, str_len);
    s21_strncat(result, &src[start_index], src_len - start_index);

    return (void *)result;
  } else {
    return s21_NULL;
  }
}
