CC = gcc
FLAGS=-Wall -Werror -Wextra
CHECKFL = -lcheck
TEST = ./tests/check_string.c
OS := $(shell uname)
ifeq ($(OS),Linux)
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_LIBS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: s21_string.a test gcov_report

test:
	$(CC) $(TEST) *.c $(TEST_LIBS) -o $@
	./test

s21_string:
	$(CC) $(FLAGS) *.c -o $@

s21_string.a: s21_string.o
	ar -crs s21_string.a *.o

s21_string.o:
	$(CC) $(FLAGS) -c *.c

gcov_report: s21_string.a test
	./test
	lcov -t "./test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

format:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c
	rm .clang-format
	cp ../materials/linters/.clang-format ./tests
	clang-format -i $(TEST)
	rm ./tests/.clang-format

check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	rm .clang-format
	cp ../materials/linters/.clang-format ./tests
	clang-format -n $(TEST)
	rm ./tests/.clang-format

clean:
	rm -rf *.o *.a check
	rm -rf *.gcno *gcda *.gcov gcov
	rm -rf report report.info
	rm -rf .clang-format
	rm test
	rm -rf ./tests/*.gcno ./tests/*.o ./tests/*.a

rebuild: clean all

.PHONY: all test s21_string s21_string.a s21_string.o gcov_report format check clean rebuild
