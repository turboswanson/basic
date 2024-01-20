#include "calc.h"

int main(void) {
  elements calc_input[512] = {0};
  elements *parser_input = calc_input;
  elements calc_output[512] = {0};
  elements *parser_output = calc_output;
  long double res_21 = 0.0;
  long double res_original = 0.0;
  int n = 0;
  char input[] = "(-x)";
  int error = validation(input); 
  n = parser(input, parser_input, 5);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);

  res_original = 1+(-5);

  printf("%.8Lf - %.8Lf\n", res_21, res_original);

  return 0;
}