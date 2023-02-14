#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char dest1[n];
  s21_memcpy(dest1, src, n);
  s21_memcpy(dest, dest1, n);
  return dest;
}
