#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t n = 0;
  int k = 1;
  for (const char *ptr1 = str1; *ptr1; ptr1++) {
    if (k) {
      k = 0;
      int k1 = 1;
      for (const char *ptr2 = str2; *ptr2; ptr2++) {
        if (k1) {
          if (*ptr1 == *ptr2) {
            n++;
            k = 1;
            k1 = 0;
          }
        }
      }
    }
  }
  return n;
}
