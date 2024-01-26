CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LIBS = -lm `pkg-config --cflags --libs gtk+-3.0`
TEST_LIBS = -lcheck -lsubunit -lgcov
SRC = main.c display.c parser.c calculation.c validation.c graph.c credit.c aux.c
TEST_SRC = parser.c calculation.c validation.c aux.c test.c
HEADER = calc.h
OBJ = main.o display.o parser.o calculation.o validation.o graph.o credit.o aux.o
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
GCOVR_PATH = ~/.local/bin/gcovr
INSTALL_PATH = /usr/local/bin/
GLADE = smartcalc.glade smartcalc.glade~
VALGRIND_FLAGS = --tool=memcheck --leak-check=yes --suppressions=gtk.supp
STYLE_BASE = --style=Google

all: calc
$(OBJ):$(SRC)
	$(CC) -g $(CFLAGS) -c $(SRC) $(LIBS)
calc: clean $(OBJ)
	 $(CC) -g $(CFLAGS) -rdynamic $(OBJ) $(LIBS) -o $@
install: clean
	sudo mkdir $(INSTALL_PATH)/SmartCalc/
	sudo cp $(SRC) $(HEADER) $(GLADE) $(INSTALL_PATH)/SmartCalc
	sudo $(CC) -rdynamic $(INSTALL_PATH)/SmartCalc/$(SRC) -o $(INSTALL_PATH)/SmartCalc/calc $(LIBS)
uninstall:
	sudo rm -rf $(INSTALL_PATH)SmartCalc
dist:
	mkdir dist
	cp $(SRC) $(HEADER) $(GLADE) Makefile dist
	tar cvzf smartcalc_v1.0.tgz dist/
	rm -rf dist
dvi:
	pdflatex info.tex
	open info.pdf
test: clean $(TEST_SRC)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_SRC) -o $@ $(LIBS) $(TEST_LIBS)
	./test	
gcov_rep: test
	mkdir report
	$(GCOVR_PATH) -r . --html --html-details -o {REPORT}
	xdg-open $(REPORT)
gcov_report: test
	gcovr -r . --html --html-details -o report.html
	xdg-open report.html		
check:
	clang-format $(STYLE_BASE) -n *.c *.h
cpp:
	cppcheck .
fix:
	clang-format $(STYLE_BASE) -i *.c *.h 
val: calc
	valgrind $(VALGRIND_FLAGS) ./calc
deb:
	$(CC) -g  validation.c parser.c calculation.c example.c -o ex $(LIBS)
	./ex			 	 
clean:
	rm -rf calc a.out test *.o build dist *.tgz *.gcno *gcda *.html *.css ex *.aux *.log *.pdf
