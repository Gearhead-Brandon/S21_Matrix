#include <check.h>

#include "../s21_matrix.h"

START_TEST(test_eq_matrix_code_1) {
  matrix_t A = {0}, A_2 = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &A_2);

  ck_assert_int_eq(s21_eq_matrix(&A, &A_2), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&A_2);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0}, B_2 = {0};
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 3, &B_2);

  init_matrix(1, &B);
  init_matrix(1, &B_2);

  ck_assert_int_eq(s21_eq_matrix(&B, &B_2), 1);

  s21_remove_matrix(&B);
  s21_remove_matrix(&B_2);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0}, C_2 = {0};
  s21_create_matrix(4, 3, &C);
  s21_create_matrix(4, 3, &C_2);

  init_matrix(2, &C);
  init_matrix(2, &C_2);

  ck_assert_int_eq(s21_eq_matrix(&C, &C_2), 1);

  s21_remove_matrix(&C);
  s21_remove_matrix(&C_2);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0}, D_2 = {0};
  s21_create_matrix(4, 3, &D);
  s21_create_matrix(4, 3, &D_2);

  init_matrix(2, &D);
  init_matrix(2, &D_2);

  ck_assert_int_eq(s21_eq_matrix(&D, &D_2), 1);

  s21_remove_matrix(&D);
  s21_remove_matrix(&D_2);
  //////////////////////////////////////////////////////////////
  matrix_t E = {0}, E_2 = {0};
  s21_create_matrix(5, 5, &E);
  s21_create_matrix(5, 5, &E_2);

  init_matrix(3, &E);
  init_matrix(3, &E_2);

  ck_assert_int_eq(s21_eq_matrix(&E, &E_2), 1);

  s21_remove_matrix(&E);
  s21_remove_matrix(&E_2);
  //////////////////////////////////////////////////////////////
  matrix_t F = {0}, F_2 = {0};
  s21_create_matrix(5, 2, &F);
  s21_create_matrix(5, 2, &F_2);

  init_matrix(3, &F);
  init_matrix(3, &F_2);

  ck_assert_int_eq(s21_eq_matrix(&F, &F_2), 1);

  s21_remove_matrix(&F);
  s21_remove_matrix(&F_2);
}
END_TEST

START_TEST(test_eq_matrix_code_0) {
  matrix_t A = {0}, A_2 = {0};
  s21_create_matrix(4, 3, &A);
  s21_create_matrix(2, 2, &A_2);

  ck_assert_int_eq(s21_eq_matrix(&A, &A_2), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&A_2);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0}, B_2 = {0};
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 3, &B_2);

  init_matrix(0, &B);
  init_matrix(1, &B_2);

  ck_assert_int_eq(s21_eq_matrix(&B, &B_2), 0);

  s21_remove_matrix(&B);
  s21_remove_matrix(&B_2);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0}, C_2 = {0};
  s21_create_matrix(2, 3, &C);
  s21_create_matrix(4, 2, &C_2);

  init_matrix(2, &C);
  init_matrix(1, &C_2);

  ck_assert_int_eq(s21_eq_matrix(&C, &C_2), 0);

  s21_remove_matrix(&C);
  s21_remove_matrix(&C_2);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0}, D_2 = {0};
  s21_create_matrix(4, 5, &D);
  s21_create_matrix(4, 5, &D_2);

  init_matrix(2, &D);
  init_matrix(4, &D_2);

  ck_assert_int_eq(s21_eq_matrix(&D, &D_2), 0);

  s21_remove_matrix(&D);
  s21_remove_matrix(&D_2);
  //////////////////////////////////////////////////////////////
  matrix_t E = {0}, E_2 = {0};
  s21_create_matrix(5, 5, &E);
  s21_create_matrix(5, 6, &E_2);

  init_matrix(3, &E);
  init_matrix(3, &E_2);

  ck_assert_int_eq(s21_eq_matrix(&E, &E_2), 0);

  s21_remove_matrix(&E);
  s21_remove_matrix(&E_2);
  //////////////////////////////////////////////////////////////
  matrix_t F = {0}, F_2 = {0};
  s21_create_matrix(5, 2, &F);
  s21_create_matrix(2, 2, &F_2);

  init_matrix(3, &F);
  init_matrix(1, &F_2);

  ck_assert_int_eq(s21_eq_matrix(&F, &F_2), 0);

  s21_remove_matrix(&F);
  s21_remove_matrix(&F_2);
}
END_TEST

Suite *eq_matrix_suite(void) {
  Suite *suite = suite_create("eq_matrix");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_eq_matrix_code_1);
  tcase_add_test(test_case, test_eq_matrix_code_0);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  Suite *suite = eq_matrix_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}