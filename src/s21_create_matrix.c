#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = 1;

  result->rows = 0;
  result->columns = 0;
  result->matrix = NULL;

  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)malloc(rows * sizeof(double *) +
                                       columns * rows * sizeof(double));

    result->matrix[0] = (double *)(result->matrix + rows);

    for (int i = 1; i < rows; i++)
      result->matrix[i] = result->matrix[0] + i * columns;

    init_matrix_by_zero(result);
    code = 0;
  }

  return code;
}