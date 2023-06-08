CC = gcc
CFLAGS = -Wall -Werror -Wextra --std=c11

s21_cat: s21_cat.o cat_lib.o
	$(CC) $(CFLAGS) s21_cat.o cat_lib.o -o s21_cat
	make clean	
s21_cat.o: s21_cat.c cat_lib.h
	$(CC) $(CFLAGS) -c s21_cat.c
cat_lib.o: cat_lib.c cat_lib.h
	$(CC) $(CFLAGS) -c cat_lib.c
test:
	bash ./tests/test_cat.sh
clean:
	rm -rf *.o	
ch:
	clang-format -n *.c	*.h
fix:
	clang-format -i *.c *.h	

