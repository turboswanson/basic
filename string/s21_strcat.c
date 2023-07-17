#include "s21_string.h"

// returns a dest string with a src string in the end of it

char *s21_strcat(char *dest, const char *src){
    int len_d = (int)s21_strlen(dest);
    int len_s = (int)s21_strlen(src);

    int i = 0;

    while(i < len_s){
        dest[len_d] = src[i];
        len_d++;
        i++;
         
    }

    dest[len_d] = '\0';

    return dest;
}