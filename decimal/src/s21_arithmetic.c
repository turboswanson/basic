#include "s21_decimal.h"

/*
ADD

0 + 0 = 0;
1 + 0 = 1;
0 + 1 = 1;
1 + 1 = 0(1);
1 + 1 + 1 = 1(1);
*/

/*
SUB

0 - 0 = 0
1 - 0 = 1
1 - 1 = 0
0 - 1 = 1(1)

*/

/*

MUL

  0 * 0 = 0;
  0 * 1 = 0;
  1 * 0 = 0;
  1 * 1 = 1;

  00000111
  00000010
  ________
  00000000
  +
  00001110
  +
  00000000
  ________


*/

/*
DIV

01000 110 / 111  (70/7)
 -111 ----> 1 (1000/111 = 0001)
  ___
  001 1 ---> 0 (cant' 11/111)
    1 1 1 ----> 1 (111/111)
  - 1 1 1
  _______
    0 0 0 ------> 0 can't(000/111)
                  answer: 1 0 1 0

*/

// int s21_add_int(int x, int y, int *carry) {
//   // int index_x = 0;
//   // int index_y = 0;

//   // for(int i = 31;i >= 0; i--){ // look for the last significant's bit
//   index

//   //   if(f_get_bit(x,i)){
//   //     index_x = i;
//   //     i = 0;
//   //   }
//   // }

//   // for(int i = 31;i >= 0; i--){ // look for the last significant's bit
//   index

//   //   if(f_get_bit(y,i)){
//   //     index_y = i;
//   //     i = 0;
//   //   }
//   // }

//   int sum = 0;
//   int res = 0;

//   // int index = ((index_x > index_y) ? index_x : index_y);

//   int index = 31;

//   for (int i = 0; i <= index; i++) {
//     int bit1 = s21_f_get_bit(x, i);
//     int bit2 = s21_f_get_bit(y, i);

//     if (*carry == 0) {
//       if (!bit1 && !bit2) {
//         sum = 0;
//         s21_f_set_bit(&res, i, sum);
//         continue;
//       }

//       if ((bit1 && !bit2) || (bit2 && !bit1)) {
//         sum = 1;
//         s21_f_set_bit(&res, i, sum);
//         continue;
//       }

//       if (bit1 && bit2) {
//         sum = 0;
//         *carry = 1;
//         s21_f_set_bit(&res, i, sum);
//         continue;
//       }
//     } else {
//       if (!bit1 && !bit2) {
//         sum = 1;
//         *carry = 0;
//         s21_f_set_bit(&res, i, sum);
//         continue;
//       }

//       if ((bit1 && !bit2) || (!bit1 && bit2)) {
//         sum = 0;
//         *carry = 1;
//         s21_f_set_bit(&res, i, sum);
//         continue;
//       }

//       if (bit1 && bit2) {
//         sum = 1;
//         *carry = 1;
//         s21_f_set_bit(&res, i, sum);
//         continue;
//       }
//     }
//   }

//   // if(*carry && index != 31){
//   //   f_set_bit(&res,index+1,1);
//   // }

//   // printf("%d",res);

//   //  for(int i = 31 ; i >= 0 ; i--){   // show each bit of res
//   //     int bit = f_get_bit(res,i);
//   //     printf("%d",bit);
//   // }

//   return res;
// }

