#include "s21_string.h"

// add n elements of src string to the end of dest string

char *s21_strncat(char *dest, const char *src, size_t n){
    size_t len_d = s21_strlen(dest);
    size_t len_s = s21_strlen(src);
    size_t i = 0;

    while(i < n){
        dest[len_d+i] = src[i];
        i++;
    }

    dest[len_d+i] = '\0';

    return dest;
}