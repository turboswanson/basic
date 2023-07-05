#include "s21_grep.h"

int main(int argc, char *argv[]) {
  opt options = {0};
  int opt;

  options.regex = NULL;
  options.line_num = 1;

  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        options.e = 1;
        regex_cat(&options.regex, optarg);
        break;
      case 'i':
        options.i = 1;
        break;
      case 'v':
        options.v = 1;
        break;
      case 'c':
        options.c = 1;
        break;
      case 'l':
        options.l = 1;
        break;
      case 'n':
        options.n = 1;
        break;
      case 'h':
        options.h = 1;
        break;
      case 's':
        options.s = 1;
        break;
      case 'f':
        options.f = 1;
        process_f_flag(argv[0], &options, optarg);
        break;
      case 'o':
        options.o = 1;
        break;
      default:
        fprintf(stderr, ERRMSG);
        graceful_exit(&options);
        exit(EXIT_FAILURE);
    }
  }

  process_options(&options, argc, &optind, argv);

  if (!options.error) process_data_files(&options, argv, argc, optind);

  graceful_exit(&options);
  (options.error) ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);
}

void process_data_files(opt *options, char *argv[], int argc, int optind) {
  for (int i = optind; i < argc; i++) {
    if (access(argv[i], F_OK) != 0) {
      if (!options->s)
        fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
                argv[i]);
      continue;
    }
    file_grep(argv[i], options);
  }
}

void process_f_flag(char *progname, opt *options, char *optarg) {
  if (access(optarg, F_OK) != 0) {
    fprintf(stderr, "%s: %s: No such file or directory\n", progname, optarg);
    options->error = 1;
  } else {
    regex_file_parse(options, optarg);
  }
}

void process_options(opt *options, int argc, int *optind, char *argv[]) {
  if (options->l) options->c = options->o = 0;
  if (options->c) options->o = 0;

  if (options->v && options->o) options->error = 1;
  if (*optind + 1 - (options->f || options->e) >= argc) options->error = 1;
  if (!options->f && !options->e && !options->error)
    regex_cat(&options->regex, argv[(*optind)++]);
  if ((argc - *optind) > 1) options->multiple_files = 1;
  if (options->regex) regex_compile(options);
}

void process_line(char *line, opt *options) {
  int match = 0;

  int str_offset = 0;
  int str_len = 0;
  regmatch_t matches[MAX_GROUPS];

  // получаем матч
  do {
    match = !regexec(&options->re, line, MAX_GROUPS, matches, 0);
    if (match != options->v) options->line_count++;

    if (options->l || options->c) continue;

    if (options->o && match) {
      str_offset = matches[0].rm_so;
      str_len = matches[0].rm_eo - matches[0].rm_so;
    }

    if (options->v) {
      if (!match) line_print(line, options, str_offset, str_len);
    } else {
      if (match) line_print(line, options, str_offset, str_len);
      // if (match) printf("%s", line);
    }

    if (options->o) line = line + matches[0].rm_eo;
  } while (options->o && match);
}

void file_grep(char *filepath, opt *options) {
  char *line = NULL;
  size_t buf_len = 0;
  ssize_t line_len;
  FILE *file = fopen(filepath, "r");

  options->file = filepath;

  while ((line_len = getline(&line, &buf_len, file)) != -1) {
    process_line(line, options);
    if (options->l && options->line_count) {
      printf("%s\n", options->file);
      break;
    }
    options->line_num++;
  }
  if (options->c) {
    (options->multiple_files && !options->h)
        ? printf("%s:%d\n", options->file, options->line_count)
        : printf("%d\n", options->line_count);
  }

  options->line_num = 1;
  options->line_count = 0;

  free(line);
  fclose(file);
}

void regex_cat(char **regex_string, char *regex) {
  char *tmp = malloc(
      ((*regex_string ? strlen(*regex_string) + 2 : 0) + strlen(regex) + 1) *
      sizeof(char));

  sprintf(tmp, "%s%s%s", *regex_string ? *regex_string : "",
          *regex_string ? "\\|" : "", regex);
  // поменять на sizeof???
  *regex_string = realloc(*regex_string, strlen(tmp) + 1);

  strcpy(*regex_string, tmp);
  free(tmp);
}

int regex_compile(opt *options) {
  int reti = 0;

  // reti = regcomp(&options->re, options->regex, options->i ? REG_ICASE : 0);
  reti = regcomp(&options->re, options->regex,
                 (options->i ? REG_ICASE : 0 | REG_NEWLINE));

  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    options->error = 1;
  }
  return reti;
}

void line_print(char *line, opt *options, int offset, int length) {
  if (options->multiple_files && !options->h) printf("%s:", options->file);
  if (options->n) printf("%d:", options->line_num);
  (!offset && !length) ? printf("%s", line)
                       : printf("%.*s", (int)length, &line[offset]);

  if (options->o == 1 || (line[strlen(line) - 1] -= '\n')) printf("\n");
}

void regex_file_parse(opt *options, char *filepath) {
  char *line = NULL;
  size_t buf_len = 0;
  ssize_t line_len;
  FILE *file = fopen(filepath, "r");
  while ((line_len = getline(&line, &buf_len, file)) != -1) {
    remove_endline(line);
    regex_cat(&options->regex, line);
  }
  fclose(file);
  free(line);
}

void remove_endline(char *str) {
  if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
}

void graceful_exit(opt *options) {
  regfree(&options->re);
  if (options->regex) free(options->regex);
}