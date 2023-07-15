#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n){
    char *dest_ptr = (char *)dest;
    char *src_ptr = (char *)src;

    size_t i = 0;

    while(i < n){
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
        i++;
    }    
    *(dest_ptr+i) = '\0';
    
    return dest;
}