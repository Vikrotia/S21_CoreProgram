#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  do {
    if (*str == (char)c) {
      res = (char *)str;
    }
  } while (*str++);
  return res;
}
