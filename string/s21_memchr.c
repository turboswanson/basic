#include "s21_string.h"

void *s21_memchr(const void *str,int c,size_t n){
  const char *s = (const char *)str;
  int match = 0;

  // for(size_t i = 0; i < n;i++){
  //   if(*s == c){
  //     match++;
  //     break;
  //   }
  //   s++;
  // }
  size_t i = 0;

  while(*s && i < n){
    if(*s == c){
      match++;
      break;
    }
    s++;
    i++;
  }

  return match ? (void*)s:NULL;
}