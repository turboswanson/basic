#include "s21_string.h"

// returns a length of the segment contains only matching to the str2 characters

size_t s21_strspn(const char *str,const char *accept){
    size_t len_s = s21_strlen(str);
    size_t len_a = s21_strlen(accept);
    size_t count = 0;
    int match = 0;

    for(size_t i = 0; i < len_s;i++){
        for(size_t j = 0; j< len_a;j++){
            if(str[i] == accept[j]){
                match = 1;
            }
        }

        if(match){
            count++;
            match = 0;
        }
        else{
            break;
        }
    }

    return count;
}
