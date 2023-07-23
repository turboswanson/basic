#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
  const char *s = "HelHo world";
  const char *e = "LeH"; 
  size_t len = strspn(s,e);
  printf("%ld",len);


  // printf("%ld",strcspn(s,reject));
 
   return 0;
}



