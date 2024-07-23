#include "s21_matrix.h"

void print_matrix(matrix_t A){
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.columns; j++){
            j == A.columns - 1 ? printf("%.6f", A.matrix[i][j]) : printf("%.6f | ", A.matrix[i][j]) ;
    }
    i !=  A.rows - 1 ? printf("\n---------------------------------\n") : printf("\n");
    }
    printf("\n");
}

void init_matrix(double number, matrix_t *A) {
  for (int i = 0; i < A->rows; i += 1) {
    for (int j = 0; j < A->columns; number += 1.0, j += 1)
      A->matrix[i][j] = number;
  }
}

void init_matrix_by_zero(matrix_t *A) {
  for (int i = 0; i < A->rows; i += 1) {
    for (int j = 0; j < A->columns; j += 1) A->matrix[i][j] = 0;
  }
}

int s21_is_bad_matrix(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}

int size_comparison(matrix_t *A, matrix_t *B) {
  int code = 1;

  if (!s21_is_bad_matrix(A) && !s21_is_bad_matrix(B))
    code = (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;

  return code;
}

void create_minor(double **src, double **B, int skip_row, int skip_col,
                  int size) {
  for (int row = 0, i = 0; row < size; row++) {
    for (int col = 0, j = 0; col < size; col++) {
      if (row != skip_row && col != skip_col) {
        B[i][j++] = src[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

double determinant(matrix_t *A, int size) {
  if (size == 1) return A->matrix[0][0];

  matrix_t B = {0};
  double result = 0;

  s21_create_matrix(size, size, &B);
  for (int sign = 1, i = 0; i < size; i++, sign *= -1) {
    create_minor(A->matrix, B.matrix, 0, i, size);
    result += sign * (A->matrix[0][i] * determinant(&B, size - 1));
  }
  s21_remove_matrix(&B);
  return result;
}