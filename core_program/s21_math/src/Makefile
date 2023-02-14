CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

all: clean s21_math.a test gcov_report

test: clean s21_math.a
	$(CC) s21_math_test.c s21_math.a -o test.out -lcheck && ./test.out

gcov_report: coverage run_coverage lcov genhtml open

coverage:
	$(CC) --coverage s21_math_test.c  -o test -lcheck
run_coverage:
	./test
lcov:
	lcov -t "Core" -o s21_test.info -c -d .
genhtml:
	genhtml -o report s21_test.info
open:
	open ./report/index.html

s21_math.a: s21_math.o
	ar rc s21_math.a s21_math.o

s21_math.o:
	$(CC) -c $(FLAGS) s21_math.c

clean:
	rm -rf test s21_math *.out *.a *.o report/ *.info *.gcda *.gcno
