#include "s21_test.h"

int main() {
  int failed_count_create_matrix = 0;
  int failed_count_remove_matrix = 0;
  int failed_count_eq_matrix = 0;
  int failed_count_sum_matrix = 0;
  int failed_count_sub_matrix = 0;
  int failed_count_mult_number = 0;
  int failed_count_mult_matrix = 0;
  int failed_count_transpose = 0;
  int failed_count_calc_complements = 0;
  int failed_count_determinant = 0;
  int failed_count_inverse_matrix = 0;

  Suite *s21_create_matrix, *s21_remove_matrix, *s21_eq_matrix, *s21_sum_matrix,
      *s21_sub_matrix, *s21_mult_number, *s21_mult_matrix, *s21_transpose,
      *s21_calc_complements, *s21_determinant, *s21_inverse_matrix;

  SRunner *runner_create_matrix, *runner_remove_matrix, *runner_eq_matrix,
      *runner_sum_matrix, *runner_sub_matrix, *runner_mult_number,
      *runner_mult_matrix, *runner_transpose, *runner_calc_complements,
      *runner_determinant, *runner_inverse_matrix;

  s21_create_matrix = s21_create_matrix_suite();
  runner_create_matrix = srunner_create(s21_create_matrix);
  srunner_set_fork_status(runner_create_matrix, CK_NOFORK);
  srunner_run_all(runner_create_matrix, CK_NORMAL);
  failed_count_create_matrix = srunner_ntests_failed(runner_create_matrix);
  srunner_free(runner_create_matrix);

  s21_remove_matrix = s21_remove_matrix_suite();
  runner_remove_matrix = srunner_create(s21_remove_matrix);
  srunner_set_fork_status(runner_remove_matrix, CK_NOFORK);
  srunner_run_all(runner_remove_matrix, CK_NORMAL);
  failed_count_remove_matrix = srunner_ntests_failed(runner_remove_matrix);
  srunner_free(runner_remove_matrix);

  s21_eq_matrix = s21_eq_matrix_suite();
  runner_eq_matrix = srunner_create(s21_eq_matrix);
  srunner_set_fork_status(runner_eq_matrix, CK_NOFORK);
  srunner_run_all(runner_eq_matrix, CK_NORMAL);
  failed_count_eq_matrix = srunner_ntests_failed(runner_eq_matrix);
  srunner_free(runner_eq_matrix);

  s21_sum_matrix = s21_sum_matrix_suite();
  runner_sum_matrix = srunner_create(s21_sum_matrix);
  srunner_set_fork_status(runner_sum_matrix, CK_NOFORK);
  srunner_run_all(runner_sum_matrix, CK_NORMAL);
  failed_count_sum_matrix = srunner_ntests_failed(runner_sum_matrix);
  srunner_free(runner_sum_matrix);

  s21_sub_matrix = s21_sub_matrix_suite();
  runner_sub_matrix = srunner_create(s21_sub_matrix);
  srunner_set_fork_status(runner_sub_matrix, CK_NOFORK);
  srunner_run_all(runner_sub_matrix, CK_NORMAL);
  failed_count_sub_matrix = srunner_ntests_failed(runner_sub_matrix);
  srunner_free(runner_sub_matrix);

  s21_mult_number = s21_mult_number_suite();
  runner_mult_number = srunner_create(s21_mult_number);
  srunner_set_fork_status(runner_mult_number, CK_NOFORK);
  srunner_run_all(runner_mult_number, CK_NORMAL);
  failed_count_mult_number = srunner_ntests_failed(runner_mult_number);
  srunner_free(runner_mult_number);

  s21_mult_matrix = s21_mult_matrix_suite();
  runner_mult_matrix = srunner_create(s21_mult_matrix);
  srunner_set_fork_status(runner_mult_matrix, CK_NOFORK);
  srunner_run_all(runner_mult_matrix, CK_NORMAL);
  failed_count_mult_matrix = srunner_ntests_failed(runner_mult_matrix);
  srunner_free(runner_mult_matrix);

  s21_transpose = s21_transpose_suite();
  runner_transpose = srunner_create(s21_transpose);
  srunner_set_fork_status(runner_transpose, CK_NOFORK);
  srunner_run_all(runner_transpose, CK_NORMAL);
  failed_count_transpose = srunner_ntests_failed(runner_transpose);
  srunner_free(runner_transpose);

  s21_calc_complements = s21_calc_complements_suite();
  runner_calc_complements = srunner_create(s21_calc_complements);
  srunner_set_fork_status(runner_calc_complements, CK_NOFORK);
  srunner_run_all(runner_calc_complements, CK_NORMAL);
  failed_count_calc_complements =
      srunner_ntests_failed(runner_calc_complements);
  srunner_free(runner_calc_complements);

  s21_determinant = s21_determinant_suite();
  runner_determinant = srunner_create(s21_determinant);
  srunner_set_fork_status(runner_determinant, CK_NOFORK);
  srunner_run_all(runner_determinant, CK_NORMAL);
  failed_count_determinant = srunner_ntests_failed(runner_determinant);
  srunner_free(runner_determinant);

  s21_inverse_matrix = s21_inverse_matrix_suite();
  runner_inverse_matrix = srunner_create(s21_inverse_matrix);
  srunner_set_fork_status(runner_inverse_matrix, CK_NOFORK);
  srunner_run_all(runner_inverse_matrix, CK_NORMAL);
  failed_count_inverse_matrix = srunner_ntests_failed(runner_inverse_matrix);
  srunner_free(runner_inverse_matrix);

  int all_count = failed_count_create_matrix + failed_count_remove_matrix +
                  failed_count_eq_matrix + failed_count_mult_matrix +
                  failed_count_transpose + failed_count_sum_matrix +
                  failed_count_calc_complements + failed_count_mult_number +
                  failed_count_sub_matrix + failed_count_determinant +
                  failed_count_inverse_matrix;

  return (all_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

void generate_random_matrix(matrix_t *A) {
  srand(time(NULL));

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = rand();
    }
  }
}

void copy_matrix(matrix_t A, matrix_t *B) {
  for (int i = 0; i < A.columns; i++) {
    for (int j = 0; j < A.rows; j++) {
      B->matrix[i][j] = A.matrix[i][j];
    }
  }
}