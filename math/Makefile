CC = gcc

SRC=$(wildcard s21_*.c)  #filename processing function
OBJ=$(patsubst %.c,%.o,${SRC}) #pattern,substitution,text
TEST_SRC=$(wildcard ./unit_tests/s21_*.c)
GCOVR_PATH=~/.local/bin/gcovr

FLAGS = -Wall -Werror -Wextra -std=c11
LIBS = -lcheck -lsubunit -lrt -lpthread -lm 
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
REPORT=report/index.html
VALGRIND_FLAGS=--tool=memcheck --leak-check=yes

STYLE_BASE=--style=Google

s21_math.a:	clean ${OBJ}
	ar rc s21_math.a ${OBJ}
	ranlib s21_math.a

${OBJ}:${SRC}
	$(CC) -c ${SRC}

test:s21_math.a
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) $< -o test $(LIBS)  
	./test

gcov_report:test
	mkdir report
	$(GCOVR_PATH) -r . --html --html-details -o $(REPORT)
	xdg-open $(REPORT)

lcov_report:test
	lcov -t "s21_math_test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	xdg-open $(REPORT)

check:
	clang-format $(STYLE_BASE) -n *.c *.h unit_tests/*.c unit_tests/*.h

fix:
	clang-format $(STYLE_BASE) -i *.c *.h unit_tests/*.c unit_tests/*.h

valgrind: clean
	valgrind $(VALGRIND_FLAGS) make test

cpp:
	cppcheck .

mini_verter:
	bash ../materials/build/run.sh

clean:
	rm -f *.o *.a *.out *.gcno *.gcda *.info
	rm -rf report test