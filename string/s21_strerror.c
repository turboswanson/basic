#include "s21_string.h"
#include "s21_strerror.h"

char *s21_strerror(int errnum) {
    static char res[512] = {'\0'}; // static means res contains the value of the previous call   
    if(errnum < 0 || errnum > S21_ERRLIST_SIZE){
        fprintf(stderr,"Unknown error %d",errnum);
    }
    s21_strcpy(res, s21_sys_errlist[errnum]);

    return res;
}
