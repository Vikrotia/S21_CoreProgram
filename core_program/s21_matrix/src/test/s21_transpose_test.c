#include "s21_test.h"

START_TEST(test_transpose_1) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 5;
  matrix.matrix[1][2] = 6;
  matrix.matrix[2][0] = 7;
  matrix.matrix[2][1] = 8;
  matrix.matrix[2][2] = 9;

  int res = s21_transpose(&matrix, &result);
  ck_assert_uint_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[0][2], 7);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[1][2], 8);
  ck_assert_double_eq(result.matrix[2][0], 3);
  ck_assert_double_eq(result.matrix[2][1], 6);
  ck_assert_double_eq(result.matrix[2][2], 9);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_2) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(3, 2, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 5;
  matrix.matrix[2][0] = 7;
  matrix.matrix[2][1] = 8;

  int res = s21_transpose(&matrix, &result);
  ck_assert_uint_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[0][2], 7);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[1][2], 8);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_3) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(1, 3, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 4;

  int res = s21_transpose(&matrix, &result);
  ck_assert_uint_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[2][0], 4);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s = suite_create("s21_transpose");
  TCase *o = tcase_create("transpose");

  tcase_add_test(o, test_transpose_1);
  tcase_add_test(o, test_transpose_2);
  tcase_add_test(o, test_transpose_3);
  suite_add_tcase(s, o);
  return s;
}
