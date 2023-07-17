#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
   char str[] = "string";
   char s[] = "STRING";
   
   s21_strncat(str,s,3);

   printf("%s",str);
   
   return 0;
}

