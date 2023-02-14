#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *lasts;
  register int ch;
  int cont = 0;
  if (str == 0) str = lasts;
  do {
    if ((ch = *str++) == '\0') cont = 1;
  } while (s21_strchr(delim, ch) && cont == 0);
  if (cont == 0) {
    str--;
    lasts = str + s21_strcspn(str, delim);
    if (*lasts != 0) *lasts++ = 0;
  }
  return cont == 0 ? str : 0;
}
