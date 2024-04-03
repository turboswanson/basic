#include "s21_math_test.h"

// START_TEST(test_n) {
//   double x = 999999;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

START_TEST(test_atan_positive) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_negative) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_one) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_one_negative) {
  double x = -1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

// START_TEST(test_atan_huge_positive) {
//   double x = 100000000.0;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

// START_TEST(test_atan_huge_negative) {
//   double x = -1000000000000000;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

// START_TEST(test_atan_big_mantissa) {
//   double x = 0.923456789012345678901234567890;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

START_TEST(test_atan_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_atan(x));
}
END_TEST

START_TEST(test_atan_inf) {
  double x = S21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_neg_inf) {
  double x = -S21_INF;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_loop_values) {
  double i = _i;
  ck_assert_ldouble_eq_tol(atan(i / 20.0), s21_atan(i / 20.0), 1e-6);
}
END_TEST

// START_TEST(test_atan_dbl_max) {
//   double x = DBL_MAX;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

// START_TEST(test_atan_dbl_min) {
//   double x = DBL_MIN;
//   ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
// }
// END_TEST

// START_TEST(test_circle) {
//   int i = _i;
//   ck_assert_ldouble_eq_tol(atan(i), s21_atan(i), 1e-6);
// ck_assert_ldouble_eq_tol(atan(1.0 / i), s21_atan(1.0 / i), 1e-6);
// ck_assert_ldouble_eq_tol(atan(1.0 / i / i), s21_atan(1.0 / i / i), 1e-6);
// ck_assert_ldouble_eq_tol(atan(1.0 / i / i / i), s21_atan(1.0 / i / i / i),
//                          1e-6);
// }
// END_TEST

START_TEST(s21_atan_test) {
  ck_assert_ldouble_eq_tol(atan(-sqrt(3)), s21_atan(-sqrt(3)), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-1.0), s21_atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-0.5), s21_atan(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-0.1), s21_atan(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-sqrt(3) / 3), s21_atan(-sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-sqrt(3) / 2), s21_atan(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-sqrt(2) / 2), s21_atan(-sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(0.0), s21_atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(0.1), s21_atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(atan(0.5), s21_atan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(3) / 3), s21_atan(sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(3) / 2), s21_atan(sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(2) / 2), s21_atan(sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(1.0), s21_atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(sqrt(3)), s21_atan(sqrt(3)), 1e-6);
  ck_assert_ldouble_eq_tol(atan(4.2658365), s21_atan(4.2658365), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-4.2658365), s21_atan(-4.2658365), 1e-6);
  ck_assert_ldouble_eq_tol(atan(4.2658365e-9), s21_atan(4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-4.2658365e-9), s21_atan(-4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(atan(S21_PI), s21_atan(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(atan(2 * S21_PI), s21_atan(2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(atan(S21_PI / 2), s21_atan(S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(S21_PI / -2), s21_atan(S21_PI / -2), 1e-6);
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(S21_PI / 2.0, s21_atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(S21_PI / -2.0, s21_atan(-INFINITY), 1e-6);
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

Suite *suite_atan(void) {
  Suite *s = suite_create("suite_atan");
  TCase *tc = tcase_create("atan_tc");

  // tcase_add_test(tc, test_n);
  tcase_add_test(tc, test_atan_positive);
  tcase_add_test(tc, test_atan_negative);
  tcase_add_test(tc, test_atan_zero);
  tcase_add_test(tc, test_atan_one);
  tcase_add_test(tc, test_atan_negative);
  tcase_add_test(tc, test_atan_one_negative);
  // tcase_add_test(tc, test_atan_huge_positive);
  // tcase_add_test(tc, test_atan_huge_negative);
  // tcase_add_test(tc, test_atan_big_mantissa);
  tcase_add_test(tc, test_atan_nan);
  tcase_add_test(tc, test_atan_inf);
  tcase_add_test(tc, test_atan_neg_inf);
  tcase_add_test(tc, test_atan_loop_values);
  // tcase_add_test(tc, test_atan_dbl_max);
  // tcase_add_test(tc, test_atan_dbl_min);
  tcase_add_test(tc, s21_atan_test);
  // tcase_add_loop_test(tc, test_circle, -360, 361);
  suite_add_tcase(s, tc);
  return s;
}