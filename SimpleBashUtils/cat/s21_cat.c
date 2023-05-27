#include "cat_lib.h"

int main(int argc, char *argv[])
{
    opt options = {0};

    parser(argc,argv, &options);

    // printf("%d %d %d %d %d %d %d %d\n",options.b,options.v,options.e,options.s,options.n,options.t,options.T,options.E);
    
    // optind - the first argv index that is not a flag argv[1] = -bsTte 

    // printf("%s",argv[2]);

    cat(optind,argv,options);



    return 0;
}