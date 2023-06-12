CC=gcc
FLAGS=-Wall -Werror -Wextra
SRC=$(wildcard s21_*.c)  #filename processing function
OBJ=$(patsubst %.c,%.o,${SRC}) #pattern,substitution,text

s21_math.a:	${OBJ}
	ar cr s21_math.a ${OBJ}
${OBJ}:${SRC}
	$(CC) -c ${SRC}
clean:
	rm -f *.o *.a		