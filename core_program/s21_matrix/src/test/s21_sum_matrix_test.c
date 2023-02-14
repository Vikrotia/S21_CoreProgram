#include "s21_test.h"

START_TEST(test_sum_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  int row = 1;
  int column = 1;

  s21_create_matrix(row, column, &matrix1);
  s21_create_matrix(row, column, &matrix2);

  generate_random_matrix(&matrix1);
  generate_random_matrix(&matrix2);

  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(res, OK);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j],
                              matrix1.matrix[i][j] + matrix2.matrix[i][j],
                              PRECISION);
    }
  }

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  int row = 4;
  int column = 6;

  s21_create_matrix(row, column, &matrix1);
  s21_create_matrix(row, column, &matrix2);

  generate_random_matrix(&matrix1);
  generate_random_matrix(&matrix2);

  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(res, OK);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j],
                              matrix1.matrix[i][j] + matrix2.matrix[i][j],
                              PRECISION);
    }
  }

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  s21_create_matrix(1, 2, &matrix1);
  s21_create_matrix(3, 2, &matrix2);

  generate_random_matrix(&matrix1);
  generate_random_matrix(&matrix2);

  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(res, CALC_ERROR);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(test_sum_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t result;

  int row = 4;
  int column = 6;

  s21_create_matrix(row, column, &matrix1);
  s21_create_matrix(row, column, &matrix2);

  generate_random_matrix(&matrix1);
  generate_random_matrix(&matrix2);

  int res = s21_sum_matrix(&matrix1, &matrix2, &result);
  ck_assert_int_eq(res, OK);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j],
                              matrix1.matrix[i][j] + matrix2.matrix[i][j],
                              PRECISION);
    }
  }

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_5) {
  double count = 1.0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  matrix_t D = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = count;
      B.matrix[i][j] = count;
      C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
      count = count + 1.0;
    }
  }
  int res = s21_sum_matrix(&A, &B, &D);
  int res_eq = s21_eq_matrix(&C, &D);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}

START_TEST(test_sum_matrix_6) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 1, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}

START_TEST(test_sum_matrix_7) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 0, &B);

  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(test_sum_matrix_8) {
  double count = 0.05;
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = count;
      m2.matrix[i][j] = count;
      origin.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
      count = count + 411.01001;
    }
  }
  int result = s21_sum_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(test_sum_matrix_9) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  double count = -4.2;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.columns; j++) {
      m1.matrix[i][j] = count;
      m2.matrix[i][j] = count;
      origin.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
      count = count - 0.001001;
    }
  }
  int result = s21_sum_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(test_sum_matrix_10) {
  matrix_t m1;
  matrix_t m2;
  matrix_t origin;
  matrix_t r;
  int check_origin = 0;
  int check_1 = s21_create_matrix(3, 3, &m1);
  int check_2 = s21_create_matrix(3, 3, &m2);
  int check_3 = s21_create_matrix(3, 3, &origin);
  m1.matrix[0][0] = 0.1;
  m1.matrix[0][1] = 0.2;
  m1.matrix[0][2] = 0.3;
  m1.matrix[1][0] = 0.4;
  m1.matrix[1][1] = 0.5;
  m1.matrix[1][2] = 0.6;
  m1.matrix[2][0] = 0.7;
  m1.matrix[2][1] = 0.8;
  m1.matrix[2][2] = 0.9;
  m2.matrix[0][0] = -1.0;
  m2.matrix[0][1] = -2.0;
  m2.matrix[0][2] = -3.0;
  m2.matrix[1][0] = -4.0;
  m2.matrix[1][1] = -5.0;
  m2.matrix[1][2] = -6.0;
  m2.matrix[2][0] = -7.0;
  m2.matrix[2][1] = -8.0;
  m2.matrix[2][2] = -9.0;
  origin.matrix[0][0] = -0.9;
  origin.matrix[0][1] = -1.8;
  origin.matrix[0][2] = -2.7;
  origin.matrix[1][0] = -3.6;
  origin.matrix[1][1] = -4.5;
  origin.matrix[1][2] = -5.4;
  origin.matrix[2][0] = -6.3;
  origin.matrix[2][1] = -7.2;
  origin.matrix[2][2] = -8.1;
  int result = s21_sum_matrix(&m1, &m2, &r);
  ck_assert_int_eq(check_1, check_origin);
  ck_assert_int_eq(check_2, check_origin);
  ck_assert_int_eq(check_3, check_origin);
  ck_assert_int_eq(result, check_origin);
  for (int i = 0; i < r.rows; i++) {
    for (int j = 0; j < r.columns; j++) {
      ck_assert_double_eq_tol(origin.matrix[i][j], r.matrix[i][j], 1e-7);
    }
  }
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&r);
  s21_remove_matrix(&origin);
}

