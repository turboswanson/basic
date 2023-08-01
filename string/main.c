#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
char str[100] = {0};
printf("%d",sprintf(str,"%s %s %d","string","string",70));
return 0;
}


