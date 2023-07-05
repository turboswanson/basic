GCC = gcc
CFLAGS = -c -Wall -Wextra -Werror -std=c11 

all: build

build: s21_grep 

s21_grep: s21_grep.o 
	$(GCC) s21_grep.o -o s21_grep 

s21_grep.o: s21_grep.c s21_grep.h
	$(GCC) $(CFLAGS) s21_grep.c -o s21_grep.o -l regex


clean:
	rm -f *.o 
	rm -f s21_grep
	clear

rebuild: clean build

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c11 *.c *.c 

val:
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all s21_grep -e la  test.txt

cl:
	clang-format -n *.c
	clang-format -n *.h


cl-i:
	clang-format -i *.c
	clang-format -i *.h
#	clang-format -i *.c
#	clang-format -i *.h
	clang-format -i common/*.c
	clang-format -i common/*.h
