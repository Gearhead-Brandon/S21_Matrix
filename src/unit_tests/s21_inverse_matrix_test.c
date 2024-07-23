#include "../s21_matrix.h"
#include "check.h"

START_TEST(test_inverse_matrix_code_0) {
  matrix_t A = {0}, R_0, X_0 = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &X_0);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&A, &R_0), 0);

  X_0.matrix[0][0] = 1;
  X_0.matrix[0][1] = -1;
  X_0.matrix[0][2] = 1;
  X_0.matrix[1][0] = -38;
  X_0.matrix[1][1] = 41;
  X_0.matrix[1][2] = -34;
  X_0.matrix[2][0] = 27;
  X_0.matrix[2][1] = -29;
  X_0.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&R_0, &X_0), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R_0);
  s21_remove_matrix(&X_0);
  ////////////////////////////////////////////////////////////
  matrix_t B, R_1, X_1;
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &X_1);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[0][2] = 3.0;
  B.matrix[1][0] = 4.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 6.0;
  B.matrix[2][0] = 8.0;
  B.matrix[2][1] = 6.0;
  B.matrix[2][2] = 9.0;

  ck_assert_int_eq(s21_inverse_matrix(&B, &R_1), 0);

  X_1.matrix[0][0] = -3.0 / 5.0;
  X_1.matrix[0][1] = 0.0;
  X_1.matrix[0][2] = 1.0 / 5.0;
  X_1.matrix[1][0] = -4.0 / 5.0;
  X_1.matrix[1][1] = 1.0;
  X_1.matrix[1][2] = -2.0 / 5.0;
  X_1.matrix[2][0] = 16.0 / 15.0;
  X_1.matrix[2][1] = -2.0 / 3.0;
  X_1.matrix[2][2] = 1.0 / 5.0;

  ck_assert_double_eq(s21_eq_matrix(&R_1, &X_1), 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&R_1);
  s21_remove_matrix(&X_1);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0}, R_2 = {0}, X_2 = {0};
  s21_create_matrix(4, 4, &C);
  s21_create_matrix(4, 4, &X_2);
  C.matrix[0][0] = -1.0;
  C.matrix[0][1] = 2.0;
  C.matrix[0][2] = 7.0;
  C.matrix[0][3] = 9.0;
  C.matrix[1][0] = 1.0;
  C.matrix[1][1] = 0.0;
  C.matrix[1][2] = 0.0;
  C.matrix[1][3] = 0.0;
  C.matrix[2][0] = 47.0;
  C.matrix[2][1] = 13.0;
  C.matrix[2][2] = 17.0;
  C.matrix[2][3] = 21.0;
  C.matrix[3][0] = 22.0;
  C.matrix[3][1] = 7.0;
  C.matrix[3][2] = 1.0;
  C.matrix[3][3] = 3.0;
  ck_assert_int_eq(s21_inverse_matrix(&C, &R_2), 0);
  X_2.matrix[0][0] = 0.0;
  X_2.matrix[0][1] = 1.0;
  X_2.matrix[0][2] = 0.0;
  X_2.matrix[0][3] = 0.0;
  X_2.matrix[1][0] = -5.0 / 23.0;
  X_2.matrix[1][1] = -121.0 / 23.0;
  X_2.matrix[1][2] = 2.0 / 23.0;
  X_2.matrix[1][3] = 1.0 / 23.0;
  X_2.matrix[2][0] = -18.0 / 23.0;
  X_2.matrix[2][1] = -379.0 / 46.0;
  X_2.matrix[2][2] = 19.0 / 46.0;
  X_2.matrix[2][3] = -25.0 / 46.0;
  X_2.matrix[3][0] = 53.0 / 69.0;
  X_2.matrix[3][1] = 1061.0 / 138.0;
  X_2.matrix[3][2] = -47.0 / 138.0;
  X_2.matrix[3][3] = 19.0 / 46.0;

  ck_assert_double_eq(s21_eq_matrix(&R_2, &X_2), 1);

  s21_remove_matrix(&C);
  s21_remove_matrix(&R_2);
  s21_remove_matrix(&X_2);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0}, R_3 = {0}, X_3 = {0};
  s21_create_matrix(2, 2, &D);
  s21_create_matrix(2, 2, &X_3);

  D.matrix[0][0] = 1.0;
  D.matrix[0][1] = 20.0;
  D.matrix[1][0] = 2.0;
  D.matrix[1][1] = 50.0;

  ck_assert_int_eq(s21_inverse_matrix(&D, &R_3), 0);

  X_3.matrix[0][0] = 5.0;
  X_3.matrix[0][1] = -2.0;
  X_3.matrix[1][0] = -0.2;
  X_3.matrix[1][1] = 0.1;

  ck_assert_double_eq(s21_eq_matrix(&R_3, &X_3), 1);

  s21_remove_matrix(&D);
  s21_remove_matrix(&R_3);
  s21_remove_matrix(&X_3);
}
END_TEST

START_TEST(test_inverse_matrix_code_1) {
  matrix_t A = {0}, R_0 = {0};
  s21_create_matrix(3, 3, &A);
  init_matrix(2, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &R_0), 1);
  /////////////////////////////////////////////////////////////
  matrix_t B = {0}, R_1 = {0};
  matrix_t *bptr = NULL;

  ck_assert_int_eq(s21_inverse_matrix(bptr, &R_1), 1);
  /////////////////////////////////////////////////////////////
  matrix_t C = {NULL, 2, 2}, R_2 = {0};
  ck_assert_int_eq(s21_inverse_matrix(&A, &R_2), 1);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_inverse_matrix_code_2) {
  matrix_t A = {0}, R_0 = {0};
  s21_create_matrix(3, 3, &A);
  init_matrix(1, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &R_0), 2);
  s21_remove_matrix(&A);
  ///////////////////////////////////////////////////////////////
  matrix_t B = {0}, R_1 = {0};
  s21_create_matrix(3, 2, &B);
  init_matrix(5, &A);
  ck_assert_int_eq(s21_inverse_matrix(&B, &R_1), 2);
  s21_remove_matrix(&B);
}
END_TEST

Suite *inverse_matrix_suite(void) {
  Suite *suite = suite_create("inverse_matrix");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_inverse_matrix_code_0);
  tcase_add_test(test_case, test_inverse_matrix_code_1);
  tcase_add_test(test_case, test_inverse_matrix_code_2);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
//   matrix_t B, R_1;
//   s21_create_matrix(3, 3, &B);
// s21_create_matrix(3, 3, &R_1);
//   B.matrix[0][0] = 2;
//   B.matrix[0][1] = 5;
//   B.matrix[0][2] = 7;
//   B.matrix[1][0] = 6;
//   B.matrix[1][1] = 3;
//   B.matrix[1][2] = 4;
//   B.matrix[2][0] = 5;
//   B.matrix[2][1] = -2;
//   B.matrix[2][2] = -3;
//   s21_inverse_matrix(&B, &R_1);
// print_matrix(R_1);
  Suite *suite = inverse_matrix_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}