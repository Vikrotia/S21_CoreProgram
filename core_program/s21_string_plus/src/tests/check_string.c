#include <check.h>
#include <ctype.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

#define BUFF_SIZE 512

typedef struct test_s {
  uint32_t origO1, mineO1;
  char origC1, mineC1;
  void *origP1;
  void *mineP1;
  int origRes, mineRes;
  int origD1, mineD1;
  int origD2, mineD2;
  short int origSD1, mineSD1;
  long int origLD1, mineLD1;
  long int origLD2, mineLD2;
  float origF1, mineF1;
  float origF2, mineF2;
  float origF3, mineF3;
  float origF4, mineF4;
  float origF5, mineF5;
  long long int origLLD1, mineLLD1;
  char origS1[100], mineS1[100];
  char origC2, mineC2;
  wchar_t origWC1[10], mineWC1[10];
  unsigned int origU1, mineU1;
  unsigned int origU2, mineU2;
  unsigned long int origUL1, mineUL1;
  unsigned long long int origULL1, mineULL1;
  signed char origSC1, mineSC1;
  long double origLF1, mineLF1;
  long double origLF2, mineLF2;
  long double origLF3, mineLF3;
  long double origLF4, mineLF4;
  long double origLF5, mineLF5;
} test;

// tests for memchr
START_TEST(test_s21_memchr_1) {
  char *str = "Mom was washed the dishes";
  char ch = 'a';
  size_t n = 7;
  ck_assert_str_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char *str = "Mom was washed the dishes";
  char ch = 'M';
  size_t n = 1;
  ck_assert_str_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char *str = "Mom was washed the dishes";
  char ch = '\0';
  size_t n = 1000;
  ck_assert_str_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_4) {
  char *str = "Mom was \0washed the dishes";
  char ch = '\0';
  size_t n = 1000;
  ck_assert_str_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_5) {
  char *str = "Mom was \0washed the dishes";
  char ch = 'd';
  size_t n = 1000;
  ck_assert_str_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_6) {
  char *str = "Mom was \0washed the dishes";
  char ch = 'a';
  int n = -3;
  ck_assert_str_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_8) {
  char *str = "Мама мыла раму";
  int ch = '1';
  int n = -3;
  ck_assert_str_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_9) {
  int str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 123, 467, 7};
  int ch = 6;
  int n = 100;
  ck_assert_str_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_0) {
  char *str = "a";
  char ch = 'a';
  int n = 3;
  ck_assert_str_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
}
END_TEST

START_TEST(test_s21_memchr_11) {
  // char *str = malloc(10 * sizeof(char));
  char str[10] = {0};
  for (int i = 0; i < 10; i++) {
    str[i] = 'a' + i;
  }
  char ch = 'c';
  int n = 100;
  ck_assert_str_eq(s21_memchr(str, ch, n), memchr(str, ch, n));
  // free(str);
}
END_TEST

// tests for memcmp
START_TEST(test_s21_memcmp_0) {
  char str1_1[128] = {0};
  for (int i = 0; i < 11; i++) {
    str1_1[i] = 'a' + i;
  }
  char str2_1[128] = {0};
  for (int i = 0; i < 11; i++) {
    str2_1[i] = 'a' + i;
  }
  str1_1[10] = '\0';
  str2_1[10] = '\0';
  size_t n = 33;
  ck_assert_int_eq(s21_memcmp(str1_1, str2_1, n), memcmp(str1_1, str2_1, n));
}
END_TEST

START_TEST(test_s21_memcmp_1) {
  char *str1_2 = malloc(10 * sizeof(char));
  for (int i = 0; i < 10; i++) {
    str1_2[i] = i;
  }
  char *str2_2 = malloc(7 * sizeof(char));
  for (int i = 0; i < 7; i++) {
    str2_2[i] = i;
  }

  size_t n = 7;
  ck_assert_int_eq(s21_memcmp(str1_2, str2_2, n), memcmp(str1_2, str2_2, n));
  free(str1_2);
  free(str2_2);
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char *str1 = "kto-to videl chto-to";
  char *str2 = "ya nichego ne videl";
  size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char *str1 = "ya nichego ne videl";
  char *str2 = "kto-to videl chto-to";
  size_t n = 100;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_4) {
  char *str1 = "poterjali nol'";
  char *strd1_3 = calloc(100000, 1);
  strd1_3 = s21_strcpy(strd1_3, str1);
  strd1_3[s21_strlen(strd1_3)] = ')';
  char *str2 = "poterjali nol'";
  char *strd2_3 = calloc(100000, 1);
  strd2_3 = s21_strcpy(strd2_3, str2);
  strd2_3[s21_strlen(strd2_3)] = ')';
  size_t n = 100;
  ck_assert_int_eq(s21_memcmp(strd1_3, strd2_3, n),
                   memcmp(strd1_3, strd2_3, n));
  free(strd1_3);
  free(strd2_3);
}
END_TEST

START_TEST(test_s21_memcmp_5) {
  char *str1 = "a i b sideli na trube";
  char *str2 = "qwerty";
  size_t n = 100;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcmp_7) {
  char *str1 = "big data KEKW";
  char *strd1_4 = calloc(100000, 1);
  strd1_4 = strcpy(strd1_4, str1);
  char *str2 = "bid data KEKW";
  char *strd2_4 = calloc(10000, 1);
  strd2_4 = strcpy(strd2_4, str2);
  unsigned long long n = 1844674;
  ck_assert_int_eq(s21_memcmp(strd1_4, strd2_4, n),
                   memcmp(strd1_4, strd2_4, n));
  free(strd1_4);
  free(strd2_4);
}
END_TEST

START_TEST(test_s21_memcmp_9) {
  double str1[] = {1000.111111111, 1000.2, 1000.3};
  double str2[] = {1000.111111111, 2000.111111111, 3000};
  unsigned long long n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// tests for memcpy
START_TEST(test_s21_memcpy_0_usage) {
  char str1[] = "black lives matter";
  char str11[] = "black lives matter";
  char str2[] = "every single day";
  size_t n = s21_strlen(str2) - 11;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, n), memcpy(str11, str2, n));
}
END_TEST

START_TEST(test_s21_memcpy_1_usage) {
  char str1[100] = "";
  char str11[100] = "";
  char str2[100] = "hmm";
  size_t n = 10;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, n), memcpy(str11, str2, n));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char str1[100] = "dva";
  char str2[100] = "sorok tri";
  size_t n = strlen(str2) + 10;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, n), memcpy(str1, str2, n));
}
END_TEST

// START_TEST (test_s21_memcpy_3) {
//     char str1[100] = "oticatelnoe n";
//     char str2[100] = "aboba";
//     size_t n = -3;
//     ck_assert_pstr_eq(s21_memcpy(str1,str2,n), memcpy(str1,str2,n));
// }
// END_TEST

// START_TEST (test_s21_memcpy_4) {
//     char *str1 =s21_NULL;
//     char *str2 =s21_NULL;
//     size_t n = 33;
//     ck_assert_pstr_eq(s21_memcpy(str1,str2,n), memcpy(str1,str2,n));
// }
// END_TEST

