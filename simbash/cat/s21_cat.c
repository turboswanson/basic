#include "cat_lib.h"

int main(int argc, char *argv[]) {
  opt options = {0};

  if (parser(argc, argv, &options)) {
    // printf("%d %d %d %d %d %d %d
    // %d\n",options.b,options.v,options.e,options.s,options.n,options.t,options.T,options.E);

    // optind - the first argv index that is not a flag argv[1] = -bsTte

    // printf("%d",argc);

    cat(optind, argv, options);
  }

  else {
    printf("Try 's21_cat --help' for more information.\n");
  }

  return 0;
}