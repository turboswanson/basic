CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = $(wildcard s21_*.c) #filename processing utility
OBJ = $(patsubt %.c,%.o,${SRC}) #pattern,substitution,source
TEST_SRC = $(wildcard ./unit_tests/s21_*.c)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
GCOVR_PATH = ~/.local/bin/gcovr
REPORT = report/index.html
LIBS = -lcheck -lsubunit -lm -lgcov
STYLE_BASE = --style=Google
VALGRIND_FLAGS = --tool=memcheck --leak-check=yes

all: s21_matrix.a

s21_matrix.a: clean ${OBJ}
	ar rc s21_matrix.a ${OBJ}
	ranlib s21_matrix.a
${OBJ} : ${SRC}
	$(CC) -c ${SRC}
test: s21_matrix.a
	$(CC) ${CFLAGS} -g ${GCOV_FLAGS} ${SRC} ${TEST_SRC} $< -o test ${LIBS}
	./test
gcov_rep: test
	mkdir report
	$(GCOVR_PATH) -r . --html --html-details -o {REPORT}
	xdg-open $(REPORT)
gcov_report: test
	gcovr -r . --html --html-details -o report.html
	xdg-open report.html				
foo: clean all
	$(CC) -g main.c ${SRC} -lm
	./a.out
valgrind: clean test
	valgrind $(VALGRIND_FLAGS) ./test
check:
	clang-format $(STYLE_BASE) -n *.c *.h unit_tests/*.c unit_tests/*.h
fix:
	clang-format $(STYLE_BASE) -i *.c *.h unit_tests/*.c unit_tests/*.h
cpp:
	cppcheck .
clean:
	rm -rf *.o s21_matrix.a a.out *.gcno *.gcda test *.html *.css report		