START_TEST(test_sum_matrix_11) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 4);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_12) {
  matrix_t result, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_13) {
  matrix_t result, B, A;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 3;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 2;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(test_sum_matrix_14) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &res_origin);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[0][3] = -4;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 14;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  A.matrix[2][3] = -1;
  A.matrix[3][0] = 10;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 9;
  A.matrix[3][3] = -3;
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 5;
  B.matrix[1][0] = -7;
  B.matrix[1][1] = 7;
  B.matrix[1][2] = 1;
  B.matrix[1][3] = 1;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 3;
  B.matrix[2][2] = 4;
  B.matrix[2][3] = -4;
  B.matrix[3][0] = 10;
  B.matrix[3][1] = 3;
  B.matrix[3][2] = 9;
  B.matrix[3][3] = -3;
  res_origin.matrix[0][0] = 10;
  res_origin.matrix[0][1] = 13;
  res_origin.matrix[0][2] = 10;
  res_origin.matrix[0][3] = 1;
  res_origin.matrix[1][0] = -1;
  res_origin.matrix[1][1] = 10;
  res_origin.matrix[1][2] = 5;
  res_origin.matrix[1][3] = 15;
  res_origin.matrix[2][0] = 12;
  res_origin.matrix[2][1] = 1;
  res_origin.matrix[2][2] = 1;
  res_origin.matrix[2][3] = -5;
  res_origin.matrix[3][0] = 20;
  res_origin.matrix[3][1] = 6;
  res_origin.matrix[3][2] = 18;
  res_origin.matrix[3][3] = -6;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_int_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(test_sum_matrix_15) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_origin);
  A.matrix[0][0] = 2.987654;
  A.matrix[0][1] = -5.3456;
  A.matrix[1][0] = 6.23;
  A.matrix[1][1] = -3.9292;
  B.matrix[0][0] = 4.838;
  B.matrix[0][1] = 8.0987;
  B.matrix[1][0] = -8;
  B.matrix[1][1] = -0.921;
  res_origin.matrix[0][0] = 7.825654;
  res_origin.matrix[0][1] = 2.7531;
  res_origin.matrix[1][0] = -1.77;
  res_origin.matrix[1][1] = -4.8502;
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_int_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(test_sum_matrix_16) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      res_origin.matrix[i][j] = i * 2;
    }
  }
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_int_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(test_sum_matrix_17) {
  matrix_t result, res_origin, B, A;
  s21_create_matrix(5, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_create_matrix(5, 4, &res_origin);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      res_origin.matrix[i][j] = i;
    }
  }
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  for (int i = 0; i < res_origin.rows; i++) {
    for (int j = 0; j < res_origin.columns; j++) {
      ck_assert_int_eq(res_origin.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&res_origin);
}

START_TEST(test_sum_matrix_18) {
  matrix_t result, B, A;
  s21_create_matrix(-5, 5, &A);
  s21_create_matrix(5, 4, &B);
  int check = s21_sum_matrix(&A, &B, &result);
  int check_origin = 1;
  ck_assert_int_eq(check, check_origin);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  Suite *s = suite_create("s21_sum_matrix");
  TCase *o = tcase_create("sum_matrix");

  tcase_add_test(o, test_sum_matrix_1);
  tcase_add_test(o, test_sum_matrix_2);
  tcase_add_test(o, test_sum_matrix_3);
  tcase_add_test(o, test_sum_matrix_4);
  tcase_add_test(o, test_sum_matrix_5);
  tcase_add_test(o, test_sum_matrix_6);
  tcase_add_test(o, test_sum_matrix_7);
  tcase_add_test(o, test_sum_matrix_8);
  tcase_add_test(o, test_sum_matrix_9);
  tcase_add_test(o, test_sum_matrix_10);
  tcase_add_test(o, test_sum_matrix_11);
  tcase_add_test(o, test_sum_matrix_12);
  tcase_add_test(o, test_sum_matrix_13);
  tcase_add_test(o, test_sum_matrix_14);
  tcase_add_test(o, test_sum_matrix_15);
  tcase_add_test(o, test_sum_matrix_16);
  tcase_add_test(o, test_sum_matrix_17);
  tcase_add_test(o, test_sum_matrix_18);

  suite_add_tcase(s, o);
  return s;
}
