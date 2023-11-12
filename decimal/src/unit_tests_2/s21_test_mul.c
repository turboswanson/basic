#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

static s21_decimal num1[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x10000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},

};

static s21_decimal num2[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x10000000}},

};

static s21_decimal result[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x10000000}},
    {{0x00000001, 0x00000000, 0x00000000, 0x10000000}},

};

START_TEST(test) {
  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_mul(num1[i], num2[i], &tmp);
    ck_assert_int_eq(s21_is_equal(result[i], tmp), 1);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

Suite *suite_mul(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_mul");
  tc = tcase_create("s21_mul");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    suite_add_tcase(s, tc);
  }

  return (s);
}
