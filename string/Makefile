CC = gcc
CFLAGS = -Wall -Werror -Wextra
{SRC} = $(wildcard s21_*.c) #filename processing utility
{OBJ} = $(patsubst %.c,%.o,${SRC}) #pattern, substitution, source
{TEST_SRC} = $(wildcard ./unit_tests/s21_*.c)
LIBS = -lcheck -lpthread -lrt -lsubunit

s21_string.a: clean ${OBJ}
	ar rc s21_string.a ${OBJ}
	ranlib s21_string.a
${OBJ}:${SRC}
	$(CC) -c $(CFLAGS) $(SRC)
test:s21_string.a
	$(CC) $(CFLAGS)	$(SRC) $(TEST_SRC) @< -o test $(LIBS)
	./test
clean:
	rm -rf *.o test s21_string.a			