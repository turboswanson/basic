TEST_FLAGS = -lgtest -pthread

all: 
	g++ sample.cpp -o sample
	./sample
test:
	g++ tests/*.cpp $(TEST_FLAGS) -o test
	./test
memcheck:
	valgrind ./test
clean:
	rm sample test
			
