#include "s21_decimal.h"

int s21_add(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int error = 0;

  s21_zero_decimal(res);

  int sign1 = s21_get_sign(x);
  int sign2 = s21_get_sign(y);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(y);
  int diff = scale1- scale2;

  int flag_signed = s21_is_add_negative(x,y);  // if res < 0

  if(s21_is_opposite(x,y)){ // -7 + 7
    s21_zero_decimal(res);

  }else if(s21_is_max(x) && s21_is_decimal(y)){ // if MAX/10 + any number    
    if(diff <= 0 && !scale1 && sign1 == sign2){
      error = 1;
    }

  }else if((s21_is_max(y) && s21_is_decimal(x))){ // if any number + MAX/10
     if(diff >= 0 && !scale2 && sign1 == sign2){
      error = 1;
    }
  }

  if(!error){
    s21_long_decimal value1 = {0};
    s21_long_decimal value2 = {0};
    s21_long_decimal total = {0};

    int res_scale = 0;
  
    s21_short_to_long_decimal(x, &value1);
    s21_short_to_long_decimal(y, &value2);  

       
    if (diff > 0) {
        s21_set_scale(&y, scale1);  // local y
    } else {
        s21_set_scale(&x, scale2);  // local x
    }

    s21_normalization(&value1, &value2, diff);  // common denominator

    if ((sign1 == sign2)) {  // IF BOTH ARE POSITIVE OR NEGATIVE
      
      s21_add_long(value1, value2, &total);

    }else if (sign1 != sign2){

      if (s21_is_greater_long(value1, value2)) { 
        
        s21_sub_long(value1, value2, &total);
       
      } else {
        
        s21_sub_long(value2, value1,&total);  
      }
    }

    if(flag_signed){
      s21_set_sign(res);
    }
    
    // now we need to find how much times we need to total/10 to make it fits
    // to our 95-bits decimal

    int set_scale = s21_get_scale(x);

    res_scale = s21_post_normalization(&total, set_scale);

    if (res_scale >= 0) {

      s21_long_to_short_decimal(total, res);
      s21_set_scale(res, res_scale);

    } else {
      error = 1;
    }
  }

  if (error && flag_signed) {
    error = 2;
  }

  if (error) s21_zero_decimal(res);

  return error;
}

void s21_add_long(s21_long_decimal value1, s21_long_decimal value2,
                  s21_long_decimal *total) {
  int res = 0, carry = 0;

  for (int i = 0; i < 256; i++) {
    res = s21_get_bit_long(value1, i) + s21_get_bit_long(value2, i) +
          carry;  // 0 (0+0+0),1(1+0+0 or 0+1+0),2(1+1+0) or 3(1+1+1)
    carry = res / 2;
    s21_set_bit_long(total, i, res % 2);
  }
}

int s21_sub(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int error = 0;

  int sign1 = s21_get_sign(x);
  int sign2 = s21_get_sign(y);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(y);

  s21_zero_decimal(res);

  int diff = scale1 - scale2;
  int flag_signed = s21_is_sub_negative(x,y);

  if(s21_is_max(x) && s21_is_decimal(y)){  // if MAX/10-(-any) or -MAX/10 - any
    if(diff <= 0 && !scale1 && sign1 != sign2){
      error = 1;
    }

  }else if((s21_is_max(y) && s21_is_decimal(x))){ // if any -(MAX/10) or -any - MAX/10
     if(diff >= 0 && !scale2 && sign1 != sign2){
      error = 1;
    }
  }

  if (!error) {
    if (s21_is_equal(x, y) && sign1 == sign2) {  //-7 - (-7) OR 7 - 7
      s21_zero_decimal(res);
    } else {
      s21_long_decimal value1 = {0};
      s21_long_decimal value2 = {0};
      s21_long_decimal total = {0};

      s21_short_to_long_decimal(x, &value1);
      s21_short_to_long_decimal(y, &value2);


      if (diff > 0) {
        s21_set_scale(&y, scale1);  // local y
      } else {
        s21_set_scale(&x, scale2);  // local x
      }

      s21_normalization(&value1, &value2, diff);  // common denominator

      if (!sign1 && !sign2) {

        if (s21_is_greater_long(value2, value1)) {  // 3 - 7
          s21_long_decimal tmp = value1;
          value1 = value2;
          value2 = tmp;
        }

        s21_sub_long(value1, value2, &total);

      }else if (sign1 && sign2) {  //-7 - (-3) OR -3 - (-7)

        if (s21_is_greater_long(value1, value2)) {
          s21_sub_long(value1, value2, &total);
        } else {
          s21_sub_long(value2, value1, &total);
        }

      }else if (sign1 != sign2) {
        s21_add_long(value1,value2,&total);
      }

      if(flag_signed){
        s21_set_sign(res);
      }

      int set_scale = s21_get_scale(x);

      int scale = s21_post_normalization(
          &total, set_scale); 

      if (scale >= 0) {

        s21_long_to_short_decimal(total, res);
        s21_set_scale(res, scale);

      } else {
        error = 1;
      }
    }
  }

  if (error && flag_signed) {
    error = 2;
  }

  if (error) s21_zero_decimal(res);

  return error;
}

