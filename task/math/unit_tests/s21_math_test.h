#ifndef S21_MATH_TEST
#define S21_MATH_TEST

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/mitchelk/code/school21github/task/math/unit_tests/s21_math_test.h"

Suite *suite_abs(void);
Suite *suite_fabs(void);


void run_test(void);
void run_testcase(Suite *testcase);

#endif