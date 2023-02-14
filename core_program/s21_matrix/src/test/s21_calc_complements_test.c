#include "s21_test.h"

START_TEST(test_calc_complements_1) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 1, &matrix);

  int res = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(res, CALC_ERROR);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 3;
  matrix.matrix[0][1] = 4;
  matrix.matrix[1][0] = 5;
  matrix.matrix[1][1] = 7;

  int res = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 7);
  ck_assert_double_eq(result.matrix[0][1], -5);
  ck_assert_double_eq(result.matrix[1][0], -4);
  ck_assert_double_eq(result.matrix[1][1], 3);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 5;
  matrix.matrix[0][2] = 7;
  matrix.matrix[1][0] = 6;
  matrix.matrix[1][1] = 3;
  matrix.matrix[1][2] = 4;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -3;

  int res = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(result.matrix[0][0], -1);
  ck_assert_double_eq(result.matrix[0][1], 38);
  ck_assert_double_eq(result.matrix[0][2], -27);
  ck_assert_double_eq(result.matrix[1][0], 1);
  ck_assert_double_eq(result.matrix[1][1], -41);
  ck_assert_double_eq(result.matrix[1][2], 29);
  ck_assert_double_eq(result.matrix[2][0], -1);
  ck_assert_double_eq(result.matrix[2][1], 34);
  ck_assert_double_eq(result.matrix[2][2], -24);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 1;
  matrix.matrix[0][2] = 0;
  matrix.matrix[0][3] = 0;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 0;
  matrix.matrix[1][3] = 0;
  matrix.matrix[2][0] = 1;
  matrix.matrix[2][1] = 1;
  matrix.matrix[2][2] = 3;
  matrix.matrix[2][3] = 4;
  matrix.matrix[3][0] = 2;
  matrix.matrix[3][1] = -1;
  matrix.matrix[3][2] = 2;
  matrix.matrix[3][3] = 3;

  int res = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 2);
  ck_assert_double_eq(result.matrix[0][1], -3);
  ck_assert_double_eq(result.matrix[0][2], 31);
  ck_assert_double_eq(result.matrix[0][3], -23);
  ck_assert_double_eq(result.matrix[1][0], -1);
  ck_assert_double_eq(result.matrix[1][1], 2);
  ck_assert_double_eq(result.matrix[1][2], -19);
  ck_assert_double_eq(result.matrix[1][3], 14);
  ck_assert_double_eq(result.matrix[2][0], 0);
  ck_assert_double_eq(result.matrix[2][1], 0);
  ck_assert_double_eq(result.matrix[2][2], 3);
  ck_assert_double_eq(result.matrix[2][3], -2);
  ck_assert_double_eq(result.matrix[3][0], 0);
  ck_assert_double_eq(result.matrix[3][1], 0);
  ck_assert_double_eq(result.matrix[3][2], -4);
  ck_assert_double_eq(result.matrix[3][3], 3);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_calc_complements_5) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(1, 1, &matrix);

  int res = s21_calc_complements(&matrix, &result);
  ck_assert_int_eq(res, CALC_ERROR);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_calc_complements_6) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

START_TEST(test_calc_complements_7) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &A);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 4;
  B.matrix[1][2] = 2;
  B.matrix[2][0] = 5;
  B.matrix[2][1] = 2;
  B.matrix[2][2] = 1;

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 10;
  A.matrix[0][2] = -20;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -14;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = -8;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = 4;

  int code = s21_calc_complements(&B, &R);
  ck_assert_int_eq(s21_eq_matrix(&R, &A), SUCCESS);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_calc_complements_8) {
  matrix_t A, B, R;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  s21_calc_complements(&A, &R);

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = -3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 14;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

END_TEST

START_TEST(test_calc_complements_9) {
  matrix_t B, R;
  s21_create_matrix(2, 3, &B);

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 4;
  B.matrix[1][2] = 2;

  int code = s21_calc_complements(&B, &R);

  ck_assert_int_eq(code, 2);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

END_TEST

START_TEST(test_calc_complements_10) {
  matrix_t A, B, R;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 5;

  s21_calc_complements(&A, &R);

  B.matrix[0][0] = 5;

  ck_assert_int_eq(s21_eq_matrix(&R, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

END_TEST

START_TEST(test_calc_complements_11) {
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_calc_complements(B, R);
  ck_assert_int_eq(res, 1);
}

END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s = suite_create("s21_calc_complements");
  TCase *o = tcase_create("calc_complements");

  tcase_add_test(o, test_calc_complements_1);
  tcase_add_test(o, test_calc_complements_2);
  tcase_add_test(o, test_calc_complements_3);
  tcase_add_test(o, test_calc_complements_4);
  tcase_add_test(o, test_calc_complements_5);
  tcase_add_test(o, test_calc_complements_6);
  tcase_add_test(o, test_calc_complements_7);
  tcase_add_test(o, test_calc_complements_8);
  tcase_add_test(o, test_calc_complements_9);
  tcase_add_test(o, test_calc_complements_10);
  tcase_add_test(o, test_calc_complements_11);

  suite_add_tcase(s, o);
  return s;
}
