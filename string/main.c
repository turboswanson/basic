#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char *s = " \0";
  const char *e = ""; 
  printf("%s",s21_strrchr(s,' '));

  // printf("%ld",strcspn(s,reject));
 
   return 0;
}



