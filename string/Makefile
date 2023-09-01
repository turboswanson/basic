CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard s21_*.c) #filename processing utility
OBJ = $(patsubst %.c,%.o,${SRC}) #pattern, substitution, source
LIBS = -lcheck -lpthread -lrt -lsubunit -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
REPORT = report/index.html
GCOVR_PATH=~/.local/bin/gcovr
VALGRIND_FLAGS=--tool=memcheck --leak-check=yes
STYLE_BASE=--style=Google


all: s21_string.a test

s21_string.a: clean ${OBJ}
	ar rc s21_string.a ${OBJ}
	ranlib s21_string.a

${OBJ}:${SRC}
	$(CC) -c $(SRC)

test:s21_string.a
	checkmk clean_mode=1 test.check > test.c 
	$(CC) $(CFLAGS) $(GCOV_FLAGS) test.c $< $(LIBS) -o test 
	./test

foo:clean
	$(CC) -g main.c ${SRC} -lm
	./a.out

gcov_rep:test
	gcovr --html -o report.html
	xdg-open report.html
gcov_report:test
	mkdir report
	$(GCOVR_PATH) -r . --html --html-details -o $(REPORT)
	xdg-open $(REPORT)

valgrind: clean
	valgrind $(VALGRIND_FLAGS) make test

check:
	clang-format $(STYLE_BASE) -n *.c *.h
fix:
	clang-format $(STYLE_BASE) -i *.c *.h			

clean:
	rm -rf *.o s21_string.a test test.c a.out report *.info *.gcda *.gcno *.html		