int s21_add(s21_decimal x, s21_decimal y, s21_decimal *res) {
  int error = 0;

  s21_zero_decimal(res);

  int carry = 0;
  (void)carry;
  int skip = 0;

  int sign1 = s21_get_sign(x);
  int sign2 = s21_get_sign(y);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(y);

  int flag_signed = 0;  // if res < 0
  int flag_mant_eq = 1;

  for (int i = 0; i < 96; i++) {  // -7 + 7 OR 7 + (-7)
    if (s21_get_bit(x, i) != s21_get_bit(y, i)) {
      flag_mant_eq = 0;
    }
  }

  if (flag_mant_eq && sign1 != sign2 && scale1 == scale2) {
    s21_zero_decimal(res);
  } else {
    s21_long_decimal value1 = {0};
    s21_long_decimal value2 = {0};
    s21_long_decimal total = {0};
    int scale = 0;
    int flag_max1 = 0;
    int flag_max2 = 0;

    if (x.bits[0] == UINT_MAX && x.bits[1] == UINT_MAX &&
        x.bits[2] == UINT_MAX && s21_is_decimal(y)) {
      flag_max1 = 1;
    }

    if (y.bits[0] == UINT_MAX && y.bits[1] == UINT_MAX &&
        y.bits[2] == UINT_MAX && s21_is_decimal(x)) {
      flag_max2 = 1;
    }

    s21_short_to_long_decimal(x, &value1);
    s21_short_to_long_decimal(y, &value2);

    int diff = scale1 - scale2;
    // int common_denominator = (diff > 0)? scale1 : scale2;

    if (flag_max1 && diff <= 0 && !scale1 && sign1 == sign2) {
      skip = 1;

      if (sign1 && sign2) {
        flag_signed = 1;
      }
    }

    if (flag_max2 && diff >= 0 && !scale2 && sign1 == sign2) {
      skip = 1;

      if (sign1 && sign2) {
        flag_signed = 1;
      }
    }

    if (!skip) {
      if (diff > 0) {
        s21_set_scale(&y, scale1);  // local y
      } else {
        s21_set_scale(&x, scale2);  // local x
      }

      s21_normalization(&value1, &value2, diff);  // common denominator

      if (sign1 == sign2) {  // if both are positive OR negative
        if (sign1) {         // IF BOTH ARE NEGATIVE
          s21_set_sign(res);
          flag_signed = 1;
        }

        s21_add_long(value1, value2, &total);

      } else {
        if (sign1) {
          if (s21_is_greater_long(
                  value1,
                  value2)) {  // if x < 0 AND NORM value1 > NORM value2 (-7 + 3)
            s21_sub_long(value1, value2, &total);
            s21_set_sign(res);
            flag_signed = 1;

          } else {
            s21_sub_long(
                value2, value1,
                &total);  // if x < 0 AND NORM value1 < NORM value2 (-3 + 7)
          }
        } else {
          if (s21_is_greater_long(value1, value2)) {  // 7 + (-3)
            s21_sub_long(value1, value2, &total);
          } else {  // 3 + (-7)
            s21_sub_long(value2, value1, &total);
            s21_set_sign(res);
            flag_signed = 1;
          }
        }
      }

      // now we need to find how much times we need to total/10 to make it fits
      // to our 95-bits decimal
      int set_scale = s21_get_scale(x);

      scale = s21_post_normalization(
          &total, set_scale);  // both scales are equal now(watch string №184)

      if (scale >= 0) {
        s21_long_to_short_decimal(total, res);
        s21_set_scale(res, scale);
        // res->bits[0] += 1;
      } else {
        error = 1;
      }
    }
  }

  if (error && flag_signed) {
    error = 2;
  }

  if (skip) error = 1;
  if (skip && flag_signed) error = 2;

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
  int flag_signed = 0;
  int skip = 0;
  int flag_max1 = 0;
  int flag_max2 = 0;

  s21_zero_decimal(res);

  if (x.bits[0] == UINT_MAX && x.bits[1] == UINT_MAX && x.bits[2] == UINT_MAX &&
      s21_is_decimal(y)) {
    flag_max1 = 1;
  }

  if (y.bits[0] == UINT_MAX && y.bits[1] == UINT_MAX && y.bits[2] == UINT_MAX &&
      s21_is_decimal(x)) {
    flag_max2 = 1;
  }

  if (flag_max1 && !scale1 && sign1 != sign2) {
    skip = 1;

    if (sign1) {
      flag_signed = 1;
    }
  }

  if (flag_max2 && !scale2 && sign1 != sign2) {
    skip = 1;

    if (sign1) {
      flag_signed = 1;
    }
  }

  if (!skip) {
    if (s21_is_equal(x, y) && sign1 == sign2) {  //-7 - (-7) OR 7 - 7
      s21_zero_decimal(res);
    } else {
      s21_long_decimal value1 = {0};
      s21_long_decimal value2 = {0};
      s21_long_decimal total = {0};

      s21_short_to_long_decimal(x, &value1);
      s21_short_to_long_decimal(y, &value2);

      int diff = scale1 - scale2;
      //  int common_denominator = (diff > 0)? scale1 : scale2;

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
          s21_set_sign(res);
          flag_signed = 1;
        }

        s21_sub_long(value1, value2, &total);
      }

      if (sign1 && sign2) {  //-7 - (-3) OR -3 - (-7)
        if (s21_is_greater_long(value1, value2)) {
          s21_sub_long(value1, value2, &total);
          s21_set_sign(res);
          flag_signed = 1;

        } else {
          s21_sub_long(value2, value1, &total);
        }
      }

      if (sign1 != sign2) {
        if (sign1) {  //-7 - 3 OR -3 - 7
          s21_add_long(value1, value2, &total);
          s21_set_sign(res);
          flag_signed = 1;

        } else {  // 7 - (-3) OR 3 - (-7)
          s21_add_long(value1, value2, &total);
        }
      }

      int set_scale = s21_get_scale(x);

      int scale = s21_post_normalization(
          &total, set_scale);  // both scales are equal now(watch string №265)

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

  if (skip) error = 1;
  if (skip && flag_signed) error = 2;

  if (error) s21_zero_decimal(res);

  return error;
}

