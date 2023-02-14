#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_memset(dest, '\0', n);
  unsigned char *addres = (unsigned char *)dest;
  while (*src && n--) {
    *addres++ = *src++;
  }
  return dest;
}
