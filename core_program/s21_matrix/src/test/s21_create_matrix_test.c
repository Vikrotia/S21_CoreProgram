#include "s21_test.h"

START_TEST(test_create_matrix_1) {
  matrix_t result_matrix;
  int res = s21_create_matrix(0, 0, &result_matrix);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}

START_TEST(test_create_matrix_2) {
  matrix_t result_matrix;
  int res = s21_create_matrix(0, 4, &result_matrix);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}

START_TEST(test_create_matrix_3) {
  matrix_t result_matrix;
  int res = s21_create_matrix(4, 0, &result_matrix);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}

START_TEST(test_create_matrix_4) {
  int rows = 5;
  int columns = 5;
  matrix_t result_matrix;
  int res = s21_create_matrix(rows, columns, &result_matrix);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(result_matrix.rows, rows);
  ck_assert_int_eq(result_matrix.rows, columns);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_create_matrix_5) {
  int rows = 3;
  int columns = 2;
  matrix_t result_matrix;
  int res = s21_create_matrix(rows, columns, &result_matrix);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(result_matrix.rows, rows);
  ck_assert_int_eq(result_matrix.columns, columns);
  s21_remove_matrix(&result_matrix);
}

START_TEST(test_create_matrix_6) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-06);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}

START_TEST(test_create_matrix_7) {
  matrix_t my_matrix;
  int ret = 0;
  ret = s21_create_matrix(4, 4, &my_matrix);
  ck_assert_int_eq(ret, 0);
  s21_remove_matrix(&my_matrix);
}

START_TEST(test_create_matrix_8) {
  matrix_t my_matrix;
  int ret = 0;
  ret = s21_create_matrix(-4, 4, &my_matrix);
  ck_assert_int_eq(ret, 1);
}

START_TEST(test_create_matrix_9) {
  matrix_t my_matrix;
  int ret = 0;
  ret = s21_create_matrix(-4, 0, &my_matrix);
  ck_assert_int_eq(ret, 1);
}

START_TEST(test_create_matrix_10) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), 1);
}

START_TEST(test_create_matrix_11) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), 1);
}

END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s = suite_create("s21_create_matrix");
  TCase *o = tcase_create("create_matrix");

  tcase_add_test(o, test_create_matrix_1);
  tcase_add_test(o, test_create_matrix_2);
  tcase_add_test(o, test_create_matrix_3);
  tcase_add_test(o, test_create_matrix_4);
  tcase_add_test(o, test_create_matrix_5);
  tcase_add_test(o, test_create_matrix_6);
  tcase_add_test(o, test_create_matrix_7);
  tcase_add_test(o, test_create_matrix_8);
  tcase_add_test(o, test_create_matrix_9);
  tcase_add_test(o, test_create_matrix_10);
  tcase_add_test(o, test_create_matrix_11);

  suite_add_tcase(s, o);
  return s;
}
