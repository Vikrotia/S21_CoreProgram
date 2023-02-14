#include "s21_test.h"

START_TEST(test_remove_matrix_1) {
  matrix_t result_matrix;
  s21_create_matrix(1, 1, &result_matrix);
  s21_remove_matrix(&result_matrix);

  ck_assert_int_eq(result_matrix.matrix == NULL, SUCCESS);
}

START_TEST(test_remove_matrix_2) {
  matrix_t result_matrix;
  s21_create_matrix(2, 2, &result_matrix);
  s21_remove_matrix(&result_matrix);

  ck_assert_int_eq(result_matrix.matrix == NULL, SUCCESS);
}

START_TEST(test_remove_matrix_3) {
  matrix_t result_matrix;
  s21_create_matrix(3, 3, &result_matrix);
  s21_remove_matrix(&result_matrix);

  ck_assert_int_eq(result_matrix.matrix == NULL, SUCCESS);
}

Suite *s21_remove_matrix_suite(void) {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *o = tcase_create("remove_matrix");

  tcase_add_test(o, test_remove_matrix_1);
  tcase_add_test(o, test_remove_matrix_2);
  tcase_add_test(o, test_remove_matrix_3);

  suite_add_tcase(s, o);
  return s;
}
