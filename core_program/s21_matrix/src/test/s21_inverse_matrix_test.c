#include "s21_test.h"

START_TEST(test_inverse_matrix_1) {
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

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, CALC_ERROR);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_inverse_matrix_2) {
  matrix_t matrix;
  matrix_t result;

  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 3;
  matrix.matrix[0][1] = 4;
  matrix.matrix[1][0] = 5;
  matrix.matrix[1][1] = 7;

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 7);
  ck_assert_double_eq(result.matrix[0][1], -4);
  ck_assert_double_eq(result.matrix[1][0], -5);
  ck_assert_double_eq(result.matrix[1][1], 3);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_3) {
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

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], -1);
  ck_assert_double_eq(result.matrix[0][2], 1);
  ck_assert_double_eq(result.matrix[1][0], -38);
  ck_assert_double_eq(result.matrix[1][1], 41);
  ck_assert_double_eq(result.matrix[1][2], -34);
  ck_assert_double_eq(result.matrix[2][0], 27);
  ck_assert_double_eq(result.matrix[2][1], -29);
  ck_assert_double_eq(result.matrix[2][2], 24);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_4) {
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

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, OK);

  ck_assert_double_eq(result.matrix[0][0], 2);
  ck_assert_double_eq(result.matrix[0][1], -1);
  ck_assert_double_eq(result.matrix[0][2], 0);
  ck_assert_double_eq(result.matrix[0][3], 0);
  ck_assert_double_eq(result.matrix[1][0], -3);
  ck_assert_double_eq(result.matrix[1][1], 2);
  ck_assert_double_eq(result.matrix[1][2], 0);
  ck_assert_double_eq(result.matrix[1][3], 0);
  ck_assert_double_eq(result.matrix[2][0], 31);
  ck_assert_double_eq(result.matrix[2][1], -19);
  ck_assert_double_eq(result.matrix[2][2], 3);
  ck_assert_double_eq(result.matrix[2][3], -4);
  ck_assert_double_eq(result.matrix[3][0], -23);
  ck_assert_double_eq(result.matrix[3][1], 14);
  ck_assert_double_eq(result.matrix[3][2], -2);
  ck_assert_double_eq(result.matrix[3][3], 3);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_5) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(4, 3, &matrix);

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, CALC_ERROR);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_inverse_matrix_6) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 5;

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(1.0 / matrix.matrix[0][0], result.matrix[0][0]);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_matrix_7) {
  matrix_t matrix;
  matrix_t result;
  s21_create_matrix(-1, -1, &matrix);

  int res = s21_inverse_matrix(&matrix, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_inverse_matrix_8) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 2;
  result1.matrix[0][1] = 5;
  result1.matrix[0][2] = 7;

  result1.matrix[1][0] = 6;
  result1.matrix[1][1] = 3;
  result1.matrix[1][2] = 4;

  result1.matrix[2][0] = 5;
  result1.matrix[2][1] = -2;
  result1.matrix[2][2] = -3;

  int expected_result = s21_create_matrix(3, 3, &result2);
  result2.matrix[0][0] = 1;
  result2.matrix[0][1] = -1;
  result2.matrix[0][2] = 1;
  result2.matrix[1][0] = -38;
  result2.matrix[1][1] = 41;
  result2.matrix[1][2] = -34;
  result2.matrix[2][0] = 27;
  result2.matrix[2][1] = -29;
  result2.matrix[2][2] = 24;
  int actual_result = s21_inverse_matrix(&result1, &result3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result2.matrix[i][j], result3.matrix[i][j], 1e-6);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_inverse_matrix_9) {
  matrix_t result1;
  matrix_t result3;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 4;
  result1.matrix[1][1] = 5;
  result1.matrix[1][2] = 6;

  result1.matrix[2][0] = 7;
  result1.matrix[2][1] = 8;
  result1.matrix[2][2] = 9;
  int expected_result = 2;
  int actual_result = s21_inverse_matrix(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);

  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_inverse_matrix_10) {
  matrix_t A, result, check;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = -1.;
  A.matrix[0][2] = 1.;
  A.matrix[1][0] = -38.;
  A.matrix[1][1] = 41.;
  A.matrix[1][2] = -34.;
  A.matrix[2][0] = 27.;
  A.matrix[2][1] = -29.;
  A.matrix[2][2] = 24.;

  check.matrix[0][0] = 2.;
  check.matrix[0][1] = 5.;
  check.matrix[0][2] = 7.;
  check.matrix[1][0] = 6.;
  check.matrix[1][1] = 3.;
  check.matrix[1][2] = 4.;
  check.matrix[2][0] = 5.;
  check.matrix[2][1] = -2.;
  check.matrix[2][2] = -3.;

  s21_inverse_matrix(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(test_inverse_matrix_11) {
  matrix_t A, B, C;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 4;
  s21_inverse_matrix(&A, &B);
  C.matrix[0][0] = -0.125;
  C.matrix[0][1] = 0.19166666;
  C.matrix[0][2] = 0.325;
  C.matrix[0][3] = -0.16666666;
  C.matrix[1][0] = -0.125;
  C.matrix[1][1] = 0.05833333;
  C.matrix[1][2] = -0.075;
  C.matrix[1][3] = 0.16666666;
  C.matrix[2][0] = 0.125;
  C.matrix[2][1] = 0.675;
  C.matrix[2][2] = 0.275;
  C.matrix[2][3] = -0.5;
  C.matrix[3][0] = 0.25;
  C.matrix[3][1] = -0.58333333;
  C.matrix[3][2] = -0.25;
  C.matrix[3][3] = 0.33333333;
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_inverse_matrix_12) {
  matrix_t A, B;
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_13) {
  matrix_t A, result;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 777;
  A.matrix[0][1] = 777;
  int check = s21_inverse_matrix(&A, &result);
  int check_origin = 2;
  ck_assert_uint_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *o = tcase_create("inverse_matrix");

  tcase_add_test(o, test_inverse_matrix_1);
  tcase_add_test(o, test_inverse_matrix_2);
  tcase_add_test(o, test_inverse_matrix_3);
  tcase_add_test(o, test_inverse_matrix_4);
  tcase_add_test(o, test_inverse_matrix_5);
  tcase_add_test(o, test_inverse_matrix_6);
  tcase_add_test(o, test_inverse_matrix_7);
  tcase_add_test(o, test_inverse_matrix_8);
  tcase_add_test(o, test_inverse_matrix_9);
  tcase_add_test(o, test_inverse_matrix_10);
  tcase_add_test(o, test_inverse_matrix_11);
  tcase_add_test(o, test_inverse_matrix_12);
  tcase_add_test(o, test_inverse_matrix_13);

  suite_add_tcase(s, o);
  return s;
}
