#include "../s21_matrix.h"
#include "check.h"

START_TEST(test_calc_complements_code_0) {
  matrix_t A = {0}, R_0, X_0;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &X_0);

  ck_assert_int_eq(s21_calc_complements(&A, &R_0), 0);

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
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &X_1);

  init_matrix(1, &B);

  ck_assert_int_eq(s21_calc_complements(&B, &R_1), 0);

  X_1.matrix[0][0] = 4.0;
  X_1.matrix[0][1] = -3.0;
  X_1.matrix[1][0] = -2.0;
  X_1.matrix[1][1] = 1.0;

  ck_assert_int_eq(s21_eq_matrix(&R_1, &X_1), 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&R_1);
  s21_remove_matrix(&X_1);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0}, R_2, X_2;
  s21_create_matrix(3, 3, &C);
  s21_create_matrix(3, 3, &X_2);

  init_matrix(2, &C);
  C.matrix[1][0] = 0;

  ck_assert_int_eq(s21_calc_complements(&C, &R_2), 0);

  X_2.matrix[0][0] = -3.0;
  X_2.matrix[0][1] = 56.0;
  X_2.matrix[0][2] = -48.0;
  X_2.matrix[1][0] = 6.0;
  X_2.matrix[1][1] = -12.0;
  X_2.matrix[1][2] = 6.0;
  X_2.matrix[2][0] = -3.0;
  X_2.matrix[2][1] = -14.0;
  X_2.matrix[2][2] = 12.0;

  ck_assert_int_eq(s21_eq_matrix(&R_2, &X_2), 1);

  s21_remove_matrix(&C);
  s21_remove_matrix(&R_2);
  s21_remove_matrix(&X_2);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0}, R_3, X_3;
  s21_create_matrix(4, 4, &D);
  s21_create_matrix(4, 4, &X_3);

  D.matrix[0][0] = 112.0;
  D.matrix[0][1] = 243.0;
  D.matrix[0][2] = 3.0;
  D.matrix[0][3] = -8.0;
  D.matrix[1][0] = 47.0;
  D.matrix[1][1] = 51.0;
  D.matrix[1][2] = -66.0;
  D.matrix[1][3] = 99.0;
  D.matrix[2][0] = -74.0;
  D.matrix[2][1] = 85.0;
  D.matrix[2][2] = 97.0;
  D.matrix[2][3] = 63.0;
  D.matrix[3][0] = -13.0;
  D.matrix[3][1] = 79.0;
  D.matrix[3][2] = -99.0;
  D.matrix[3][3] = -121.0;

  ck_assert_int_eq(s21_calc_complements(&D, &R_3), 0);

  X_3.matrix[0][0] = -2879514.0;
  X_3.matrix[0][1] = -1236631.0;
  X_3.matrix[0][2] = -1685096.0;
  X_3.matrix[0][3] = 880697.0;
  X_3.matrix[1][0] = 1162090.0;
  X_3.matrix[1][1] = -714015.0;
  X_3.matrix[1][2] = 4046255.0;
  X_3.matrix[1][3] = -3901600.0;
  X_3.matrix[2][0] = 4362897.0;
  X_3.matrix[2][1] = -2049432.0;
  X_3.matrix[2][2] = -532912.0;
  X_3.matrix[2][3] = -1370781.0;
  X_3.matrix[3][0] = 3412773.0;
  X_3.matrix[3][1] = -1569493.0;
  X_3.matrix[3][2] = 3144517.0;
  X_3.matrix[3][3] = 1284666.0;

  ck_assert_int_eq(s21_eq_matrix(&R_3, &X_3), 1);

  s21_remove_matrix(&D);
  s21_remove_matrix(&R_3);
  s21_remove_matrix(&X_3);
  //////////////////////////////////////////////////////////////
  matrix_t E = {0}, R_4, X_4;
  s21_create_matrix(4, 4, &E);
  s21_create_matrix(4, 4, &X_4);

  E.matrix[0][0] = -1.0;
  E.matrix[0][1] = 2.0;
  E.matrix[0][2] = 7.0;
  E.matrix[0][3] = 9.0;
  E.matrix[1][0] = 1.0;
  E.matrix[1][1] = 0.0;
  E.matrix[1][2] = 0.0;
  E.matrix[1][3] = 0.0;
  E.matrix[2][0] = 47.0;
  E.matrix[2][1] = 13.0;
  E.matrix[2][2] = 17.0;
  E.matrix[2][3] = 21.0;
  E.matrix[3][0] = 22.0;
  E.matrix[3][1] = 7.0;
  E.matrix[3][2] = 1.0;
  E.matrix[3][3] = 3.0;

  ck_assert_int_eq(s21_calc_complements(&E, &R_4), 0);

  X_4.matrix[0][0] = 0.0;
  X_4.matrix[0][1] = -30.0;
  X_4.matrix[0][2] = -108.0;
  X_4.matrix[0][3] = 106.0;
  X_4.matrix[1][0] = 138.0;
  X_4.matrix[1][1] = -726.0;
  X_4.matrix[1][2] = -1137.0;
  X_4.matrix[1][3] = 1061.0;
  X_4.matrix[2][0] = 0.0;
  X_4.matrix[2][1] = 12.0;
  X_4.matrix[2][2] = 57.0;
  X_4.matrix[2][3] = -47.0;
  X_4.matrix[3][0] = 0.0;
  X_4.matrix[3][1] = 6.0;
  X_4.matrix[3][2] = -75.0;
  X_4.matrix[3][3] = 57.0;

  ck_assert_int_eq(s21_eq_matrix(&R_4, &X_4), 1);

  s21_remove_matrix(&E);
  s21_remove_matrix(&R_4);
  s21_remove_matrix(&X_4);
  //////////////////////////////////////////////////////////////
  matrix_t F = {0}, R_5, X_5;
  s21_create_matrix(1, 1, &F);
  s21_create_matrix(1, 1, &X_5);

  F.matrix[0][0] = 5.0;

  ck_assert_int_eq(s21_calc_complements(&F, &R_5), 0);

  X_5.matrix[0][0] = 1.0;

  ck_assert_int_eq(s21_eq_matrix(&R_5, &X_5), 1);

  s21_remove_matrix(&F);
  s21_remove_matrix(&R_5);
  s21_remove_matrix(&X_5);
}
END_TEST

