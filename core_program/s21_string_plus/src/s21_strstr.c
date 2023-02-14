#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  int flag_of_end = 0;
  while (*haystack && !(flag_of_end)) {
    char *begin = (char *)haystack;
    const char *pattern = needle;
    while (*haystack && *pattern && *haystack == *pattern) {
      haystack++;
      pattern++;
    }
    if (!*pattern) {
      res = begin;
      flag_of_end = 1;
    }
    haystack = begin + 1;
  }
  return res;
}
