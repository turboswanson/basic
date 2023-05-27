CC = gcc
CFLAGS = -Wall -Werror -Wextra

s21_cat: s21_cat.o cat_lib.o
	$(CC) $(CFLAGS) s21_cat.o cat_lib.o
	make clean	
s21_cat.o: s21_cat.c cat_lib.h
	$(CC) $(CFLAGS) -c s21_cat.c
cat_lib.o: cat_lib.c cat_lib.h
	$(CC) $(CFLAGS) -c cat_lib.c
clean:
	rm -rf *.o	

