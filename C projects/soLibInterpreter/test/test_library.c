#include <stdio.h>
#include <stdlib.h>

void example(void) {
    printf("Function 'example' executed.\n");
}

void test1_func(void) {
    int a = 5, b = 10;
    printf("Function 'test1_func' executed. Sum of %d and %d is %d.\n", a, b, a + b);
}

void env_func(void) {
    const char *env = getenv("LD_LIBRARY_PATH");
    if (env) {
        printf("Function 'env_func' executed. LD_LIBRARY_PATH: %s\n", env);
    } else {
        printf("Function 'env_func' executed. LD_LIBRARY_PATH is not set.\n");
    }
}

void random_func(void) {
    int random_number = rand() % 100;
    printf("Function 'random_func' executed. Random number: %d\n", random_number);
    printf(" ********************************************************* \n");
}