#include "../s21_matrix.h"
#include "check.h"

START_TEST(test_mult_number_code_0) {
  matrix_t A = {0}, R_0, X_0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &X_0);

  ck_assert_int_eq(s21_mult_number(&A, 2.0, &R_0), 0);

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
  s21_create_matrix(2, 3, &X_1);

  init_matrix(1, &B);

  ck_assert_int_eq(s21_mult_number(&B, 4.0, &R_1), 0);

  X_1.matrix[0][0] = 4.0;
  X_1.matrix[0][1] = 8.0;
  X_1.matrix[0][2] = 12.0;
  X_1.matrix[1][0] = 16.0;
  X_1.matrix[1][1] = 20.0;
  X_1.matrix[1][2] = 24.0;

  ck_assert_int_eq(s21_eq_matrix(&R_1, &X_1), 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&R_1);
  s21_remove_matrix(&X_1);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0}, R_2, X_2;
  s21_create_matrix(4, 3, &C);
  s21_create_matrix(4, 3, &X_2);

  init_matrix(2, &C);

  ck_assert_int_eq(s21_mult_number(&C, 20.0, &R_2), 0);

  X_2.matrix[0][0] = 40.0;
  X_2.matrix[0][1] = 60.0;
  X_2.matrix[0][2] = 80.0;
  X_2.matrix[1][0] = 100.0;
  X_2.matrix[1][1] = 120.0;
  X_2.matrix[1][2] = 140.0;
  X_2.matrix[2][0] = 160.0;
  X_2.matrix[2][1] = 180.0;
  X_2.matrix[2][2] = 200.0;
  X_2.matrix[3][0] = 220.0;
  X_2.matrix[3][1] = 240.0;
  X_2.matrix[3][2] = 260.0;

  ck_assert_int_eq(s21_eq_matrix(&R_2, &X_2), 1);

  s21_remove_matrix(&C);
  s21_remove_matrix(&R_2);
  s21_remove_matrix(&X_2);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0}, R_3, X_3;
  s21_create_matrix(5, 3, &D);
  s21_create_matrix(5, 3, &X_3);

  init_matrix(2, &D);

  ck_assert_int_eq(s21_mult_number(&D, -10, &R_3), 0);

  X_3.matrix[0][0] = -20.0;
  X_3.matrix[0][1] = -30.0;
  X_3.matrix[0][2] = -40.0;
  X_3.matrix[1][0] = -50.0;
  X_3.matrix[1][1] = -60.0;
  X_3.matrix[1][2] = -70.0;
  X_3.matrix[2][0] = -80.0;
  X_3.matrix[2][1] = -90.0;
  X_3.matrix[2][2] = -100.0;
  X_3.matrix[3][0] = -110.0;
  X_3.matrix[3][1] = -120.0;
  X_3.matrix[3][2] = -130.0;
  X_3.matrix[4][0] = -140.0;
  X_3.matrix[4][1] = -150.0;
  X_3.matrix[4][2] = -160.0;

  ck_assert_int_eq(s21_eq_matrix(&R_3, &X_3), 1);

  s21_remove_matrix(&D);
  s21_remove_matrix(&R_3);
  s21_remove_matrix(&X_3);
  //////////////////////////////////////////////////////////////
  matrix_t E = {0}, R_4, X_4;
  s21_create_matrix(5, 5, &E);
  s21_create_matrix(5, 5, &X_4);

  init_matrix(3, &E);

  ck_assert_int_eq(s21_mult_number(&E, 2, &R_4), 0);

  X_4.matrix[0][0] = 6.0;
  X_4.matrix[0][1] = 8.0;
  X_4.matrix[0][2] = 10.0;
  X_4.matrix[0][3] = 12.0;
  X_4.matrix[0][4] = 14.0;
  X_4.matrix[1][0] = 16.0;
  X_4.matrix[1][1] = 18.0;
  X_4.matrix[1][2] = 20.0;
  X_4.matrix[1][3] = 22.0;
  X_4.matrix[1][4] = 24.0;
  X_4.matrix[2][0] = 26.0;
  X_4.matrix[2][1] = 28.0;
  X_4.matrix[2][2] = 30.0;
  X_4.matrix[2][3] = 32.0;
  X_4.matrix[2][4] = 34.0;
  X_4.matrix[3][0] = 36.0;
  X_4.matrix[3][1] = 38.0;
  X_4.matrix[3][2] = 40.0;
  X_4.matrix[3][3] = 42.0;
  X_4.matrix[3][4] = 44.0;
  X_4.matrix[4][0] = 46.0;
  X_4.matrix[4][1] = 48.0;
  X_4.matrix[4][2] = 50.0;
  X_4.matrix[4][3] = 52.0;
  X_4.matrix[4][4] = 54.0;

  ck_assert_int_eq(s21_eq_matrix(&R_4, &X_4), 1);

  s21_remove_matrix(&E);
  s21_remove_matrix(&R_4);
  s21_remove_matrix(&X_4);
  //////////////////////////////////////////////////////////////
  matrix_t F = {0}, R_5, X_5;
  s21_create_matrix(5, 2, &F);
  s21_create_matrix(5, 2, &X_5);

  init_matrix(4, &F);

  ck_assert_int_eq(s21_mult_number(&F, 5, &R_5), 0);

  X_5.matrix[0][0] = 20.0;
  X_5.matrix[0][1] = 25.0;
  X_5.matrix[1][0] = 30.0;
  X_5.matrix[1][1] = 35.0;
  X_5.matrix[2][0] = 40.0;
  X_5.matrix[2][1] = 45.0;
  X_5.matrix[3][0] = 50.0;
  X_5.matrix[3][1] = 55.0;
  X_5.matrix[4][0] = 60.0;
  X_5.matrix[4][1] = 65.0;

  ck_assert_int_eq(s21_eq_matrix(&R_5, &X_5), 1);

  s21_remove_matrix(&F);
  s21_remove_matrix(&R_5);
  s21_remove_matrix(&X_5);
}
END_TEST