void s21_sub_long(s21_long_decimal value1, s21_long_decimal value2,
                  s21_long_decimal *total) {
  // int bit1 = 0;
  // int bit2 = 0;
  // int z = 0;
  // int tmp = 0;

  // for(int i = 0; i < 256; i++){
  //   bit1 = s21_get_bit_long(value1,i);
  //   bit2 = s21_get_bit_long(value2,i);
  //   z = bit1 - bit2 - tmp;
  //   tmp = z < 0;
  //   z = abs(z);
  //   s21_set_bit_long(total,i,z % 2);
  // }

  for (int i = 0; i < 8; i++) {
    value2.bits[i] = ~value2.bits[i];
  }

  s21_long_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};

  s21_add_long(value2, one, &value2);

  s21_add_long(value1, value2, total);
}

// int s21_mul_int(int x, int y) {
//   int index_x;
//   int index_y;
//   for (int i = 31; i >= 0; i--) {
//     if (s21_f_get_bit(x, i)) {
//       index_x = i;
//       break;
//     }
//   }

//   for (int i = 31; i >= 0; i--) {
//     if (s21_f_get_bit(y, i)) {
//       index_y = i;
//       break;
//     }
//   }

//   int index = (index_x > index_y) ? index_x : index_y;

//   int bit_y = 0;
//   int bit_x = 0;

//   int tmp[index];

//   for (int i = 0; i <= index; i++) {
//     for (int j = 0; j <= 31; j++) {
//       s21_f_set_bit(&tmp[i], j, 0);  // make tmp[] = {0};
//     }
//   }

//   for (int i = 0; i <= index; i++) {
//     bit_y = s21_f_get_bit(y, i);

//     for (int j = 0; j <= index; j++) {
//       bit_x = s21_f_get_bit(x, j);

//       if (!bit_x || !bit_y) {
//         s21_f_set_bit(&tmp[i], j, 0);
//       } else {
//         s21_f_set_bit(&tmp[i], j, 1);
//       }
//     }
//   }

//   for (int i = 0; i <= index; i++) {
//     tmp[i] = tmp[i] << i;
//   }

//   //  for(int i = 31 ; i >= 0 ; i--){   // show each bit of res
//   //       int bit = f_get_bit(tmp[1],i);
//   //       printf("%d ",bit);
//   //   }

//   int res = 0;
//   int carry = 0;

//   for (int i = 0; i <= index; i++) {
//     res = s21_add_int(res, tmp[i], &carry);
//   }

