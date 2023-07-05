#include "s21_math_test.h"

START_TEST(fabs_test1) { ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0)); }
END_TEST

START_TEST(fabs_test2) {
  ck_assert_ldouble_eq(s21_fabs(-1.000005), fabs(-1.000005));
}
END_TEST

START_TEST(fabs_test3) { ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0)); }
END_TEST

START_TEST(fabs_test4) { ck_assert_ldouble_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST

START_TEST(fabs_test5) {
  ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF));
}
END_TEST

START_TEST(fabs_test6) {
  ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-S21_INF));
}
END_TEST

START_TEST(fabs_test7) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(fabs_test8) {
  ck_assert_ldouble_eq(s21_fabs(1000.042), fabs(1000.042));
}
END_TEST

START_TEST(fabs_test9) {
  ck_assert_ldouble_eq(s21_fabs(-1000.042), fabs(-1000.042));
}
END_TEST

START_TEST(fabs_test10) {
  ck_assert_ldouble_eq(s21_fabs(987633.465), fabs(987633.465));
}
END_TEST

START_TEST(fabs_loop) {
  ck_assert_ldouble_eq(s21_fabs(0.1 * _i), fabs(0.1 * _i));
}
END_TEST

START_TEST(s21_fabs_test) {
  ck_assert_int_eq(fabs(-8.55), s21_fabs(-8.55));
  ck_assert_int_eq(fabs(-0.33), s21_fabs(-0.33));
  ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
  ck_assert_int_eq(fabs(0.5), s21_fabs(0.5));
  ck_assert_int_eq(fabs(1.17394757593), s21_fabs(1.17394757593));
  ck_assert_int_eq(fabs(100.1), s21_fabs(100.1));
  ck_assert_int_eq(abs((int)INFINITY), s21_abs((int)INFINITY));
  ck_assert_int_eq(abs((int)-INFINITY), s21_abs((int)-INFINITY));
  ck_assert_int_eq(abs((int)NAN), s21_abs((int)NAN));
}
END_TEST

Suite *suite_fabs(void) {
  Suite *s = suite_create("suite_fabs");
  TCase *tc = tcase_create("fabs_tc");

  tcase_add_test(tc, fabs_test1);
  tcase_add_test(tc, fabs_test2);
  tcase_add_test(tc, fabs_test3);
  tcase_add_test(tc, fabs_test4);
  tcase_add_test(tc, fabs_test5);
  tcase_add_test(tc, fabs_test6);
  tcase_add_test(tc, fabs_test7);
  tcase_add_test(tc, fabs_test8);
  tcase_add_test(tc, fabs_test9);
  tcase_add_test(tc, fabs_test10);
  tcase_add_test(tc, s21_fabs_test);
  tcase_add_loop_test(tc, fabs_loop, -100, 101);

  suite_add_tcase(s, tc);
  return s;
}