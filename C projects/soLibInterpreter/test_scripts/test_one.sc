# Regular test script for sotest

use test/test_library.so
vcall example      #### SYNTAX ERROR
call test1_func
call env_func
call random_func
use test/other_test_library.so
call reverse_string
call calculate_sqrt
call division_by_random
call random_float
use test/test_library.so
call example
call test1_func
call env_func
call random_func
use test/other_test_library.so
call reverse_string
trcall calculate_sqrt    #### SYNTAX ERROR
call division_by_random
call random_float
use test/test_library.so
call example
call test1_func
call env_func
call random_func
use test/other_test_library.so
call reverse_string
call calculate_sqrt
call division_by_random
call random_float

