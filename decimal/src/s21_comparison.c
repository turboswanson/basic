#include "s21_decimal.h"

int s21_is_greater(s21_decimal x, s21_decimal y) {
  int res = 0;
  int sign1 = s21_get_sign(x);
  int sign2 = s21_get_sign(y);
  s21_long_decimal value1 = {0};
  s21_long_decimal value2 = {0};

  if(s21_is_equal(x,y)){
    res = 0;
  }else if(!s21_is_decimal(x) && !s21_is_decimal(y)){
    res = 0;
  }else if (sign1 && !sign2) {  
    res = 0;
  } else if (!sign1 && sign2) {  
    res = 1;
  } else {
    s21_short_to_long_decimal(x, &value1);
    s21_short_to_long_decimal(y, &value2);

    int scale1 = s21_get_scale(x);
    int scale2 = s21_get_scale(y);

    int diff = scale1 - scale2;

    s21_normalization(&value1, &value2, diff);
    res = s21_is_greater_long(value1, value2);

    if (sign1 && sign2) {
      if (res) {
          res = 0;
      } else {
          res = 1;
      }
    } 
  }

  return res;
}

int s21_is_equal(s21_decimal x, s21_decimal y) {
  int flag = 1;

  s21_long_decimal value1 = {0};
  s21_long_decimal value2 = {0};

  s21_short_to_long_decimal(x, &value1);
  s21_short_to_long_decimal(y, &value2);

  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(y);

  int diff = scale1 - scale2;

  s21_normalization(&value1, &value2, diff);

  for (int i = 0; i < 256; i++) {
    if (s21_get_bit_long(value1, i) != s21_get_bit_long(value2, i)) {
      flag = 0;
      i = 256;
    }
  }

  if (s21_get_sign(x) != s21_get_sign(y) &&
      (!s21_equals_zero(x) || !s21_equals_zero(y)))
    flag = 0;

 return flag;
}


int s21_is_not_equal(s21_decimal x, s21_decimal y) {
  int res = 1;

  if (s21_is_equal(x, y)) {
    res = 0;
  }

  return res;
}

int s21_is_equal_long(s21_long_decimal x, s21_long_decimal y) {
  int flag = 1;

  for (int i = 0; i < 256; i++) {
    if (s21_get_bit_long(x, i) != s21_get_bit_long(y, i)) {
      flag = 0;
      i = 256;
    }
  }

  return flag;
}

int s21_is_greater_long(s21_long_decimal x, s21_long_decimal y) {
  int bit1 = 0;
  int bit2 = 0;
  int flag = 0;

  for (int i = 255; i >= 0; i--) {
    bit1 = s21_get_bit_long(x, i);
    bit2 = s21_get_bit_long(y, i);

    if (bit1 && !bit2) {
      flag = 1;
      i = -1;
    }

    if (!bit1 && bit2) {
      i = -1;
    }
  }

  return flag;
}

int s21_equals_zero_long(s21_long_decimal x) {
  int flag = 1;

  for (int i = 0; i < 256; i++) {
    if (s21_get_bit_long(x, i)) {
      flag = 0;
    }
  }

  return flag;
}

int s21_equals_zero(s21_decimal x) {
  int flag = 1;

  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(x, i)) {
      flag = 0;
    }
  }

  return flag;
}

int s21_is_greater_or_equal(s21_decimal x, s21_decimal y) {
  int res = 0;

  if (s21_is_equal(x, y) || s21_is_greater(x, y)) {
    res = 1;
  }

  return res;
}

int s21_is_greater_or_equal_long(s21_long_decimal x, s21_long_decimal y) {
  int res = 0;

  if (s21_is_equal_long(x, y) || s21_is_greater_long(x, y)) {
    res = 1;
  }

  return res;
}

int s21_is_less(s21_decimal x, s21_decimal y) {
  int res = 0;

  if (!s21_is_greater_or_equal(x, y)) {
    res = 1;
  }

  return res;
}

int s21_is_less_or_equal(s21_decimal x, s21_decimal y) {
  int res = 0;

  if (s21_is_equal(x, y) || s21_is_less(x, y)) {
    res = 1;
  }

  return res;
}

