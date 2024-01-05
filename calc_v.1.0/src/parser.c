#include "calc.h"

/*
  num/x  type = 1 / priority = 0 / value = num;

  +/-    type = 2 / priority = 1 / operation[0] = '+'
  *      type = 2 / priority = 2 / operation[0] = '*'
  ^      type = 2 / priority = 3 / operation[0] = '^'

  fun    type = 3 / priority = 3 / operation[0] = 's',operation[1] = 'q',
  operation[2] = 'r', operation[3] = 't'

  ()     type = 4 / priority = 0 /  operation[0] = '('
*/

int parser(char *input_buffer, elements *lexem, double x_value) {
  char buf[1024] = {0};
  int count = 0;
  int error = 0;
  // int flag_neg = 0;
  strncpy(buf, input_buffer, sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';

  size_t len = strlen(buf);

  for (size_t i = 0; i < len; i++) {
    if (i == 0 && buf[i] == '+') i++;
    if (i == 0 && buf[i] == '-') {
      unary_processing(lexem, &count);
      lexem += count;
      i++;
    }

    if (isdigit(buf[i])) {
      error = digit_processing(lexem, buf, &i);
      lexem++;
      count++;
    }

    if (buf[i] == 'x') {
      lexem->type = 1;
      lexem->value = x_value;
      lexem->operation[0] = 'x';
      i++;
      lexem++;
      count++;
    }

    if (!error) {
      if (buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] == '/' ||
          buf[i] == '^') {
        operator_processing(buf[i], lexem);
        lexem++;
        count++;
      }

      // sin,cos,tan,asin,acos,atan,log,sqrt

      if (buf[i] == 's' || buf[i] == 'c' || buf[i] == 't' || buf[i] == 'a' ||
          buf[i] == 'l' || buf[i] == 'm') {
        function_processing(buf, lexem, &i);
        count++;
        lexem++;
      }

      if ((buf[i] == '(' && buf[i + 1] != '-') ||
          (buf[i] == ')' && buf[i - 2] != '-')) {
        brackets_processing(buf[i], lexem);
        count++;
        lexem++;
      }

      if (buf[i] == '(' && buf[i + 1] == '-') {
        negative_processing(&lexem);
        i++;
        count = count + 2;
        lexem++;
      }
    }
  }

  return count;
}

int digit_processing(elements *lexem, char *buf, size_t *i) {
  int err = 0;
  int dot = 0;
  char *start = (char *)buf + *i;
  lexem->type = 1;

  while (isdigit(buf[*i])) {
    (*i)++;

    if (buf[*i] == '.') {
      (*i)++;
      dot++;
    }
  }

  if (dot <= 1) {
    double res = 0.0;
    // char *prevLocale = setlocale(LC_NUMERIC, NULL);
    // setlocale(LC_NUMERIC, "C");

    sscanf(start, "%lf", &res);
    // g_print("%lf",res);
    lexem->value = res;
    // setlocale(LC_NUMERIC, prevLocale);
  } else {
    err = 1;
  }

  return err;
}

void unary_processing(elements *lexem, int *count) {
  lexem->type = 1;
  lexem->value = -1.0;
  (*count)++;
  lexem++;

  lexem->type = 2;
  lexem->priority = 2;
  lexem->operation[0] = '*';
  (*count)++;
}

void operator_processing(char operator, elements * lexem) {
  if (operator== '+' || operator== '-') {
    lexem->type = 2;
    lexem->priority = 1;
  }

  if (operator== '*' || operator== '/') {
    lexem->type = 2;
    lexem->priority = 2;
  }

  if (operator== '^') {
    lexem->type = 2;
    lexem->priority = 3;
  }

  lexem->operation[0] = operator;
}

