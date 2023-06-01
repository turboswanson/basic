GCC = gcc
CFLAGS = -c -Wall -Wextra -Werror -std=c11 

all: build

build: s21_cat

s21_cat: s21_cat.o 
	$(GCC) s21_cat.o -o s21_cat

s21_cat.o: s21_cat.c s21_cat.h
	$(GCC) $(CFLAGS) s21_cat.c -o s21_cat.o -l pcre

s21_grep: s21_grep.o 
	$(GCC) grep/s21_grep.o -o grep/s21_grep -l pcre

s21_grep.o: grep/s21_grep.c grep/s21_grep.h
	$(GCC) $(CFLAGS) grep/s21_grep.c -o grep/s21_grep.o

parser_arg.o: common/parser_arg.c common/parser_arg.h
	$(GCC) $(CFLAGS) common/parser_arg.c -o common/parser_arg.o

clean:
	rm -f *.o 
	rm -f s21_cat grep/s21_grep
	clear

rebuild: clean build

start:
	s21_cat s21_cat.h

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c grep/*.c 

val:
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all grep/s21_grep -e la  grep/test.txt

cl:
	clang-format -n *.c
	clang-format -n *.h


cl-i:
	clang-format -i *.c
	clang-format -i *.h
#	clang-format -i grep/*.c
#	clang-format -i grep/*.h
	clang-format -i common/*.c
	clang-format -i common/*.h
