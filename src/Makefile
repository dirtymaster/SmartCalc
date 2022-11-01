APP = build/SmartCalc.app
BACKEND_FILES = s21_smartcalc.c;
BACKEND_FILES_O = s21_smartcalc.o

CC+FLAGS = g++ -std=c++17 -Wall -Wextra -Werror
GCOVFLAGS = -L. --coverage -ls21_smartcalc
OS = $(shell uname)
ifeq ($(OS), Linux)
	GTEST_FLAGS = -lgtest -lm -pthread -lrt -lsubunit
else
	GTEST_FLAGS = -lgtest
endif

TEST_COMPILE = $(CC+FLAGS) tests.cpp s21_smartcalc.a $(GTEST_FLAGS) -L. -ls21_smartcalc

all: test install clean

install:
	cd View && qmake && make && make clean && rm Makefile
	mv View/SmartCalc.app/Contents/MacOS/SmartCalc .
	./SmartCalc

uninstall:
	rm -rf View/SmareCalc.app SmartCalc

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	cp Makefile *.cpp *.h *.pro *.ui *.user* Archive_SmartCalc_v1.0/src/
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v1.0/

test: s21_smartcalc.a
	$(TEST_COMPILE)
	./a.out

gcov_report:
	rm -f *.g*
	$(CC+FLAGS) tests.cpp Model/model.cpp Controller/controller.cpp $(GTEST_FLAGS) $(GCOVFLAGS)
	./a.out
	lcov -t a.out -o rep.info -c -d .
	genhtml -o report rep.info
	open ./report/index.html
	rm -rf *.gcda *.gcno *.info

s21_smartcalc.a: s21_smartcalc.o
	ar rcs libs21_smartcalc.a *.o
	rm -rf *.o
	ranlib libs21_smartcalc.a
	cp libs21_smartcalc.a s21_smartcalc.a
	cp libs21_smartcalc.a ls21_smartcalc.a

s21_smartcalc.o:
	$(CC+FLAGS) -c tests.cpp Model/model.cpp Controller/controller.cpp

check: test
	CK_FORK=no leaks --atExit -- ./a.out

clean: uninstall
	rm -rf *.o *.a *.gcda *.gcno *.info s21_test report s21_calc s21_test a.out \
	build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug

rebuild: clean uninstall all

reinstall: clean uninstall install