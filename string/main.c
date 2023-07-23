#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char *s = "HelHo world";
  const char *e = "wor"; 
  printf("%s",s21_strstr(s,e));


  // printf("%ld",strcspn(s,reject));
 
   return 0;
}



