#ifndef GREP
#define GREP
#define _GNU_SOURCE
#include <fcntl.h>
#include <getopt.h>
#include <regex.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_GROUPS 10

#define ERRMSG                                                              \
  "Usage: grep [OPTION]... PATTERNS [FILE]...\nTry 'grep --help' for more " \
  "information.\n"

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int line_num;
  int line_count;
  int multiple_files;
  char *file;
  char *regex_file;
  char *regex;
  int trailing_n;
  int error;
  regex_t re;
} opt;

void free_everything(size_t n, ...);
void remove_endline(char *str);
void regex_file_parse(opt *options, char *filepath);
void file_grep(char *filepath, opt *options);
void regex_cat(char **regex_string, char *regex);
int process_flags(int argc, char *argv[], opt *options);
void line_print(char *line, opt *options, int offset, int length);
void graceful_exit(opt *options);
int regex_compile(opt *options);
void process_options(opt *options, int argc, int *optind, char *argv[]);
void process_f_flag(char *progname, opt *options, char *optarg);
void process_data_files(opt *options, char *argv[], int argc, int optind);

// int regex_compile(opt *options, char *argv[]);
#endif