//   return res;
// }

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

  if (!s21_is_decimal(x) && !s21_is_decimal(y)) {
    error = 3;
  } else if (s21_is_decimal(x)) {  // 0/any value = 0
    if (s21_is_decimal(y)) {
      int scale, res_scale = 0;

      s21_long_decimal value1 = {0}, value2 = {0}, total = {0};
      s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};

      int scale1 = s21_get_scale(x);
      int scale2 = s21_get_scale(y);
      (void)scale1;
      (void)scale2;
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

  int limit = 58;  // limit calculation ability of for

  if (value1.bits[1] || value1.bits[2] || value2.bits[1] || value2.bits[2]) {
    limit = 96;
  }
  (void)limit;

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

    // int result = 0;
    // s21_decimal res = {0};
    // s21_long_to_short_decimal(*total,&res);
    // s21_from_decimal_to_int(res,&result);
    // printf("%d\n",result);

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
    // s21_long_decimal ten = {{10,0,0,0,0,0,0,0}};
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

// s21_long_decimal division(s21_long_decimal value1, s21_long_decimal value2,
//                           s21_long_decimal *remainder) {
//   s21_long_decimal result = {0};
//   s21_long_decimal partial_remainder = {0};
//   s21_long_decimal quotinent = {0};

//   if (s21_is_greater_long(value2, value1)) {  // 3/5
//     partial_remainder = value1;
//   } else {
//     // FIND SHIFT

//     int left1 = 0;  // index of the last significant bit that equals 1
//     int left2 = 0;

//     for (int i = 255; i >= 0; i--) {
//       if (s21_get_bit_long(value1, i)) {
//         left1 = i;
//         break;
//       }
//     }

//     for (int i = 255; i >= 0; i--) {
//       if (s21_get_bit_long(value2, i)) {
//         left2 = i;
//         break;
//       }
//     }

//     int shift = left1 - left2;  // ALWAYS > 0 because we have already
//     compared
//                                 // if value2 > value1

//     // SHIFT THE DIVISOR(value2)

//     s21_long_decimal shifted_divisor = value2;
//     s21_shift_long_left(&shifted_divisor, shift);

//     // FIND QUOTINENT AND PARTIAL_REMAINDER

//     s21_long_decimal dividend = value1;

//     int need_substraction = 1;  // it's nessesary initially

//     while (shift >= 0) {
//       if (need_substraction == 1) {
//         s21_sub_long(dividend, shifted_divisor, &partial_remainder);
//       } else {
//         s21_add_long(dividend, shifted_divisor, &partial_remainder);
//       }

//       s21_shift_long_left(&quotinent, 1);

//       if (!(s21_get_bit_long(partial_remainder, 255))) {
//         s21_set_bit_long(&quotinent, 0, 1);
//       }

//       dividend = partial_remainder;

//       s21_shift_long_left(&dividend, 1);

//       if (!(s21_get_bit_long(partial_remainder, 255))) {
//         need_substraction = 1;
//       } else {
//         need_substraction = 0;
//       }

//       --shift;
//     }

//     if (s21_get_bit_long(partial_remainder, 255)) {
//       s21_add_long(partial_remainder, shifted_divisor, &partial_remainder);
//     }

//     s21_shift_long_right(&partial_remainder, left1 - left2);
//   }

//   result = quotinent;
//   (void)remainder;

//   return result;
// }

// int s21_division_post_normalization(s21_long_decimal *res,s21_long_decimal
// *value2,s21_long_decimal *remainder){
//   /*  62/16
//       res = 3 , remainder = 14
//       1:14 * 10 = 140 /16 = 8 (12)  3*10 + 8 = 38
//       2:12 * 10 = 120 / 16 = 7 (8)  38*10 + 7 = 387
//       3:8 *  10 = 80/16 = 5 (0)  387*10 + 5 = 3875

//       power = 3;

//       res = 3875 / 10^3 (3.875)
//       remainder = 0

//       59/15

//       res = 3, remainder = 14

//       1:14 * 10 = 140/15 = 9(5) 3*10 + 9  = 39
//       2:5  * 10 = 50/15  = 3(5) 39*10 + 3 = 393
//       3:5  * 10 = 50/15  = 3(5) 393*10 + 3 = 3933
//       4:5  * 10 = 50/15  = 3(5) 3933*10 + 3 = 39333
//       .....
//       28:5 * 10 = 50/15  = 3(5) 3933333333333333333333333333333333

//       power 28;

//       res = 3933333333333333333333333333333333
//       remainder = 5

//       */
//      int power = 0;
//      s21_long_decimal num = {0};
//      s21_long_decimal ten = {10,0,0,0,0,0,0,0};

//      while(power < 28 && !s21_equals_zero_long(*remainder)){
//         s21_mul_long(*remainder,ten,remainder);//14 * 10 = 140
//         num = division(*remainder,*value2,remainder); //140/16 -> num =
//         8,remainder = 12 s21_mul_long(*res,ten,res);//res = 3*10
//         s21_add_long(*res,num,res);// res = 38
//         power++;
//       }

//       return power;
// }

// s21_decimal s21_abs(s21_decimal num){
//   s21_decimal res = num;
//   s21_set_bit(&res,127,0);

//   return res;
// }

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
  int flag = 0;
  s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int remainder = 0;

  while ((res->bits[3] || res->bits[4] || res->bits[5] || res->bits[6] ||
          res->bits[7]) &&
         scale > 0) {  //

    s21_div_long_int(*res, ten, res, &remainder);

    if (res->bits[3] && scale == 1) {
      flag = 1;
    }

    scale--;  // because 314/10^2 == 31/10 each time we make res/10 we need to
              // make scale--(10^x x--) OR x/10^5 : 1/10 == 10x/10^5 == x/10^4
  }

  // printf("%d\n",remainder);

  // if (flag && scale == 0 && res->bits[3] == 0 &&
  //     s21_get_bit_long(*res, 0)) {  // making res = res - 1
  //   s21_set_bit_long(res, 0, 0);
  // }
  (void)flag;
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

// void s21_increase_scale_long_decimal(s21_long_decimal *dst, int n) {
//   s21_long_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}}, tmp = {0};
//   for (int i = 0; i < n; i++) {
//     s21_mul_long(*dst, ten, &tmp);
//     *dst = tmp;
//     s21_zero_long(&tmp);
//   }
// }