CC = gcc
FLAGS = -Wall -Werror -Wextra --std=c11
LIBS = -lcheck -lsubunit -lm -lgcov
FUNC_FILES_C = *.c 
FUNC_FILES_O = *.o
CHECKFLAGS = $(shell pkg-config --cflags --libs check)
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBNAME = s21_matrix.a
GLFLAGS = --coverage
EXCLUDE = --exclude "unit_tests/*" --exclude "matrix_func.c"

all: s21_matrix.a

peer: 
	make clean
	make gcov_open

build_object_files:
	$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(FUNC_FILES_C)

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

s21_matrix.a:
	$(CC) $(FLAGS) -c $(FUNC_FILES_C)
	make build_library
	rm -rf *.o

test: all
	$(CC) unit_tests/s21_create_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_create_matrix_test
	$(CC) unit_tests/s21_remove_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_remove_matrix_test
	$(CC) unit_tests/s21_eq_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_eq_matrix_test
	$(CC) unit_tests/s21_sum_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sum_matrix_test
	$(CC) unit_tests/s21_sub_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_sub_matrix_test
	$(CC) unit_tests/s21_mult_number_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_mult_number_test
	$(CC) unit_tests/s21_mult_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_mult_matrix_test
	$(CC) unit_tests/s21_transpose_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_transpose_test
	$(CC) unit_tests/s21_calc_complements_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_calc_complements_test
	$(CC) unit_tests/s21_determinant_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_determinant_test
	$(CC) unit_tests/s21_inverse_matrix_test.c -L. s21_matrix.a $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) -o s21_inverse_matrix_test
	make start_tests

start_tests:
	./s21_create_matrix_test
	./s21_remove_matrix_test
	./s21_eq_matrix_test
	./s21_sum_matrix_test
	./s21_sub_matrix_test
	./s21_mult_number_test
	./s21_mult_matrix_test
	./s21_transpose_test
	./s21_calc_complements_test
	./s21_determinant_test
	./s21_inverse_matrix_test

gcov_report: clean build_object_files build_library test
#	gcov $(FUNC_FILES_C)
	~/.local/bin/gcovr -r . $(EXCLUDE) --html --html-details -o s21_matrix.html

gcov_open: 
	make gcov_report
	xdg-open s21_matrix.html

clean:
	rm -f *.o *.a *.gcno *.gcov *.gcda *.html *.css s21_*_test *.info

del: clean
	rm -f *.c *.h unit_tests/*.c
	rmdir unit_tests

rebuild:
	make clean
	make