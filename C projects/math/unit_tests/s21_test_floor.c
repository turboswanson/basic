#include "s21_math_test.h"
START_TEST(floor_test1) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test2) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test3) {
  double x = S21_NEGZERO;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test4) {
  double x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_test5) {
  double x = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
}
END_TEST

START_TEST(floor_test6) {
  double x = NAN;
  ck_assert_ldouble_nan(s21_floor(x));
}
END_TEST

START_TEST(floor_test7) {
  double x = -4.7;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test8) {
  double x = 4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test9) {
  double x = 4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test10) {
  double x = -4.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST

START_TEST(floor_test11) {
  double x = -4732323456789076.5;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST
START_TEST(test_zero) { ck_assert_ldouble_eq(floor(0), s21_floor(0)); }
END_TEST

START_TEST(test_neg) { ck_assert_ldouble_eq(floor(-1234), s21_floor(-1234)); }
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(floor(1234), s21_floor(1234)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(ceil(1), s21_ceil(1)); }
END_TEST

START_TEST(test_normal) { ck_assert_ldouble_eq(floor(1.7), s21_floor(1.7)); }
END_TEST

START_TEST(test_normal_negative) {
  ck_assert_int_eq(floor(-1.7), s21_floor(-1.7));
}
END_TEST

START_TEST(test_normal_negative_1) {
  ck_assert_int_eq(floor(-0.7), s21_floor(-0.7));
}
END_TEST

START_TEST(test_normal_above_1) {
  ck_assert_ldouble_eq(floor(14.7), s21_floor(14.7));
}
END_TEST
START_TEST(test_lesser_than_1) {
  ck_assert_ldouble_eq(floor(0.7), s21_floor(0.7));
}
END_TEST
START_TEST(test_positive_inf) {
  ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
}
END_TEST
START_TEST(test_negative_inf) {
  ck_assert_ldouble_eq(floor(-S21_INF), s21_floor(-S21_INF));
}
END_TEST

START_TEST(test_nan) { ck_assert_ldouble_nan(s21_floor(S21_NAN)); }
END_TEST

START_TEST(test_high_accuracy) {
  ck_assert_ldouble_eq(floor(0.123456907912345), s21_floor(0.123456907912345));
}
END_TEST

START_TEST(test_tolerance_loop) {
  ck_assert_ldouble_eq_tol(ceil(0.1 * _i), s21_ceil(0.1 * _i), DBL_EPSILON);
  ck_assert_ldouble_eq_tol(ceil(-0.1 * _i), s21_ceil(-0.1 * _i), DBL_EPSILON);
}
END_TEST

START_TEST(s21_floor_test) {
  ck_assert_ldouble_eq(floor(-100.97), s21_floor(-100.97));
  ck_assert_ldouble_eq(floor(-11.2), s21_floor(-11.2));
  ck_assert_ldouble_eq(floor(-0.1112), s21_floor(-0.1112));
  ck_assert_ldouble_eq(floor(0), s21_floor(0));
  ck_assert_ldouble_eq(floor(0.0), s21_floor(0.0));
  ck_assert_ldouble_eq(floor(0.00001), s21_floor(0.00001));
  ck_assert_ldouble_eq(floor(21.1567), s21_floor(21.1567));
  ck_assert_ldouble_eq(floor(34.999), s21_floor(34.999));

  ck_assert_ldouble_infinite(floor(INFINITY));
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(floor(-INFINITY));
  ck_assert_ldouble_infinite(s21_floor(-INFINITY));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_nan(s21_floor(-NAN));
  ck_assert_ldouble_nan(floor(-NAN));
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, floor_test1);
  tcase_add_test(tc, floor_test2);
  tcase_add_test(tc, floor_test3);
  tcase_add_test(tc, floor_test4);
  tcase_add_test(tc, floor_test5);
  tcase_add_test(tc, floor_test6);
  tcase_add_test(tc, floor_test7);
  tcase_add_test(tc, floor_test8);
  tcase_add_test(tc, floor_test9);
  tcase_add_test(tc, floor_test10);
  tcase_add_test(tc, floor_test11);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_normal_negative);
  tcase_add_test(tc, test_normal_negative_1);
  tcase_add_test(tc, test_normal_above_1);
  tcase_add_test(tc, test_negative_inf);
  tcase_add_test(tc, test_lesser_than_1);
  tcase_add_test(tc, test_positive_inf);
  tcase_add_test(tc, test_nan);
  tcase_add_loop_test(tc, test_tolerance_loop, -100, 101);
  tcase_add_test(tc, test_high_accuracy);
  tcase_add_test(tc, s21_floor_test);
  suite_add_tcase(s, tc);
  return s;
}