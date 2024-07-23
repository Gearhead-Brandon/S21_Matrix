#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if ((s21_is_bad_matrix(A))) return 1;
  if (A->columns != A->rows) return 2;

  s21_create_matrix(A->rows, A->columns, result);

  if (A->rows != 1) {
    matrix_t B = {0};
    s21_create_matrix(A->rows, A->columns, &B);
    for (int sign = 0, i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        create_minor(A->matrix, B.matrix, i, j, A->rows);
        sign = ((i + j) % 2 == 0) ? 1 : (-1);
        result->matrix[i][j] = sign * determinant(&B, A->rows - 1);
      }
    }
    s21_remove_matrix(&B);
  } else
    result->matrix[0][0] = 1;

  return 0;
}