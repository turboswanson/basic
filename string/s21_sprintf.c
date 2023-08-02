/* 

Specifiers 
c - character
d - signed devimal integer
i - signed devimal integer(may be decimal, octal, hexadecimal)
f - decimal foating point
s - string of characters
u - unsigned decimal integer
% - character %

Flags
- left-justify
+ forces to precede the result with a plus or minus 
space if no sign is going to be written

Width
 minimum number of characters to be written 

   Precision

   Length
h
l
*/

//example s21_sprintf(str,"string %d %d %d",756);

#include "s21_string.h"
void f_write(char *buf, const char *format);
int check_string(char *format);
int check_specs(char c);

int s21_sprintf(char *buf,const char *format,...){
    int res = 0;

    while(*format){
        if(*format != '%'){
            char tmp = *format;
            s21_strcat(buf,&tmp);
            format++;
        }
        res = check_string(format);
        return res;
    }

// return s21_strlen(buf);   

}

int check_string(char *format){
    int res = 0;
    int i = 0;
    while(format[i] != '\0'){
        if(check_specs(format[i])){
            break;
        }
            res = 1;
        i++;
    }

    return res;
}

int check_specs(char c){
    int res = 0;
    char *specs = "cdifsu";

    for(int i = 0; specs[i];i++){
        if(specs[i] == c){
            res = 1;
            break;
        }
    }
    return res;
}