START_TEST(test_s21_memcpy_5_big_n) {
  char str1[100] = "";
  char str2[100] = "hmm";
  size_t n = 100;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, n), memcpy(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcpy_6_equal_str) {
  char str1[] = "spider-man";
  char *str2 = str1;
  size_t n = 1;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, n), memcpy(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcpy_7_zeroed_n) {
  char str1[] = "spider-man";
  char str2[] = "batman";
  size_t n = 0;
  ck_assert_pstr_eq(s21_memcpy(str1, str2, n), memcpy(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memcpy_8_memory_check) {
  char src[] = "check memory usage";
  s21_size_t bytes = strlen(src) - 1;
  char test[bytes + 8];
  char expected[bytes + 8];
  s21_memcpy(test, src, bytes);
  memcpy(expected, src, bytes);
  ck_assert_mem_eq(test, expected, bytes);
}
END_TEST

START_TEST(test_s21_memcpy_9_memory_check) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

// tests for memmove
START_TEST(test_s21_memmove_0_usage) {
  char str1[] = "black lives matter";
  char str11[] = "black lives matter";
  char str2[] = "every single day";
  size_t n = s21_strlen(str2) - 11;
  ck_assert_pstr_eq(s21_memmove(str1, str2, n), memmove(str11, str2, n));
}
END_TEST

START_TEST(test_s21_memmove_1_usage) {
  char str1[100] = "";
  char str11[100] = "";
  char str2[] = "hmm";
  size_t n = 10;
  ck_assert_pstr_eq(s21_memmove(str1, str2, n), memmove(str11, str2, n));
}
END_TEST

START_TEST(test_s21_memmove_2) {
  char str1[100] = "dva";
  char str2[100] = "sorok tri";
  size_t n = strlen(str2) + 10;
  ck_assert_pstr_eq(s21_memmove(str1, str2, n), memmove(str1, str2, n));
}
END_TEST

// START_TEST (test_s21_memmove_3) {
//     char str1[100] = "oticatelnoe n";
//     char str2[10] = "aboba";
//     size_t n = -3;
//     ck_assert_pstr_eq(s21_memmove(str1,str2,n), memmove(str1,str2,n));
// }
// END_TEST

// START_TEST (test_s21_memmove_4) {
//     char *str1 =s21_NULL;
//     char *str2 =s21_NULL;
//     size_t n = 33;
//     ck_assert_pstr_eq(s21_memmove(str1,str2,n), memmove(str1,str2,n));
// }
// END_TEST

START_TEST(test_s21_memmove_5_big_n) {
  char str1[100] = "";
  char str2[10] = "hmm";
  size_t n = 100;
  ck_assert_pstr_eq(s21_memmove(str1, str2, n), memmove(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memmove_6_equal_str) {
  char str1[] = "spider-man";
  char *str2 = str1;
  size_t n = 1;
  ck_assert_pstr_eq(s21_memmove(str1, str2, n), memmove(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memmove_7_zeroed_n) {
  char str1[] = "spider-man";
  char str2[] = "batman";
  size_t n = 0;
  ck_assert_pstr_eq(s21_memmove(str1, str2, n), memmove(str1, str2, n));
}
END_TEST

START_TEST(test_s21_memmove_8_memory_check) {
  char src[] = "check memory usage";
  s21_size_t bytes = strlen(src) - 1;
  char test[bytes + 8];
  char expected[bytes + 8];
  s21_memmove(test, src, bytes);
  memmove(expected, src, bytes);
  ck_assert_mem_eq(test, expected, bytes);
}
END_TEST

START_TEST(test_s21_memmove_9_memory_check) {
  char src[] = "Aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

// tests for memset
START_TEST(test_s21_memset_0) {
  char str[] = "aboba";
  int c = 77;
  s21_size_t n = 6;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

// START_TEST (test_s21_memset_1) {
//     char str[] = "aboba";
//     int c = 77;
//     s21_size_t n = -1;
//     ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
// }
// END_TEST

START_TEST(test_s21_memset_2) {
  char str[] = "aboba";
  int c = 77;
  s21_size_t n = 3;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

// START_TEST (test_s21_memset_3) {
//     char *str =s21_NULL;
//     int c = 77;
//     s21_size_t n = 1;
//     ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
// }
// END_TEST

// START_TEST (test_s21_memset_4) {
//     char *str =s21_NULL;
//     int c = 77;
//     s21_size_t n = 1;
//     ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
// }
// END_TEST

START_TEST(test_s21_memset_5) {
  char *str = s21_NULL;
  int c = 77;
  s21_size_t n = 0;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

// START_TEST (test_s21_memset_6) {
//     char str[30] = "nu eto ban";
//     int c = 77;
//     s21_size_t n = 40;
//     ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
// }
// END_TEST

START_TEST(test_s21_memset_7) {
  char str[] = "nu eto\0 ban";
  int c = 77;
  s21_size_t n = 10;
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

// START_TEST (test_s21_memset_8) {
//     char* str = malloc(10 * sizeof(char));
//     for (int i =0; i < 10; i++) {
//         str[i] = 'a' + i;
//     }
//     int c = 'c';
//     int n = 100;
//     ck_assert_pstr_eq(memset(str, c, n), s21_memset(str, c, n));
// }
// END_TEST

// tests for strcat
START_TEST(test_s21_strcat_0) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " govnocoder";
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str11, str2));
}
END_TEST

// START_TEST (test_s21_strcat_1) {
//     char str1[100] = "Paramore";
//     char str11[100] = "Paramore";
//     ck_assert_pstr_eq(strcat(str1+2,str1+3), s21_strcat(str11+2, str11+3));
// }
// END_TEST

// START_TEST (test_s21_strcat_2) {
//     char str1[100] = "Chris Torek";
//     char str11[100] ="Chris Torek";
//     ck_assert_pstr_eq(strcat(str1,str1), s21_strcat(str11, str11));
// }
// END_TEST

// START_TEST (test_s21_strcat_3) {
//     char str1[100] = "Chris Torek";
//     char str11[100] ="Chris Torek";
//     ck_assert_pstr_eq(strcat(str1,str1), s21_strcat(str11, str11));
// }
// END_TEST

START_TEST(test_s21_strcat_4) {
  char str1[100] = {0};
  char str11[100] = {0};
  char str2[] = " govnocoder";
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str11, str2));
}
END_TEST

// tests for strncat
START_TEST(test_s21_strncat_0) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " govnocoder";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_1) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " molodec SHUTKA";
  s21_size_t n = 30000;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char str1[100] = "Chris Torek";
  char str11[100] = "Chris Torek";
  char str2[] = " Za rabotoi";
  s21_size_t n = -1;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char str1[100] = "Chris\0 Torek";
  char str11[100] = "Chris\0 Torek";
  char str2[] = " plohoicoder";
  s21_size_t n = 7;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char str1[100] = "Chris\0 Torek";
  char str11[100] = "Chris\0 Torek";
  char str2[] = " plohoi\0coder";
  s21_size_t n = 100;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char str1[100] = "nichego";
  char str11[100] = "nichego";
  char str2[] = "ne proishodit";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(str1, str2, n), s21_strncat(str11, str2, n));
}
END_TEST

// tests for strchr
START_TEST(test_s21_strchr_0) {
  char str1[100] = "Chris Torek";
  int c = 'T';
  ck_assert_pstr_eq(strchr(str1, c), s21_strchr(str1, c));
}
END_TEST

START_TEST(test_s21_strchr_1) {
  char str1[100] = "Chris Torek";
  int c = 700;
  ck_assert_pstr_eq(strchr(str1, c), s21_strchr(str1, c));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char str1[100] = "Chris \0Torek";
  int c = 'T';
  ck_assert_pstr_eq(strchr(str1, c), s21_strchr(str1, c));
}
END_TEST

// tests for strcmp
START_TEST(test_s21_strcmp_0) {
  char str1[100] = "Chris Torek";
  char str2[100] = "programmist";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// START_TEST (test_s21_strcmp_1) {
//     char str1[100] = "Chris Torek";
//     char c = 'C';
//     char b = 'C';
//     ck_assert_int_eq(s21_strcmp(str1, &c), strcmp(str1, &b));
//     ck_assert_str_eq()
// }
// END_TEST

START_TEST(test_s21_strcmp_2) {
  char str1[100] = "Chris\0 Torek";
  char str2[100] = "Chris";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(test_s21_strcmp_3) {
  char str1[100] = "\0Chris Torek";
  char str2[100] = "\0Chris";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// tests for strncmp
START_TEST(test_s21_strncmp_0) {
  char *str1 = "Mom was washed the dishes";
  char *str2 = "Mom was";
  size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// START_TEST (test_s21_strncmp_1) {
//     char *str1 =s21_NULL;
//     char str2[100] = "Chris";
//     ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
// }
// END_TEST

START_TEST(test_s21_strncmp_2) {
  char *str1 = "Lora Palmer";
  char str2[100] = "Lora Aboba";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// tests for strcpy
START_TEST(test_s21_strcpy_0) {
  char str1[10] = "a";
  char str11[10] = "a";
  char *str2 = "baobab";
  ck_assert_pstr_eq(s21_strcpy(str1, str2), strcpy(str11, str2));
}
END_TEST

START_TEST(test_s21_strcpy_1) {
  char str1[100] = "zaciklivanie";
  char str11[100] = "zaciklivanie";
  char *str2 = "zip-zap";
  ck_assert_pstr_eq(s21_strcpy(str1, str2), strcpy(str11, str2));
}
END_TEST

// START_TEST (test_s21_strcpy_1_1) {
//     char str1[100] = "zaciklivanie";
//     char str11[100] = "zaciklivanie";
//     char* str2 = "zip-zap";
//     s21_strcpy(str1, str2);
//     strcpy(str11, str2);
//     str1[strlen(str1)] = 'a';
//     str1[strlen(str11)] = 'a';
//     ck_assert_pstr_eq(str1, str11);
// }
// END_TEST

START_TEST(test_s21_strcpy_2) {
  char str1[100] = "\0";
  char str11[100] = "\0";
  char *str2 = "abordazhnii kruk";
  ck_assert_pstr_eq(s21_strcpy(str1, str2), strcpy(str11, str2));
}
END_TEST

// START_TEST (test_s21_strcpy_3) {
//     char *str1 = s21_NULL;
//     char *str11 = s21_NULL;
//     char* str2 = "Seg_NULL";
//     ck_assert_pstr_eq(s21_strcpy(str1, str2), strcpy(str11, str2));
// }
// END_TEST

START_TEST(test_s21_strcpy_4) {
  char str1[100] = "determinator";
  char str11[100] = "determinator";
  char *str2 = "\0\0\0";
  ck_assert_pstr_eq(s21_strcpy(str1, str2), strcpy(str11, str2));
}
END_TEST

START_TEST(test_s21_strcpy_5) {
  char str1[100] = "sdvigaem ukazatel";
  char str11[100] = "sdvigaem ukazatel";
  char *str2 = "kolobok povesilsya";
  ck_assert_pstr_eq(s21_strcpy(str1 + 9, str2 + 2),
                    strcpy(str11 + 9, str2 + 2));
}
END_TEST

// tests for strncpy
START_TEST(test_s21_strncpy_0) {
  char str1[100] = "Yasos biby";
  char str11[100] = "Yasos biby";
  char str2[100] = "boba i";
  s21_size_t n = 99;
  ck_assert_pstr_eq(s21_strncpy(str1, str2, n), strncpy(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncpy_1) {
  char str1[100] = "skazhi ka dyadya ved' ne darom";
  char str11[100] = "skazhi ka dyadya ved' ne darom";
  char str2[100] = "aboba";
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_strncpy(str1, str2, n), strncpy(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char str1[100] = "skazhi ka dyadya ved' ne darom";
  char str11[100] = "skazhi ka dyadya ved' ne darom";
  char str2[100] = "a\0boba";
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_strncpy(str1, str2, n), strncpy(str11, str2, n));
}
END_TEST

START_TEST(test_s21_strncpy_2_1) {
  char str1[100] = "skazhi ka dyadya ved' ne darom";
  char str11[100] = "skazhi ka dyadya ved' ne darom";
  ck_assert_pstr_eq(str1 + 3, str11 + 3);
}
END_TEST

START_TEST(test_s21_strncpy_2_2) {
  char str1[100] = "skazhi ka dyadya ved' ne darom";
  char str11[100] = "skazhi ka dyadya ved' ne darom";
  ck_assert_pstr_eq(str1 + 5, str11 + 5);
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char str1[100] = "skazhi ka dyadya ved' ne darom";
  char str11[100] = "skazhi ka dyadya ved' ne darom";
  char str2[100] = "aboba";
  s21_size_t n = 2;
  ck_assert_pstr_eq(s21_strncpy(str1, str2, n), strncpy(str11, str2, n));
}
END_TEST

// tests for strcspn
START_TEST(test_s21_strcspn_0) {
  char *str1 = "tatarstan super gud";
  char *str11 = "tatarstan super gud";
  char str2[100] = "zxc";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str11, str2));
}
END_TEST

START_TEST(test_s21_strcspn_1) {
  char *str1 = "kva";
  char *str11 = "kva";
  char str2[100] = "\0";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str11, str2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char *str1 = "kva";
  char *str11 = "kva";
  char str2[100] = "frog sing rock";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str11, str2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char *str1 = "\0 ne problema";
  char *str11 = "\0 ne problema";
  char str2[100] = "ne";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str11, str2));
}
END_TEST

// tests for strlen
START_TEST(test_s21_strlen_0) {
  char *str1 = "\0 ne problema";
  char *str11 = "\0 ne problema";
  ck_assert_int_eq(strlen(str1), s21_strlen(str11));
}
END_TEST

START_TEST(test_s21_strlen_1) {
  char *str1 = "dve abobi po utru ne mogli naiti biby";
  char *str11 = "dve abobi po utru ne mogli naiti biby";
  ck_assert_int_eq(strlen(str1), s21_strlen(str11));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char *str1 = "dve abobi po utru ne\0 mogli naiti biby";
  char *str11 = "dve abobi po utru ne\0 mogli naiti biby";
  ck_assert_int_eq(strlen(str1), s21_strlen(str11));
}
END_TEST

// START_TEST (test_s21_strlen_3) {
//     char *str1 = s21_NULL;
//     char *str11 = s21_NULL;
//     ck_assert_int_eq(strlen(str1), s21_strlen(str11));
// }
// END_TEST

START_TEST(test_s21_strlen_4) {
  char str1[100] = "eul + ult";
  char str11[100] = "eul + ult";
  ck_assert_int_eq(strlen(str1), s21_strlen(str11));
}
END_TEST

// tests for strpbrk
START_TEST(test_s21_strpbrk_0) {
  char str1[100] = "a u nas v kvartire Jazz";
  char str11[100] = "a u nas v kvartire Jazz";
  char str2[100] = "a u nas kal'yanii rep kek";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str11, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_1) {
  char str1[100] = "NO PAIN no gain";
  char str11[100] = "NO PAIN no gain";
  char str2[100] = " ";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str11, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str1[100] = "NO PAIN no gain";
  char str11[100] = "NO PAIN no gain";
  char *str2 = "\0Dream on";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str11, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str1[100] = "net takih simvolov";
  char str11[100] = "net takih simvolov";
  char *str2 = "A_YA_NAIDU";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str11, str2));
}
END_TEST

// tests for strrchr
START_TEST(test_s21_strrchr_0) {
  char *str1 = "Zavod stoit";
  char *str11 = "Zavod stoit";
  int c = 'Z';
  ck_assert_pstr_eq(strrchr(str1, c), s21_strrchr(str11, c));
}
END_TEST

START_TEST(test_s21_strrchr_1) {
  char *str1 = "Zavod stoit";
  char *str11 = "Zavod stoit";
  int c = 'v';
  ck_assert_pstr_eq(strrchr(str1, c), s21_strrchr(str11, c));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char *str1 = "Zavod stoit";
  char *str11 = "Zavod stoit";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(str1, c), s21_strrchr(str11, c));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char *str1 = "Zavod\0 stoit";
  char *str11 = "Zavod\0 stoit";
  int c = '\0';
  ck_assert_pstr_eq(strrchr(str1, c), s21_strrchr(str11, c));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char *str1 = "klara u karli ukrala korali";
  char *str11 = "klara u karli ukrala korali";
  int c = 'k';
  ck_assert_pstr_eq(strrchr(str1, c), s21_strrchr(str11, c));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char *str1 = "net takogo simvola";
  char *str11 = "net takogo simvola";
  int c = 'Z';
  ck_assert_pstr_eq(strrchr(str1, c), s21_strrchr(str11, c));
}
END_TEST

// tests for strspn
START_TEST(test_s21_strspn_0) {
  char *str1 = "kot po imeni gav";
  char *str11 = "kot po imeni gav";
  char *str2 = "po";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str11, str2));
}
END_TEST

START_TEST(test_s21_strspn_1) {
  char *str1 = "kot po imeni gav";
  char *str11 = "kot po imeni gav";
  char *str2 = "kot";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str11, str2));
}
END_TEST

