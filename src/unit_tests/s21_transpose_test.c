#include "../s21_matrix.h"
#include "check.h"

START_TEST(test_transpose_code_0) {
  matrix_t A = {0}, R_0, X_0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &X_0);

  ck_assert_int_eq(s21_transpose(&A, &R_0), 0);

  X_0.matrix[0][0] = 0.0;
  X_0.matrix[0][1] = 0.0;
  X_0.matrix[1][0] = 0.0;
  X_0.matrix[1][1] = 0.0;

  ck_assert_int_eq(s21_eq_matrix(&R_0, &X_0), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&R_0);
  s21_remove_matrix(&X_0);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0}, R_1, X_1;
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 2, &X_1);

  init_matrix(1, &B);

  ck_assert_int_eq(s21_transpose(&B, &R_1), 0);

  X_1.matrix[0][0] = 1.0;
  X_1.matrix[0][1] = 4.0;
  X_1.matrix[1][0] = 2.0;
  X_1.matrix[1][1] = 5.0;
  X_1.matrix[2][0] = 3.0;
  X_1.matrix[2][1] = 6.0;

  ck_assert_int_eq(s21_eq_matrix(&R_1, &X_1), 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&R_1);
  s21_remove_matrix(&X_1);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0}, R_2, X_2;
  s21_create_matrix(4, 3, &C);
  s21_create_matrix(3, 4, &X_2);

  init_matrix(2, &C);

  ck_assert_int_eq(s21_transpose(&C, &R_2), 0);

  X_2.matrix[0][0] = 2.0;
  X_2.matrix[0][1] = 5.0;
  X_2.matrix[0][2] = 8.0;
  X_2.matrix[0][3] = 11.0;
  X_2.matrix[1][0] = 3.0;
  X_2.matrix[1][1] = 6.0;
  X_2.matrix[1][2] = 9.0;
  X_2.matrix[1][3] = 12.0;
  X_2.matrix[2][0] = 4.0;
  X_2.matrix[2][1] = 7.0;
  X_2.matrix[2][2] = 10.0;
  X_2.matrix[2][3] = 13.0;

  ck_assert_int_eq(s21_eq_matrix(&R_2, &X_2), 1);

  s21_remove_matrix(&C);
  s21_remove_matrix(&R_2);
  s21_remove_matrix(&X_2);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0}, R_3, X_3;
  s21_create_matrix(3, 5, &D);
  s21_create_matrix(5, 3, &X_3);

  init_matrix(2, &D);

  ck_assert_int_eq(s21_transpose(&D, &R_3), 0);

  X_3.matrix[0][0] = 2.0;
  X_3.matrix[0][1] = 7.0;
  X_3.matrix[0][2] = 12.0;
  X_3.matrix[1][0] = 3.0;
  X_3.matrix[1][1] = 8.0;
  X_3.matrix[1][2] = 13.0;
  X_3.matrix[2][0] = 4.0;
  X_3.matrix[2][1] = 9.0;
  X_3.matrix[2][2] = 14.0;
  X_3.matrix[3][0] = 5.0;
  X_3.matrix[3][1] = 10.0;
  X_3.matrix[3][2] = 15.0;
  X_3.matrix[4][0] = 6.0;
  X_3.matrix[4][1] = 11.0;
  X_3.matrix[4][2] = 16.0;

  ck_assert_int_eq(s21_eq_matrix(&R_3, &X_3), 1);

  s21_remove_matrix(&D);
  s21_remove_matrix(&R_3);
  s21_remove_matrix(&X_3);
  //////////////////////////////////////////////////////////////
  matrix_t E = {0}, R_4, X_4;
  s21_create_matrix(3, 3, &E);
  s21_create_matrix(3, 3, &X_4);

  init_matrix(-3, &E);

  ck_assert_int_eq(s21_transpose(&E, &R_4), 0);

  X_4.matrix[0][0] = -3;
  X_4.matrix[0][1] = 0;
  X_4.matrix[0][2] = 3;
  X_4.matrix[1][0] = -2;
  X_4.matrix[1][1] = 1;
  X_4.matrix[1][2] = 4;
  X_4.matrix[2][0] = -1;
  X_4.matrix[2][1] = 2;
  X_4.matrix[2][2] = 5;

  ck_assert_int_eq(s21_eq_matrix(&R_4, &X_4), 1);

  s21_remove_matrix(&E);
  s21_remove_matrix(&R_4);
  s21_remove_matrix(&X_4);
  //////////////////////////////////////////////////////////////
  matrix_t F = {0}, F_2 = {0}, R_5, X_5;
  s21_create_matrix(3, 2, &F);
  s21_create_matrix(2, 3, &X_5);

  init_matrix(4, &F);

  ck_assert_int_eq(s21_transpose(&F, &R_5), 0);

  X_5.matrix[0][0] = 4.0;
  X_5.matrix[0][1] = 6.0;
  X_5.matrix[0][2] = 8.0;
  X_5.matrix[1][0] = 5.0;
  X_5.matrix[1][1] = 7.0;
  X_5.matrix[1][2] = 9.0;

  ck_assert_int_eq(s21_eq_matrix(&R_5, &X_5), 1);

  s21_remove_matrix(&F);
  s21_remove_matrix(&R_5);
  s21_remove_matrix(&X_5);
}
END_TEST

START_TEST(test_transpose_code_1) {
  matrix_t A = {0}, R_0;
  s21_create_matrix(-2, -3, &A);

  ck_assert_int_eq(s21_transpose(&A, &R_0), 1);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&R_0);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0}, R_1;
  s21_create_matrix(-2, -3, &B);

  ck_assert_int_eq(s21_transpose(&B, &R_1), 1);

  s21_remove_matrix(&B);
  // s21_remove_matrix(&R_1);
  ////////////////////////////////////////////////////////////
  matrix_t C = {0}, R_2;
  s21_create_matrix(2, 3, &C);

  C.matrix = NULL;

  ck_assert_int_eq(s21_transpose(&C, &R_2), 1);

  s21_remove_matrix(&C);
  // s21_remove_matrix(&R_2);
  ////////////////////////////////////////////////////////////
  matrix_t R_3;
  matrix_t *D = NULL;

  ck_assert_int_eq(s21_transpose(D, &R_3), 1);

  // s21_remove_matrix(&D);
  // s21_remove_matrix(&R_3);
}
END_TEST

// START_TEST(test_transpose_code_2){

//     matrix_t A = {0}, R_0;
//     s21_create_matrix(2, 3 , &A);

//     ck_assert_int_eq(s21_transpose(&A, &R_0), 2);

//     s21_remove_matrix(&A);
//     s21_remove_matrix(&R_0);
// ////////////////////////////////////////////////////////////

//     matrix_t B = {0}, R_1;

//     s21_create_matrix(3, 4, &A);

//     init_matrix(1.0, &B);

//     ck_assert_int_eq(s21_transpose(&B, &R_1), 2);

//     s21_remove_matrix(&A);
//     s21_remove_matrix(&B);
// }
//  END_TEST

Suite *transpose_suite(void) {
  Suite *suite = suite_create("transpose");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_transpose_code_0);
  tcase_add_test(test_case, test_transpose_code_1);
  // tcase_add_test(test_case, test_transpose_code_2);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  Suite *suite = transpose_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}