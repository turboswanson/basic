#include "s21_decimal_test.h"

void floor_test_function(float n, float accuracy) {
  s21_decimal var1 = {0}, var2 = {0};
  float value1 = 0, value2 = 0;
  s21_from_float_to_decimal(n, &var1);
  s21_floor(var1, &var2);
  s21_from_decimal_to_float(var2, &value2);
  value1 = floorf(n);
  ck_assert_float_eq_tol(value1, value2, accuracy);
}

START_TEST(floor_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(floor_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

// START_TEST(floor_4) {
//   float n = s21_rand_r(-8388608, 8388608);
//   floor_test_function(n, 10);
// }

START_TEST(floor_5) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_set_scale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(floor_6) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_set_scale(&value_1, 5);
  s21_set_sign(&value_1);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_set_sign(&check);
  s21_decimal result = {0};
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(floor_7) {
  s21_decimal src1;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal res_od = {0};
  s21_floor(src1, &res_od);
  s21_decimal result = {0};
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_test_wtf_1) {
  s21_decimal src1, res;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b00000000000010100000000000000000;
  s21_floor(src1, &res);
  s21_decimal result;
  result.bits[0] = 0b10100111011000111111111111111111;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res.bits[0], result.bits[0]);
  ck_assert_float_eq(res.bits[1], result.bits[1]);
  ck_assert_float_eq(res.bits[2], result.bits[2]);
  ck_assert_float_eq(res.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_test_wtf_2) {
  s21_decimal src1, res;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b10000000000010100000000000000000;
  s21_floor(src1, &res);
  s21_decimal result;
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res.bits[0], result.bits[0]);
  ck_assert_float_eq(res.bits[1], result.bits[1]);
  ck_assert_float_eq(res.bits[2], result.bits[2]);
  ck_assert_float_eq(res.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_test_wtf_3) {
  s21_decimal src1 = {{123456, 0, 0, (3 << 16) + 0x80000000}}, res;
  float a = 123.45;
  float b = floor(-123.456);
  s21_floor(src1, &res);
  s21_from_decimal_to_float(res, &a);
  ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(s21_floor_test_wtf_4) {
  s21_decimal src1, res;
  src1.bits[0] = 0b10010011111100000001110001010010;
  src1.bits[1] = 0b00000000000000000000000100100000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000010100000000000000000;
  s21_floor(src1, &res);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000001111011;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res.bits[0], result.bits[0]);
  ck_assert_float_eq(res.bits[1], result.bits[1]);
  ck_assert_float_eq(res.bits[2], result.bits[2]);
  ck_assert_float_eq(res.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_test_wtf_5) {
  s21_decimal src1, res;
  src1.bits[0] = 0b01010101001110101110101110110001;
  src1.bits[1] = 0b00001101101101001101101001011111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  s21_floor(src1, &res);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res.bits[0], result.bits[0]);
  ck_assert_float_eq(res.bits[1], result.bits[1]);
  ck_assert_float_eq(res.bits[2], result.bits[2]);
  ck_assert_float_eq(res.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_test_wtf_6) {
  s21_decimal src1, res;
  src1.bits[0] = 0b01010101001110101110101110110001;
  src1.bits[1] = 0b00001101101101001101101001011111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000100100000000000000000;
  s21_floor(src1, &res);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res.bits[0], result.bits[0]);
  ck_assert_float_eq(res.bits[1], result.bits[1]);
  ck_assert_float_eq(res.bits[2], result.bits[2]);
  ck_assert_float_eq(res.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_floor) {
  float arg1[] = {17.1, -3.14,     -787878.0, 78.14, 955.189, -1.155,
                  4.0,  -234.9144, 0.123755,  0.025, 15.141,  847.599,
                  2.1,  155.1,     -234.9144, 0.000};

  float arg2[] = {17.0, -4.0, -787878.0, 78.0,  955.0, -2.0,  4.0,    -235.0,
                  0.0,  0.0,  15.0,      847.0, 2.0,   155.0, -235.0, 0.0};

  s21_decimal src1, result;
  s21_from_float_to_decimal(arg1[_i], &src1);
  s21_floor(src1, &result);
  float s21_dst, s21_src;
  s21_from_decimal_to_float(src1, &s21_src);
  s21_from_decimal_to_float(result, &s21_dst);
  ck_assert_float_eq(s21_dst, arg2[_i]);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("case_floor");

  tcase_add_test(tc, floor_0);
  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  // tcase_add_loop_test(tc, floor_4, 0, 1000);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);
  tcase_add_test(tc, s21_floor_test_wtf_1);
  tcase_add_test(tc, s21_floor_test_wtf_2);
  tcase_add_test(tc, s21_floor_test_wtf_3);
  tcase_add_test(tc, s21_floor_test_wtf_4);
  tcase_add_test(tc, s21_floor_test_wtf_5);
  tcase_add_test(tc, s21_floor_test_wtf_6);
  tcase_add_test(tc, test_floor);

  suite_add_tcase(s, tc);
  return s;
}