#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char *s = "string";
  char *accept = "i";
  
  printf("%s\n",strpbrk(s,accept));

  // printf("%ld",strcspn(s,reject));
 
   return 0;
}



