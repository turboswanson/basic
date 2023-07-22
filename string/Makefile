CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = $(wildcard s21_*.c) #filename processing utility
OBJ = $(patsubst %.c,%.o,${SRC}) #pattern, substitution, source
LIBS = -lcheck -lpthread -lrt -lsubunit -lm

s21_string.a: clean ${OBJ}
	ar rc s21_string.a ${OBJ}
	ranlib s21_string.a
${OBJ}:${SRC}
	$(CC) -c $(SRC)

test:s21_string.a
	checkmk clean_mode=1 test.check > test.c 
	$(CC) $(CFLAGS) test.c $< $(LIBS) -o test 
	./test
foo:clean s21_string.a
	$(CC) -g main.c s21_string.a
	./a.out		
clean:
	rm -rf *.o s21_string.a test test.c a.out		