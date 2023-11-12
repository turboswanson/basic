#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

static s21_decimal num1[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000005, 0x00000000, 0x00000000, 0x00000000}},
};

static s21_decimal num2[] = {
    {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
    {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},
};

static s21_decimal result[] = {
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
    {{25, 0x00000000, 0x00000000, 0x00010000}}};

START_TEST(test) {
  for (size_t i = 0; i < sizeof(num1) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    // printf("i = %zu\n", i);
    int ret = s21_div(num1[i], num2[i], &tmp);
    // printf("%08x | %08x | %08x | %08x\n", result[i].bits[3],
    // result[i].bits[2],
    //          result[i].bits[1], result[i].bits[0]);
    // printf("%08x | %08x | %08x | %08x\n\n", tmp.bits[3], tmp.bits[2],
    //          tmp.bits[1], tmp.bits[0]);
    ck_assert_int_eq(s21_is_equal(result[i], tmp), 1);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

Suite *suite_div(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_div");
  tc = tcase_create("s21_div");

  if (s != NULL && tc != NULL) {
    tcase_add_test(tc, test);
    suite_add_tcase(s, tc);
  }

  return (s);
}
