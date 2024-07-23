#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_bad_matrix(A)) {
    printf("DF\n");
    return 1;
  }
  if (A->columns != A->rows) return 2;

  if (A->rows == 1)
    *result = A->matrix[0][0];
  else
    *result = determinant(A, A->rows);

  return 0;
}