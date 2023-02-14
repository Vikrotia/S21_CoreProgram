#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  int destLength = s21_strlen(dest);
  int srcLength = s21_strlen(src);
  for (int x = 0; x <= srcLength; x += 1) dest[destLength + x] = src[x];
  return dest;
}
