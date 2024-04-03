CC=gcc
DEBUG_FLAG=-g
CFLAGS=-Wall -Werror -Wextra -std=c11
LIBS=-lcheck -lsubunit -lm -lgcov
GCOV_FLAGS=-fprofile-arcs -ftest-coverage --coverage
VALGRIND_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes --error-limit=no
STYLE_BASE=--style=Google
LOG_FLAG=--log-file

QMAKE_PATH=/home/mitchelk/Qt6/6.6.2/gcc_64/bin/qmake
# QMAKE_PATH=/home/nenamaxi/Qt/6.6.1/gcc_64/bin/qmake
# QMAKE_PATH=/usr/lib/qt6/bin/qmake  
PRO_PATH=../front/s21_3dViewer.pro
GCOVR_PATH=gcovr
BUILD_DIR=build
INSTALL_PATH= $(BUILD_DIR)
EXCLUDE_PATH=tests

PARSER_DIR=parser
TRANSFORM_DIR=transform
FRONT_DIR=front
TEST_DIR=tests

SOURCES_CPP=$(shell find front -name '*.cpp')
HEADER_HPP=$(shell find front -name '*.hpp')
HEADER_H=$(shell find front -name '*.h')
PARSER_SOURCES=$(shell find parser -name '*.c')
PARSER_HEADER=$(shell find parser -name '*.h')
TEST_SOURCES=$(shell find tests -name '*.c')
TEST_HEADER=$(shell find tests -name '*.h')

TRANSFORM_SOURCES=$(shell find transform -name '*.c')
TRANSFORM_HEADER=$(shell find transform -name '*.h')

OBJECTS=$(SOURCES:.c=.o)

LOG_FILE=3d_viewer.log 

EXECUTABLE=s21_3dViewer
TEST_EXECUTABLE=test

all: clean install run

run: 
	./$(INSTALL_PATH)/$(EXECUTABLE)

install : createDirBuild
	@cd $(INSTALL_PATH) && $(QMAKE_PATH) -o Makefile $(PRO_PATH) && make

uninstall:
	rm -rf $(INSTALL_PATH)

dist:
	@mkdir dist
	cp -r $(PARSER_DIR) $(TRANSFORM_DIR) $(FRONT_DIR) Makefile dist
	tar cvzf s21_3dViewer_v1.0.tgz dist/
	rm -rf dist

.PHONY : tests

tests:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(PARSER_SOURCES) $(TRANSFORM_SOURCES) $(TEST_SOURCES) -o $(TEST_DIR)/test $(LIBS)
	./$(TEST_DIR)/$(TEST_EXECUTABLE)

gcov_report: tests createDirReport
	$(GCOVR_PATH) -r . -e $(EXCLUDE_PATH) --html --html-details -o $(TEST_DIR)/report_dir/report.hmtl
	xdg-open $(TEST_DIR)/report_dir/report.hmtl

val: tests
	valgrind $(VALGRIND_FLAGS) ./$(TEST_DIR)/$(TEST_EXECUTABLE)

check:
	clang-format $(STYLE_BASE) -n  $(HEADER_HPP) $(HEADER_H) $(SOURCES_CPP) $(PARSER_SOURCES) $(TRANSFORM_SOURCES) $(PARSER_HEADER) $(TRANSFORM_HEADER) $(TEST_SOURCES) $(TEST_HEADER)

fix:
	clang-format $(STYLE_BASE) -i  $(HEADER_HPP) $(HEADER_H) $(SOURCES_CPP) $(PARSER_SOURCES) $(TRANSFORM_SOURCES) $(PARSER_HEADER) $(TRANSFORM_HEADER) $(TEST_SOURCES) $(TEST_HEADER)

documentation:
	doxygen Doxyfile

latexPdf: documentation
	@cd ./Docs/latex/ && make pdf > /dev/null 2>&1
	@mv ./Docs/latex/refman.pdf DocumentationDVI.pdf

dvi: 
	xdg-open DocumentationDVI.pdf

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -o $(DEBUG_FLAG) $< -o $(INSTALL_PATH)/$@

createDirBuild:
	@if [ ! -d "$(INSTALL_PATH)" ]; then mkdir $(INSTALL_PATH); fi

createDirReport:
	@if [ ! -d "$(TEST_DIR)/report_dir" ]; then mkdir $(TEST_DIR)/report_dir; fi


clean:
	rm -rf $(INSTALL_PATH) $(EXECUTABLE) $(TEST_DIR)/*gcno $(TEST_DIR)/*.gcda $(TEST_DIR)/*.html $(TEST_DIR)/*.css $(TEST_DIR)/$(TEST_EXECUTABLE) 
	rm -rf *.css *tgz $(TEST_DIR)/report_dir/
	rm -rf Docs
# $@ - targetname
# $< - the first dependency
# $^ - all dependencies	