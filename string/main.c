#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
   char str[] = "string";
   char s[] = "STRING";
   
   s21_strcat(str,s);

   printf("%s",str);
   
   return 0;
}

