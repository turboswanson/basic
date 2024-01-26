#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;

  if (result == NULL) {
    error = 1;
  } else {
    *result = value;

    if (s21_get_sign(value)) {
      s21_set_bit(result, 127, 0);
    } else {
      s21_set_sign(result);
    }
  }

  return error;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;

  if (result == NULL) {
    error = 1;

  } else {
    s21_zero_decimal(result);

    int scale = s21_get_scale(value);
    int sign = s21_get_sign(value);

    s21_long_decimal tmp = {0};

    s21_short_to_long_decimal(value, &tmp);

    s21_long_decimal ten = {{10, 0, 0, 0}};
    int remainder = 0;

    for (int i = 0; i < scale; i++) {
      s21_div_long_int(tmp, ten, &tmp, &remainder);

      if (tmp.bits[0] < 10 && (scale - i) > 1) {
        s21_zero_long(&tmp);
        break;
      }
    }

    s21_long_to_short_decimal(tmp, result);

    if (sign) {
      s21_set_sign(result);
    }

    if (scale) {
      s21_set_scale(result, 0);
    }
  }

  return error;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0;
  // 3.5 -> 4.0  -3.5 -> -4.0
  if (result == NULL) {
    error = 1;

  } else {
    s21_zero_decimal(result);

    int sign = s21_get_sign(value);

    s21_decimal unsigned_value = value;
    if (sign) s21_set_bit(&unsigned_value, 127, 0);

    s21_decimal truncated = {0};

    s21_truncate(unsigned_value, &truncated);

    s21_decimal fract = {0};

    s21_sub(unsigned_value, truncated, &fract);

    s21_decimal zero_five = {{5, 0, 0, 0}};
    s21_set_scale(&zero_five, 1);

    s21_decimal one = {{1, 0, 0, 0}};

    if (s21_is_greater_or_equal(fract, zero_five)) {
      s21_add(truncated, one, result);
    } else {
      *result = truncated;
    }

    if (sign) s21_set_sign(result);

  }

  return error;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  // 3.8 -> 3.0
  //-3.8 -> 4.0
  int error = 0;

  if (result == NULL) {
    error = 1;
  } else {

    s21_zero_decimal(result);
    s21_truncate(value, result);
    s21_decimal one = {{1, 0, 0, 0}};

    if (s21_get_sign(value) && !s21_is_equal(*result, value)) {
      s21_sub(*result, one, result);
    }
  }

  return error;
}

float s21_rand_r(float a, float b) {
  float m = (float)rand() / RAND_MAX;
  float num = a + m * (b - a);
  return num;
}