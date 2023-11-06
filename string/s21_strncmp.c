#include "s21_string.h"

// compares n symbols of two strings

// int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
//   int result = 0;
//   for (s21_size_t i = 0; i < n; i++) {
//     if (str1[i] != str2[i]) {
//       result = (int)(str1[i] - str2[i]);
//       break;
//     }
//     if (str1[i] == '\0') {
//       break;
//     }
//   }
//   return result;
// }

// int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
//   for (s21_size_t i = 0; i < n; i++) {
//     if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
//       return (int)(str1[i] - str2[i]);
//     }
//   }

//   return 0;
// }

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int f = 0;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    if (*(str1 + i) > *(str2 + i)) {
      f = *(str1 + i) - *(str2 + i);
      break;
    } else if (*(str1 + i) < *(str2 + i)) {
      f = *(str1 + i) - *(str2 + i);
      break;
    }
  }
  return f;
}