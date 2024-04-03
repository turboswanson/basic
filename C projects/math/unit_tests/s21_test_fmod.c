#include "s21_math_test.h"

START_TEST(fmod_test1) {
  double x = 12.0;
  double y = 4.0;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test2) {
  double x = 0.0;
  double y = 5.5;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test3) {
  double x = S21_INF;
  double y = 5.5;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test4) {
  double x = -S21_INF;
  double y = 5.5;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test5) {
  double x = 5.8;
  double y = 0.0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test6) {
  double x = 5.8;
  double y = S21_NEGZERO;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test7) {
  double x = 5.8;
  double y = S21_INF;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test8) {
  double x = 5.8;
  double y = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), 1e-6);
}
END_TEST

START_TEST(fmod_test9) {
  double x = S21_NAN;
  double y = 12.6;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test10) {
  double x = 5.5;
  double y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(s21_fmod_loop) {
  ck_assert_ldouble_eq(fmod(_i, _i), s21_fmod(_i, _i));
  ck_assert_ldouble_eq(fmod(_i, -_i), s21_fmod(_i, -_i));
  ck_assert_ldouble_eq(fmod(-_i, _i), s21_fmod(-_i, _i));
}
END_TEST

START_TEST(s21_fmod_loop2) {
  ck_assert_ldouble_eq(fmod(0.1 * _i, 0.1 * _i), s21_fmod(0.1 * _i, 0.1 * _i));
  ck_assert_ldouble_eq(fmod(0.1 * _i, -0.1 * _i),
                       s21_fmod(0.1 * _i, -0.1 * _i));
  ck_assert_ldouble_eq(fmod(-0.1 * _i, 0.1 * _i),
                       s21_fmod(-0.1 * _i, 0.1 * _i));
}
END_TEST

START_TEST(s21_fmod_test) {
  ck_assert_ldouble_eq(fmod(-100400, -8), s21_fmod(-100400, -8));
  ck_assert_ldouble_eq(fmod(-100.97, -100), s21_fmod(-100.97, -100));
  ck_assert_ldouble_eq(fmod(-21, -12.3), s21_fmod(-21, -12.3));
  ck_assert_ldouble_eq(fmod(-1.5, -1), s21_fmod(-1.5, -1));
  ck_assert_ldouble_eq(fmod(0, 0.1), s21_fmod(0, 0.1));
  ck_assert_ldouble_eq(fmod(1.11, 1.0), s21_fmod(1.11, 1.0));
  ck_assert_ldouble_eq(fmod(5, 5), s21_fmod(5, 5));
  ck_assert_ldouble_eq(fmod(444, 444.0006), s21_fmod(444, 444.0006));
  ck_assert_ldouble_eq(fmod(800400, 8), s21_fmod(800400, 8));
}
END_TEST

Suite *suite_fmod(void) {
  Suite *s = suite_create("suite_fmod");
  TCase *tc = tcase_create("fmod_tc");

  tcase_add_test(tc, fmod_test1);
  tcase_add_test(tc, fmod_test2);
  tcase_add_test(tc, fmod_test3);
  tcase_add_test(tc, fmod_test4);
  tcase_add_test(tc, fmod_test5);
  tcase_add_test(tc, fmod_test6);
  tcase_add_test(tc, fmod_test7);
  tcase_add_test(tc, fmod_test8);
  tcase_add_test(tc, fmod_test9);
  tcase_add_test(tc, fmod_test10);
  tcase_add_test(tc, s21_fmod_test);
  tcase_add_loop_test(tc, s21_fmod_loop, 1, 101);
  tcase_add_loop_test(tc, s21_fmod_loop2, 1, 101);

  suite_add_tcase(s, tc);
  return s;
}