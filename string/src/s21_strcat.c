#include "s21_string.h"

// returns a dest string with a src string in the end of it

// char *s21_strcat(char *dest, const char *src) {
//   int len_d = (int)s21_strlen(dest);
//   int len_s = (int)s21_strlen(src);

//   int i = 0;

//   while (i < len_s) {
//     dest[len_d + i] = src[i];
//     i++;
//   }

//   dest[len_d + i] = '\0';

//   return dest;
// }

char *s21_strcat(char *dest, const char *src) {
  s21_size_t i, j;

  for (i = 0; dest[i] != '\0'; i++)
    ;

  for (j = 0; src[j] != '\0'; j++) dest[i + j] = src[j];

  dest[i + j] = '\0';

  return dest;
}