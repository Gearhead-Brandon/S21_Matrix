#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS, stop = 0;
  if (!size_comparison(A, B)) {
    for (int i = 0; i < A->rows && !stop; i++) {
      for (int j = 0; j < A->columns && !stop; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) stop = 1;
      }
    }

    if (stop) code = FAILURE;
  } else
    code = 0;

  return code;
}