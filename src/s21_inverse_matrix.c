#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  
  if ((s21_is_bad_matrix(A))) return 1;
  if (A->columns != A->rows) return 2;

  double det = 0;
  int status = s21_determinant(A, &det);
  if (det == 0 || fabs(det) < 1e-6 || status != 0) return 2;

  matrix_t B = {0}, transpose = {0};
  s21_create_matrix(A->rows, A->columns, result);
  s21_calc_complements(A, &B);
  s21_transpose(&B, &transpose);

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = transpose.matrix[i][j] / det;

  s21_remove_matrix(&B);
  s21_remove_matrix(&transpose);

  return 0;
}