START_TEST(test_s21_strspn_2) {
  char *str1 = "\0kot po imeni gav";
  char *str11 = "\0kot po imeni gav";
  char *str2 = "\0kot";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str11, str2));
}
END_TEST

START_TEST(test_s21_strspn_3) {
  char *str1 = "kot po imeni gav";
  char *str11 = "kot po imeni gav";
  char *str2 = "kot po imeni gav\0sorrow";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str11, str2));
}
END_TEST

// tests for strstr
START_TEST(test_s21_strstr_0) {
  char *str1 = "stroka v stroke";
  char *str11 = "stroka v stroke";
  char *str2 = "v str";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str11, str2));
}
END_TEST

START_TEST(test_s21_strstr_1) {
  char *str1 = "stroka v stroke";
  char *str11 = "stroka v stroke";
  char *str2 = "str\0";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str11, str2));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char *str1 = "stroka v stroke";
  char *str11 = "stroka v stroke";
  char *str2 = "str\0ing";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str11, str2));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char *str1 = "strok\0a v stroke";
  char *str11 = "strok\0a v stroke";
  char *str2 = "v s";
  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str11, str2));
}
END_TEST

// tests for strtok
START_TEST(test_s21_strtok_0) {
  char str1[100] = "dva+odin+tri+sem'";
  char str11[100] = "dva+odin+tri+sem'";
  char *str2 = "+";
  char *tok = s21_NULL;
  char *tokO = s21_NULL;
  tok = s21_strtok(str1, str2);
  tokO = strtok(str11, str2);
  while (tok != s21_NULL) {
    ck_assert_pstr_eq(tok, tokO);
    tok = strtok(s21_NULL, str2);
    tokO = s21_strtok(s21_NULL, str2);
  }
}
END_TEST

START_TEST(test_s21_strtok_1) {
  char str1[100] = "kak don vi don menya don nashli don ";
  char str11[100] = "kak don vi don menya don nashli don ";
  char *str2 = "don";
  char *tok;
  char *tokO;
  tok = s21_strtok(str1, str2);
  tokO = strtok(str11, str2);
  while (tok != s21_NULL) {
    ck_assert_pstr_eq(tok, tokO);
    tok = strtok(s21_NULL, str2);
    tokO = s21_strtok(s21_NULL, str2);
  }
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str1[100] = "kak\0 don\0 vi \0don men\0ya don n\0ashli don ";
  char str11[100] = "kak\0 don\0 vi \0don men\0ya don n\0ashli don ";
  char *str2 = "\0";
  char *tok;
  char *tokO;
  tok = s21_strtok(str1, str2);
  tokO = strtok(str11, str2);
  while (tok != s21_NULL) {
    ck_assert_pstr_eq(tok, tokO);
    tok = strtok(s21_NULL, str2);
    tokO = s21_strtok(s21_NULL, str2);
  }
}
END_TEST

// tests for strerror
START_TEST(test_s21_strerror_0) {
  int err_num = 7;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST
START_TEST(test_s21_strerror_1) {
  int err_num = 134;
  ck_assert_pstr_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

// TESTS FOR BONUS FUNCTIONS
// tests for to_upper
START_TEST(test_s21_to_upper_0) {
  char str1[] = "The quick brown fox jumps over the lazy dog.";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_upper_1) {
  char str1[] = "The quick brown fox jumps\0 over the lazy dog.";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "THE QUICK BROWN FOX JUMPS");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  char str1[] = "";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  char str1[] = "A8B8I75du3A12B3Uda";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "A8B8I75DU3A12B3UDA");
  free(str2);
}
END_TEST

// START_TEST(test_s21_to_upper_4) {
//   char *str1 = s21_NULL;
//   char *str2 = (char *)s21_to_upper(str1);
//   ck_assert_pstr_eq(str2, s21_NULL);
//   if (str2) free(str2);
// }
// END_TEST

// tests for to_lower
START_TEST(test_s21_to_lower_0) {
  char str1[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "the quick brown fox jumps over the lazy dog.");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_1) {
  char str1[] = "THE QUICK BROWN FOX JUMPS\0 OVER THE LAZY DOG.";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "the quick brown fox jumps");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char str1[] = "";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  char str1[] = "A8B8I75du3A12B3Uda";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "a8b8i75du3a12b3uda");
  free(str2);
}
END_TEST

// START_TEST(test_s21_to_lower_4) {
//   char *str1 = s21_NULL;
//   char *str2 = (char *)s21_to_lower(str1);
//   ck_assert_pstr_eq(str2, s21_NULL);
//   if (str2) free(str2);
// }
// END_TEST

// tests f0r insert
START_TEST(test_s21_insert_0) {
  char str1[] = "gde";
  char str2[] = "zdec";
  char *str3 = (char *)s21_insert(str1, str2, 2);
  ck_assert_pstr_eq(str3, "gdzdece");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_insert_1) {
  char str1[] = "gde";
  char str2[] = "zdec";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_pstr_eq(str3, "zdecgde");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char str1[] = "gde";
  char str2[] = "zdec";
  char *str3 = (char *)s21_insert(str1, str2, 5);
  ck_assert_pstr_eq(str3, s21_NULL);
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_insert_3) {
  char str1[] = "gdeto dal\0eko";
  char str2[] = "ec";
  char *str3 = (char *)s21_insert(str1, str2, 9);
  ck_assert_pstr_eq(str3, "gdeto dalec");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char str1[] = "gdeto daleko";
  char str2[] = "12345EKI BEGI";
  char *str3 = (char *)s21_insert(str1 + 2, str2 + 5, 7);
  ck_assert_pstr_eq(str3, "eto dalEKI BEGIeko");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char *str1 = s21_NULL;
  char str2[] = "12345EKI BEGI";
  char *str3 = (char *)s21_insert(str1, str2 + 5, 7);
  ck_assert_pstr_eq(str3, s21_NULL);
  if (str3) free(str3);
}
END_TEST

