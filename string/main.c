#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
   char str[] = "string";
   
   s21_memset(str,'$',3);
   
   printf("%s",str);
   
   return 0;
}

