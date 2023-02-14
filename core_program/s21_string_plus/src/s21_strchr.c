#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *str1 = (char *)str;
  char *prt = s21_NULL;
  int flag_of_end = 0;
  if (c == 0) {
    prt = "\0";
  } else {
    for (; *str1 && !(flag_of_end); str1++) {
      if (*str1 == c) {
        prt = str1;
        flag_of_end = 1;
      }
    }
  }
  return prt;
}
