#include "s21_math_test.h"

START_TEST(ceil_test1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil_test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil_test3) {
  double x = S21_NEGZERO;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(ceil_test4) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(ceil_test5) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
}
END_TEST

START_TEST(ceil_test6) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_ceil(x));
}
END_TEST

START_TEST(ceil_test7) {
  double x = 4.7;
  ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), 6);
}
END_TEST

START_TEST(s21_ceil_test8) {
  ck_assert_double_eq_tol(s21_ceil(-0.1), ceil(-0.1), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test9) {
  ck_assert_double_eq_tol(s21_ceil(-213.3), ceil(-213.3), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test10) {
  ck_assert_double_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(s21_ceil_test11) {
  ck_assert_double_nan(s21_ceil(NAN));
  ck_assert_double_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_ceil_test12) {
  ck_assert_double_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(s21_ceil_test13) {
  ck_assert_double_eq_tol(s21_ceil(50), ceil(50), 0.000001);
}
END_TEST

START_TEST(test_inf) {
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  ck_assert_ldouble_infinite(ceil(S21_INF));
}
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_nan(ceil(S21_NAN));
}
END_TEST

START_TEST(test_y_zero) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(test_x_inf_y_zero) {
  double x = 8743517471375471154.34143134134134;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  ck_assert_ldouble_eq(s21_ceil(-x), ceil(-x));
}

START_TEST(test_zero) { ck_assert_ldouble_eq(ceil(0), s21_ceil(0)); }
END_TEST

START_TEST(test_neg) { ck_assert_ldouble_eq(ceil(-1234), s21_ceil(-1234)); }
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(ceil(1234), s21_ceil(1234)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(ceil(1), s21_ceil(1)); }
END_TEST

START_TEST(test_normal) { ck_assert_ldouble_eq(ceil(1.7), s21_ceil(1.7)); }
END_TEST

START_TEST(test_normal_negative) {
  ck_assert_int_eq(ceil(-1.7), s21_ceil(-1.7));
}
END_TEST

START_TEST(test_normal_above_1) {
  ck_assert_ldouble_eq(ceil(14.7), s21_ceil(14.7));
}
END_TEST
START_TEST(test_lesser_than_1) {
  ck_assert_ldouble_eq(ceil(0.7), s21_ceil(0.7));
}
END_TEST
START_TEST(test_positive_inf) {
  ck_assert_ldouble_eq(ceil(S21_INF), s21_ceil(S21_INF));
}
END_TEST
START_TEST(test_negative_inf) {
  ck_assert_ldouble_eq(ceil(-S21_INF), s21_ceil(-S21_INF));
}
END_TEST

START_TEST(test_dbl_min) {
  ck_assert_ldouble_eq(ceil(DBL_MIN), s21_ceil(DBL_MIN));
}
END_TEST

START_TEST(test_dbl_max) {
  ck_assert_ldouble_eq(ceil(DBL_MAX), s21_ceil(DBL_MAX));
}
END_TEST

START_TEST(test_tolerance_loop) {
  ck_assert_ldouble_eq_tol(ceil(0.1 * _i), s21_ceil(0.1 * _i), DBL_EPSILON);
}
END_TEST

Suite *suite_ceil(void) {
  Suite *s = suite_create("suite_ceil");
  TCase *tc = tcase_create("ceil_tc");

  tcase_add_test(tc, ceil_test1);
  tcase_add_test(tc, ceil_test2);
  tcase_add_test(tc, ceil_test3);
  tcase_add_test(tc, ceil_test4);
  tcase_add_test(tc, ceil_test5);
  tcase_add_test(tc, ceil_test6);
  tcase_add_test(tc, ceil_test7);
  tcase_add_test(tc, s21_ceil_test8);
  tcase_add_test(tc, s21_ceil_test9);
  tcase_add_test(tc, s21_ceil_test10);
  tcase_add_test(tc, s21_ceil_test11);
  tcase_add_test(tc, s21_ceil_test12);
  tcase_add_test(tc, s21_ceil_test13);
  tcase_add_test(tc, test_inf);
  tcase_add_test(tc, test_nan);
  tcase_add_test(tc, test_y_zero);
  tcase_add_test(tc, test_x_inf_y_zero);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_normal_negative);
  tcase_add_test(tc, test_normal_above_1);
  tcase_add_test(tc, test_negative_inf);
  tcase_add_test(tc, test_lesser_than_1);
  tcase_add_test(tc, test_positive_inf);
  tcase_add_test(tc, test_dbl_min);
  tcase_add_test(tc, test_dbl_max);
  tcase_add_loop_test(tc, test_tolerance_loop, -100, 101);

  suite_add_tcase(s, tc);
  return s;
}