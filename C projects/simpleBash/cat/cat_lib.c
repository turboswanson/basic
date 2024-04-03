#include "cat_lib.h"

int parser(int argc, char *argv[], opt *options) {
  int x = 0;

  const char *shorts = "benstvET";
  const struct option longs[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                 {"number", no_argument, NULL, 'n'},
                                 {"squeeze-blank", no_argument, NULL, 's'},
                                 {"help", no_argument, NULL, 'h'},
                                 {NULL, no_argument, NULL, 0}};

  int index;

  while ((x = getopt_long(argc, argv, shorts, longs, &index)) != -1) {
    switch (x) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'E':
        options->E = 1;
        break;
      case 'T':
        options->T = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      default:
        return 0;
    }
  }

  return 1;
}

void cat(int z, char *argv[], opt options) {
  FILE *f = fopen(argv[z], "r");
  if (options.h) {
    printf("Go to look somewhere else");

  }

  else if (!f) {
    fprintf(stderr, "s21_cat: %s : No such file or directory\n", argv[z]);

  }

  else {
    int c;
    int count = 0, counter_check = 0, flag = 0;

    while ((c = getc(f)) != EOF) {
      if ((flag == 2) && (options.s) && (c == '\n')) {
        continue;
      }

      if (options.b) {
        if (c != '\n') {
          if (counter_check == 0) {
            printf("%6d\t", ++count);
            counter_check = 1;
          }

        }

        else {
          counter_check = 0;
        }
        // printf(" %d ",counter_check);     // print counter_check everytime to
        // see how it works
      }

      else if (options.n) {
        if (counter_check == 0) {
          printf("%6d\t", ++count);
          counter_check = 1;
        }

        if (c == '\n') {
          counter_check = 0;
        }
        // printf(" %d ",counter_check);    // print counter_check everytime to
        // see how it works
      }

      if ((options.t || options.T) && (c == '\t'))  //  09 - horizontal tab
      {
        printf("^");
        c = 'I';  //'\t' + 64;
      }

      if (c == '\n') {
        if (options.E || options.e) {
          printf("$");
        }
        flag++;
      } else {
        if (flag) {
          flag = 0;
        }
      }

      if (options.v) {
        // if (c >= 0 && c <= 31 && c != '\n' && c != '\t') {
        //   printf("^");
        //   c = c + 64;
        // }

        // if (c > 127 && c < 160) printf("M-^");
        // if ((c < 32 && c != '\n' && c != '\t') || c == 127) printf("^");
        // if ((c < 32 || (c > 126 && c < 160)) && c != '\n' && c != '\t') c = c
        // > 126 ? c - 128 + 64 : c + 64;

        if (c == 9 || c == 10) {
          printf("%c", c);
        }

        else if (c >= 32 && c < 127) {
          printf("%c", c);
        }

        else if (c == 127) {
          printf("^?");
        }

        else if (c >= 128 + 32) {
          printf("M-");
          (c < 128 + 127) ? printf("%c", c - 128) : (printf("^?"));
        } else {
          (c > 32) ? printf("M-^%c", c - 128 + 64) : printf("^%c", c + 64);
        }
      }

      else {
        printf("%c", c);
      }
    }

    fclose(f);
  }
}
