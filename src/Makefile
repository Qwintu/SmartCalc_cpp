CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17 -g  #-mmacosx-version-min=11.5 #-fsanitize=leak -fsanitize=address
TESTFLAGS = -lgtest -lgtest_main -fprofile-arcs -ftest-coverage

OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
LDFLAGS = -lcheck -lm
endif
ifeq ($(OS),Linux)
LDFLAGS=-lcheck_pic -lrt -lpthread -lsubunit -lm
endif

all: clean info

info:
	@echo "Available make targets:"
	@echo "  install    : install SmartCalc 2.0 to desktop"
	@echo "  uninstall  : remove SmartCalc 2.0 from desktop"
	@echo "  test       : run tests"
	@echo "  dist       : create packages ready for distribution"
	@echo "  dvi        : make documentation"
	@echo "  gcov_report: show test coverage"

install:
	cd ./SmartCalc && cmake .
	cmake --build ./SmartCalc
	mv ./SmartCalc/SmartCalc.app ~/Desktop

uninstall:
	rm -rf ~/Desktop/SmartCalc.app

test: clean 
	$(CC) --coverage $(CFLAGS) tests/*.cc Controllers/*.cc Models/*.cc $(TESTFLAGS) -o test
	./test

gcov_report: clean 
	$(CC) $(CFLAGS)  -fprofile-arcs -ftest-coverage  Controllers/*.cc Models/*.cc tests/*.cc -lgtest -o test.info
	./test.info
	# gcov --no-output tests.info
	lcov --ignore-errors deprecated --ignore-errors inconsistent --no-external --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1
	genhtml coverage.info -o report --rc lcov_branch_coverage=1
	open ./report/index.html

dvi:
	cd docs&&doxygen
	open docs/html/index.html

dist: clean
	rm -rf ./SmartCalc_v2.0
	mkdir ./SmartCalc_v2.0
	cp -a Makefile  Controllers/*.cc Model/s*.cc  Controllers/*.h Models*.h ./SmartCalc ./docs ./SmartCalc_v2.0
	tar cvzf SmartCalc_v1.0.tgz ./SmartCalc_v2.0
	mv SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf ./SmartCalc_v2.0
 
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
	$(CC) $(CFLAGS) tests/*.cc Controllers/*.cc Models*.cc -lcheck -o calc_lib_test
	./calc_lib_test
	valgrind -s --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --quiet --track-origins=yes --verbose --log-file=res_leak.txt ./calc_lib_test

p: clean
	rm -rf ./build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug
	git add .
	git commit -m "20.05.24 final"
	git push origin develop 

install_gtest: 
		/bin/zsh -c "cd /opt/goinfre/${USER} \
		&& git clone https://github.com/google/googletest.git \
		&& cd googletest && mkdir build && cd build && cmake -DCMAKE_CXX_COMPILER:STRING="/usr/local/bin/g++" .. \
		&& make"

brew:
		/bin/bash -c "cd /opt/goinfre/${USER} && git clone https://github.com/Homebrew/brew homebrew"
		printf "eval \"%c(/opt/goinfre/${USER}/homebrew/bin/brew shellenv)\"\n\
brew update --force --quiet\n\
chmod -R go-w \"%c(brew --prefix)/share/zsh\"" "$$" "$$" >> /Users/${USER}/.zprofile \
&& export PATH=/opt/goinfre/${USER}/homebrew/bin:${PATH} && source ~/.zshrc
