TEST_FLAGS = -lgtest -pthread

all: 
	g++ sample.cpp -o sample
	./sample
test:
	g++ tests/map_tests.cpp tests/array_tests.cpp tests/queue_tests.cpp tests/stack_tests.cpp tests/vector_tests.cpp tests/tests_main.cpp $(TEST_FLAGS) -o test
	./test
	rm test
memcheck:
	valgrind ./test
clean:
	rm sample test
			
