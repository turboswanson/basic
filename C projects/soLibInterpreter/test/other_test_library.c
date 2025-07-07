#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse_string(void) {
    char str[] = "Hello, World!";
    size_t len = strlen(str);
    char reversed[len + 1];

    for (size_t i = 0; i < len; i++) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';

    printf("Function 'reverse_string' executed. Original: %s, Reversed: %s\n", str, reversed);
}

void calculate_sqrt(void) {
    double number = 25.0;
    double result = sqrt(number);
    printf("Function 'calculate_sqrt' executed. Square root of %.2f is %.2f\n", number, result);
}

void division_by_random(void) {
    fprintf(stderr, "Function 'division_by_zero' executed. Simulating division by zero...\n");
    double a = 10, b = (double)rand() / RAND_MAX * 100.0;
    if (!b) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Result: %lf\n", a / b);
}

void random_float(void) {
    float random_number = (float)rand() / RAND_MAX * 100.0; 
    printf("Function 'random_float' executed. Random float: %.2f\n", random_number);
    printf(" ********************************************************* \n");
}