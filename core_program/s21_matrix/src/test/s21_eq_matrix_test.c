#include "s21_test.h"

START_TEST(test_eq_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);

  generate_random_matrix(&matrix1);
  copy_matrix(matrix1, &matrix2);

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_eq_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);

  generate_random_matrix(&matrix1);
  matrix2.matrix[0][0] = 3;

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_eq_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  generate_random_matrix(&matrix1);
  copy_matrix(matrix1, &matrix2);

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_eq_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);

  generate_random_matrix(&matrix1);
  copy_matrix(matrix1, &matrix2);
  matrix2.matrix[1][0] = -3;

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_eq_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);

  generate_random_matrix(&matrix1);
  copy_matrix(matrix1, &matrix2);

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_eq_matrix_6) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);

  generate_random_matrix(&matrix1);
  copy_matrix(matrix1, &matrix2);
  matrix2.matrix[0][2] = -12;

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_eq_matrix_7) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(3, 2, &matrix1);
  s21_create_matrix(2, 3, &matrix2);

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}

START_TEST(test_eq_matrix_8) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_9) {
  double count = 0;
  count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 1, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count + 18.0145247524;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_10) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      count = count - 0.241;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);
  B.matrix[2][2] += 0.000009;
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_11) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count + 1.0;
      count = count + 1.5412;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_12) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_13) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(-1, 1, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
}

START_TEST(test_eq_matrix_14) {
  double count = 1.0;
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count - 234.011;
      B.matrix[i][j] = count;
      count = count + 1.0;
    }
  }
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_eq_matrix_15) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(-1, -1, &matrix1);
  s21_create_matrix(-1, -1, &matrix2);

  int res = s21_eq_matrix(&matrix1, &matrix2);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *o = tcase_create("eq_matrix");

  tcase_add_test(o, test_eq_matrix_1);
  tcase_add_test(o, test_eq_matrix_2);
  tcase_add_test(o, test_eq_matrix_3);
  tcase_add_test(o, test_eq_matrix_4);
  tcase_add_test(o, test_eq_matrix_5);
  tcase_add_test(o, test_eq_matrix_6);
  tcase_add_test(o, test_eq_matrix_7);
  tcase_add_test(o, test_eq_matrix_8);
  tcase_add_test(o, test_eq_matrix_9);
  tcase_add_test(o, test_eq_matrix_10);
  tcase_add_test(o, test_eq_matrix_11);
  tcase_add_test(o, test_eq_matrix_12);
  tcase_add_test(o, test_eq_matrix_13);
  tcase_add_test(o, test_eq_matrix_14);
  tcase_add_test(o, test_eq_matrix_15);

  suite_add_tcase(s, o);
  return s;
}
