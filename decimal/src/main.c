#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "s21_decimal.h"

#define EXPONENT_PLUS_1 65536

int main(void) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  // s21_set_scale(&num2,1);
  s21_decimal tmp;
  printf("%d\n", s21_round(num1, &tmp));
  printf("%d\n", s21_truncate(num1, &tmp));
  printf("%d\n", s21_floor(num1, &tmp));
  printf("%d\n", s21_negate(num1, &tmp));
  printf("%d\n", s21_add(num1, num2, &tmp));
  printf("%d\n", s21_sub(num1, num2, &tmp));
  printf("%d\n", s21_mul(num1, num2, &tmp));
  printf("%d", s21_div(num1, num2, &tmp));

  // for (int i = 0; i < 80; i++) {
  //   s21_round(arr[i],&tmp);
  //   printf("%d - %d\n",i,s21_is_equal(tmp,result[i]));
  // }
  // for(int i = 31; i >= 0;i--){
  //     int bit = s21_f_get_bit(a,i);
  //     printf("%d",bit);

  //     if(i == 96 || i == 64 || i == 32)printf(" ");//bits
  //     if(i == 127)printf(" "); // sign
  //     if(i == 120)printf(" "); // 0
  //     if(i == 112)printf(" "); //pow

  // }

  // for (int i = 127; i >= 0; i--) {
  //   int bit = s21_get_bit(tmp, i);
  //   printf("%d", bit);

  //   if (i == 96 || i == 64 || i == 32) printf(" ");  // bits
  //   if (i == 127) printf(" ");                       // sign
  //   if (i == 120) printf(" ");                       // 0
  //   if (i == 112) printf(" ");                       // pow
  // }
  // // printf("%d",s21_is_equal(tmp,result[13]));

  // printf("\n");

  // for(int i = 127; i >= 0;i--){
  //     int bit = s21_get_bit(num2[29],i);
  //     printf("%d",bit);

  //     if(i == 96 || i == 64 || i == 32)printf(" ");//bits
  //     if(i == 127)printf(" "); // sign
  //     if(i == 120)printf(" "); // 0
  //     if(i == 112)printf(" "); //pow

  // }

  //   for(int i = 255; i >= 0;i--){
  //     int bit = s21_get_bit_long(tmp,i);
  //     printf("%d",bit);

  //     if(i % 32 == 0) printf(" ");

  //   }

  return 0;
}

/*

*BITWISE LEFT SHIFT*

int x = 2;
x << 3 --> x*2^3 ---> x = 16;

*BITWISE RIGHT SHIFT*

int x = 8;

x >> 3 --> x/(2^3)  --> x = 1;
*/

/*

BITS[3]

0    0000000   0001 1100 0000 000 0000 0000
127  126-120   119-112    112 - 96
31   30 - 24     23-16    15  -  0
s                pow

sign:          pow: 10^0 - 10^28
0 > 0
1 < 0
*/

/*
IF NUM < 0

char x = -3;

2's complement method :

1. 3 = 00000011
2. ~3 = 11111100
3. +1 = 11111101
-3 == 11111101


32bit system

INT_MAX = 2 147 483 648; // 01111111111111111111111111111111
UINT_MAX = 4 294 967 295; //11111111111111111111111111111111

*/