#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char *str = "\0";
   char *res = s21_strchr(str,'\0');

   printf("%s",res);
   
   return 0;
}

