#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t str1Length = s21_strlen(str1);
  s21_size_t shift = 0;
  int status = 0;
  for (shift = 0; status == 0 && shift < str1Length; shift += 1) {
    if (s21_strchr(str2, str1[shift])) status = 1;
  }
  return (char *)(status ? (str1 + shift - 1) : s21_NULL);
}
