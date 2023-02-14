#include "s21_test.h"

START_TEST(test_determinant_1) {
  matrix_t matrix;
  s21_create_matrix(1, 1, &matrix);
  matrix.matrix[0][0] = 1.232;

  double det = 0;

  int res = s21_determinant(&matrix, &det);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(det, 1.232, PRECISION);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_2) {
  matrix_t matrix;
  s21_create_matrix(2, 2, &matrix);
  matrix.matrix[0][0] = 2342.234;
  matrix.matrix[0][1] = 2.312;
  matrix.matrix[1][0] = 24.234;
  matrix.matrix[1][1] = 424.2;

  double det = 0;

  int res = s21_determinant(&matrix, &det);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(det, 993519.633792, PRECISION);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_3) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 2.34;
  matrix.matrix[0][1] = 27.345;
  matrix.matrix[0][2] = 25.23;
  matrix.matrix[1][0] = 2.55;
  matrix.matrix[1][1] = 8.56;
  matrix.matrix[1][2] = 45.75;
  matrix.matrix[2][0] = 55.3;
  matrix.matrix[2][1] = 4.34;
  matrix.matrix[2][2] = 24.33;

  double det = 0;

  int res = s21_determinant(&matrix, &det);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(det, 55844.5082595, PRECISION);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_4) {
  matrix_t matrix;
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 1.34;
  matrix.matrix[0][1] = 7.423;
  matrix.matrix[0][2] = 2.45;
  matrix.matrix[0][3] = 2.42;
  matrix.matrix[1][0] = 34;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = 5;
  matrix.matrix[1][3] = 24.52;
  matrix.matrix[2][0] = 3;
  matrix.matrix[2][1] = 4.5;
  matrix.matrix[2][2] = 2.4;
  matrix.matrix[2][3] = 2.4;
  matrix.matrix[3][0] = 8.43;
  matrix.matrix[3][1] = 3.5;
  matrix.matrix[3][2] = 53.6;
  matrix.matrix[3][3] = 24.5;

  double det = 0;

  int res = s21_determinant(&matrix, &det);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(det, -10769.66942328, PRECISION);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_5) {
  matrix_t matrix;
  s21_create_matrix(4, 3, &matrix);
  double det = 0;

  int res = s21_determinant(&matrix, &det);
  ck_assert_int_eq(res, CALC_ERROR);
  ck_assert_double_eq_tol(det, 0, PRECISION);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_determinant_6) {
  matrix_t A;
  double B, R = 1.25;
  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = 1.25;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_7) {
  matrix_t A;
  double B, R = -69;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_8) {
  matrix_t A;
  double B, R = -2;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = -5;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_9) {
  matrix_t A;
  double B, R = 25;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_10) {
  matrix_t A;
  double B, R = 23;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = -6;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_11) {
  matrix_t A;
  double B, R = -8;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = -7;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 5;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_12) {
  matrix_t A = {0};
  double B, R = 18;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -5;
  A.matrix[0][3] = 8;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = -6;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = -5;
  A.matrix[2][2] = -7;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = -4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = -6;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_13) {
  matrix_t A = {0};
  double B, R = -69.0 / 4.0;
  s21_create_matrix(5, 5, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;

  s21_determinant(&A, &B);

  ck_assert(fabs(B - R) < 1e-7);

  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_14) {
  matrix_t A;
  double B;
  s21_create_matrix(4, 5, &A);
  int res = s21_determinant(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}

END_TEST

START_TEST(test_determinant_15) {
  matrix_t a = {0};
  double number;
  s21_create_matrix(4, 4, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 13;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[1][3] = 16;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 90;
  a.matrix[2][3] = 19;
  a.matrix[3][0] = 1;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 7;
  a.matrix[3][3] = 17;

  s21_determinant(&a, &number);
  ck_assert_int_eq(number, 13608);
  s21_remove_matrix(&a);
}

END_TEST

START_TEST(test_determinant_16) {
  matrix_t *B = NULL;
  double re = 0;
  int res = s21_determinant(B, &re);
  ck_assert_int_eq(res, 1);
}

END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s = suite_create("s21_determinant");
  TCase *o = tcase_create("determinant");

  tcase_add_test(o, test_determinant_1);
  tcase_add_test(o, test_determinant_2);
  tcase_add_test(o, test_determinant_3);
  tcase_add_test(o, test_determinant_4);
  tcase_add_test(o, test_determinant_5);
  tcase_add_test(o, test_determinant_6);
  tcase_add_test(o, test_determinant_7);
  tcase_add_test(o, test_determinant_8);
  tcase_add_test(o, test_determinant_9);
  tcase_add_test(o, test_determinant_10);
  tcase_add_test(o, test_determinant_11);
  tcase_add_test(o, test_determinant_12);
  tcase_add_test(o, test_determinant_13);
  tcase_add_test(o, test_determinant_14);
  tcase_add_test(o, test_determinant_15);
  tcase_add_test(o, test_determinant_16);

  suite_add_tcase(s, o);
  return s;
}
