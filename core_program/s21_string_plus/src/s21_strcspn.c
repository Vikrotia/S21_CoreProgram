#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t num = 0;
  int flag_of_end = 0;
  for (; *str1 && !flag_of_end; str1++) {
    if (s21_strchr(str2, *str1)) {
      flag_of_end = 1;
    } else {
      num++;
    }
  }
  return num;
}
