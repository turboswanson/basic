#include "s21_string.h"

// While I tried to make it with changing 's' to '$' in *str = "string" I get a segmentation fault because *str = "string" is a string literal. 
//It means there is a read-only memory allocated

//returns a pointer to a string[] with a replacement of a specific character

void *s21_memset(void *str, int c, size_t n){
  unsigned char *string = (unsigned char *)str;
  while(n--) *string++ = c;

  return str;  
}