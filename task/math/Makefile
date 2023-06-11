CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
TEST_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck

SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o,${SRC})
TEST_SRC=$(wildcard ./unit_tests/s21_*.c)

s21_math.a: $(OBJ)
	ar cr s21_math.a $(OBJ)
$(OBJ):$(SRC)
	gcc -c $(SRC)
clean:
	rm -f *.o *.a

test: s21_math.a
	$(CC) $(FLAGS) $(TEST_SRC) -o unit_test $(LIBS) $(TEST_FLAGS)
	./unit_test 			