void function_processing(char *buf, elements *lexem, size_t *i) {
  if (buf[*i] == 's' && buf[*i + 1] == 'i' && buf[*i + 2] == 'n') {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 's';
    lexem->operation[1] = 'i';
    lexem->operation[2] = 'n';
    *i = *i + 3;
  } else if (buf[*i] == 'c' && buf[*i + 1] == 'o' && buf[*i + 2] == 's') {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 'c';
    lexem->operation[1] = 'o';
    lexem->operation[2] = 's';
    *i = *i + 3;
  } else if (buf[*i] == 't' && buf[*i + 1] == 'a' && buf[*i + 2] == 'n') {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 't';
    lexem->operation[1] = 'a';
    lexem->operation[2] = 'n';
    *i = *i + 3;
  }
  if (buf[*i] == 's' && buf[*i + 1] == 'q' && buf[*i + 2] == 'r' &&
      buf[*i + 3] == 't') {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 's';
    lexem->operation[1] = 'q';
    lexem->operation[2] = 'r';
    lexem->operation[3] = 't';
    *i = *i + 4;
  } else if (buf[*i] == 'a') {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 'a';

    if (buf[*i + 1] == 's' && buf[*i + 2] == 'i' && buf[*i + 3] == 'n') {
      lexem->type = 3;
      lexem->priority = 3;
      lexem->operation[1] = 's';
      lexem->operation[2] = 'i';
      lexem->operation[3] = 'n';
    } else if (buf[*i + 1] == 'c' && buf[*i + 2] == 'o' && buf[*i + 3] == 's') {
      lexem->type = 3;
      lexem->priority = 3;
      lexem->operation[1] = 'c';
      lexem->operation[2] = 'o';
      lexem->operation[3] = 's';
    } else if (buf[*i + 1] == 't' && buf[*i + 2] == 'a' && buf[*i + 3] == 'n') {
      lexem->type = 3;
      lexem->priority = 3;
      lexem->operation[1] = 't';
      lexem->operation[2] = 'a';
      lexem->operation[3] = 'n';
    }

    *i = *i + 4;
  } else if (buf[*i] == 'l') {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 'l';

    if (buf[*i + 1] == 'o' && buf[*i + 2] == 'g') {
      lexem->operation[1] = 'o';
      lexem->operation[2] = 'g';
      *i = *i + 3;
    } else if (buf[*i + 1] == 'n') {
      lexem->operation[1] = 'n';
      *i = *i + 2;
    }
  } else if (buf[*i] == 'm' && buf[*i + 1] == 'o' && buf[*i + 2] == 'd') {
    lexem->type = 2;
    lexem->priority = 2;
    lexem->operation[0] = 'm';
    lexem->operation[1] = 'o';
    lexem->operation[2] = 'd';
    i = i + 2;
  }
}

void brackets_processing(char c, elements *lexem) {
  lexem->type = 4;
  lexem->priority = 0;
  lexem->operation[0] = c;
}

void negative_processing(elements **lexem) {
  (*lexem)->type = 1;
  (*lexem)->value = -1.0;

  (*lexem)++;
  (*lexem)->type = 2;
  (*lexem)->priority = 2;
  (*lexem)->operation[0] = '*';
}

void postfix(elements *input, elements *output, int *count) {
  int count_out = *count, count_in = 0, i = 0;
  elements tmp_stack[512] = {0};
  elements *tmp = tmp_stack;

  while (count_in++ < *count) {
    if (input->type == 1) {  // num or x
      input_to_output(output, input);
      output++;
    }

    if (input->type == 2 || input->type == 3) {  // operator or function
      while (i > 0) {
        tmp--;
        if (input->priority <= tmp->priority) {
          /*
            prioriry comparing, if input's less pull tmp to output
            e.g 2*2+3 output : 22 tmp: *
            and when we meet + ---> output : 22* tmp: +
            then output: 22*3+
          */

          input_to_output(output, tmp);
          output++;
          i--;
        } else {
          tmp++;
          break;
        }
      }

      input_to_output(tmp, input);
      tmp++;
      i++;
    }

    if (input->type == 4) {  // brackets
      sort_brackets(input, &output, &tmp, &i, &count_out);
    }

    input++;
  }

  while (i > 0) {  // pull the rest of tmp into output
    tmp--;
    input_to_output(output, tmp);
    output++;
    i--;
  }

  *count = count_out;  // a size without brackets
}

void input_to_output(elements *output, elements *input) {
  output->type = input->type;
  output->priority = input->priority;
  output->operation[0] = input->operation[0];
  output->operation[1] = input->operation[1];
  output->operation[2] = input->operation[2];
  output->operation[3] = input->operation[3];
  output->operation[4] = input->operation[4];
  output->value = input->value;
}

void sort_brackets(elements *input, elements **output, elements **tmp, int *i,
                   int *count_out) {
  if (input->operation[0] == '(') {
    (*count_out)--;
    input_to_output(*tmp, input);
    (*tmp)++;
    (*i)++;
  }

  if (input->operation[0] == ')') {
    (*count_out)--;

    while (*i > 0) {
      (*tmp)--;
      if ((*tmp)->operation[0] == '(') {
        (*i)--;
        break;
      } else {
        input_to_output(*output, *tmp);
        (*output)++;
        (*i)--;
      }
    }
  }
}
