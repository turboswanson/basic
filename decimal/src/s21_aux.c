#include "s21_decimal.h"

int s21_is_opposite(s21_decimal x, s21_decimal y){
  int res = 1;
  
  for (int i = 0; i < 96; i++) {  // -7 + 7 OR 7 + (-7)
    if (s21_get_bit(x, i) != s21_get_bit(y, i)) {
      res = 0;
      i = 96;
    }
  }

  if(res && (s21_get_sign(x) == s21_get_sign(y))){
    res = 0;
  }

  if(res && (s21_get_scale(x) != s21_get_scale(y))){
    res = 0;
  }

  return res;
}

int s21_is_max(s21_decimal num){
  int res = 0;

  if(num.bits[0] == UINT_MAX && num.bits[1] == UINT_MAX && num.bits[2] == UINT_MAX){
    res = 1;
  }

  return res;
}


int s21_is_add_negative(s21_decimal value1,s21_decimal value2){ // is add result negative
  
  int res = 0;
  int sign1 = s21_get_sign(value1);
  int sign2 = s21_get_sign(value2);

  if(sign1 && sign2){ // -5 + (-7)
    res = 1;
  }else if(!sign1 && sign2){ // 5 + (-7)
    
    s21_set_bit(&value2,127,0); // for abs comparing

    if(s21_is_greater(value2,value1)){
      res = 1;
    }
  }else if(sign1 && !sign2){ // -5 + 7 or -7 + 5
    s21_set_bit(&value1,127,0);

     if(s21_is_greater(value1,value2)){
      res = 1;
    }
  }

  return res;
}

int s21_is_sub_negative(s21_decimal value1,s21_decimal value2){ // is sub result negative
  
  int res = 0;
  int sign1 = s21_get_sign(value1);
  int sign2 = s21_get_sign(value2);

  if(!sign1 && !sign2){ // 7-5 > 0 but 5-7 < 0
    if(s21_is_less(value1,value2)){
      res = 1;
    }
  }else if(sign1 && sign2){
    if(s21_is_less(value1,value2)){ // -7 - (-5)
      res = 1;
    }
  }else if(sign1 && !sign2){ // -5-7 
    res = 1;
  }

  return res;
}

void print_int(int num){

  for(int i = 31; i >= 0;i--){
      int bit = s21_f_get_bit(num,i);
      printf("%d",bit);

      if(i == 96 || i == 64 || i == 32)printf(" "); //bits
      if(i == 127)printf(" "); // sign
      if(i == 120)printf(" "); // 0
      if(i == 112)printf(" "); //pow

  }
}

void print_decimal(s21_decimal value){

  for (int i = 127; i >= 0; i--) {
    int bit = s21_get_bit(value, i);
    printf("%d", bit);

    if (i == 96 || i == 64 || i == 32) printf(" ");  // bits
    if (i == 127) printf(" ");                       // sign
    if (i == 120) printf(" ");                       // 0
    if (i == 112) printf(" ");                       // pow
  }
}

void print_long_decimal(s21_long_decimal value){
      for(int i = 255; i >= 0;i--){
      int bit = s21_get_bit_long(value,i);
      printf("%d",bit);

      if(i % 32 == 0) printf(" ");

    }
}