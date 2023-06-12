#ifndef S21_MATH_TEST_H
#define S21_MATH_TEST_H

#include "../s21_math.h"
#include <check.h>
#include <stdlib.h>


Suite *suite_abs(void);
Suite *suite_fabs(void);

void run_test(void);
void run_testcase(Suite *testcase);

#endif