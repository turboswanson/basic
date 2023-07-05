#include "s21_math_test.h"

START_TEST(test_sin_small_positive) {
  double x = 2.523;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_small_negative) {
  double x = -2.523;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_huge_positive) {
  double x = 923456789;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_huge_negative) {
  double x = -923456789;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_sin_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_sin(x));
}
END_TEST

START_TEST(test_sin_inf) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_sin(x));
}
END_TEST

START_TEST(test_sin_fractional_pi_values) {
  int i = _i;
  if (i != 0) {
    ck_assert_ldouble_eq_tol(sin(S21_PI / i), s21_sin(S21_PI / i), 1e-6);
  } else {
    ck_assert_ldouble_nan(s21_sin(S21_PI / i));
  }
}
END_TEST

START_TEST(test_sin_whole_pi_values) {
  int i = _i;
  ck_assert_ldouble_eq_tol(sin(S21_PI * i), s21_sin(S21_PI * i), 1e-6);
}
END_TEST

START_TEST(test_sin_big_mantissa) {
  double x = 0.12345678901234567890;
  ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), 1e-6);
}
END_TEST

START_TEST(test_circle) {
  int i = _i;
  ck_assert_ldouble_eq_tol(sin(i), s21_sin(i), 1e-6);
  // ck_assert_ldouble_eq_tol(sin(1.0 / i), s21_sin(1.0 / i), 1e-6);
  // ck_assert_ldouble_eq_tol(sin(1.0 / i / i), s21_sin(1.0 / i / i), 1e-6);
  // ck_assert_ldouble_eq_tol(sin(1.0 / i / i / i), s21_sin(1.0 / i / i / i),
  //                          1e-6);
  // ck_assert_ldouble_eq_tol(sin(-1.0 / i), s21_sin(-1.0 / i), 1e-6);
  // ck_assert_ldouble_eq_tol(sin(-1.0 / i / i), s21_sin(-1.0 / i / i), 1e-6);
  // ck_assert_ldouble_eq_tol(sin(-1.0 / i / i / i), s21_sin(-1.0 / i / i / i),
  //                          1e-6);
}
END_TEST

START_TEST(s21_sin_test) {
  ck_assert_ldouble_eq_tol(sin(-1.0), s21_sin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-0.5), s21_sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-0.1), s21_sin(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-2 * S21_PI), s21_sin(-2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-3 * S21_PI / 2), s21_sin(-3 * S21_PI / 2),
                           1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 6), s21_sin(-S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 4), s21_sin(-S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 3), s21_sin(-S21_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 2), s21_sin(-S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI), s21_sin(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(0.0), s21_sin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(sin(0.1), s21_sin(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(sin(0.5), s21_sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(sin(S21_PI), s21_sin(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(2 * S21_PI), s21_sin(2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-2 * S21_PI), s21_sin(-2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(3 * S21_PI), s21_sin(3 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-3 * S21_PI), s21_sin(-3 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(sin(S21_PI / 2), s21_sin(S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 3), s21_sin(-S21_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 4), s21_sin(-S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(sin(-S21_PI / 6), s21_sin(-S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(sin(3 * S21_PI / 2), s21_sin(3 * S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(sin(1.0), s21_sin(1.0), 1e-6);

  ck_assert_ldouble_nan(sin(INFINITY));
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sin(-INFINITY));
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sin(NAN));
}
END_TEST

Suite *suite_sin(void) {
  Suite *s = suite_create("suite_sin");
  TCase *tc = tcase_create("sin_tc");

  tcase_add_test(tc, test_sin_small_positive);
  tcase_add_test(tc, test_sin_small_negative);
  tcase_add_test(tc, test_sin_huge_positive);
  tcase_add_test(tc, test_sin_huge_negative);
  tcase_add_test(tc, test_sin_zero);
  tcase_add_test(tc, test_sin_nan);
  tcase_add_test(tc, test_sin_inf);
  tcase_add_loop_test(tc, test_sin_fractional_pi_values, 0, 9);
  tcase_add_test(tc, test_sin_whole_pi_values);
  tcase_add_test(tc, test_sin_big_mantissa);
  tcase_add_test(tc, s21_sin_test);
  tcase_add_loop_test(tc, test_circle, -360, 361);
  suite_add_tcase(s, tc);
  return s;
}