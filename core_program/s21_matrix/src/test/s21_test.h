#ifndef S21_TEST_H_
#define S21_TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"

#define PRECISION 1E-6
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

Suite *s21_create_matrix_suite();
Suite *s21_remove_matrix_suite();
Suite *s21_eq_matrix_suite();
Suite *s21_sum_matrix_suite();
Suite *s21_sub_matrix_suite();
Suite *s21_mult_number_suite();
Suite *s21_mult_matrix_suite();
Suite *s21_transpose_suite();
Suite *s21_calc_complements_suite();
Suite *s21_determinant_suite();
Suite *s21_inverse_matrix_suite();

void generate_random_matrix(matrix_t *A);
void copy_matrix(matrix_t A, matrix_t *B);
#endif  //  S21_TEST_H_