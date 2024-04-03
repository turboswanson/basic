CC = gcc
CFLAGS = -Wall -Werror -Wextra --std=c11

s21_grep: s21_grep.o
	$(CC) $(CFLAGS) s21_grep.o -o s21_grep
	make clean	
s21_grep.o: s21_grep.c s21_grep.h
	$(CC) $(CFLAGS) -c s21_grep.c

clean:
	rm -rf *.o
ch:
	clang-format -n *.c	*.h
fix:
	clang-format -i *.c *.h	


