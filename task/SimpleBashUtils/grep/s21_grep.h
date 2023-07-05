#ifndef GREP_H
#define GREP_H
#define _GNU_SOURCE

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define short_options "e:ivclnhsf:o"

typedef struct {
  int e;  // several  patterns
  int i;  // no registr
  int v;  // remainder
  int c;  // count
  int l;  // list
  int n;  // number
  int h;  // hide filename
  int s;  // hide errors
  int f;  // pattern file
  int o;  // print pattern without the rest
  int multiple_files;
  int flag_err;
  char string[256];
  int count;
  int num;
} opt;

void parser(int argc, char *argv[], opt *options);

void process_options(opt *options, int argc, char *argv[]);

regex_t get_regex(opt *options);

void f_grep(char *filename, opt *options, regex_t *preg);

void process_line(char *line, regex_t *preg, opt *options, char *filename);

void f_print(char *line, opt *options, int str_offset, int str_len,
             char *filename);

void process_f_flag(char *filename, opt *options);

#endif