START_TEST(test_mult_number_code_1) {
  matrix_t A = {0}, R_0 = {0};
  s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  // A.matrix = NULL;
  ck_assert_int_eq(s21_mult_number(&A, 2, &R_0), 1);

  // s21_remove_matrix(&A);
  // s21_remove_matrix(&R_0);

  ////////////////////////////////////////////////////////////
  matrix_t B = {0}, R_1 = {0};
  s21_create_matrix(-2, -3, &B);
  B.matrix = NULL;

  ck_assert_int_eq(s21_mult_number(&B, 4, &R_1), 1);

  s21_remove_matrix(&B);
  // s21_remove_matrix(&R_1);
  ////////////////////////////////////////////////////////////
  matrix_t R_2 = {0};
  matrix_t *C = NULL;
  // s21_create_matrix(-2,-3 , &C);
  // C.matrix = NULL;

  ck_assert_int_eq(s21_mult_number(C, 4, &R_2), 1);

  // s21_remove_matrix(&C);
  // s21_remove_matrix(&R_2);
}
END_TEST

// START_TEST(test_mult_number_code_2){

//     matrix_t A = {0}, A_2 = {0}, R_0;
//     s21_create_matrix(2, 3 , &A);
//     s21_create_matrix(2, 2 , &A_2);

//     ck_assert_int_eq(s21_mult_number(&A, &A_2, &R_0), 2);

//     s21_remove_matrix(&A);
//     s21_remove_matrix(&A_2);
//     s21_remove_matrix(&R_0);
// ////////////////////////////////////////////////////////////
//     matrix_t B = {0}, B_2 = {0}, R_1;
//     s21_create_matrix(2, 3 , &B);
//     s21_create_matrix(2, 4 , &B_2);

//     init_matrix(0, &B);
//     init_matrix(1, &B_2);

//     ck_assert_int_eq(s21_mult_number(&B, &B_2, &R_1), 2);

//     s21_remove_matrix(&B);
//     s21_remove_matrix(&B_2);
//     s21_remove_matrix(&R_1);
// //////////////////////////////////////////////////////////////
//     matrix_t C = {0}, C_2 = {0}, R_2;
//     s21_create_matrix(4, 3 , &C);
//     s21_create_matrix(4, 2 , &C_2);

//     init_matrix(1, &C);
//     init_matrix(1, &C_2);

//     ck_assert_int_eq(s21_mult_number(&C, &C_2, &R_2), 2);

//     s21_remove_matrix(&C);
//     s21_remove_matrix(&C_2);
//     s21_remove_matrix(&R_2);
// //////////////////////////////////////////////////////////////
//     matrix_t D = {0}, D_2 = {0}, R_3;
//     s21_create_matrix( 4, 5, &D);
//     s21_create_matrix( 4, 3, &D_2);

//     init_matrix(2, &D);
//     init_matrix(4, &D_2);

//     ck_assert_int_eq(s21_mult_number(&D, &D_2, &R_3), 2);

//     s21_remove_matrix(&D);
//     s21_remove_matrix(&D_2);
//     s21_remove_matrix(&R_3);
// //////////////////////////////////////////////////////////////
//     matrix_t E = {0}, E_2 = {0}, R_4;
//     s21_create_matrix( 5, 5, &E);
//     s21_create_matrix( 5, 6, &E_2);

//     init_matrix(3, &E);
//     init_matrix(3, &E_2);

//     ck_assert_int_eq(s21_mult_number(&E, &E_2, &R_4), 2);

//     s21_remove_matrix(&E);
//     s21_remove_matrix(&E_2);
//     s21_remove_matrix(&R_4);
// //////////////////////////////////////////////////////////////
//     matrix_t F = {0}, F_2 = {0}, R_5;
//     s21_create_matrix( 5, 2, &F);
//     s21_create_matrix( 2, 3, &F_2);

//     init_matrix(3, &F);
//     init_matrix(1, &F_2);

//     ck_assert_int_eq(s21_mult_number(&F, &F_2, &R_5), 2);

//     s21_remove_matrix(&F);
//     s21_remove_matrix(&F_2);
//     s21_remove_matrix(&R_5);
// }
// END_TEST

Suite *mult_number_suite(void) {
  Suite *suite = suite_create("mult_number");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_mult_number_code_0);
  tcase_add_test(test_case, test_mult_number_code_1);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  Suite *suite = mult_number_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}