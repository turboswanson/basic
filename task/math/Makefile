CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC=$(wildcard s21_*.c)  #filename processing function
OBJ=$(patsubst %.c,%.o,${SRC}) #pattern,substitution,text
TEST_SRC = $(wildcard ./unit_tests/s21_*.c)

LIBS = -lcheck -lsubunit -lrt -lpthread -lm 

s21_math.a:	${OBJ}
	ar rc s21_math.a ${OBJ}
	ranlib s21_math.a

${OBJ}:${SRC}
	$(CC) -c ${SRC}

test:s21_math.a
	$(CC) $(FLAGS) $(TEST_SRC) $< -o test $(LIBS)  	
	./test
	
clean:
	rm -f *.o *.a *.out test