void s21_sub_long(s21_long_decimal value1, s21_long_decimal value2,
                  s21_long_decimal *total) {

  for (int i = 0; i < 8; i++) {
    value2.bits[i] = ~value2.bits[i];
  }

  s21_long_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};

  s21_add_long(value2, one, &value2);

  s21_add_long(value1, value2, total);
}


int s21_mul(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int sign1 = s21_get_sign(x);
  int sign2 = s21_get_sign(y);
  int error = 0;
  int scale = 0;
  int flag_signed = 0;
  s21_zero_decimal(res);

  if (!s21_equals_zero(x) || !s21_equals_zero(y)) {
    s21_long_decimal value1 = {0};
    s21_long_decimal value2 = {0};
    s21_long_decimal total = {0};

    s21_short_to_long_decimal(x, &value1);
    s21_short_to_long_decimal(y, &value2);

    if (sign1 != sign2) {
      s21_set_sign(res);
      flag_signed = 1;
    }

    scale = s21_get_scale(x) + s21_get_scale(y);

    error = s21_mul_long(value1, value2, &total);

    scale = s21_post_normalization(&total, scale);

    if (scale >= 0) {
      s21_set_scale(res, scale);
      s21_long_to_short_decimal(total, res);
    } else {
      error = 1;
    }
  }

  if (error && flag_signed) {
    error = 2;
  }

  if (error) s21_zero_decimal(res);

  return error;
}

int s21_mul_long(s21_long_decimal value1, s21_long_decimal value2,
                 s21_long_decimal *res) {
  int error = 0;
  int count = 0;  // current position
  s21_long_decimal tmp = {0};

  for (int i = 0; i < 256 && !error; i++) {
    if (s21_get_bit_long(value2, i)) {
      error = s21_shift_long_left(&value1, i - count);
      s21_add_long(value1, tmp, &tmp);
      count = i;
    }
  }

  *res = tmp;

  return error;
}

int s21_div(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int error = 0;

  s21_zero_decimal(res);

 if (s21_is_decimal(x)) {  // 0/any value = 0
    if (s21_is_decimal(y)) {
      int scale, res_scale = 0;

      s21_long_decimal value1 = {0}, value2 = {0}, total = {0};
      s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};

      int sign1 = s21_get_sign(x);
      int sign2 = s21_get_sign(y);

      if (sign1 != sign2) s21_set_sign(res);

      s21_short_to_long_decimal(x, &value1);
      s21_short_to_long_decimal(y, &value2);

      scale = s21_div_long(value1, value2, &total);
      s21_set_scale(&x, s21_get_scale(x) + scale);

      res_scale = s21_get_scale(x) - s21_get_scale(y);
      if (res_scale > 0) {
        res_scale = s21_post_normalization(&total, res_scale);
      } else if (res_scale < 0) {
        for (int i = 0; i < abs(res_scale); i++) {
          s21_mul_long(total, ten, &total);
        }
        res_scale = s21_post_normalization(&total, 0);
      }

      if (res_scale >= 0) {
        s21_long_to_short_decimal(total, res);
        s21_set_scale(res, res_scale);
      } else {
        error = 1;
      }

      if (error == 1 && s21_get_sign(*res)) error = 2;

      if (error) s21_zero_decimal(res);

    } else {
      error = 3;
    }
  }

  return error;
}

int s21_div_long(s21_long_decimal value1, s21_long_decimal value2,
                 s21_long_decimal *total) {
  int left1 = 0;
  int left2 = 0;
  int scale = 0;
  int save_scale = 0;
  int bit2 = 0;
  int diff = 0;

  s21_zero_long(total);

  s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_long_decimal tmp = {0};

  for (int i = 255; i >= 0 && (!left1 || !left2); i--) {
    if (left1 == 0 && s21_get_bit_long(value1, i)) {
      left1 = i;
    }

    if (left2 == 0 && s21_get_bit_long(value2, i)) {
      left2 = i;
    }
  }

  bit2 = left2;  // the highest bit of value2 before all moves

  for (int i = 0;
       i < 96 &&
       s21_is_long_decimal(
           value1);) {  // while VALUE1 as a REMAINDER != 0 or MANTISSA is full
                        // like 1.333333333333333333333
    // if I made until i < 96 there is a HUGE number so post-normalization can't
    // deal with

    if (i > 0) {  // if remainder
      s21_shift_long_left(&value2, 1);
      s21_mul_long(*total, ten, total);
      // s21_mul_long(*total, ten, total);

      s21_mul_long(value1, ten, &value1);
      save_scale++;
    }

    scale = s21_equation_long(
        &value1, &value2);  // how much we need to shift to the left or (MUL *
                            // 10) each number to be able to sub it
    if (i < 1) save_scale += scale;

    left1 = left2 = 0;

    for (int j = 255; j >= 0 && (!left1 || !left2);
         j--) {  // find lefts after equation
      if (left1 == 0 && s21_get_bit_long(value1, j)) {
        left1 = j;
      }

      if (left2 == 0 && s21_get_bit_long(value2, j)) {
        left2 = j;
      }
    }

    diff = left2 - bit2;  // how much value2 was left-shifted

    if (diff < 0) diff = 0;

    for (; diff >= 0 && s21_is_long_decimal(value1);) {
      if (s21_is_greater_long(value2, value1)) {
        s21_set_bit_long(&tmp, 0, 0);
      } else {
        s21_sub_long(value1, value2, &value1);
        s21_set_bit_long(&tmp, 0, 1);
      }

      i++;
      diff--;

      if (diff >= 0) s21_shift_long_right(&value2, 1);

      s21_shift_long_left(&tmp, 1);
    }

    if (diff >= 0) s21_shift_long_left(&tmp, diff + 1);

    s21_shift_long_right(&tmp, 1);

    s21_add_long(*total, tmp, total);
    s21_zero_long(&tmp);
  }

  return save_scale;
}

