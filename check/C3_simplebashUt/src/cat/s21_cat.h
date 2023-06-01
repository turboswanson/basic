#ifndef CAT
#define CAT
#define _GNU_SOURCE
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int v;
  int b;
  int e;
  int n;
  int s;
  int t;
  int count;
  int last_empty;
  int lazy_hack;
} opt;

void file_print(char *filepath, opt *options);
void line_prepend(char *line, opt *options);
void v_print(unsigned char c);
void line_print(const char *line, opt *options, size_t len);
#endif