// tests for trim
START_TEST(test_s21_trim_0) {
  char str1[] = "che real'no vse udalish";
  char str2[] = "chso";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_pstr_eq(str3, "e real'no vse udali");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_trim_1) {
  char str1[] = "AAA tak ti tollkoo po krajam udalyaesh";
  char str2[] = "abobA shlepa";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_pstr_eq(str3, "tak ti tollkoo po krajam udaly");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_trim_2) {
  char str1[] = "\0AAA tak ti tollkoo po krajam udalyaesh";
  char str2[] = "abob\0";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_pstr_eq(str3, "");
  if (str3) free(str3);
}
END_TEST

START_TEST(test_s21_trim_3) {
  char *str1 = s21_NULL;
  char str2[] = "abob\0";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_pstr_eq(str3, s21_NULL);
  if (str3) free(str3);
}
END_TEST

// TESTING SSCANF__________________
// flag_c i vse vse vse
START_TEST(test_s21_sscanf_c_0) {
  char *str = "pomogite";
  char c;
  char cc;
  char *format = "pomo%c";

  sscanf(str, format, &c, &c, &c);
  s21_sscanf(str, format, &cc, &cc, &cc);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_1) {
  char *str = "\0\0pomogite";
  char c = ' ';
  char cc = ' ';
  char *format = "\0%c\0";

  sscanf(str, format, &c, &c, &c);
  s21_sscanf(str, format, &cc, &cc, &cc);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_flazhki_2) {
  char *str = "lzhe flag I";
  char c;
  char cc;
  char *format = "%k";
  int er, ero;
  ero = sscanf(str, format, &c, &c, &c);
  er = s21_sscanf(str, format, &cc, &cc, &cc);
  ck_assert_int_eq(ero, er);
}
END_TEST

START_TEST(test_s21_sscanf_flazhki_3) {
  char *str = "123 lzhe flag I i ego prespeshniki";
  char c;
  char cc;
  char *format = "%z%d";
  int er, ero;
  ero = sscanf(str, format, &c, &c, &c);
  er = s21_sscanf(str, format, &cc, &cc, &cc);
  ck_assert_int_eq(ero, er);
}
END_TEST

