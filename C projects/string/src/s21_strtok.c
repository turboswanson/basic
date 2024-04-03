#include "s21_string.h"

// breaks a string into a series of tokens separated with delims

char *s21_strtok(char *str, const char *delim) {
  static char *mem = s21_NULL;

  if (str) mem = str;

  if (mem) {
    str = mem +
          s21_strspn(mem, delim);  // if the strig starts with a delim we should
                                   // shift it to the first not-matching element
    mem = str + s21_strcspn(str, delim);  // shift to the delim
    if (*mem != '\0') {  // if it isn't the end of a string we should make it
                         // ending with '\0'
      *mem = '\0';
      mem++;
    }
  }

  return *str != '\0' ? str : s21_NULL;
}
