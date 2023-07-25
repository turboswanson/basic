#include "s21_string.h"

// breaks a string into a series of tokens separated with delims


char *s21_strtok(char *str, const char *delim){
 static char* mem = NULL;

  if (str) mem = str;

  if (mem) {
    str = mem + s21_strspn(mem, delim);
    mem = str + s21_strcspn(str, delim);
    if (*mem != '\0') {
      *mem = '\0';
      ++mem;
    }
  }

  // if (*str == '\0') mem = s21_NULL;

  return *str != '\0' ? str : NULL; 
  }
