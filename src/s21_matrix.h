#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

void print_matrix(matrix_t A);

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int size_comparison(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_is_bad_matrix(matrix_t *A);

int s21_transpose(matrix_t *A, matrix_t *result);

void create_minor(double **src, double **B, int skip_row, int skip_col,
                  int size);

double determinant(matrix_t *A, int size);

int s21_determinant(matrix_t *A, double *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void init_matrix(double number, matrix_t *A);

void init_matrix_by_zero(matrix_t *A);

#endif