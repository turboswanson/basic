#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  char *src = "hellO";
  char dest[256] = "aaaaaaaaa";
  s21_strcpy(dest,src);

  printf("%s",dest);
   
   return 0;
}



