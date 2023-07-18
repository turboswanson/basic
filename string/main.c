#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char *s = "strsstring";
  char *reject = "xyz";
  
  printf("%ld\n",s21_strcspn(s,reject));
  printf("%ld",strcspn(s,reject));
 
   return 0;
}



