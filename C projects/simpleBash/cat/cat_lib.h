#ifndef CAT_LIB_H
#define CAT_LIB_H

#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

typedef struct opt {
  int b;
  int e;
  int v;
  int n;
  int s;
  int t;
  int E;
  int T;
  int h;
} opt;

int parser(int argc, char *argv[], opt *options);

void cat(int z, char *argv[], opt options);

#endif