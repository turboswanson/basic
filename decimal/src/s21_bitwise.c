#include "s21_decimal.h"

int s21_f_get_bit(int num, int index) {
  int mask = 1u << (index % 32);

  return (num & mask) != 0;
}

void s21_f_set_bit(int *res, int index, int bit) {
  int mask = 1 << (index % 32);

  if (bit == 0) {
    *res = *res & ~mask;
  } else
    *res = *res | mask;
}

int s21_get_bit(s21_decimal src, int index) {
  int mask =
      1u << (index % 32);  // each src.bits[0-3] consist of 31 bits so to move 1
                           // to a specific index we need to do % operation

  return (src.bits[index / 32] & mask) != 0;

  /*comparing the whole including index src.bits[] with a mask e.g
     0000000100000000 0000001000000000

     0 & 1 -> 0
     1 & 1 -> 1
     1 & 0 -> 0
  */
}

int s21_get_scale(s21_decimal src) {
  int mask = 127 << 16;

  /*
  127 == 00000000000000000000000001111111

  127 << 16 == 00000000000000001111111100000000


  */
  int scale = (mask & src.bits[3]) >> 16;

  return scale;
}

int s21_get_sign(s21_decimal src) { return (src.bits[3] & 1u << 31) != 0; }

void s21_set_bit(
    s21_decimal *dst, int index,
    int bit) {  // dst->bits[0-2],index of element we need to set, 0 or 1
  int mask = 1u << (index % 32);

  if (bit == 0) {
    dst->bits[index / 32] = dst->bits[index / 32] & ~mask;
  }

  /* mask = 00001000000

  to make a specific bit == 0 we need to & it with 0 ( 0 & 0 == 0, 1 & 0 )

  so we need to ~mask ---> 111111111011111111
  */
  else {
    dst->bits[index / 32] = dst->bits[index / 32] | mask;
  }

  /*
  0 | 1 == 1
  1 | 1 == 1
  0 | 0 == 0
  */
}

void s21_set_scale(s21_decimal *dst, int scale) {
  int sign = 0;
  sign = s21_get_sign(*dst);  // now we know if there was a sign in dst->bits[3]
                              // or not before we make it 0

  dst->bits[3] = 0;

  scale <<= 16;  // set scale index

  dst->bits[3] = scale | dst->bits[3];  // merging

  if (sign) s21_set_sign(dst);
}

void s21_set_sign(s21_decimal *dst) { dst->bits[3] = dst->bits[3] | 1u << 31; }

int s21_shift_decimal_left(s21_decimal *dst, int num) {
  int buf[3] = {0};
  int error = 0;

  for (int i = 0; i < num; i++) {
    for (int j = 0; j < 2; j++) {
      buf[j] = s21_get_bit(
          *dst, (j + 1) * 32 - 1);  // save the last bit of each bits (31,63)
    }

    for (int k = 2; k > 0 && !error; k--) {
      if (s21_get_bit(*dst, 95))
        error = 1;  // if the most signficant bit of mantissa = 1 there is NO
                    // WAY to make it left-shifted
      dst->bits[k] <<= 1;
      s21_set_bit(dst, k * 32, buf[k - 1]);  // set them to the first position
                                             // of each bits ( to 32,63)
    }
    dst->bits[0] <<= 1;
  }

  return error;
}

int s21_shift_long_left(s21_long_decimal *dst, int num) {
  int buf[8] = {0};
  int error = 0;

  for (int i = 0; i < num; i++) {
    for (int j = 0; j < 7; j++) {
      buf[j] = s21_get_bit_long(
          *dst,
          (j + 1) * 32 - 1);  // save the last bit of each bits (31,63,95,127)
    }

    for (int k = 7; k > 0 && !error; k--) {
      if (s21_get_bit_long(*dst, 255))
        error = 1;  // if the most signficant bit of mantissa = 1 there is NO
                    // WAY to make it left-shifted
      dst->bits[k] <<= 1;
      s21_set_bit_long(dst, k * 32,
                       buf[k - 1]);  // set them to the first position of each
                                     // bits ( to 32,63)
    }
    dst->bits[0] <<= 1;
  }

  return error;
}

int s21_shift_decimal_right(s21_decimal *dst, int num) {
  int error = 0;

  int buffer[3] = {0};

  for (int k = 0; k < num; k++) {
    for (int i = 0; i < 2; i++) {
      buffer[i] = s21_get_bit(*dst, (i + 1) * 32);
    }
    for (int i = 0; i < 2; i++) {
      dst->bits[i] >>= 1;
      s21_set_bit(dst, (i + 1) * 32 - 1, buffer[i]);
    }
    dst->bits[2] >>= 1;
  }

  return error;
}

int s21_shift_long_right(s21_long_decimal *dst, int num) {
  int buffer[7] = {0};
  int error = 0;

  for (int k = 0; k < num; k++) {
    for (int i = 0; i < 7; i++) {
      buffer[i] = s21_get_bit_long(*dst, (i + 1) * 32);
    }
    for (int i = 0; i < 7; i++) {
      dst->bits[i] >>= 1;
      s21_set_bit_long(dst, (i + 1) * 32 - 1, buffer[i]);
    }
    dst->bits[7] >>= 1;
  }

  return error;
}

void s21_short_to_long_decimal(s21_decimal src, s21_long_decimal *dst) {
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }
}

void s21_long_to_short_decimal(s21_long_decimal src, s21_decimal *dst) {
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = src.bits[i];
  }
}

int s21_get_bit_long(s21_long_decimal src, int index) {
  int mask = 1u << (index % 32);

  return (src.bits[index / 32] & mask) != 0;
}

void s21_set_bit_long(s21_long_decimal *dst, int index, int bit) {
  int mask = 1u << (index % 32);

  if (bit == 0) {
    dst->bits[index / 32] = dst->bits[index / 32] & ~mask;
  }

  /* mask = 00001000000

  to make a specific bit == 0 we need to & it with 0 ( 0 & 0 == 0, 1 & 0 )

  so we need to ~mask ---> 111111111011111111
  */
  else {
    dst->bits[index / 32] = dst->bits[index / 32] | mask;
  }
}

int s21_is_decimal(s21_decimal dst) {
  return dst.bits[0] + dst.bits[1] + dst.bits[2];
}

int s21_is_long_decimal(s21_long_decimal dst) {
  return dst.bits[0] + dst.bits[1] + dst.bits[2] + dst.bits[3] + dst.bits[4] +
         dst.bits[5] + dst.bits[6] + dst.bits[7];
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