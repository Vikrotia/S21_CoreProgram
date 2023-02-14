#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int flag_memcmp = 0, flag_of_end = 0;
  while (!flag_of_end && (n--) && ptr1 && ptr2) {
    if (*ptr1 != *ptr2) {
      flag_memcmp = (*ptr1) - (*ptr2);
      flag_of_end = 1;
    }
    ptr1++;
    ptr2++;
  }
  return flag_memcmp;
}
