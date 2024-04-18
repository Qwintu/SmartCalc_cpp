CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17 -g #-fsanitize=leak -fsanitize=address

OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
LDFLAGS = -lcheck -lm
endif
ifeq ($(OS),Linux)
LDFLAGS=-lcheck_pic -lrt -lpthread -lsubunit -lm
endif

all: clean calc_lib.a gcov_report
	$(CC) $(CFLAGS) calc.c
	./a.out

calc_lib.a:
	$(CC) $(CFLAGS) -c calc_lib.c calc_lib.h
	ar rc calc_lib.a calc_lib.o
	ranlib calc_lib.a

test: clean calc_lib.a
	$(CC) $(CFLAGS) calc_lib.a tests.c -o calc_lib_test $(LDFLAGS)
	./calc_lib_test


gcov_report: clean calc_lib.a
	$(CC) $(CFLAGS) --coverage tests.c calc_lib.c calc_lib.a $(LDFLAGS) -o gcov_tests
	./gcov_tests
	lcov -t "calc_lib" -o calc_lib.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report calc_lib.info --rc lcov_branch_coverage=1
	open report/index.html

install:
	cd ./SmartCalc && cmake .
	cmake --build ./SmartCalc
	mv ./SmartCalc/SmartCalc.app ~/Desktop

uninstall:
	rm -rf ~/Desktop/SmartCalc.app

dvi:
	cd docs&&doxygen
	open docs/html/index.html

dist: clean
	rm -rf ./SmartCalc_v1.0
	mkdir ./SmartCalc_v1.0
	cp -a Makefile *.c *.h ./SmartCalc ./docs ./SmartCalc_v1.0
	tar cvzf SmartCalc_v1.0.tgz ./SmartCalc_v1.0
	mv SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf ./SmartCalc_v1.0
style:
	clang-format -style=google -n *.c ./SmartCalc/*.cpp
	clang-format -style=google -n *.h ./SmartCalc/*.h

make_style:
	clang-format -style=google -i *.c ./SmartCalc/*.cpp
	clang-format -style=google -i *.h ./SmartCalc/*.h

clean:
	rm -rf vgcheck ./*.o ./*.a ./*.out ./*.dSYM gcov_test *.html *.css ./GcovReport ./test ./*.gcda ./*.gch ./*.gcno ./report ./calc_lib_test
	rm -rf ./*.info ./gcov_tests ./gcov_tests ./res_leak.txt ./s21_matrix_test

utest: clean
	$(CC) $(CFLAGS) calc_lib.c tests.c -lcheck -o calc_lib_test
	./calc_lib_test
	valgrind -s --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --quiet --track-origins=yes --verbose --log-file=res_leak.txt ./calc_lib_test

p: clean
	rm -rf ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug
	git add .
	git commit -m "11.04.24 cred calc"
	git push origin develop 

mvc: clean
	$(CC) $(CFLAGS) mn.cc deposit_controller.cc view.cc deposit_model.cc
	./a.out