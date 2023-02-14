#include "s21_matrix.h"

int s21_existence_of_matrix(matrix_t *A) {
  int res = 0;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) res = 1;
  return res;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows > 0 && columns > 0) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (NULL == result->matrix) {
      res = INCORRECT_MATRIX;
      result->matrix = NULL;
    } else {
      for (int i = 0; i < rows && !res; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (NULL == result->matrix[i]) {
          res = INCORRECT_MATRIX;
          result->matrix = NULL;
        }
      }
    }
  } else {
    result->matrix = NULL;
    res = INCORRECT_MATRIX;
  }
  if (!res) {
    result->rows = rows;
    result->columns = columns;
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i]) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }
  }
  free(A->matrix);
  A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (s21_existence_of_matrix(A) && s21_existence_of_matrix(B) &&
      EQ_SIZE(A, B)) {
    for (int i = 0; i < A->rows && res; i++) {
      for (int j = 0; j < A->columns && res; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          res = FAILURE;
        }
      }
    }
  } else
    res = FAILURE;
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_existence_of_matrix(A) && s21_existence_of_matrix(B)) {
    if EQ_SIZE (A, B) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        for (int i = 0; i < A->rows && !res; i++) {
          for (int j = 0; j < A->columns && !res; j++) {
            if (A->matrix[i][j] + B->matrix[i][j] > __DBL_MAX__ ||
                isinf(A->matrix[i][j]) || isinf(B->matrix[i][j])) {
              res = CALCULATION_ERROR;
              result->matrix = NULL;
            } else
              result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      } else {
        res = CALCULATION_ERROR;
        result->matrix = NULL;
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_existence_of_matrix(A) && s21_existence_of_matrix(B)) {
    if EQ_SIZE (A, B) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        for (int i = 0; i < A->rows && !res; i++) {
          for (int j = 0; j < A->columns && !res; j++) {
            if (isinf(A->matrix[i][j]) || isinf(B->matrix[i][j])) {
              res = CALCULATION_ERROR;
              result->matrix = NULL;
            } else
              result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else {
        res = CALCULATION_ERROR;
        result->matrix = NULL;
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (s21_existence_of_matrix(A)) {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows && !res; i++) {
        for (int j = 0; j < A->columns && !res; j++) {
          if (isinf(A->matrix[i][j]) || isinf(number) ||
              A->matrix[i][j] * number >
                  __DBL_MAX__) {  // NAN посмотреть как делать
            res = CALCULATION_ERROR;
            result->matrix = NULL;
          } else
            result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (s21_existence_of_matrix(A) && s21_existence_of_matrix(B)) {
    if (A->columns == B->rows) {
      if (!s21_create_matrix(A->rows, B->columns, result)) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < B->rows; k++) {
              if (A->matrix[i][k] * B->matrix[k][j] > __DBL_MAX__ ||
                  A->matrix[i][k] * B->matrix[k][j] + result->matrix[i][j] >
                      __DBL_MAX__ ||
                  isinf(A->matrix[i][k]) || isinf(B->matrix[k][j])) {
                res = CALCULATION_ERROR;
                result->matrix = NULL;
              } else
                result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      } else {
        res = CALCULATION_ERROR;
        result->matrix = NULL;
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (s21_existence_of_matrix(A)) {
    if (!s21_create_matrix(A->columns, A->rows, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}

double s21_minor_matrix(matrix_t *A) {
  double minor = 0;
  if (A->rows == 1 && A->columns == 1)
    minor = A->matrix[0][0];
  else if (A->rows == 2 && A->columns == 2)
    minor =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else if (A->rows > 2 && A->columns > 2) {
    matrix_t temp_matrix = {0};
    for (int x = 0; x < A->columns; x++) {
      if (!s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix)) {
        for (int i = 1; i < A->rows; i++) {
          int column = 0;
          for (int j = 0; j < A->rows; j++) {
            if (j != x) {
              temp_matrix.matrix[i - 1][column] = A->matrix[i][j];
              column++;
            }
          }
        }
      }
      minor +=
          pow(-1, x + 2) * A->matrix[0][x] * s21_minor_matrix(&temp_matrix);
      s21_remove_matrix(&temp_matrix);
    }
  }
  return minor;
}

int s21_matrix_for_minor(matrix_t *A, matrix_t *result, int i, int j) {
  int res = OK;
  if (!s21_create_matrix(A->rows - 1, A->columns - 1, result)) {
    int x = 0;
    for (int i1 = 0; i1 < A->rows; i1++) {
      if (i1 != i) {
        int y = 0;
        for (int j1 = 0; j1 < A->rows; j1++) {
          if (j1 != j) {
            result->matrix[x][y] = A->matrix[i1][j1];
            y++;
          }
        }
        x++;
      }
    }
  } else {
    res = CALCULATION_ERROR;
    result->matrix = NULL;
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (s21_existence_of_matrix(A)) {
    if (A->rows == A->columns && A->rows > 1) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        matrix_t temp_matrix = {0};
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (!s21_matrix_for_minor(A, &temp_matrix, i, j)) {
              result->matrix[i][j] =
                  pow(-1, i + j) * s21_minor_matrix(&temp_matrix);
              s21_remove_matrix(&temp_matrix);
            }
          }
        }
      } else {
        res = CALCULATION_ERROR;
        result->matrix = NULL;
      }
    } else if (A->rows == A->columns && A->rows == 1 && A->matrix[0][0] != 0) {
      if (!s21_create_matrix(1, 1, result))
        result->matrix[0][0] = A->matrix[0][0];
      else {
        res = CALCULATION_ERROR;
        result->matrix = NULL;
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  double determinant = 0.0;
  *result = 0;
  if (s21_existence_of_matrix(A)) {
    if (A->columns == A->rows) {
      if (A->columns == 1) {
        *result = A->matrix[0][0];
      } else {
        matrix_t temp_matrix = {0};
        s21_calc_complements(A, &temp_matrix);
        for (int i = 0; i < A->columns; i++)
          determinant += A->matrix[0][i] * temp_matrix.matrix[0][i];
        *result = determinant;
        s21_remove_matrix(&temp_matrix);
      }
    } else {
      res = CALCULATION_ERROR;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double determinant = 0.0;
  if (s21_existence_of_matrix(A)) {
    if (A->columns == A->rows) {
      s21_determinant(A, &determinant);
      if (fabs(determinant)) {
        if (!s21_create_matrix(A->rows, A->columns, result)) {
          if (A->rows == A->columns && A->columns == 1)
            result->matrix[0][0] = 1 / A->matrix[0][0];
          else {
            matrix_t temp_matrix_trans = {0};
            matrix_t temp_matrix_comp = {0};
            s21_transpose(A, &temp_matrix_trans);
            s21_calc_complements(&temp_matrix_trans, &temp_matrix_comp);
            for (int i = 0; i < temp_matrix_comp.rows; i++) {
              for (int j = 0; j < temp_matrix_comp.columns; j++) {
                result->matrix[i][j] =
                    temp_matrix_comp.matrix[i][j] / determinant;
              }
            }
            s21_remove_matrix(&temp_matrix_trans);
            s21_remove_matrix(&temp_matrix_comp);
          }
        } else {
          res = CALCULATION_ERROR;
          result->matrix = NULL;
        }
      } else {
        res = CALCULATION_ERROR;
        result->matrix = NULL;
      }
    } else {
      res = CALCULATION_ERROR;
      result->matrix = NULL;
    }
  } else {
    res = INCORRECT_MATRIX;
    result->matrix = NULL;
  }
  return res;
}
