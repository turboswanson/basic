#include "calc.h"

int main(void) {
  elements calc_input[512] = {0};
  elements *parser_input = calc_input;
  elements calc_output[512] = {0};
  elements *parser_output = calc_output;
  double res_21 = 0.0;
  double res_original = 0.0;
  int n = 0;
  char input[] = "44mod3/5.1 + 0.1/10^(-1)/((-sqrt(1357-245)))";
  n = parser(input, parser_input, 0);
  postfix(parser_input, parser_output, &n);
  calculation(parser_output, n, &res_21);

  res_original = 44 % 3 / 5.1 + 0.1 / pow(10., -1) / -sqrt(1357. - 245.);

  printf("%lf - %lf\n", res_21, res_original);

  return 0;
}