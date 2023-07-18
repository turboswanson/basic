#include "s21_string.h"
// copies up to n characters from src string to a dest string

char *s21_strncpy(char *dest, const char *src, size_t n){
    char *res = (char *)dest;

    if (n > s21_strlen(src)){
        s21_strcpy(dest,src);
    }
    else{
        while(n-- && *src){
            *res = *src;
            res++;
            src++;
        }
    }

    return dest;

}
