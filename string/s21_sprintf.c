/* 

Specifiers 
c - character    s21_sprintf(buf,"string%c",'$');
d - signed decimal integer  s21_sprintf(buf,"string%d",46);
i - signed decimal integer(may be decimal, octal, hexadecimal)   s21_sprintf(buf,"string%i",65);
f - decimal floating point  s21_sprintf(buf,"string%f",46.5);
s - string of characters s21_sprintf(buf,"string%s","another string");
u - unsigned decimal integer 
% - character %

Flags
- left-justify   s21_sprintf(buf,"string%-d",46);     COMPARE OUTPUT to see the difference!!!!!! sprintf(str,"string1 %5d",45)   sprintf(str,"string1 %-5d",45)

+ forces to precede the result with a plus or minus  s21_sprintf(buf,"string%+d",46); 
space if no sign is going to be written s21_sprintf(buf,"string % d",46);

Width
 minimum number of characters to be written  s21_sprintf(buf,"string%5d",46)   ----->  string   46

Precision   s21_sprintf(buf,"string%.5d",46); ------> string00046     s21_sprintf(buf,"string%.3f",46.565646);    -----> srting46.566

Length
h  s21_sprintf(buf,"string%hd",46);
l s21_sprintf(buf,"string%ld",46);  long int (ld) = -2 147 483 648 to  2 147 483 648



example s21_sprintf(buf,"string1 %.5dstring2 %5.5f string3 %c",45,3.14567843,'$');  ----> string1 00045 string2 3.14568 string3 $
*/



#include "s21_string.h"

typedef struct flags{
    int space;
    int minus;
    int plus;
    int dot;
    int num;
}flags;

typedef struct specs{
    int c;
    int d;
    int i;
    int f;
    int s;
    int u;
}specs;

int check_flag(const char *format,flags *f);
int check_spec(const char *format,specs *s);


int s21_sprintf(char *buf,const char *format, ...){
    flags f = {0};
    specs s = {0};

    while(*format){
        if(*format != '%'){
            char c[1] = {'\0'};
            c[0] = *format;
            s21_strcat(buf,c);
            format++;
        }else{
            format++;// got a '%' and move for one step to see what is the next one
            
            while(check_flag(format,&f)){  // find out if there is a space, '-', '+' or a number after %
                if(f.space){ // if s21_sprintf(buf,"string %   5d",45)
                    char space[1] = {'\0'};
                    space[0] = *format;
                    s21_strcat(buf,space);
                    f.space = 0;
                    format++;
                    continue;
                }
                format++;
            }

            check_spec(format,&s); // find out what specifier is
                         

        }
    }

    return s21_strlen(buf);
}

int check_flag(const char *format,flags *f){
    int flag = 0;
    switch(*format){
        case ' ' : f->space = 1;flag = 1;break;
        case '-' : f->minus = 1;flag = 1;break;
        case '+' : f->plus = 1;flag = 1;break;
        case '.' : f->dot = 1;flag = 1;break;
    }

    if(isdigit(*format)){
        f->num = *format;
        flag = 1;
    }
    
    return flag;
}

int check_spec(const char *format,specs *s){
    int flag = 0;
    switch(*format){
        case 'c': s->c = 1;flag = 1;break;
        case 'd' : s->d = 1;flag = 1; break;
        case 'i' : s->i = 1;flag = 1; break;
        case 'f' : s->f = 1;flag = 1; break;
        case 's' : s->s = 1; flag = 1; break;
        case 'u' : s->u = 1; flag = 1;break;
    }
}
