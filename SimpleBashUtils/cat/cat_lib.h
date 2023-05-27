#ifndef CAT_LIB_H
#define CAT_LIB_H

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

typedef struct opt
{
    int b;
    int e;
    int v;
    int n;
    int s;
    int t;
    int E;
    int T;
}opt;

void parser(int argc, char *argv[], opt *options);

void cat(int z,char *argv[], opt options);

#endif