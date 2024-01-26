#include <check.h>

#include "calc.h"

START_TEST(check_input) {
  int err = 0;
  char string[] = "1+2+3-log(6)*sqrt(10)+ln(10)";
  err = validation(string);
  ck_assert_int_eq(0, err);

  char string_1[] = "1+2+3*ln()";
  err = validation(string_1);
  ck_assert_int_eq(1, err);

  char string_2[] = "1.123123+2mod4+(3*7)+sqrt(7)";
  err = validation(string_2);
  ck_assert_int_eq(0, err);

  char string_3[] = "1+2mod4+3*(7+1)+acos(1/2)+5^2";
  err = validation(string_3);
  ck_assert_int_eq(0, err);

  char string_5[] = "^1+2mod4+3*(7+1)+atan(1/2)";
  err = validation(string_5);
  ck_assert_int_eq(1, err);

  char string_6[] = "cos(1/2)+2mod4+3*(7+1)+sin(0)";
  err = validation(string_6);
  ck_assert_int_eq(0, err);

  char string_7[] = "tan(1/2)+2mod4+3*(7+1)+asin(0)+atan(0)";
  err = validation(string_7);
  ck_assert_int_eq(0, err);

  char string_8[] = "123456789+";
  err = validation(string_8);
  ck_assert_int_eq(1, err);

  char string_10[] = "";
  err = validation(string_10);
  ck_assert_int_eq(1, err);

  char string_12[] = "1+4/";
  err = validation(string_12);
  ck_assert_int_eq(1, err);

  char string_13[] = "1+4*";
  err = validation(string_13);
  ck_assert_int_eq(1, err);

  char string_14[] = "(1+5-4*)";
  err = validation(string_14);
  ck_assert_int_eq(1, err);

  char string_15[] = "1+((5-4)/410";
  err = validation(string_15);
  ck_assert_int_eq(1, err);

  char string_18[] = "*0+(5-4)";
  err = validation(string_18);
  ck_assert_int_eq(1, err);

  char string_19[] = "1/0.5+2";
  err = validation(string_19);
  ck_assert_int_eq(0, err);

  char string_20[] = "1+";
  err = validation(string_20);
  ck_assert_int_eq(1, err);

  char string_21[] = "1++1";
  err = validation(string_21);
  ck_assert_int_eq(1, err);

  char string_22[] = "sin(mod.";
  err = validation(string_22);
  ck_assert_int_eq(1, err);

  char string_23[] = "4.5.6";
  err = validation(string_23);
  ck_assert_int_eq(1, err);

  char string_24[] = "4/0+1";
  err = validation(string_24);
  ck_assert_int_eq(1, err);

  char string_25[] = "^.sin";
  err = validation(string_25);
  ck_assert_int_eq(1, err);

  char string_26[] = "4+5./0^56";
  err = validation(string_26);
  ck_assert_int_eq(1, err);

  char string_27[] = "1+2";
  err = x_validation(string_27);
  ck_assert_int_eq(1, err);

  char string_28[] = "sin(x)";
  err = x_validation(string_28);
  ck_assert_int_eq(2, err);

  char string_29[] = "3..15";
  err = x_validation(string_29);
  ck_assert_int_eq(1, err);

  char string_30[] = "ln()";
  err = x_validation(string_30);
  ck_assert_int_eq(2, err);

  char string_31[] = "-sin()";
  err = x_validation(string_31);
  ck_assert_int_eq(1, err);

  char string_32[] = "4(";
  err = x_validation(string_32);
  ck_assert_int_eq(1, err);

  char string_33[] = "1.3455.7";
  err = x_validation(string_33);
  ck_assert_int_eq(1, err);

  char string_34[] = "5.5";
  err = x_validation(string_34);
  ck_assert_int_eq(0, err);

  char string_35[] = "5/0";
  err = validation(string_35);
  ck_assert_int_eq(1, err);

  char string_36[] = "5sin(";
  err = validation(string_36);
  ck_assert_int_eq(1, err);
}
END_TEST