START_TEST(test_s21_sscanf_c_4) {
  char *str = "9337ciforki i chisla";
  char c;
  int v;
  char cc;
  int vv;
  char *format = "%c%d%c";
  int er;
  int ero;
  ero = sscanf(str, format, &c, &v, &c);
  er = s21_sscanf(str, format, &cc, &vv, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
  ck_assert_int_eq(v, vv);
}
END_TEST

START_TEST(test_s21_sscanf_c_5) {
  char *str = "a93\037ciforki i chisla";
  char c;
  int v;
  char cc;
  int vv;
  char *format = "%c%d";
  int er;
  int ero;
  ero = sscanf(str, format, &c, &v, &c);
  er = s21_sscanf(str, format, &cc, &vv, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
  ck_assert_int_eq(v, vv);
}
END_TEST

START_TEST(test_s21_sscanf_c_6) {
  char *str = "chto-to bespoleznoe";
  char c;
  int v = -1;
  char cc;
  int vv = -1;
  char *format = "%ca%";
  int er;
  int ero;
  ero = sscanf(str, format, &c, &v);
  er = s21_sscanf(str, format, &cc, &vv);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
  ck_assert_int_eq(v, vv);
}
END_TEST

START_TEST(test_s21_sscanf_flag_AFG_7) {
  char *str = "zdes bil kornelius";
  char cc;
  char *format = "%c%c%c%c%c%c%abobac%c%c%c%c%c%c%c";
  int er;
  char c;
  int ero;
  ero = sscanf(str, format, &c, &c, &c, &c, &c, &c, &c, &c, &c, &c, &c, &c, &c,
               &c, &c, &c, &c, &c, &c, &c);
  er = s21_sscanf(str, format, &cc, &cc, &cc, &cc, &cc, &cc, &cc, &cc, &cc, &cc,
                  &cc, &cc, &cc, &cc, &cc, &cc, &cc, &cc, &cc, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_razzzzzdelitel_8) {
  char *str = "zdes bil kornelius";
  char cc;
  char *format = "%czzzzz%c";
  int er;
  char c;
  int ero;
  ero = sscanf(str, format, &c, &c);
  er = s21_sscanf(str, format, &cc, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_razdelitel_9) {
  char *str = "zdes bil kornelius";
  char cc;
  char *format = "%cdes bi%c";
  int er;
  char c;
  int ero;
  ero = sscanf(str, format, &c, &c);
  er = s21_sscanf(str, format, &cc, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_razdelitel_10) {
  char *str = "zdes bil kornelius";
  char cc;
  char *format = "\t\n%c";
  int er;
  char c;
  int ero;
  ero = sscanf(str, format, &c);
  er = s21_sscanf(str, format, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_razdelitel_11) {
  char *str = " \t  \n  zdes bil kornelius";
  char cc;
  char *format = " z%c";
  int er;
  char c;
  int ero;
  ero = sscanf(str, format, &c);
  er = s21_sscanf(str, format, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_razdelitel_12) {
  char *str = " \t  \n  zdes bil kornelius";
  char cc = ' ';
  char *format = " hopa%c";
  int er = 0;
  char c = ' ';
  int ero = 0;
  ero = sscanf(str, format, &c);
  er = s21_sscanf(str, format, &cc);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(c, cc);
}
END_TEST

START_TEST(test_s21_sscanf_c_razdelitel_13) {
  test t = {0};
  char *str = "hochy v rec";
  char *format = " %c%s";
  char resOrig1[100];
  char resMine1[100];
  t.origRes = sscanf(str, format, &t.origC1, resOrig1);
  t.mineRes = s21_sscanf(str, format, &t.mineC1, resMine1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origC1, t.mineC1);
}
END_TEST

START_TEST(test_s21_sscanf_c_razdelitel_14) {
  test t = {0};
  char *str = " hochy v rec";
  char *format = " %c%s";
  char resOrig1[100];
  char resMine1[100];
  t.origRes = sscanf(str, format, &t.origC1, resOrig1);
  t.mineRes = s21_sscanf(str, format, &t.mineC1, resMine1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origC1, t.mineC1);
}
END_TEST

// flag d
//  START_TEST(test_s21_sscanf_d_0) {
//      char *str = "0333";
//      unsigned int vv;
//      char* format = "%d";
//      int er;
//      unsigned int v;
//      int ero;
//      ero = sscanf(str, format, &v);
//      er = s21_sscanf(str, format, &vv);
//    ck_assert_int_eq(ero, er);
//    ck_assert_int_eq(v, vv);
//  }
//  END_TEST

START_TEST(test_s21_sscanf_d_1) {
  char *str = "0x333";
  unsigned int vv;
  char *format = "%d";
  int er;
  unsigned int v;
  int ero;
  ero = sscanf(str, format, &v);
  er = s21_sscanf(str, format, &vv);
  ck_assert_int_eq(ero, er);
  ck_assert_int_eq(v, vv);
}
END_TEST

START_TEST(test_s21_sscanf_d_2) {
  char *str = "0x333";
  unsigned int vv;
  char *format = "%d";
  int er;
  unsigned int v;
  int ero;
  char c;
  ero = sscanf(str, format, &c, &c, &v);
  er = s21_sscanf(str, format, &c, &c, &vv);
  ck_assert_int_eq(ero, er);
}
END_TEST

START_TEST(test_s21_sscanf_d_3) {
  test t = {0};
  char *str = "334";
  char *format = "%d";
  t.origRes = sscanf(str, format, &t.origC1, &t.origC2, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineC1, &t.mineC2, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origC1, t.mineC1);
}
END_TEST

START_TEST(test_s21_sscanf_d_4) {
  test t = {0};
  char *str = "334zx444";
  char *format = "%dzz%d";
  t.origRes = sscanf(str, format, &t.origD1, &t.origD2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, &t.mineD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
}
END_TEST

START_TEST(test_s21_sscanf_d_5) {
  test t = {0};
  char *str = "fff";
  char *format = "%d";
  t.origRes = sscanf(str, format, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
}
END_TEST

START_TEST(test_s21_sscanf_d_6) {
  test t = {0};
  char *str = "123 3211 \n231 \t321 12 3213213213213213";
  char *format = "%d%d%d%d%d %d";
  t.origRes = sscanf(str, format, &t.origD1, &t.origD1, &t.origD1, &t.origD1,
                     &t.origD1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, &t.mineD1, &t.mineD1,
                         &t.mineD1, &t.mineD1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
}
END_TEST

START_TEST(test_s21_sscanf_d_7) {
  test t = {0};
  char *str = "1234563123";
  char *format = "%5d";
  t.origRes = sscanf(str, format, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
}
END_TEST

START_TEST(test_s21_sscanf_d_8) {
  test t = {0};
  char *str = "1234563123";
  char *format = "%5d%*2d%d";
  t.origRes = sscanf(str, format, &t.origD1, &t.origD2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, &t.mineD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
  ck_assert_int_eq(t.origD2, t.mineD2);
}
END_TEST

START_TEST(test_s21_sscanf_d_9) {
  test t = {0};
  char *str = "123456-3123";
  char *format = "%6hd%*2d%d";
  t.origRes = sscanf(str, format, &t.origD1, &t.origD2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, &t.mineD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
  ck_assert_int_eq(t.origD2, t.mineD2);
}
END_TEST

START_TEST(test_s21_sscanf_d_10) {
  test t = {0};
  char *str = "123456-3123";
  char *format = "%6hd%*1d%d";
  t.origRes = sscanf(str, format, &t.origD1, &t.origD2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, &t.mineD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
  ck_assert_int_eq(t.origD2, t.mineD2);
}
END_TEST

START_TEST(test_s21_sscanf_d_11) {
  test t = {0};
  char *str = "1234563123";
  char *format = "%-5d%*2d%d";
  t.origRes = sscanf(str, format, &t.origD1, &t.origD2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, &t.mineD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origD1, t.mineD1);
  ck_assert_int_eq(t.origD2, t.mineD2);
}
END_TEST

START_TEST(test_s21_sscanf_d_12) {
  test t = {0};
  char *str = "3333333333";
  char *format = "%ld";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_d_13) {
  test t = {0};
  char *str = "33333333 33";
  char *format = "%lld %hhd";
  t.origRes = sscanf(str, format, &t.origLD1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
  ck_assert_int_eq(t.origD1, t.mineD1);
}
END_TEST

// tests flag i
START_TEST(test_s21_sscanf_i_0) {
  test t = {0};
  char *str = "033333";
  char *format = "%i";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_1) {
  test t = {0};
  char *str = "0xFF";
  char *format = "%i";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_2) {
  test t = {0};
  char *str = "0xFF0xAC";
  char *format = "%i%i";
  t.origRes = sscanf(str, format, &t.origLD1, &t.origLD2);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1, &t.mineLD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
  ck_assert_int_eq(t.origLD2, t.mineLD2);
}
END_TEST

START_TEST(test_s21_sscanf_i_3) {
  test t = {0};
  char *str = "0xFF0xAC";
  char *format = "%4i%i";
  t.origRes = sscanf(str, format, &t.origLD1, &t.origLD2);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1, &t.mineLD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
  ck_assert_int_eq(t.origLD2, t.mineLD2);
}
END_TEST

START_TEST(test_s21_sscanf_i_4) {
  test t = {0};
  char *str = "0xFF-0xAC";
  char *format = "%i-%i";
  t.origRes = sscanf(str, format, &t.origLD1, &t.origLD2);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1, &t.mineLD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
  ck_assert_int_eq(t.origLD2, t.mineLD2);
}
END_TEST

START_TEST(test_s21_sscanf_i_5) {
  test t = {0};
  char *str = "-0xAC";
  char *format = "%i";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_6) {
  test t = {0};
  char *str = "-0xAC 312";
  char *format = "%4i%d";
  t.origRes = sscanf(str, format, &t.origLD1, &t.origLD2);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1, &t.mineLD2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
  ck_assert_int_eq(t.origLD2, t.mineLD2);
}
END_TEST

START_TEST(test_s21_sscanf_i_7) {
  test t = {0};
  char *str = "-0xLC 312";
  char *format = "%5li";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_8) {
  test t = {0};
  char *str = "-0xfC 312";
  char *format = "%li";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_9) {
  test t = {0};
  char *str = "fC";
  char *format = "%li";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_10) {
  test t = {0};
  char *str = "+0xfC 312";
  char *format = "%li";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_11) {
  test t = {0};
  char *str = "-fC 312";
  char *format = "%li";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

START_TEST(test_s21_sscanf_i_12) {
  test t = {0};
  char *str = "-";
  char *format = "%i";
  t.origRes = sscanf(str, format, &t.origLD1);
  t.mineRes = s21_sscanf(str, format, &t.mineLD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.origLD1, t.mineLD1);
}
END_TEST

// tests for flags_eEfgG
START_TEST(test_s21_sscanf_eEfgG_0) {
  test t = {0};
  char *str = "infinity iNFInity inFInity infinITy iNfinity";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_1) {
  test t = {0};
  char *str = "33 33 33 33 33";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_2) {
  test t = {0};
  char *str = "0k33 0k33 0k33 0k33 0k33";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_3) {
  test t = {0};
  char *str = "033 033 033 033 033";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_4) {
  test t = {0};
  char *str =
      "13.123456789 13.123456789 13.123456789 13.123456789 13.123456789";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_5) {
  test t = {0};
  char *str = "inF InF inF INF inf";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_6) {
  test t = {0};
  char *str = "Nan NAN 0.0000 0 NaN";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_float_nan(t.origF1);
  ck_assert_float_nan(t.mineF1);
  ck_assert_float_nan(t.origF2);
  ck_assert_float_nan(t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_float_nan(t.origF5);
  ck_assert_float_nan(t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_7) {
  test t = {0};
  char *str = "inF InF inF INF inf";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_8) {
  test t = {0};
  char *str = ".333434 .333434 .333434 .333434 .333434";
  char *format = "%Le%LE%Lf%lg%lG";
  t.origRes = sscanf(str, format, &t.origLF1, &t.origLF2, &t.origLF3,
                     &t.origLF4, &t.origLF5);
  t.mineRes = s21_sscanf(str, format, &t.mineLF1, &t.mineLF2, &t.mineLF3,
                         &t.mineLF4, &t.mineLF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_ldouble_eq_tol(t.origLF1, t.mineLF1, 0.000001);
  ck_assert_ldouble_eq_tol(t.origLF2, t.mineLF2, 0.000001);
  ck_assert_ldouble_eq_tol(t.origLF3, t.mineLF3, 0.000001);
  ck_assert_double_eq_tol(t.origLF4, t.mineLF4, 0.000001);
  ck_assert_double_eq_tol(t.origLF5, t.mineLF5, 0.000001);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_9) {
  test t = {0};
  char *str = "1.4441 1.31e+4 -3.31e-4 0.444e-5 0,31E-7";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  ck_assert_double_eq(t.origF4, t.mineF4);
  ck_assert_double_eq(t.origF5, t.mineF5);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_10) {
  test t = {0};
  char *str = "1.4441-1.31E+4--3.31E-4-0.444e-5-0,31E-7";
  char *format = "%e-%E-%f-%g-%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_11) {
  test t = {0};
  char *str = ". . . . .";
  char *format = "%e%E%f%g%G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_12) {
  test t = {0};
  char *str = "1.4441 1.31e+4 -3.31e-4 0.444e-5 0,31E-7";
  char *format = "%4e%4E%4f%4g%4G";
  t.origRes = sscanf(str, format, &t.origF1, &t.origF2, &t.origF3, &t.origF4,
                     &t.origF5);
  t.mineRes = s21_sscanf(str, format, &t.mineF1, &t.mineF2, &t.mineF3,
                         &t.mineF4, &t.mineF5);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_double_eq(t.origF2, t.mineF2);
  ck_assert_double_eq(t.origF3, t.mineF3);
  // ck_assert_double_eq(t.origF4, t.mineF4);
  // ck_assert_double_eq(t.origF5, t.mineF5);
  // ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_13) {
  test t = {0};
  char *str = "1.4441";
  char *format = "%0e";
  t.origRes = sscanf(str, format, &t.origF1);
  t.mineRes = s21_sscanf(str, format, &t.mineF1);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_14) {
  test t = {0};
  char *str = "11ee";
  char *format = "%e";
  t.origRes = sscanf(str, format, &t.origF1);
  t.mineRes = s21_sscanf(str, format, &t.mineF1);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_eEfgG_15) {
  test t = {0};
  char *str = "11..231";
  char *format = "%e";
  t.origRes = sscanf(str, format, &t.origF1);
  t.mineRes = s21_sscanf(str, format, &t.mineF1);
  ck_assert_double_eq(t.origF1, t.mineF1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

// tests for flag_o
START_TEST(test_s21_sscanf_o_0) {
  test t = {0};
  char *str = "77";
  char *format = "%o";
  t.origRes = sscanf(str, format, &t.origU1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
}
END_TEST

START_TEST(test_s21_sscanf_o_1) {
  test t = {0};
  char *str = "077 0373";
  char *format = "%o%o";
  t.origRes = sscanf(str, format, &t.origU1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

START_TEST(test_s21_sscanf_o_2) {
  test t = {0};
  char *str = "0X 0373";
  char *format = "%o%o";
  t.origRes = sscanf(str, format, &t.origU1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_o_3) {
  test t = {0};
  char *str = "0343";
  char *format = "%2o%o";
  t.origRes = sscanf(str, format, &t.origU1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

START_TEST(test_s21_sscanf_o_4) {
  test t = {0};
  char *str = "0343a";
  char *format = "%o%c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

// tests for %
START_TEST(test_s21_sscanf_o_5) {
  test t = {0};
  char *str = "034%3a";
  char *format = "%o%%%c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

START_TEST(test_s21_sscanf_o_procent_6) {
  test t = {0};
  char *str = "034kkk%3a";
  char *format = "%d %% %c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineC1, t.origC1);
}
END_TEST

START_TEST(test_s21_sscanf_o_7) {
  test t = {0};
  char *str = "-034%3a";
  char *format = "%o%%%c";
  t.origRes = sscanf(str, format, &t.origU1, &t.origC1);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineC1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineD1, t.origD1);
}
END_TEST

// tests for flags_xX
START_TEST(test_s21_sscanf_xX_0) {
  test t = {0};
  char *str = "aAf FfA";
  char *format = "%x %X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_1) {
  test t = {0};
  char *str = "-aAf FfA";
  char *format = "%x %X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_2) {
  test t = {0};
  char *str = "-0xaAf 0xFfA";
  char *format = "%x %X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_3) {
  test t = {0};
  char *str = "-0xaAf dfscx 0xFfA";
  char *format = "%x %X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_4) {
  test t = {0};
  char *str = "-0xaAf dfscx- 0xFfA";
  char *format = "%x kkkk%X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_5) {
  test t = {0};
  char *str = "0xZZZ ZZ";
  char *format = "%x %X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_6) {
  test t = {0};
  char *str = "0x34\t\t 1";
  char *format = "%x%X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_7) {
  test t = {0};
  char *str = "abcdef";
  char *format = "%4x%X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

START_TEST(test_s21_sscanf_xX_8) {
  test t = {0};
  char *str = "-ABCdef";
  char *format = "%4x%X";
  t.origRes = sscanf(str, format, &t.origU1, &t.origU2);
  t.mineRes = s21_sscanf(str, format, &t.mineU1, &t.mineU2);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

// tests for flag_p
START_TEST(test_s21_sscanf_p_0) {
  test t = {0};
  char *str = "0xFFFF";
  char *format = "%p%p";
  t.origRes = sscanf(str, format, &t.origP1);
  t.mineRes = s21_sscanf(str, format, &t.mineP1);
  ck_assert_int_eq(t.mineRes, t.origRes);
  ck_assert_int_eq(t.mineU1, t.origU1);
  ck_assert_int_eq(t.mineU2, t.origU2);
}
END_TEST

// tests for flag_s
START_TEST(test_s21_sscanf_s_0) {
  test t = {0};
  char *str = "probel space";
  char *format = "%s%s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_1) {
  test t = {0};
  char *str = "probel %space";
  char *format = "%s%%%s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_2) {
  test t = {0};
  char *str = "kak-dva palca";
  char *format = "%s-%s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_3) {
  test t = {0};
  char *str = "kak-dva \t\tpalca";
  char *format = "%s %s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_4) {
  test t = {0};
  char *str = "213kak-dva \t\tpalca";
  char *format = "%d %s %s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, &t.origD1, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineD1, t.origD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_5) {
  test t = {0};
  char *str = "0x213kak-dva \t\tpalca";
  char *format = "%d %s %s";
  char resOrig1[100];
  char resOrig2[100];
  char resMine1[100];
  char resMine2[100];
  t.origRes = sscanf(str, format, &t.origD1, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineD1, t.origD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_6) {
  test t = {0};
  char *str = "0x213kak-dva \t\tpalca";
  char *format = "%i %s %s";
  char resOrig1[100] = {0};
  char resOrig2[100] = {0};
  char resMine1[100] = {0};
  char resMine2[100] = {0};
  t.origRes = sscanf(str, format, &t.origD1, resOrig1, resOrig2);
  t.mineRes = s21_sscanf(str, format, &t.mineD1, resMine1, resMine2);
  ck_assert_str_eq(resOrig1, resMine1);
  ck_assert_str_eq(resOrig2, resMine2);
  ck_assert_int_eq(t.mineD1, t.origD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_s_7) {
  test t = {0};
  char *str = "ya_nichego_ne_zapishu_hi_hi";
  char *format = "%*s";
  char origS[100] = {0};
  char mineS[100] = {0};
  t.origRes = sscanf(str, format, origS);
  t.mineRes = s21_sscanf(str, format, mineS);
  ck_assert_str_eq(origS, mineS);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

// test for flag_n
START_TEST(test_s21_sscanf_n_0) {
  test t = {0};
  char *str = " hochy v rec";
  char *format = "%s%n";
  char resOrig1[100] = {0};
  char resMine1[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, resMine1, &t.mineD1);
  ck_assert_int_eq(t.mineD1, t.origD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

START_TEST(test_s21_sscanf_n_1) {
  test t = {0};
  char *str = " hochy      ";
  char *format = "%s %n";
  char resOrig1[100] = {0};
  char resMine1[100] = {0};
  t.origRes = sscanf(str, format, resOrig1, &t.origD1);
  t.mineRes = s21_sscanf(str, format, resMine1, &t.mineD1);
  ck_assert_int_eq(t.mineD1, t.origD1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

// tests for flag_u
START_TEST(test_s21_sscanf_u_0) {
  test t = {0};
  char *str = "-1 -1 -1 -1";
  char *format = "%ho %hho %lu %llu";
  t.origRes =
      sscanf(str, format, &t.origSD1, &t.origSC1, &t.origUL1, &t.origULL1);
  t.mineRes =
      s21_sscanf(str, format, &t.mineSD1, &t.mineSC1, &t.mineUL1, &t.mineULL1);
  ck_assert_int_eq(t.origSD1, t.mineSD1);
  ck_assert_int_eq(t.origSC1, t.mineSC1);
  ck_assert_int_eq(t.origUL1, t.mineUL1);
  ck_assert_int_eq(t.origULL1, t.mineULL1);
  ck_assert_int_eq(t.mineRes, t.origRes);
}
END_TEST

/* TESTS FOR S21_SPRINTF */

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  ck_assert_int_eq(
      sprintf(str1, format, 949149114140, 14, 1441, 14414, 9681),
      s21_sprintf(str2, format, 949149114140, 14, 1441, 14414, 9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_null_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%p", &str1), sprintf(str2, "%p", &str1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(sprintf_test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%%"), sprintf(str2, "%%"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%%%%%%%%"), sprintf(str2, "%%%%%%%%"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
  char str1[100000] = {'\0'};
  char str2[100000] = {'\0'};
  char format[] = "%+0*.*d%%";
  int hex = 5;
  int hex2 = 10;
  s21_sprintf(str1, format, hex, hex2, hex);
  sprintf(str2, format, hex, hex2, hex);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %g %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_wide_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %lc";
//   wchar_t wchar = 1086;
//   unsigned long w = 1086;
//   int b = sprintf(str1, format, wchar);
//   int a = s21_sprintf(str2, format, wchar);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }

// START_TEST(sprintf_width_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %5c";
//   char w = 'c';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }

// START_TEST(sprintf_minus_wide_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %-5lc";
//   unsigned long w = 1086;
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_string) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %ls";
//   wchar_t w[] = L"приветик";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_string1) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %5.12ls";
//   wchar_t w[] = L"опана";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_string2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %120ls ABOBA";
//   wchar_t w[] = L"тестим девачки";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_string3) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %-43ls";
//   wchar_t w[] = L"абобус амогус тест";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_string4) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %43ls";
//   wchar_t w[] = L"еще одна строчка широких";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(sprintf_wide_char2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %43lc";
//   unsigned long w = 1088;
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_int_eq(a, b);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_inf_test) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is abnormal %f";
  int a = s21_sprintf(str1, format, log(0));
  int b = sprintf(str2, format, log(0));
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_nan_test) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%f";
  int a = s21_sprintf(str1, format, log(-1) * -1);
  int b = sprintf(str2, format, log(-1) * -1);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *string_suite(void) {
  Suite *s;
  TCase *tc_memchr;
  TCase *tc_memcmp;
  TCase *tc_memcpy;
  TCase *tc_memmove;
  TCase *tc_memset;
  TCase *tc_strcat;
  TCase *tc_strncat;
  TCase *tc_strchr;
  TCase *tc_strcmp;
  TCase *tc_strncmp;
  TCase *tc_strcpy;
  TCase *tc_strncpy;
  TCase *tc_strcspn;
  TCase *tc_strlen;
  TCase *tc_strpbrk;
  TCase *tc_strrchr;
  TCase *tc_strspn;
  TCase *tc_strstr;
  TCase *tc_strtok;
  TCase *tc_strerror;
  // tests for bonus
  TCase *tc_to_upper;
  TCase *tc_to_lower;
  TCase *tc_insert;
  TCase *tc_trim;
  // tests for scanf
  TCase *tc_scanf_c;
  TCase *tc_scanf_d;
  TCase *tc_scanf_i;
  TCase *tc_scanf_eEfgG;
  TCase *tc_scanf_o;
  TCase *tc_scanf_xX;
  TCase *tc_scanf_p;
  TCase *tc_scanf_s;
  TCase *tc_scanf_n;
  TCase *tc_scanf_u;
  // tests for sprintf
  TCase *tc;

  s = suite_create("String");

  tc_memchr = tcase_create("memchr");
  tcase_add_test(tc_memchr, test_s21_memchr_1);
  tcase_add_test(tc_memchr, test_s21_memchr_2);
  tcase_add_test(tc_memchr, test_s21_memchr_3);
  tcase_add_test(tc_memchr, test_s21_memchr_4);
  tcase_add_test(tc_memchr, test_s21_memchr_5);
  tcase_add_test(tc_memchr, test_s21_memchr_6);
  tcase_add_test(tc_memchr, test_s21_memchr_8);
  tcase_add_test(tc_memchr, test_s21_memchr_9);
  tcase_add_test(tc_memchr, test_s21_memchr_0);
  tcase_add_test(tc_memchr, test_s21_memchr_11);
  suite_add_tcase(s, tc_memchr);

  tc_memcmp = tcase_create("memcmp");
  tcase_add_test(tc_memcmp, test_s21_memcmp_0);
  tcase_add_test(tc_memcmp, test_s21_memcmp_1);
  tcase_add_test(tc_memcmp, test_s21_memcmp_2);
  tcase_add_test(tc_memcmp, test_s21_memcmp_3);
  tcase_add_test(tc_memcmp, test_s21_memcmp_4);
  tcase_add_test(tc_memcmp, test_s21_memcmp_5);
  tcase_add_test(tc_memcmp, test_s21_memcmp_7);
  tcase_add_test(tc_memcmp, test_s21_memcmp_9);
  suite_add_tcase(s, tc_memcmp);

  tc_memcpy = tcase_create("memcpy");
  tcase_add_test(tc_memcpy, test_s21_memcpy_0_usage);
  tcase_add_test(tc_memcpy, test_s21_memcpy_1_usage);
  tcase_add_test(tc_memcpy, test_s21_memcpy_2);
  // tcase_add_test(tc_memcpy, test_s21_memcpy_3);
  // tcase_add_test(tc_memcpy, test_s21_memcpy_4);
  tcase_add_test(tc_memcpy, test_s21_memcpy_5_big_n);
  tcase_add_test(tc_memcpy, test_s21_memcpy_6_equal_str);
  tcase_add_test(tc_memcpy, test_s21_memcpy_7_zeroed_n);
  tcase_add_test(tc_memcpy, test_s21_memcpy_8_memory_check);
  tcase_add_test(tc_memcpy, test_s21_memcpy_9_memory_check);
  suite_add_tcase(s, tc_memcpy);

  tc_memmove = tcase_create("memmove");
  tcase_add_test(tc_memmove, test_s21_memmove_0_usage);
  tcase_add_test(tc_memmove, test_s21_memmove_1_usage);
  tcase_add_test(tc_memmove, test_s21_memmove_2);
  // tcase_add_test(tc_memmove, test_s21_memmove_3);
  // tcase_add_test(tc_memmove, test_s21_memmove_4);
  tcase_add_test(tc_memmove, test_s21_memmove_5_big_n);
  tcase_add_test(tc_memmove, test_s21_memmove_6_equal_str);
  tcase_add_test(tc_memmove, test_s21_memmove_7_zeroed_n);
  tcase_add_test(tc_memmove, test_s21_memmove_8_memory_check);
  tcase_add_test(tc_memmove, test_s21_memmove_9_memory_check);
  suite_add_tcase(s, tc_memmove);

  tc_memset = tcase_create("memset");
  tcase_add_test(tc_memset, test_s21_memset_0);
  // tcase_add_test(tc_memset, test_s21_memset_1);
  tcase_add_test(tc_memset, test_s21_memset_2);
  // tcase_add_test(tc_memset, test_s21_memset_3);
  // tcase_add_test(tc_memset, test_s21_memset_4);
  tcase_add_test(tc_memset, test_s21_memset_5);
  // tcase_add_test(tc_memset, test_s21_memset_6);
  tcase_add_test(tc_memset, test_s21_memset_7);
  // tcase_add_test(tc_memset, test_s21_memset_8);
  suite_add_tcase(s, tc_memset);

  tc_strcat = tcase_create("strcat");
  tcase_add_test(tc_strcat, test_s21_strcat_0);
  // tcase_add_test(tc_strcat, test_s21_strcat_1);
  // tcase_add_test(tc_strcat, test_s21_strcat_2);
  // tcase_add_test(tc_strcat, test_s21_strcat_3);
  tcase_add_test(tc_strcat, test_s21_strcat_4);
  suite_add_tcase(s, tc_strcat);

  tc_strncat = tcase_create("strncat");
  tcase_add_test(tc_strncat, test_s21_strncat_0);
  tcase_add_test(tc_strncat, test_s21_strncat_1);
  tcase_add_test(tc_strncat, test_s21_strncat_2);
  tcase_add_test(tc_strncat, test_s21_strncat_3);
  tcase_add_test(tc_strncat, test_s21_strncat_4);
  tcase_add_test(tc_strncat, test_s21_strncat_5);
  suite_add_tcase(s, tc_strncat);

  tc_strchr = tcase_create("strchr");
  tcase_add_test(tc_strchr, test_s21_strchr_0);
  tcase_add_test(tc_strchr, test_s21_strchr_1);
  tcase_add_test(tc_strchr, test_s21_strchr_2);
  suite_add_tcase(s, tc_strchr);

  tc_strcmp = tcase_create("strcmp");
  tcase_add_test(tc_strcmp, test_s21_strcmp_0);
  // tcase_add_test(tc_strcmp, test_s21_strcmp_1);
  tcase_add_test(tc_strcmp, test_s21_strcmp_2);
  tcase_add_test(tc_strcmp, test_s21_strcmp_3);
  suite_add_tcase(s, tc_strcmp);

  tc_strncmp = tcase_create("strncmp");
  tcase_add_test(tc_strncmp, test_s21_strncmp_0);
  // tcase_add_test(tc_strncmp, test_s21_strncmp_1);
  tcase_add_test(tc_strncmp, test_s21_strncmp_2);
  suite_add_tcase(s, tc_strncmp);

  tc_strcpy = tcase_create("strcpy");
  tcase_add_test(tc_strcpy, test_s21_strcpy_0);
  tcase_add_test(tc_strcpy, test_s21_strcpy_1);
  // tcase_add_test(tc_strcpy, test_s21_strcpy_1_1);
  tcase_add_test(tc_strcpy, test_s21_strcpy_2);
  // tcase_add_test(tc_strcpy, test_s21_strcpy_3);
  tcase_add_test(tc_strcpy, test_s21_strcpy_4);
  tcase_add_test(tc_strcpy, test_s21_strcpy_5);
  suite_add_tcase(s, tc_strcpy);

  tc_strncpy = tcase_create("strncpy");
  tcase_add_test(tc_strncpy, test_s21_strncpy_0);
  tcase_add_test(tc_strncpy, test_s21_strncpy_1);
  tcase_add_test(tc_strncpy, test_s21_strncpy_2);
  tcase_add_test(tc_strncpy, test_s21_strncpy_2_1);
  tcase_add_test(tc_strncpy, test_s21_strncpy_2_2);
  tcase_add_test(tc_strncpy, test_s21_strncpy_3);
  suite_add_tcase(s, tc_strncpy);

  tc_strcspn = tcase_create("strcspn");
  tcase_add_test(tc_strcspn, test_s21_strcspn_0);
  tcase_add_test(tc_strcspn, test_s21_strcspn_1);
  tcase_add_test(tc_strcspn, test_s21_strcspn_2);
  tcase_add_test(tc_strcspn, test_s21_strcspn_3);
  suite_add_tcase(s, tc_strcspn);

  tc_strlen = tcase_create("strlen");
  tcase_add_test(tc_strlen, test_s21_strlen_0);
  tcase_add_test(tc_strlen, test_s21_strlen_1);
  tcase_add_test(tc_strlen, test_s21_strlen_2);
  // tcase_add_test(tc_strlen, test_s21_strlen_3);
  tcase_add_test(tc_strlen, test_s21_strlen_4);
  suite_add_tcase(s, tc_strlen);

  tc_strpbrk = tcase_create("strpbrk");
  tcase_add_test(tc_strpbrk, test_s21_strpbrk_0);
  tcase_add_test(tc_strpbrk, test_s21_strpbrk_1);
  tcase_add_test(tc_strpbrk, test_s21_strpbrk_2);
  tcase_add_test(tc_strpbrk, test_s21_strpbrk_3);
  suite_add_tcase(s, tc_strpbrk);

  tc_strrchr = tcase_create("strrchr");
  tcase_add_test(tc_strrchr, test_s21_strrchr_0);
  tcase_add_test(tc_strrchr, test_s21_strrchr_1);
  tcase_add_test(tc_strrchr, test_s21_strrchr_2);
  tcase_add_test(tc_strrchr, test_s21_strrchr_3);
  tcase_add_test(tc_strrchr, test_s21_strrchr_4);
  tcase_add_test(tc_strrchr, test_s21_strrchr_5);
  suite_add_tcase(s, tc_strrchr);

  tc_strspn = tcase_create("strspn");
  tcase_add_test(tc_strspn, test_s21_strspn_0);
  tcase_add_test(tc_strspn, test_s21_strspn_1);
  tcase_add_test(tc_strspn, test_s21_strspn_2);
  tcase_add_test(tc_strspn, test_s21_strspn_3);
  suite_add_tcase(s, tc_strspn);

  tc_strstr = tcase_create("strstr");
  tcase_add_test(tc_strstr, test_s21_strstr_0);
  tcase_add_test(tc_strstr, test_s21_strstr_1);
  tcase_add_test(tc_strstr, test_s21_strstr_2);
  tcase_add_test(tc_strstr, test_s21_strstr_3);
  suite_add_tcase(s, tc_strstr);

  tc_strtok = tcase_create("strtok");
  tcase_add_test(tc_strtok, test_s21_strtok_0);
  tcase_add_test(tc_strtok, test_s21_strtok_1);
  tcase_add_test(tc_strtok, test_s21_strtok_2);
  suite_add_tcase(s, tc_strtok);

  tc_strerror = tcase_create("strerror");
  tcase_add_test(tc_strerror, test_s21_strerror_0);
  tcase_add_test(tc_strerror, test_s21_strerror_1);
  suite_add_tcase(s, tc_strerror);

  // tests for bonus
  tc_to_upper = tcase_create("to_upper");
  tcase_add_test(tc_to_upper, test_s21_to_upper_0);
  tcase_add_test(tc_to_upper, test_s21_to_upper_1);
  tcase_add_test(tc_to_upper, test_s21_to_upper_2);
  tcase_add_test(tc_to_upper, test_s21_to_upper_3);
  // tcase_add_test(tc_to_upper, test_s21_to_upper_4);
  suite_add_tcase(s, tc_to_upper);

  tc_to_lower = tcase_create("to_lower");
  tcase_add_test(tc_to_lower, test_s21_to_lower_0);
  tcase_add_test(tc_to_lower, test_s21_to_lower_1);
  tcase_add_test(tc_to_lower, test_s21_to_lower_2);
  tcase_add_test(tc_to_lower, test_s21_to_lower_3);
  // tcase_add_test(tc_to_lower, test_s21_to_lower_4);
  suite_add_tcase(s, tc_to_lower);

  tc_insert = tcase_create("insert");
  tcase_add_test(tc_insert, test_s21_insert_0);
  tcase_add_test(tc_insert, test_s21_insert_1);
  tcase_add_test(tc_insert, test_s21_insert_2);
  tcase_add_test(tc_insert, test_s21_insert_3);
  tcase_add_test(tc_insert, test_s21_insert_4);
  tcase_add_test(tc_insert, test_s21_insert_5);
  suite_add_tcase(s, tc_insert);

  tc_trim = tcase_create("trim");
  tcase_add_test(tc_trim, test_s21_trim_0);
  tcase_add_test(tc_trim, test_s21_trim_1);
  tcase_add_test(tc_trim, test_s21_trim_2);
  tcase_add_test(tc_trim, test_s21_trim_3);
  suite_add_tcase(s, tc_trim);

  // tests for scanf
  tc_scanf_c = tcase_create("flag_c");
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_0);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_1);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_flazhki_2);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_flazhki_3);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_4);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_5);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_6);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_flag_AFG_7);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razzzzzdelitel_8);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razdelitel_9);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razdelitel_10);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razdelitel_11);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razdelitel_12);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razdelitel_13);
  tcase_add_test(tc_scanf_c, test_s21_sscanf_c_razdelitel_14);
  suite_add_tcase(s, tc_scanf_c);

  tc_scanf_d = tcase_create("flag_d");
  tcase_add_test(tc_scanf_d, test_s21_sscanf_c_0);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_1);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_2);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_3);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_4);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_5);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_6);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_7);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_8);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_9);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_10);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_11);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_12);
  tcase_add_test(tc_scanf_d, test_s21_sscanf_d_13);
  suite_add_tcase(s, tc_scanf_d);

  tc_scanf_i = tcase_create("flag_i");
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_0);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_1);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_2);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_3);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_4);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_5);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_6);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_7);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_8);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_9);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_10);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_11);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_i_12);
  suite_add_tcase(s, tc_scanf_i);

  tc_scanf_eEfgG = tcase_create("flags_eEfgG");
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_0);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_1);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_2);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_3);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_4);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_5);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_6);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_7);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_8);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_9);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_10);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_11);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_12);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_13);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_14);
  tcase_add_test(tc_scanf_i, test_s21_sscanf_eEfgG_15);
  suite_add_tcase(s, tc_scanf_eEfgG);

  tc_scanf_o = tcase_create("flag_o");
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_0);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_1);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_2);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_3);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_4);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_5);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_procent_6);
  tcase_add_test(tc_scanf_o, test_s21_sscanf_o_7);
  suite_add_tcase(s, tc_scanf_o);

  tc_scanf_xX = tcase_create("flags_xX");
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_0);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_1);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_2);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_3);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_4);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_5);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_6);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_7);
  tcase_add_test(tc_scanf_xX, test_s21_sscanf_xX_8);
  suite_add_tcase(s, tc_scanf_xX);

  tc_scanf_p = tcase_create("flags_p");
  tcase_add_test(tc_scanf_p, test_s21_sscanf_p_0);
  suite_add_tcase(s, tc_scanf_p);

  tc_scanf_s = tcase_create("flags_s");
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_0);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_1);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_2);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_3);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_4);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_5);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_6);
  tcase_add_test(tc_scanf_s, test_s21_sscanf_s_7);
  suite_add_tcase(s, tc_scanf_s);

  tc_scanf_n = tcase_create("flags_n");
  tcase_add_test(tc_scanf_n, test_s21_sscanf_n_0);
  tcase_add_test(tc_scanf_n, test_s21_sscanf_n_1);
  suite_add_tcase(s, tc_scanf_n);

  tc_scanf_u = tcase_create("flags_u");
  tcase_add_test(tc_scanf_u, test_s21_sscanf_u_0);
  suite_add_tcase(s, tc_scanf_u);

  tc = tcase_create("sprintf");
  tcase_add_test(tc, sprintf_simple_int);
  tcase_add_test(tc, sprintf_precise_int);
  tcase_add_test(tc, sprintf_width_int);
  tcase_add_test(tc, sprintf_minus_width_int);
  tcase_add_test(tc, sprintf_plus_width_int);
  tcase_add_test(tc, sprintf_padding_int);
  tcase_add_test(tc, sprintf_star_width_int);
  tcase_add_test(tc, sprintf_star_precision_int);
  tcase_add_test(tc, sprintf_many_flags_many_ints);
  tcase_add_test(tc, sprintf_flags_long_int);
  tcase_add_test(tc, sprintf_flags_short_int);
  tcase_add_test(tc, sprintf_flags_another_long_int);
  tcase_add_test(tc, sprintf_zero_precision_zero_int);
  tcase_add_test(tc, sprintf_space_flag_int);
  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);
  tcase_add_test(tc, sprintf_octal_width);
  tcase_add_test(tc, sprintf_octal_flags);
  tcase_add_test(tc, sprintf_octal_precision);
  tcase_add_test(tc, sprintf_octal_many_flags);
  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_octal_long);
  tcase_add_test(tc, sprintf_octal_many);
  tcase_add_test(tc, sprintf_octal);
  tcase_add_test(tc, sprintf_octal_zero);
  tcase_add_test(tc, sprintf_octal_hash);
  tcase_add_test(tc, sprintf_unsigned_zero);
  tcase_add_test(tc, sprintf_hex_width);
  tcase_add_test(tc, sprintf_hex_flags);
  tcase_add_test(tc, sprintf_hex_precision);
  tcase_add_test(tc, sprintf_hex_many);
  tcase_add_test(tc, sprintf_hex_many_flags);
  tcase_add_test(tc, sprintf_hex_zero);
  tcase_add_test(tc, sprintf_hex_huge);
  tcase_add_test(tc, sprintf_hex_short);
  tcase_add_test(tc, sprintf_hex_long);
  tcase_add_test(tc, sprintf_hex_one_longer_width);
  tcase_add_test(tc, sprintf_hex_two_longer_width);
  tcase_add_test(tc, sprintf_one_char);
  tcase_add_test(tc, sprintf_one_precision);
  tcase_add_test(tc, sprintf_one_flags);
  tcase_add_test(tc, sprintf_one_width);
  tcase_add_test(tc, sprintf_one_many);
  tcase_add_test(tc, sprintf_one_many_flags);
  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  tcase_add_test(tc, sprintf_ptr);
  tcase_add_test(tc, sprintf_ptr_width);
  tcase_add_test(tc, sprintf_ptr_precision);
  tcase_add_test(tc, sprintf_null_ptr);
  tcase_add_test(tc, sprintf_n_specifier);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_float_precision);
  tcase_add_test(tc, sprintf_float_width);
  tcase_add_test(tc, sprintf_float_precision_zero);
  tcase_add_test(tc, sprintf_float_precision_empty);
  tcase_add_test(tc, sprintf_float_precision_huge);
  tcase_add_test(tc, sprintf_float_precision_huge_negative);
  tcase_add_test(tc, sprintf_float_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_float_many);
  tcase_add_test(tc, sprintf_e_precision);
  tcase_add_test(tc, sprintf_e_precision_zero);
  tcase_add_test(tc, sprintf_e_precision_empty);
  tcase_add_test(tc, sprintf_e_precision_huge);
  tcase_add_test(tc, sprintf_e_precision_huge_negative);
  tcase_add_test(tc, sprintf_e_huge);
  tcase_add_test(tc, sprintf_e_many);
  tcase_add_test(tc, sprintf_e_width);
  tcase_add_test(tc, sprintf_e_flags);
  tcase_add_test(tc, sprintf_E_int);
  tcase_add_test(tc, sprintf_all_empty);
  tcase_add_test(tc, sprintf_empty_format_and_parameters);
  tcase_add_test(tc, sprintf_test_one_char);
  tcase_add_test(tc, sprintf_test_many_char);
  tcase_add_test(tc, sprintf_test_one_string);
  tcase_add_test(tc, sprintf_test_many_string);
  tcase_add_test(tc, sprintf_test_one_dec);
  tcase_add_test(tc, sprintf_test_many_dec);
  tcase_add_test(tc, sprintf_test_one_int);
  tcase_add_test(tc, sprintf_test_many_int);
  tcase_add_test(tc, sprintf_test_one_float);
  tcase_add_test(tc, sprintf_test_many_float);
  tcase_add_test(tc, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_lower);
  tcase_add_test(tc, sprintf_test_one_hex_upper);
  tcase_add_test(tc, sprintf_test_many_hex_lower);
  tcase_add_test(tc, sprintf_test_many_hex_upper);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      tc, sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_length);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(tc, sprintf_test_sprintf1);
  tcase_add_test(tc, sprintf_test_sprintf2);
  tcase_add_test(tc, sprintf_test_sprintf3);
  tcase_add_test(tc, sprintf_test_sprintf4);
  tcase_add_test(tc, sprintf_test_sprintf6);
  tcase_add_test(tc, sprintf_test_sprintf7);
  tcase_add_test(tc, sprintf_test_sprintf8);
  tcase_add_test(tc, sprintf_test_sprintf9);
  tcase_add_test(tc, sprintf_test_sprintf10);
  tcase_add_test(tc, sprintf_test_sprintf11);
  tcase_add_test(tc, sprintf_test_sprintf12);
  tcase_add_test(tc, sprintf_test_sprintf14);
  tcase_add_test(tc, sprintf_test_sprintf15);
  tcase_add_test(tc, sprintf_test_sprintf16);
  tcase_add_test(tc, sprintf_test_sprintf17);
  tcase_add_test(tc, sprintf_test_sprintf18);
  tcase_add_test(tc, sprintf_test_sprintf19);
  tcase_add_test(tc, sprintf_test_sprintf20);
  tcase_add_test(tc, sprintf_test_sprintf24);
  tcase_add_test(tc, sprintf_test_sprintf25);
  tcase_add_test(tc, sprintf_test_sprintf28);
  tcase_add_test(tc, sprintf_test_sprintf29);
  tcase_add_test(tc, sprintf_test_sprintf30);
  tcase_add_test(tc, sprintf_test_sprintf31);
  tcase_add_test(tc, sprintf_test_sprintf32);
  tcase_add_test(tc, sprintf_test_sprintf33);
  tcase_add_test(tc, sprintf_test_sprintf35);
  tcase_add_test(tc, sprintf_test_sprintf36);
  tcase_add_test(tc, sprintf_test_sprintf37);
  tcase_add_test(tc, sprintf_test_sprintf38);
  tcase_add_test(tc, sprintf_test_sprintf39);
  tcase_add_test(tc, sprintf_test_sprintf40);
  tcase_add_test(tc, sprintf_test_sprintf41);
  tcase_add_test(tc, sprintf_test_sprintf42);
  tcase_add_test(tc, sprintf_test_sprintf43);
  tcase_add_test(tc, sprintf_test_sprintf44);
  tcase_add_test(tc, sprintf_test_sprintf26);
  tcase_add_test(tc, sprintf_test_sprintf27);
  tcase_add_test(tc, sprintf_g_trailing_zero);
  tcase_add_test(tc, sprintf_g_large);
  tcase_add_test(tc, sprintf_g_small);
  tcase_add_test(tc, sprintf_g_precision);
  tcase_add_test(tc, sprintf_g_precision_zero);
  tcase_add_test(tc, sprintf_g_precision_missing);
  tcase_add_test(tc, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tc, sprintf_g_one_zero);
  tcase_add_test(tc, sprintf_g_mantiss);
  tcase_add_test(tc, sprintf_g_mantiss_flags);
  tcase_add_test(tc, sprintf_g_short_no_mantiss);
  tcase_add_test(tc, sprintf_g_many);
  tcase_add_test(tc, sprintf_g_zero);
  tcase_add_test(tc, sprintf_inf_test);
  tcase_add_test(tc, sprintf_nan_test);
  // tcase_add_test(tc, sprintf_wide_char);
  // tcase_add_test(tc, sprintf_width_char);
  // tcase_add_test(tc, sprintf_minus_wide_char);
  // tcase_add_test(tc, sprintf_wide_string);
  // tcase_add_test(tc, sprintf_wide_string1);
  // tcase_add_test(tc, sprintf_wide_string2);
  // tcase_add_test(tc, sprintf_wide_string3);
  // tcase_add_test(tc, sprintf_wide_string4);
  // tcase_add_test(tc, sprintf_wide_char2);
  suite_add_tcase(s, tc);

  return s;
}

int main(void) {
  setlocale(LC_ALL, "RU");
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}