void s21_div_long_int(s21_long_decimal value1, s21_long_decimal value2,
                      s21_long_decimal *total, int *remainder) {
  int left1 = 0;
  int left2 = 0;
  int scale = 0;
  int save_scale = 0;
  int bit2 = 0;

  s21_zero_long(total);

  if (!s21_equals_zero_long(value1)) {

    s21_long_decimal tmp = {0};

    for (int i = 255; i >= 0 && (!left1 || !left2); i--) {
      if (left1 == 0 && s21_get_bit_long(value1, i)) {
        left1 = i;
      }

      if (left2 == 0 && s21_get_bit_long(value2, i)) {
        left2 = i;
      }
    }

    bit2 = left2;  // the highest bit of value2 before all moves

    scale = s21_equation_long(
        &value1, &value2);  // how much we need to shift to the left or (MUL *
                            // 10) each number to be able to sub it

    save_scale += scale;

    left1 = left2 = 0;

    for (int i = 255; i >= 0 && (!left1 || !left2);
         i--) {  // find lefts after equation
      if (left1 == 0 && s21_get_bit_long(value1, i)) {
        left1 = i;
      }

      if (left2 == 0 && s21_get_bit_long(value2, i)) {
        left2 = i;
      }
    }

    int diff = left2 - bit2;  // how much value2 was left-shifted

    if (diff < 0) diff = 0;

    for (; diff >= 0 && s21_is_long_decimal(value1);) {
      if (s21_is_greater_long(value2, value1)) {
        s21_set_bit_long(&tmp, 0, 0);
      } else {
        s21_sub_long(value1, value2, &value1);
        s21_set_bit_long(&tmp, 0, 1);
      }

      diff--;

      if (diff >= 0) s21_shift_long_right(&value2, 1);

      s21_shift_long_left(&tmp, 1);
    }

    if (diff >= 0) s21_shift_long_left(&tmp, diff + 1);

    s21_shift_long_right(&tmp, 1);

    s21_add_long(*total, tmp, total);
    s21_zero_long(&tmp);

    *remainder = value1.bits[0];
  }
}

int s21_equation_long(s21_long_decimal *value1, s21_long_decimal *value2) {
  int scale = 0;
  s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};

  while (s21_is_greater_long(*value2, *value1)) {
    s21_mul_long(*value1, ten, value1);
    scale++;
  }

  while (s21_is_greater_or_equal_long(*value1, *value2)) {
    s21_shift_long_left(value2, 1);
  }

  s21_shift_long_right(value2, 1);

  return scale;
}

void s21_zero_decimal(s21_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
}

void s21_zero_long(s21_long_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = dst->bits[4] =
      dst->bits[5] = dst->bits[6] = dst->bits[7] = 0;
}

void s21_normalization(s21_long_decimal *value1, s21_long_decimal *value2,
                       int diff) {
  s21_long_decimal x = {{10, 0, 0, 0, 0, 0, 0}}, res = {0};

  if (diff > 0) {  // increase value2 power
    for (int i = 0; i < diff; i++) {
      s21_mul_long(*value2, x, &res);
      *value2 = res;
      s21_zero_long(&res); 
    }

  } else if (diff < 0) {  // increase value1 power
    for (int i = 0; i < -diff; i++) {
      s21_mul_long(*value1, x, &res);
      *value1 = res;
      s21_zero_long(&res);
    }
  }
}

int s21_post_normalization(s21_long_decimal *res, int scale) {

  s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int remainder = 0;

  while ((res->bits[3] || res->bits[4] || res->bits[5] || res->bits[6] ||
          res->bits[7]) &&
         scale > 0) {  

    s21_div_long_int(*res, ten, res, &remainder);

    scale--; 
  }

  s21_long_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};

  if (remainder >= 5) {
    s21_add_long(*res, one, res);
  }

  if ((res->bits[3] || res->bits[4] || res->bits[5] || res->bits[6] ||
       res->bits[7])) {
    scale = -1;
  }

  return scale;
}