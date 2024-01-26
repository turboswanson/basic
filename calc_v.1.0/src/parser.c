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

static int check_symbol(char c, char symbol) {
  int res = 0;

  if (c == symbol) {
    res = 1;
  }

  return res;
}

static int is_operator(char c) {
  int res = 0;

  if ((c == '+' || c == '-' || c == '*' || c == '/' || c == '^')) {
    res = 1;
  }

  return res;
}

static int is_function(char c) {
  int res = 0;

  if ((c == 's' || c == 'c' || c == 't' || c == 'a' || c == 'm' || c == 'l')) {
    res = 1;
  }

  return res;
}

int parser(char *input_buffer, elements *lexem, long double x_value) {
  char buf[1024] = {0};
  int count = 0;
  int error = 0;
  int flag_negative = 0;

  strncpy(buf, input_buffer, sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';

  size_t len = strlen(buf);

  for (size_t i = 0; i < len; i++) {
    if (i == 0 && check_symbol(buf[i], '+')) {
      i++;
    }

    if (i == 0 && check_symbol(buf[i], '-')) {
      unary_processing(lexem, &count);
      lexem += count;
      i++;
    }

    if (isdigit(buf[i])) {
      error = digit_processing(lexem, buf, &i);
      lexem++;
      count++;
      if (flag_negative) {
        lexem->type = 4;
        lexem->priority = 0;
        lexem->operation[0] = ')';
        flag_negative = 0;
        i++;
        lexem++;
      }
    }

    if (check_symbol(buf[i], 'x')) {
      lexem->type = 1;
      lexem->value = x_value;
      lexem->operation[0] = 'x';
      i++;
      lexem++;
      count++;
    }

    if (!error) {
      if (is_operator(buf[i])) {
        operator_processing(buf[i], lexem);
        lexem++;
        count++;
      }

      // sin,cos,tan,asin,acos,atan,log,sqrt

      if (is_function(buf[i])) {
        function_processing(buf, lexem, &i);
        count++;
        lexem++;
      }

      if ((check_symbol(buf[i], '(') && buf[i + 1] != '-') ||
          (check_symbol(buf[i], ')'))) {
        brackets_processing(buf[i], lexem);
        count++;
        lexem++;
      }

      if (check_symbol(buf[i], '(') && check_symbol(buf[i + 1], '-')) {
        negative_processing(&lexem);
        flag_negative = 1;
        i++;
        count = count + 4;
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
    long double res = 0.0;
    sscanf(start, "%Lf", &res);
    lexem->value = res;
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
  if (check_symbol(operator, '+') || check_symbol(operator, '-')) {
    lexem->type = 2;
    lexem->priority = 1;
  }

  if (check_symbol(operator, '*') || check_symbol(operator, '/')) {
    lexem->type = 2;
    lexem->priority = 2;
  }

  if (check_symbol(operator, '^')) {
    lexem->type = 2;
    lexem->priority = 3;
  }

  lexem->operation[0] = operator;
}

void function_processing(char *buf, elements *lexem, size_t *i) {
  if (check_symbol(buf[*i], 's') && check_symbol(buf[*i + 1], 'i')) {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 's';
    lexem->operation[1] = 'i';
    lexem->operation[2] = 'n';
    *i = *i + 3;
  } else if (check_symbol(buf[*i], 'c') && check_symbol(buf[*i + 1], 'o')) {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 'c';
    lexem->operation[1] = 'o';
    lexem->operation[2] = 's';
    *i = *i + 3;
  } else if (check_symbol(buf[*i], 't') && check_symbol(buf[*i + 1], 'a')) {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 't';
    lexem->operation[1] = 'a';
    lexem->operation[2] = 'n';
    *i = *i + 3;
  }
  if (check_symbol(buf[*i], 's') && check_symbol(buf[*i + 1], 'q')) {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 's';
    lexem->operation[1] = 'q';
    lexem->operation[2] = 'r';
    lexem->operation[3] = 't';
    *i = *i + 4;
  } else if (check_symbol(buf[*i], 'a')) {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 'a';

    if (check_symbol(buf[*i + 1], 's') && check_symbol(buf[*i + 2], 'i')) {
      lexem->type = 3;
      lexem->priority = 3;
      lexem->operation[1] = 's';
      lexem->operation[2] = 'i';
      lexem->operation[3] = 'n';
    } else if (check_symbol(buf[*i + 1], 'c') &&
               check_symbol(buf[*i + 2], 'o')) {
      lexem->type = 3;
      lexem->priority = 3;
      lexem->operation[1] = 'c';
      lexem->operation[2] = 'o';
      lexem->operation[3] = 's';
    } else if (check_symbol(buf[*i + 1], 't') &&
               check_symbol(buf[*i + 2], 'a')) {
      lexem->type = 3;
      lexem->priority = 3;
      lexem->operation[1] = 't';
      lexem->operation[2] = 'a';
      lexem->operation[3] = 'n';
    }

    *i = *i + 4;
  } else if (check_symbol(buf[*i], 'l')) {
    lexem->type = 3;
    lexem->priority = 3;
    lexem->operation[0] = 'l';

    if (check_symbol(buf[*i + 1], 'o') && check_symbol(buf[*i + 2], 'g')) {
      lexem->operation[1] = 'o';
      lexem->operation[2] = 'g';
      *i = *i + 3;
    } else if (check_symbol(buf[*i + 1], 'n')) {
      lexem->operation[1] = 'n';
      *i = *i + 2;
    }
  } else if (check_symbol(buf[*i], 'm')) {
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
  (*lexem)->type = 4;
  (*lexem)->priority = 0;
  (*lexem)->operation[0] = '(';
  (*lexem)++;

  (*lexem)->type = 1;
  (*lexem)->value = -1.0;
  (*lexem)++;

  (*lexem)->type = 2;
  (*lexem)->priority = 2;
  (*lexem)->operation[0] = '*';
}

void postfix(elements *input, elements *output, int *count) {
  int count_out = *count, count_in = 0, i = 0;
  elements tmp_stack[256] = {0};
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
