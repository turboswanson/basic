#include <string.h>
#include <stdio.h>

int main(void){
    char *str = "string";
    char *s = memchr(str,'g',4); // поиск символа 'g' в первых 4 байтах строки string
    printf("%s",s);

    return 0;
}