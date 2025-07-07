CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -std=c11
LIBFLAGS = $(CFLAGS) -fPIC
LDFLAGS = -ldl
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
TARGET = sotest
TEST_DIR = test
TEST_SCRIPTS_DIR = test_scripts
SO_FILES = $(patsubst %.c,%.so,$(wildcard $(TEST_DIR)/*.c))
SRC = main.c library_handler.c
SCRIPT_ONE = $(TEST_SCRIPTS_DIR)/test_one.sc
SCRIPT_TWO = $(TEST_SCRIPTS_DIR)/test_two.sc
SCRIPT_THREE = $(TEST_SCRIPTS_DIR)/test_three.sc

all: clean $(TARGET) $(SO_FILES)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

$(TEST_DIR)/%.so: $(TEST_DIR)/%.c
	$(CC) $(LIBFLAGS) -shared -o $@ $< -lm

test_one: clean $(TARGET) $(SO_FILES)
	@echo "Running tests..."
	LD_LIBRARY_PATH=$(pwd/test) ./$(TARGET) $(SCRIPT_ONE)
test_two: clean $(TARGET) $(SO_FILES)
	@echo "Running tests..."
	LD_LIBRARY_PATH=$(pwd/test) ./$(TARGET) $(SCRIPT_TWO)
test_three: clean $(TARGET) $(SO_FILES)
	@echo "Running tests..."
	LD_LIBRARY_PATH=$(pwd/test) ./$(TARGET) $(SCRIPT_THREE)
memcheck: clean $(TARGET) $(SO_FILES)
	valgrind $(VALGRIND_FLAGS) ./$(TARGET) $(SCRIPT_ONE)
clean:
	@rm -f $(TARGET) $(SO_FILES)