#include "s21_grep.h"

int main(int argc, char *argv[]) {
  opt options = {0};  // options init
  options.num = 1;
  parser(argc, argv, &options);

  process_options(&options, argc, argv);

  if (options.flag_err) exit(1);

  // regular expression compiling

  regex_t preg = get_regex(&options);

  if (options.flag_err) {
    regfree(&preg);
    exit(1);
  }

  // file processing

  for (int i = optind; i < argc; i++) {
    char *filename = argv[i];

    f_grep(filename, &options, &preg);
  }

  regfree(&preg);

  return 0;
}

void parser(int argc, char *argv[], opt *options) {
  int x = 0;

  while ((x = getopt(argc, argv, short_options)) != -1) {
    switch (x) {
      case 'e':  // grep -e pattern -e pattern filename
        if (options->e || options->f) strcat(options->string, "\\|");
        strcat(options->string, optarg);
        options->e = 1;
        break;
      case 'i':
        options->i = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'f':
        process_f_flag(optarg, options);
        options->f = 1;
        break;
      case 'o':
        options->o = 1;
        break;
      default:
        options->flag_err = 1;
        break;
    }
  }
}

void process_options(opt *options, int argc, char *argv[]) {
  // options priority

  if (options->l) {
    options->c = 0;
    options->o = 0;
  }

  if (options->c) {
    options->o = 0;
  }

  // compatibility

  if (options->v && options->o) {
    fprintf(stderr, "./s21_grep: invalid options --'v' and -- 'o'");
    options->flag_err = 1;
  }

  // regular expression init BASIC

  if (!options->f && !options->e && !options->flag_err) {
    strcat(options->string, argv[(optind)++]);
  }

  // if multiply

  if ((argc - optind) > 1) options->multiple_files = 1;
}

regex_t get_regex(opt *options) {
  regex_t preg;
  int cflags = (options->i) ? REG_ICASE : 0;
  if (regcomp(&preg, options->string, cflags)) {
    fprintf(stderr, "regex compilation error");
    options->flag_err = 1;
  }

  return preg;
}

void f_grep(char *filename, opt *options, regex_t *preg) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    options->flag_err = 1;
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", filename);
    // exit(1);
    return;
  }

  char *line = NULL;
  size_t buffer = 0;
  ssize_t len = 0;

  while ((len = getline(&line, &buffer, file)) != -1) {
    process_line(line, preg, options, filename);

    if (options->l && options->count) {
      printf("%s\n", filename);
      break;
    }
    options->num++;
  }

  if (options->c) {
    if (options->multiple_files && !options->h) {
      printf("%s:%d\n", filename, options->count);
    } else {
      printf("%d\n", options->count);
    }
  }
  options->num = 1;
  options->count = 0;

  free(line);
  fclose(file);
}

void process_line(char *line, regex_t *preg, opt *options, char *filename) {
  int match = 0;

  size_t nmatch = 10;  // количество матчей

  // адрес всего совпадения сохраняется в pmatch[0]

  /* typdef struct{
      regoff_t rm_so; - start
      regoff_t rm_eo;  - end
  }*/
  regmatch_t pmatch[10];

  int str_offset = 0;
  int str_len = 0;

  do {
    match = !regexec(preg, line, nmatch, pmatch, 0);

    if (match != options->v) {
      options->count++;
    }

    if (options->l || options->c) continue;

    if (options->o && match) {
      str_offset = pmatch[0].rm_so;
      str_len = pmatch[0].rm_eo - pmatch[0].rm_so;
    }

    if ((options->v && !match) || (!options->v && match)) {
      f_print(line, options, str_offset, str_len, filename);
    }

    if (options->o)
      line = line + pmatch[0].rm_eo;  // сместили строку к символу,идущему после
                                      // конца совпадения
  } while (options->o && match);
}

void f_print(char *line, opt *options, int str_offset, int str_len,
             char *filename) {
  if (options->multiple_files && !options->h) {
    printf("%s:", filename);
  }

  if (options->n) {
    printf("%d:", options->num);
  }

  if (!str_offset && !str_len) {  // regular output
    printf("%s", line);

  }

  else {
    printf("%.*s", (int)str_len, &line[str_offset]);
  }

  if (options->o || (line[strlen(line) - 1] -= '\n')) {
    printf("\n");
  }
}

void process_f_flag(char *filename, opt *options) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "s21_grep: %s: No such file or directory\n", filename);
    options->flag_err = 1;
    exit(1);
  }

  char *line = NULL;
  size_t buffer = 0;
  ssize_t len = 0;

  while ((len = getline(&line, &buffer, file)) != -1) {
    if (line[strlen(line) - 1] == '\n') {  // remove '\n'
      line[strlen(line) - 1] = '\0';
    }

    if (options->e || options->f) strcat(options->string, "\\|");
    strcat(options->string, line);
  }
  fclose(file);
  free(line);
}