START_TEST(calculate) {
  elements calc_input[256] = {0};
  elements *parser_input = calc_input;
  elements calc_output[256] = {0};
  elements *parser_output = calc_output;
  long double res_21 = 0.0;
  long double res_original = 0.0;
  int n;

  char input[] = "11+2^5";
  n = parser(input, parser_input, 0);

  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 11 + pow(2, 5);
  ck_assert_double_eq(res_original, res_21);

  char input_x[] = "-0.1+0.2";
  n = parser(input_x, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = -0.1 + 0.2;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_1[] = "11+(-2)^5";
  n = parser(input_1, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 11 + pow(-2, 5);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_2[] = "cos(1)+3";
  n = parser(input_2, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = cos(1) + 3;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_3[] = "2^(2.1+1)-11mod2";
  n = parser(input_3, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = pow(2, (2.1 + 1)) - fmod(11, 2);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_4[] = "sin(0.5)-cos(1)+tan(0.5)+acos(0.5)-asin(1)-atan(1)";
  n = parser(input_4, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = sin(0.5) - cos(1) + tan(0.5) + acos(0.5) - asin(1) - atan(1);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_5[] = "sqrt(4.123456789)+3-1.12";
  n = parser(input_5, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = sqrt(4.123456789) + 3 - 1.12;
  ck_assert_double_ge_tol(res_original, res_21, 0.001);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_6[] = "log(10.2)-ln(10.2)";
  n = parser(input_6, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = log10(10.2) - log(10.2);
  ck_assert_double_eq(res_original, res_21);
  // printf("%lf",res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_8[] = "sqrt(4+1)+((-3)+1)";
  n = parser(input_8, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = sqrt(4 + 1) + (-3 + 1);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_9[] = "1.1122-(-1)";
  n = parser(input_9, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 1.1122 - (-1);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_10[] = "sin(x)";
  n = parser(input_10, parser_input, 1.1);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = sin(1.1);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_11[] =
      "15.4121212121212/(7.1-(1.1+1.1))*3-(2+(1+1))*15.4/"
      "(7-(200.1+1))*3-(2+(1+1))*(15.0/"
      "(7-(1.1+1))*3.4-(2+(1+1))+15.23456789101112/(7.5-(1+1))*3.5-(2+(1+1)))";
  n = parser(input_11, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 15.4121212121212 / (7.1 - (1.1 + 1.1)) * 3 -
                 (2 + (1 + 1)) * 15.4 / (7 - (200.1 + 1)) * 3 -
                 (2 + (1 + 1)) * (15.0 / (7 - (1.1 + 1)) * 3.4 - (2 + (1 + 1)) +
                                  15.23456789101112 / (7.5 - (1 + 1)) * 3.5 -
                                  (2 + (1 + 1)));
  ck_assert_double_eq_tol(res_original, res_21, 0.01);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_12[] = "1.25+3.45";
  n = parser(input_12, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 1.25 + 3.45;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_13[] = "1.25-3.45";
  n = parser(input_13, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 1.25 - 3.45;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_14[] = "1.25*3.45";
  n = parser(input_14, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 1.25 * 3.45;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_15[] = "1.25/3.45";
  n = parser(input_15, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 1.25 / 3.45;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_16[] = "3*(4+7)";
  n = parser(input_16, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 3 * (4 + 7);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_17[] = "1.25mod3.45";
  n = parser(input_17, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = fmod(1.25, 3.45);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_18[] = "1.25^3.45";
  n = parser(input_18, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = pow(1.25, 3.45);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_19[] = "x";
  n = parser(input_19, parser_input, 3.45);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = 3.45;
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_20[] = "(5.23+1.25)*(0.25+0.001)";
  n = parser(input_20, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = (5.23 + 1.25) * (0.25 + 0.001);
  ck_assert_double_eq_tol(res_original, res_21, 0.01);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);
}

END_TEST;

START_TEST(calculate_1) {
  elements calc_input[512] = {0};
  elements *parser_input = calc_input;
  elements calc_output[512] = {0};
  elements *parser_output = calc_output;
  long double res_21 = 0.0;
  long double res_original = 0.0;
  int n;

  char input_21[] = "sin((5.23+1.25)*(0.25+0.001))";
  n = parser(input_21, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = sin((5.23 + 1.25) * (0.25 + 0.001));
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_22[] = "cos((5.23+1.25)*(0.25+0.001))";
  n = parser(input_22, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = cos((5.23 + 1.25) * (0.25 + 0.001));
  ck_assert_double_eq_tol(res_original, res_21, 0.001);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_23[] = "tan((5.23+1.25)*(0.25+0.001))";
  n = parser(input_23, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = tan((5.23 + 1.25) * (0.25 + 0.001));
  ck_assert_double_eq_tol(res_original, res_21, 0.01);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_24[] = "asin(7/7.7)";
  n = parser(input_24, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = asin(7 / 7.7);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_25[] = "acos(7/7.7)";
  n = parser(input_25, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = acos(7 / 7.7);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_26[] = "atan(7/7.7)";
  n = parser(input_26, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = atan(7 / 7.7);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_27[] = "sqrt(1357-245)";
  n = parser(input_27, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = sqrt(1357 - 245);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_28[] = "ln(1357-245)";
  n = parser(input_28, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = log(1357 - 245);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_29[] = "log(1357-245)";
  n = parser(input_29, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = log10(1357 - 245);
  ck_assert_double_eq(res_original, res_21);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_30[] = "cos(sin(tan(-0.005)))";
  n = parser(input_30, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = cos(sin(tan(-0.005)));
  ck_assert_double_eq_tol(res_original, res_21, 0.01);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_31[] = "log(32+1)*7/11*432*(sin(2)*12-45+4)/2";
  n = parser(input_31, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = log10(32 + 1) * 7 / 11 * 432 * (sin(2) * 12 - 45 + 4) / 2;
  ck_assert_double_eq_tol(res_original, res_21, 0.000001);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  char input_32[] = "x+x/2+x^2";
  n = parser(input_32, parser_input, -4.33333);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);
  res_original = -4.33333 + -4.33333 / 2 + pow(-4.33333, 2);
  ck_assert_double_eq_tol(res_original, res_21, 0.000001);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);

  // char input_33[] = "x/(-x)";
  // n = parser(input_33, parser_input, -4444.123456789);
  // postfix(parser_input, parser_output, &n);
  // calculation(parser_output, n, &res_21);
  // res_original = -4444.123456789/4444.123456789;
  // ck_assert_double_eq_tol(res_original, res_21,0.000001);

  free_lexem(parser_input, n);
  free_lexem(parser_output, n);
}

END_TEST;

Suite *s21_SmartCalc_tests_create() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_SmartCalc");
  tc_core = tcase_create("tests");
  tcase_add_test(tc_core, check_input);
  tcase_add_test(tc_core, calculate);
  tcase_add_test(tc_core, calculate_1);

  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  Suite *s = s21_SmartCalc_tests_create();
  SRunner *s21_SmartCalc_runner = srunner_create(s);
  int number_failed;
  srunner_run_all(s21_SmartCalc_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_SmartCalc_runner);
  srunner_free(s21_SmartCalc_runner);

  return number_failed == 0 ? 0 : 1;
}