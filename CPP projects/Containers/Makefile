CC = g++
CCFLAGS = -Wall -Wextra -Wextra -std=c++17 -g
TESTFLAGS = -lgtest -lm -pthread
RM = rm -rf

GCOVR = $(shell which gcovr || echo ~/.local/bin/gcovr)
# pip install gcovr

# имя тестового файла
TESTS_NAME = s21_containers_test
# имя тестового файла c тестами покрытия кода gcovr
TESTS_GCOV_NAME = s21_containers_gcov

# основные файлы и директории
DIR = ./s21_containers
DIR_PLUS = ./s21_containersplus
HEADER = s21_containers.h
HEADER_PLUS = s21_containersplus.h

# файлы и директории тестов
TEST_DIR = tests/
TEST_OBJ = $(TEST_SRC:.cpp=.o)
TEST_SRC = $(shell find $(TEST_DIR) -name "*.cpp")

.PHONY: all clean test gcov_report

all: test

test: clean $(TESTS_NAME)
	./$(TESTS_NAME)

$(TESTS_NAME): $(TEST_OBJ) $(HEADER) $(HEADER_PLUS)
	$(CC) $(CCFLAGS) $^ $(TESTFLAGS) -o $@ 

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@
	
gcov_report:clean_gcov clean_report $(TESTS_GCOV_NAME)
	./$(TESTS_GCOV_NAME)
	mkdir report
	$(GCOVR) -r . --exclude-throw-branches --exclude-unreachable-branches --html --html-details -o report/coverage.html --exclude=$(TEST_DIR)
	make clean_gcov
	xdg-open report/coverage.html

$(TESTS_GCOV_NAME): $(TEST_SRC) $(HEADER) $(HEADER_PLUS)
	$(CC) $(CCFLAGS) -g -fprofile-arcs -ftest-coverage $^ $(TESTFLAGS) -o $@

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(shell find -name "*.cpp")
	clang-format -n $(shell find -name "*.tpp")
	clang-format -n $(shell find -name "*.hpp")
	rm -rf .clang-format

cpp:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem $(DIR) $(DIR_PLUS)

val: test
	valgrind --tool=memcheck --leak-check=yes ./$(TESTS_NAME)

clean: clean_gcov clean_report
	$(RM) $(TESTS_NAME)
	$(RM) $(shell find $(DIR) -name "*.o")
	$(RM) $(shell find $(DIR_PLUS) -name "*.o")
	$(RM) $(shell find $(TEST_DIR) -name "*.o")

clean_report:
	$(RM) report

clean_gcov:
	$(RM) $(TESTS_GCOV_NAME)
	$(RM) *.gcda
	$(RM) *.gcno
