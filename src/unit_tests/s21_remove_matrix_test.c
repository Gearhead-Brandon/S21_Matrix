#include <check.h>

#include "../s21_matrix.h"

START_TEST(test_remove_matrix_code_0) {
  matrix_t A = {0};
  int res_0 = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) res_0 = 1;
  ck_assert_int_eq(res_0, 0);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0};
  int res_1 = s21_create_matrix(3, 3, &B);
  s21_remove_matrix(&B);
  if (B.matrix != NULL) res_1 = 1;
  ck_assert_int_eq(res_1, 0);
  ////////////////////////////////////////////////////////////
  matrix_t C = {0};
  int res_2 = s21_create_matrix(4, 4, &C);
  s21_remove_matrix(&C);
  if (C.matrix != NULL) res_2 = 1;
  ck_assert_int_eq(res_2, 0);
  ////////////////////////////////////////////////////////////
  matrix_t D = {0};
  int res_3 = s21_create_matrix(4, 7, &D);
  s21_remove_matrix(&D);
  if (C.matrix != NULL) res_3 = 1;
  ck_assert_int_eq(res_3, 0);
  ////////////////////////////////////////////////////////////
  matrix_t F = {0};
  int res_4 = s21_create_matrix(3, 2, &F);
  s21_remove_matrix(&F);
  if (C.matrix != NULL) res_4 = 1;
  ck_assert_int_eq(res_4, 0);
  ////////////////////////////////////////////////////////////
  matrix_t E = {0};
  int res_5 = s21_create_matrix(3, 2, &E);
  s21_remove_matrix(&E);
  if (C.matrix != NULL) res_5 = 1;
  ck_assert_int_eq(res_5, 0);
  ////////////////////////////////////////////////////////////
  matrix_t *G = NULL;
  // int res_6 = s21_create_matrix(3, 2 , G);
  s21_remove_matrix(G);
  // if(C.matrix != NULL)
  //     res_6 = 1;

  // ck_assert_int_eq(res_6, 0);
}
END_TEST

Suite *remove_matrix_suite(void) {
  Suite *suite = suite_create("remove_matrix");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_remove_matrix_code_0);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  Suite *suite = remove_matrix_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}