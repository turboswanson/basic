#include "s21_cat.h"

int main(int argc, char *argv[]) {
  opt options = {0};
  options.count = 1;
  int opt;

  // Длинные аргументы
  const struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, "benstvET", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        options.b = options.n = 1;
        break;
      case 'n':
        options.n = 1;
        break;
      case 's':
        options.s = 1;
        break;
      case 'v':
        options.v = 1;
        break;
      case 't':
        options.v = options.t = 1;
        break;
      case 'T':
        options.t = 1;
        break;
      case 'e':
        options.v = options.e = 1;
        break;
      case 'E':
        options.e = 1;
        break;
      default:
        printf("Try 'cat --help' for more information.\n");
        exit(EXIT_FAILURE);
    }
  };

  while (optind < argc) {
    char *filepath = argv[optind++];
    (access(filepath, F_OK) != 0)
        ? fprintf(stderr, "%s: %s: No such file or directory\n", "cat",
                  filepath)
        : file_print(filepath, &options);
  }
}

void file_print(char *filepath, opt *options) {
  char *line = NULL;
  size_t len = 0;
  ssize_t init_len = 0;
  // ssize_t lazy_hack2 = init_len;

  FILE *file = fopen(filepath, "r");

  while ((init_len = getline(&line, &len, file)) != -1) {
    if (init_len == 1 && options->last_empty && options->s) continue;
    (init_len == 1 && !options->lazy_hack) ? (options->last_empty = 1)
                                           : (options->last_empty = 0);

    line_prepend(line, options);
    line_print(line, options, init_len);
  }
  options->lazy_hack = 1;
  options->last_empty = 0;
  // printf("\n");

  free(line);
  fclose(file);
}

void line_prepend(char *line, opt *options) {
  if ((options->n && !options->lazy_hack) &&
      !(options->b && !strcmp(line, "\n")))
    printf("%6d\t", options->count++);
  options->lazy_hack = 0;
}

void line_print(const char *line, opt *options, size_t len) {
  for (size_t i = 0; i < len; i++)
  // while ((size_t)i < len)
  {
    unsigned char c = line[i];
    if ((options->t) && c == '\t') {
      printf("^I");
    } else if ((options->e) && c == '\n') {
      printf("$\n");
    } else if (options->v) {
      v_print(c);
    } else
      printf("%c", c);

    //   i++;
  }
}

void v_print(unsigned char c) {
  if (c == 9 || c == 10) {
    printf("%c", c);
  } else if (c >= 32 && c < 127) {
    printf("%c", c);
  } else if (c == 127) {
    printf("^?");
  } else if (c >= 128 + 32) {
    printf("M-");
    (c < 128 + 127) ? printf("%c", c - 128) : printf("^?");
  } else {
    (c > 32) ? printf("M-^%c", c - 128 + 64) : printf("^%c", c + 64);
  }
}
