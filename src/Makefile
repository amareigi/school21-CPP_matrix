CC = gcc
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c++17
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
s21_MATRIX_C = s21_*.cpp
s21_MATRIX_O = s21_*.o
SUITE_CASES_C = suite_*.cpp
SUITE_CASES_O = suite_*.o
FLAG_TESTS = -lgtest -lstdc++ -lm



all: clean gcov_report

s21_matrix_oop.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_MATRIX_C) 
	ar rc s21_matrix_oop.a $(s21_MATRIX_O) -lm
	ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main_test.cpp
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_MATRIX_C) main_test.o $(SUITE_CASES_O) $(FLAG_TESTS)
	./tests

valgrind_test: s21_matrix_oop.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main_test.cpp -g
	$(CC) -g $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_MATRIX_C) main_test.o $(SUITE_CASES_O) $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./tests

gcov_report: test
	gcovr --html-details -o report.html
	open report.html

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cpp
	clang-format -i *.cpp
	clang-format -n *.h
	clang-format -i *.h
	rm -rf .clang-format

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
