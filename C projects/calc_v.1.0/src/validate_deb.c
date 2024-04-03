#include "calc.h"

int main(){
    char *str = "1.3337777777777777777";
    int error = validation(str);
    long double res = 0.0;
    sscanf(str,"%Lf",&res);
    printf("%.8Lf",res);

    return 0;
}