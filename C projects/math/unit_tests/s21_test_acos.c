#include "s21_math_test.h"

START_TEST(test_pos) {
  double x = 0.999;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST

START_TEST(test_pos2) {
  double x = 1;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST

START_TEST(test_pos3) {
  double x = 3.0;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(test_pos4) {
  double x = 0;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST

START_TEST(test_neg) {
  double x = -0.001;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST

START_TEST(test_neg2) {
  double x = -0.9999;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST

START_TEST(test_neg3) {
  double x = -1 - 1e-16;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6);
}
END_TEST

START_TEST(test_nul) {
  double x = 1.001;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(test_nul2) {
  double x = -1.1;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(test_nul3) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(test_nul4) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_acos(x));
}
END_TEST

START_TEST(test_circle_nan) {
  int i = _i;
  ck_assert_ldouble_nan(acos(i));
  ck_assert_ldouble_nan(s21_acos(i));
  // ck_assert_ldouble_eq_tol(acos(1.0 / i), s21_acos(1.0 / i), 1e-6);
  // ck_assert_ldouble_eq_tol(acos(1.0 / i / i), s21_acos(1.0 / i / i), 1e-6);
  // ck_assert_ldouble_eq_tol(acos(1.0 / i / i / i), s21_acos(1.0 / i / i / i),
  //                          1e-6);
  // ck_assert_ldouble_eq_tol(acos(-1.0 / i), s21_acos(-1.0 / i), 1e-6);
  // ck_assert_ldouble_eq_tol(acos(-1.0 / i / i), s21_acos(-1.0 / i / i), 1e-6);
  // ck_assert_ldouble_eq_tol(acos(-1.0 / i / i / i), s21_acos(-1.0 / i / i /
  // i),
  //                          1e-6);
}
END_TEST

START_TEST(test_circle) {
  int i = _i;
  ck_assert_ldouble_eq_tol(acos(i), s21_acos(i), 1e-6);
}
END_TEST

START_TEST(s21_acos_test) {
  ck_assert_ldouble_eq_tol(acos(-1.0), s21_acos(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-0.5), s21_acos(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-0.1), s21_acos(-0.1), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(3) / 3), s21_acos(-sqrt(3) / 3), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(3) / 2), s21_acos(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(2) / 4), s21_acos(-sqrt(2) / 4), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.0), s21_acos(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.1), s21_acos(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.5), s21_acos(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(acos(0.7071067811865475244),
                           s21_acos(0.7071067811865475244), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-0.7071067811865475244),
                           s21_acos(-0.7071067811865475244), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(3) / 2), s21_acos(-sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(sqrt(3) / 2), s21_acos(sqrt(3) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(sqrt(2) / 2), s21_acos(sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-sqrt(2) / 2), s21_acos(-sqrt(2) / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(1 / 2), s21_acos(1 / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(-1 / 2), s21_acos(-1 / 2), 1e-6);
  ck_assert_ldouble_eq_tol(acos(1.0), s21_acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(acos(4.2658365e-9), s21_acos(4.2658365e-9), 1e-6);
  ck_assert_ldouble_eq_tol(acos(S21_PI / 4), s21_acos(S21_PI / 4), 1e-6);
  // ck_assert_ldouble_nan(acos(S21_PI));
  ck_assert_ldouble_nan(s21_acos(S21_PI));
  ck_assert_ldouble_nan(acos(sqrt(3)));
  ck_assert_ldouble_nan(s21_acos(sqrt(3)));
  // ck_assert_ldouble_nan(acos(-5));
  ck_assert_ldouble_nan(s21_acos(-5));
  // ck_assert_ldouble_nan(acos(5));
  ck_assert_ldouble_nan(s21_acos(5));
  ck_assert_ldouble_nan(acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(acos(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(acos(NAN));
  ck_assert_ldouble_nan(s21_acos(NAN));
}
END_TEST

Suite *suite_acos(void) {
  Suite *s = suite_create("suite_acos");
  TCase *tc = tcase_create("acos_tc");

  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos2);
  tcase_add_test(tc, test_pos3);
  tcase_add_test(tc, test_pos4);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_neg2);
  tcase_add_test(tc, test_neg3);
  tcase_add_test(tc, test_nul);
  tcase_add_test(tc, test_nul2);
  tcase_add_test(tc, test_nul3);
  tcase_add_test(tc, test_nul4);
  tcase_add_test(tc, s21_acos_test);
  tcase_add_loop_test(tc, test_circle, 0, 2);
  tcase_add_loop_test(tc, test_circle_nan, 2, 361);

  suite_add_tcase(s, tc);
  return s;
}