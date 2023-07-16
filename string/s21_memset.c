#include "s21_string.h"

void *s21_memset(void *str, int c, size_t n){
  unsigned char *string = (unsigned char *)str;
  while(n--) *string++ = c;

  return str;  
}