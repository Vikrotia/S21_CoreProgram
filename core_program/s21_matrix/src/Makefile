COMMIT=Dev
FLAGS=-Wall -Werror -Wextra
CC=gcc
GFLAGS=-fprofile-arcs -ftest-coverage
LFLAGS=-lm -lcheck
CLEAN_FILES=a.out test.out s21_matrix.a *.info *.gcno *.gcda unit_test *.o

all: gcov_report

s21_matrix.a: clean
	$(CC) $(FLAGS) -c s21_matrix.c
	ar -crs s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a
	rm -rf *.o

test: clean s21_matrix.a
	$(CC) $(CFLAGS) -c test/*.c 
	$(CC) $(CFLAGS) *.o -o test.out $(LFLAGS) s21_matrix.a
	./test.out

gcov_report: clean test
	$(CC) $(FLAGS) $(GFLAGS) test/*.c s21_matrix.c -o unit_test $(LFLAGS)
	./unit_test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

clean:
	rm -rf $(CLEAN_FILES)
	rm -rf report

git: git_add git_commit git_push

git_add:
	git add .

git_commit:
	git commit -m "$(COMMIT)"

git_push:
	git push origin develop

style_check:
	clang-format -style=Google -n *.c *.h

style_correct:
	clang-format -style=Google -i *c *.h
