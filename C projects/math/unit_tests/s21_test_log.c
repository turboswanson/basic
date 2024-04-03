#include "s21_math_test.h"

START_TEST(test_pos) {
  double x = 2.523;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST

START_TEST(test_max) {
  double x = DBL_MAX;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST

START_TEST(test_min) {
  double x = DBL_MIN;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST

START_TEST(test_pos_1) {
  double x = 4.3234323e-43;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST

START_TEST(test_neg) {
  double x = -3432.12;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(test_zero) {
  double x = 0;
  ck_assert_ldouble_infinite(s21_log(x));
}
END_TEST

START_TEST(test_one) {
  double x = 1;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), 1e-6);
}
END_TEST

START_TEST(test_nan_pos) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(test_nan_neg) {
  double x = -S21_NAN;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(test_inf_pos) {
  double x = S21_INF;
  ck_assert_ldouble_infinite(s21_log(x));
}
END_TEST

START_TEST(test_inf_neg) {
  double x = -S21_INF;
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(s21_log_loop) {
  ck_assert_ldouble_eq_tol(log(_i), s21_log(_i), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.1 * _i), s21_log(0.1 * _i), 1e-6);
  ck_assert_ldouble_eq_tol(log(1.0 / _i), s21_log(1.0 / _i), 1e-6);
}
END_TEST

START_TEST(s21_log_loop_nan) {
  ck_assert_ldouble_nan(log(-_i));
  ck_assert_ldouble_nan(log(-_i));
  ck_assert_ldouble_nan(s21_log(0.1 * -_i));
  ck_assert_ldouble_nan(s21_log(0.1 * -_i));
}
END_TEST

START_TEST(s21_log_test) {
  ck_assert_ldouble_eq_tol(log(123.895304), s21_log(123.895304), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.003), s21_log(0.003), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.5), s21_log(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(log(0.783645), s21_log(0.783645), 1e-6);
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), 1e-6);
  ck_assert_ldouble_eq_tol(log(1.0), s21_log(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(log(S21_E), s21_log(S21_E), 1e-6);
  ck_assert_ldouble_eq_tol(log(200), s21_log(200), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(9.5463728645e6), log(9.5463728645e6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(5637385895.018274), log(5637385895.018274),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1e-10), log(1.1e-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1e-55), log(1.1e-55), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1e-70), log(1.1e-70), 1e-6);

  // ck_assert_ldouble_infinite(log(0.00001));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(log(INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(NAN));
  ck_assert_ldouble_nan(s21_log(NAN));
}
END_TEST

Suite *suite_log(void) {
  Suite *s = suite_create("suite_log");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_max);
  tcase_add_test(tc, test_min);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_zero);
  tcase_add_test(tc, test_one);
  tcase_add_test(tc, test_nan_pos);
  tcase_add_test(tc, test_nan_neg);
  tcase_add_test(tc, test_inf_pos);
  tcase_add_test(tc, test_inf_neg);
  tcase_add_test(tc, s21_log_test);
  tcase_add_loop_test(tc, s21_log_loop_nan, 1, 101);
  tcase_add_loop_test(tc, s21_log_loop, 1, 101);

  suite_add_tcase(s, tc);
  return s;
}