#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  char *str1 = "hellO";
  char *str2 = "hello";

  printf("%d",s21_strncmp(str1,str2,10));
   
   return 0;
}

