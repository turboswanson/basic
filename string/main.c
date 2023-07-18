#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char c[] = "a\n\0";
  char dest[256] = "lolkek";
  s21_strncpy(dest,c,3);

  printf("%s",dest);
   
   return 0;
}



