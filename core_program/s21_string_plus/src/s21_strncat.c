#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != src) {
    unsigned char *ptr = (unsigned char *)dest + s21_strlen(dest);
    while (*src && n--) {
      *ptr++ = *src++;
    }
  }
  return dest;
}
