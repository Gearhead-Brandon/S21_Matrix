#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = (s21_is_bad_matrix(A) || s21_is_bad_matrix(B));

  if (!code && !(code = A->columns != B->rows ? 2 : 0)) {

    if (!(code = s21_create_matrix(A->rows, B->columns, result))) {

      for (int x = 0; x < A->rows; x += 1) {

        for (int y = 0; y < B->columns; y += 1){

          for (int z = 0; z < B->rows; z += 1)
            result->matrix[x][y] += A->matrix[x][z] * B->matrix[z][y];
            
        }
      }
    }
  }

  return code;
}