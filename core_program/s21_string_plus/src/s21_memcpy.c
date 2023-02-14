#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != src) {
    unsigned char *dest1 = (unsigned char *)dest;
    unsigned char *src1 = (unsigned char *)src;
    s21_size_t i = n - 1;
    if ((unsigned long)dest1 < (unsigned long)src1) {
      while (n--) {
        *dest1++ = *src1++;
      }
    } else {
      while (n--) {
        *(dest1 + i) = *(src1 + i);
        dest1--;
        src1--;
      }
    }
  }
  return dest;
}
