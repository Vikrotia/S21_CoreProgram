#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
#define EQ_SIZE(A, B) (A->rows == B->rows && A->columns == B->columns)
#define EPS 1e-7

// Matrix structure
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/**
 * @brief Existence of matrix.
 * @param A matrix.
 * @return 1 - OK; 0 - Error, incorrect matrix;
 */
int s21_existence_of_matrix(matrix_t *A);

/**
 * @brief Creating matrix.
 * @param rows row count.
 * @param columns columns count.
 * @param result created matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Cleaning of matrix.
 * @param A matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief Matrix comparison.
 * @param A first matrix.
 * @param B second matrix.
 * @return 0 - The matrices A, B are not equal; 1 - The matrices A, B are equal;
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief Adding matrices.
 * @param A first matrix.
 * @param B second matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Subtracting matrices.
 * @param A first matrix.
 * @param B second matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Matrix multiplication by scalar.
 * @param A first matrix.
 * @param number scalar.
 * @param result resulted matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief Multiplication of two matrices.
 * @param A first matrix.
 * @param B second matrix.
 * @param result resulted matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief Matrix transpose.
 * @param A start matrix.
 * @param result resulted matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief Minor of matrix and matrix of algebraic complements .
 * @param A start matrix.
 * @param result resulted matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief Matrix determinant.
 * @param A start matrix.
 * @param result resulted matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief Inverse of the matrix.
 * @param A start matrix.
 * @param result resulted matrix.
 * @return 0 - OK; 1 - Error, incorrect matrix;
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_matrix_for_minor(matrix_t *A, matrix_t *result, int i, int j);
double s21_minor_matrix(matrix_t *A);

#endif  // S21_MATRIX_H_