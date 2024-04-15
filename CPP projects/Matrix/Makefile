CXX = g++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++
DEBUG_FLAG = -ggdb
CHECKFLAG=-lgtest
GCOV_FLAGS=-fprofile-arcs -ftest-coverage --coverage
SRC_DIR = ./source
BUILD_DIR = ./build
BIN_DIR = ./bin
REPORT_DIR = ./report
TEST_DIR = ./test
INCLUDE_DIR = ./include
EXCLUDE_PATH = ./test
SRC = $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRC = ./test/s21matrix_test.cpp
SRC_OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))
TEST_OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(TEST_DIR)/%.o,$(SRC))
TEST_SRC = $(TEST_DIR)/*.cpp
LIB = s21_matrix_oop.a
EXECUTABLE = debug
TEST_EXECUTABLE = s21matrix_test
GCOV_EXECUTABLE = report
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(BUILD_DIR)/valgrind-out.txt
CPPCHECK_FLAGS = --language=c++
STYLE_BASE=--style=Google

.PHONY: test debug

all: clean createDirBuild createBinDir $(BIN_DIR)/$(LIB)

createDirBuild:
	@if [ ! -d "$(BUILD_DIR)" ]; then mkdir $(BUILD_DIR);fi
createBinDir:
	@if [ ! -d "$(BIN_DIR)" ]; then mkdir $(BIN_DIR);fi
createReportDir:
	@if [ ! -d "$(REPORT_DIR)" ]; then mkdir $(REPORT_DIR);fi			
$(BIN_DIR)/$(LIB): $(SRC_OBJ)
	ar rc $@ $^ 
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@
$(TEST_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@
test: createBinDir $(BIN_DIR)/$(TEST_EXECUTABLE)
	./$(BIN_DIR)/$(TEST_EXECUTABLE)
$(BIN_DIR)/$(TEST_EXECUTABLE): $(TEST_OBJ)
	$(CXX) $^ $(TEST_SRC) $(CHECKFLAG) -o $@
gcov_report: clean createReportDir	
	$(CXX) $(CXX_FLAGS) $(GCOV_FLAGS) $(TEST_SRC) $(SRC) $(CHECKFLAG) -o $(REPORT_DIR)/$(GCOV_EXECUTABLE)
	./$(REPORT_DIR)/$(GCOV_EXECUTABLE)
	gcovr -r . -e test --html --html-details -o $(REPORT_DIR)/report.hmtl
	xdg-open $(REPORT_DIR)/report.hmtl
debug: all
	$(CXX) $(CXX_FLAGS) $(DEBUG_FLAG) debug.cpp -o $(BIN_DIR)/$(EXECUTABLE) $(BIN_DIR)/$(LIB)
	./$(BIN_DIR)/$(EXECUTABLE)
memcheck: createDirBuild test
	valgrind $(VALGRIND_FLAGS) ./$(BIN_DIR)/$(TEST_EXECUTABLE)
	cat $(BUILD_DIR)/valgrind-out.txt
check_style:
	clang-format $(STYLE_BASE) -n $(SRC) $(TEST_SRC) $(INCLUDE_DIR)/*.h
fix_style:
	clang-format $(STYLE_BASE) -i $(SRC) $(TEST_SRC) $(INCLUDE_DIR)/*.h
cppcheck:
	cppcheck $(CPPCHECK_FLAGS) $(SRC) $(INCLUDE_DIR)/*.h		
clean:
	rm -rf $(TEST_DIR)/*.o $(BUILD_DIR) $(BIN_DIR) $(REPORT_DIR)
	
# $@ - target
# $< - the first dependencie
# $^ - all dependencies