START_TEST(test_calc_complements_code_1) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);

  res = s21_calc_complements(&A, &Z);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_calc_complements_code_2) {
  matrix_t A = {0}, R_0;
  s21_create_matrix(2, 3, &A);

  ck_assert_int_eq(s21_calc_complements(&A, &R_0), 2);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&R_0);
  ///////////////////////////////////////////////////////////////
  matrix_t B = {0}, R_1;
  s21_create_matrix(2, 4, &B);

  ck_assert_int_eq(s21_calc_complements(&B, &R_1), 2);

  s21_remove_matrix(&B);
  // s21_remove_matrix(&R_1);
}
END_TEST

Suite *calc_complements_suite(void) {
  Suite *suite = suite_create("calc_complements");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_calc_complements_code_0);
  tcase_add_test(test_case, test_calc_complements_code_1);
  tcase_add_test(test_case, test_calc_complements_code_2);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  // matrix_t A, B ;
  // s21_create_matrix(3,3 , &A);
  // s21_create_matrix(3,3 , &B);
  // A.matrix[0][0] = 1.0;
  // A.matrix[0][1] = 2.0;
  // A.matrix[0][2] = 3.0;
  // A.matrix[1][0] = 0.0;
  // A.matrix[1][1] = 4.0;
  // A.matrix[1][2] = 2.0;
  // A.matrix[2][0] = 5.0;
  // A.matrix[2][1] = 2.0;
  // A.matrix[2][2] = 1.0;
  // print_matrix(A);

  // s21_calc_complements(&A, &B);

  // print_matrix(B);
  Suite *suite = calc_complements_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}