#include <check.h>

#include "../s21_matrix.h"

START_TEST(test_create_matrix_code_0) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(2, 2, &A), 0);
  s21_remove_matrix(&A);

  ////////////////////////////////////////////////////////////
  matrix_t B = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &B), 0);
  s21_remove_matrix(&B);

  ////////////////////////////////////////////////////////////
  matrix_t C = {0};
  ck_assert_int_eq(s21_create_matrix(4, 4, &C), 0);
  s21_remove_matrix(&C);
  ////////////////////////////////////////////////////////////
  matrix_t D = {0};
  ck_assert_int_eq(s21_create_matrix(4, 7, &D), 0);
  s21_remove_matrix(&D);

  ////////////////////////////////////////////////////////////
  matrix_t F = {0};
  ck_assert_int_eq(s21_create_matrix(6, 7, &F), 0);
  s21_remove_matrix(&F);

  ////////////////////////////////////////////////////////////
  matrix_t G = {0};
  ck_assert_int_eq(s21_create_matrix(10, 10, &G), 0);
  s21_remove_matrix(&G);
}
END_TEST

START_TEST(test_create_matrix_code_1) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(2, -3, &A), 1);
  ////////////////////////////////////////////////////////////
  matrix_t B = {0};
  ck_assert_int_eq(s21_create_matrix(-2, -4, &B), 1);
}
END_TEST

Suite *create_matrix_suite(void) {
  Suite *suite = suite_create("remove_matrix");
  TCase *test_case = tcase_create("case_is_equal");

  tcase_add_test(test_case, test_create_matrix_code_0);
  tcase_add_test(test_case, test_create_matrix_code_1);

  suite_add_tcase(suite, test_case);
  return suite;
}

int main() {
  Suite *suite = create_matrix_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return failures == 0 ? 0 : 1;
}