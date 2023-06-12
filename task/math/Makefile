CC=gcc
FLAGS=-Wall -Werror -Wextra
SRC=$(wildcard s21_*.c)  #filename processing function
OBJ=$(patsubst %.c,%.o,${SRC}) #pattern,substitution,text
TEST_SRC=$(wildcard ./unit_tests/s21_*.c)
LIBS=-lcheck -lsubunit -lm 

s21_math.a:	${OBJ}
	ar cr s21_math.a ${OBJ}
${OBJ}:${SRC}
	$(CC) -c ${SRC}

test:s21_math.a
	$(CC) $(FLAGS) $(TEST_SRC) $< -o unit_test $(LIBS)  	

	
clean:
	rm -f *.o *.a *.out		