#include "s21_string.h"

// char *s21_strstr(const char *hay, const char *needle) {
//   char *res = (char *)hay;
//   char *s = (char *)needle;
//   int count = 0;
//   int x = 0;

//   while (*hay) {
//     if (*hay == *needle) {
//       while (*hay == *needle) {
//         hay++;
//         needle++;
//         count++;
//       }
//       break;
//     }
//     x++;
//     hay++;
//   }

//   return (count == s21_strlen(s)) ? (char *)(res + x) : s21_NULL;
// }

// char *s21_strstr(const char *hay, const char *needle) {
//   while (*hay) {
//     const char *tempHay = hay;  // each time variables declaration
//     const char *tempNeedle = needle;

//     while (*tempHay && *tempNeedle && *tempHay == *tempNeedle) {
//       tempHay++;
//       tempNeedle++;
//     }

//     if (!*tempNeedle) {  // if we went through the whole needle string and
//                          // reached '\0'
//       return (char *)hay;
//     }

//     hay++;
//   }

//   return NULL;
// }

int comparing(const char *haystack, const char *needle) {
  int result = 0;
  int break_flag = 0;
  while (*haystack && *needle && !break_flag) {
    if (*haystack != *needle) {
      result = 0;
      break_flag = 1;
    }

    haystack++;
    needle++;
  }
  result = (*needle == '\0');
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  const char *result = s21_NULL;
  int flag = 1;
  int break_flag = 0;

  if (s21_strlen(haystack) == 0 && s21_strlen(needle) == 0) {
    flag = 0;
    result = "";
  }
  while (*haystack && !break_flag) {
    if ((*haystack == *needle && comparing(haystack, needle)) ||
        (*haystack == '\0' || *needle == '\0')) {
      result = haystack;
      flag = 0;
      break_flag = 1;
    }
    haystack++;
  }

  return flag ? s21_NULL : (char *)result;
}