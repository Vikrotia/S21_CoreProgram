#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src && str && start_index <= (s21_strlen(src))) {
    result =
        (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, src, start_index);
      s21_strcat(result, str);
      s21_strcat(result, src + start_index);
    }
  }
  return result;
}
