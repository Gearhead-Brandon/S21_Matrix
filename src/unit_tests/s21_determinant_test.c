#include "../s21_matrix.h"
#include "check.h"

START_TEST(test_determinant_code_0) {
  matrix_t A = {0};
  double res_0 = 0;
  s21_create_matrix(2, 2, &A);

  ck_assert_int_eq(s21_determinant(&A, &res_0), 0);

  ck_assert_double_eq(res_0, 0.0);

  s21_remove_matrix(&A);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0};
  s21_create_matrix(2, 2, &B);
  double res_1 = 0;
  init_matrix(1, &B);

  ck_assert_int_eq(s21_determinant(&B, &res_1), 0);

  ck_assert_double_eq(res_1, -2.0);

  s21_remove_matrix(&B);
  //////////////////////////////////////////////////////////////
  matrix_t C = {0};
  s21_create_matrix(3, 3, &C);
  double res_2 = 0;
  init_matrix(4, &C);
  C.matrix[0][0] = 50;

  ck_assert_int_eq(s21_determinant(&C, &res_2), 0);

  ck_assert_double_eq(res_2, -138);

  s21_remove_matrix(&C);
  //////////////////////////////////////////////////////////////
  matrix_t D = {0};
  s21_create_matrix(3, 3, &D);
  double res_3 = 0;

  D.matrix[0][0] = 4000.87;
  D.matrix[0][1] = 454.0;
  D.matrix[0][2] = 4.0;
  D.matrix[1][0] = 2.0;
  D.matrix[1][1] = 1.897;
  D.matrix[1][2] = 3.0;
  D.matrix[2][0] = 0.000087;
  D.matrix[2][1] = 2.5668;
  D.matrix[2][2] = 1.0;

  ck_assert_int_eq(s21_determinant(&D, &res_3), 0);

  ck_assert_double_eq_tol(res_3, -24105.996724, 0.000001);

  s21_remove_matrix(&D);
  //////////////////////////////////////////////////////////////
  matrix_t E = {0};
  s21_create_matrix(2, 2, &E);
  double res_4 = 0;

  E.matrix[0][0] = -677700.0;
  E.matrix[0][1] = 654.0;
  E.matrix[1][0] = 2.0;
  E.matrix[1][1] = -0.00001;

  ck_assert_int_eq(s21_determinant(&E, &res_4), 0);

  ck_assert_double_eq_tol(res_4, -1301.223, 0.000001);

  s21_remove_matrix(&E);
  //////////////////////////////////////////////////////////////
  matrix_t F = {0};
  s21_create_matrix(1, 1, &F);
  double res_5 = 0;

  F.matrix[0][0] = -6.0;

  ck_assert_int_eq(s21_determinant(&F, &res_5), 0);

  ck_assert_double_eq_tol(res_5, -6, 0.000001);

  s21_remove_matrix(&F);
}
END_TEST

START_TEST(test_determinant_code_1) {
  double res_0 = 0.0;
  matrix_t A = {NULL, 0, 0};

  ck_assert_int_eq(s21_determinant(&A, &res_0), 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_code_2) {
  double res_0 = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);

  ck_assert_int_eq(s21_determinant(&A, &res_0), 2);
  s21_remove_matrix(&A);
  ///////////////////////////////////////////////////////////////
  matrix_t B = {0};

  s21_create_matrix(2, 4, &B);
  double res_1 = 0;

  ck_assert_int_eq(s21_determinant(&B, &res_1), 2);

  s21_remove_matrix(&B);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *suite = suite_create("determinant");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_determinant_code_0);
  tcase_add_test(test_case, test_determinant_code_1);
  tcase_add_test(test_case, test_determinant_code_2);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  Suite *suite = determinant_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}