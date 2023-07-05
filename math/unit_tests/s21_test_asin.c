#include "s21_math_test.h"

START_TEST(test_asin_positive) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_negative) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_zero) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_one) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_one_negative) {
  double x = -1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_huge_positive) {
  double x = 5;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_huge_negative) {
  double x = -5;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_big_mantissa) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_eps_positive) {
  double x = 1 + 1e-16;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_eps_negative) {
  double x = -1 - 1e-16;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_inf) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_circle_nan) {
  int i = _i;
  ck_assert_ldouble_nan(asin(i));
  ck_assert_ldouble_nan(s21_asin(i));
  // ck_assert_ldouble_eq_tol(asin(1.0 / i), s21_asin(1.0 / i), 1e-6);
  // ck_assert_ldouble_eq_tol(asin(1.0 / i / i), s21_asin(1.0 / i / i), 1e-6);
  // ck_assert_ldouble_eq_tol(asin(1.0 / i / i / i), s21_asin(1.0 / i / i / i),
  //                          1e-6);
  // ck_assert_ldouble_eq_tol(asin(-1.0 / i), s21_asin(-1.0 / i), 1e-6);
  // ck_assert_ldouble_eq_tol(asin(-1.0 / i / i), s21_asin(-1.0 / i / i), 1e-6);
  // ck_assert_ldouble_eq_tol(asin(-1.0 / i / i / i), s21_asin(-1.0 / i / i /
  // i),
  //                          1e-6);
}
END_TEST

START_TEST(test_circle) {
  int i = _i;
  ck_assert_ldouble_eq_tol(asin(i), s21_asin(i), 1e-6);
}
END_TEST

START_TEST(s21_asin_test) {
  ck_assert_ldouble_eq_tol(asin(-1.0), s21_asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-0.5), s21_asin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-0.1), s21_asin(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-sqrt(3) / 3), s21_asin(-sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-sqrt(3) / 2), s21_asin(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(-sqrt(2) / 2), s21_asin(-sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0.0), s21_asin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0.1), s21_asin(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(asin(0.5), s21_asin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(asin(sqrt(3) / 3), s21_asin(sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(asin(sqrt(3) / 2), s21_asin(sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(sqrt(2) / 2), s21_asin(sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(asin(1.0), s21_asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(asin(4.2658365e-9), s21_asin(4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(asin(S21_PI / 4), s21_asin(S21_PI / 4), 1e-6);
  // ck_assert_ldouble_nan(asin(S21_PI));
  ck_assert_ldouble_nan(s21_asin(S21_PI));
  ck_assert_ldouble_nan(asin(sqrt(3)));
  ck_assert_ldouble_nan(s21_asin(sqrt(3)));
  // ck_assert_ldouble_nan(asin(-5));
  ck_assert_ldouble_nan(s21_asin(-5));
  // ck_assert_ldouble_nan(asin(5));
  // ck_assert_ldouble_nan(s21_asin(5));
  ck_assert_ldouble_nan(asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(NAN));
  ck_assert_ldouble_nan(s21_asin(NAN));
}
END_TEST

Suite *suite_asin(void) {
  Suite *s = suite_create("suite_asin");
  TCase *tc = tcase_create("asin_tc");

  tcase_add_test(tc, test_asin_positive);
  tcase_add_test(tc, test_asin_negative);
  tcase_add_test(tc, test_asin_zero);
  tcase_add_test(tc, test_asin_one);
  tcase_add_test(tc, test_asin_negative);
  tcase_add_test(tc, test_asin_one_negative);
  tcase_add_test(tc, test_asin_huge_positive);
  tcase_add_test(tc, test_asin_huge_negative);
  tcase_add_test(tc, test_asin_big_mantissa);
  tcase_add_test(tc, test_asin_eps_positive);
  tcase_add_test(tc, test_asin_eps_negative);
  tcase_add_test(tc, test_asin_nan);
  tcase_add_test(tc, test_asin_inf);
  tcase_add_test(tc, s21_asin_test);
  tcase_add_loop_test(tc, test_circle, 0, 2);
  tcase_add_loop_test(tc, test_circle_nan, 2, 361);
  suite_add_tcase(s, tc);
  return s;
}