#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
for(int i = 0; i != 134;i++){
    printf("%s\n",s21_strerror(i));
}

return 0;
}


