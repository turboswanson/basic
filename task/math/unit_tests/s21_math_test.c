#include "s21_math_test.h"

void run_test(void){
    Suite *list[] = {
        suite_abs(),suite_fabs(),NULL
    };

  for (Suite **current_testcase = list; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

void run_testcase(Suite *testcase){
    static int counter = 1;

    if(counter > 0) putchar('\n');
    printf("%s%d%s","CURRENT TEST: ",counter,"\n");
    counter++;
    SRunner *sr = srunner_create(testcase);

    srunner_set_fork_status(sr,CK_NOFORK);
    srunner_run_all(sr,CK_NORMAL);

    srunner_free(sr);
}

int main(void){
    run_test();

    return 0;
}