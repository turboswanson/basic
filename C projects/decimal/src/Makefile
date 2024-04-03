CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = $(wildcard s21_*.c) 
OBJ = $(patsubst %.c,%.o,${SRC})
TEST_SRC = $(wildcard ./unit_tests/s21_*.c)
LIBS = -lcheck -lsubunit -lrt -lpthread -lm -lgcov
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
GCOVR_PATH=~/.local/bin/gcovr
REPORT=report/index.html
STYLE_BASE=--style=Google
VALGRIND_FLAGS=--tool=memcheck --leak-check=yes

all: s21_decimal.a

s21_decimal.a: clean ${OBJ}
	ar rc s21_decimal.a ${OBJ}
	ranlib s21_decimal.a
${OBJ}:${SRC}
	$(CC) -c ${SRC}
test: s21_decimal.a
	$(CC) $(CFLAGS) -g $(GCOV_FLAGS) $(SRC) $(TEST_SRC) $< -o test $(LIBS) 
	./test
gcov_rep:test
	mkdir report
	$(GCOVR_PATH) -r . --html --html-details -o $(REPORT)
	xdg-open $(REPORT)
gcov_report:test
	gcovr -r . --html --html-details -o report.html
	xdg-open report.html
lcov_report:test
	lcov -t "test" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	xdg-open $(REPORT)

foo:clean all
	$(CC) -g example.c $(SRC) -lm
	./a.out
check:
	clang-format $(STYLE_BASE) -n *.c *.h unit_tests/*.c unit_tests/*.h

fix:
	clang-format $(STYLE_BASE) -i *.c *.h unit_tests/*.c unit_tests/*.h
cpp:
	cppcheck .

valgrind: clean test
	valgrind $(VALGRIND_FLAGS) ./test		

clean:
	rm -rf *.o s21_decimal.a a.out test test.c *.gcda *.gcno *.html rm-rf report *.info *.css

