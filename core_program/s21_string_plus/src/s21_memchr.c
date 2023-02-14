#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  unsigned char *res = s21_NULL;
  int flag_of_end = 0;
  while (ptr && (n--) && !flag_of_end) {
    if (*ptr == (unsigned char)c) {
      res = ptr;
      flag_of_end = 1;
    }
    ptr++;
  }
  return res;
}
