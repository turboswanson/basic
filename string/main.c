#include <stdio.h>
#include "s21_string.h"
#include <string.h>
#include <stdarg.h>

void display(char *format,...);

int main(void){                 
// char str[100] = {0};
// printf("%d\n",s21_sprintf(str,"string1 %-.5d string2 %5.5f string3 %c",45,3.14567843,'$'));   // 
// printf("%s",str);

display("Count: %d Price: %f Article: %c",24,68.4,'&');

return 0;

}

void display(char *format,...){
    int d;
    double f;
    unsigned char e;
    va_list factor;

    va_start(factor,format);  // va_start(va_list param, last explicit param)

    for(char *c = format;*c; c++){
        if(*c != '%'){
            printf("%c",*c);
            continue;
        }
            c++;
            switch(*c){
                case 'd' :
                    d = va_arg(factor,int); //type va_arg (va_lis param, type)
                    printf("%d",d);
                    break;
                case 'f':
                    f = va_arg(factor, double);
                    printf("%.2lf",f);
                    break;
                case 'c':
                // it's necessary to use (unsigned char) because we can't use va_arg(factor,char)
                // (char will be promoted to int as it's shorter than int,moreover float will be promoted as double)
                    e = (unsigned char)va_arg(factor,int);
                    printf("%c",e);
                    break;   
                default:
                    printf("%c",*c);                    
        }
      

    }
    va_end(factor);

}



