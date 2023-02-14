#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <ctype.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

#define SPECIFIERS_LIST "cdieEfgGosuxXpn%"
#define FIND_NUMB ".-0123456789"
#define NUMBERS "0123456789"
#define NUMBERS_16 "0123456789abcdef"
#define BUFSIZE 512

int s21_sprintf(char *str, const char *format, ...);

typedef struct format {
  // flags
  bool flag_minus;
  bool flag_plus;
  bool flag_space;
  bool flag_numsign;
  bool flag_zero;

  // width
  int width;

  // precision
  bool is_precision;
  int precision;

  // length
  char length;

  // specifier
  char specifier;
} handle_format;

enum mode {
  REG_MODE,
  EXP_MODE,
};

// parse print_format
void get_flags(const char *format, handle_format *print_format,
               int spec_position);
void get_width(const char *format, handle_format *print_format,
               va_list arguments, int spec_position);
void get_precision(const char *format, handle_format *print_format,
                   va_list arguments, int spec_position);
void get_length(const char *format, handle_format *print_format,
                int spec_position);
void get_specifier(const char *format, handle_format *print_format,
                   int spec_position);
int format_handler(
    char *position, char *start, handle_format print_format,
    va_list arguments);  // return number of successfully print chars

// handle specifier with the desired format
int handle_char(handle_format print_format, char *position, va_list arguments);
int handle_int(handle_format print_format, char *position, va_list arguments);
int handle_mantissa(handle_format print_format, char *position,
                    va_list arguments);
int handle_float(handle_format print_format, char *position, va_list arguments);
int handle_shortest_float(handle_format print_format, char *position,
                          va_list arguments);
int handle_octal_numb(handle_format print_format, char *position,
                      va_list arguments);
int handle_string(handle_format print_format, char *position,
                  va_list arguments);
int handle_uint(handle_format print_format, char *position, va_list arguments);
int handle_hex_numb(handle_format print_format, char *position,
                    va_list arguments);
int handle_pointer(handle_format print_format, char *position,
                   va_list arguments);
int handle_percent(handle_format print_format, char *position);

// preformat functions
int handle_flags_and_width(handle_format print_format, char *position);
int format_precision_diouxX(handle_format print_format, char *position);
int format_precision_gG(char *position, int saved_precision);
int format_precision_s(handle_format print_format, char *position, int len);
int format_precision_opxX(handle_format print_format, char *position,
                          int prefix_len);

// secondary functions
int num_to_str(int64_t val, char *position, int capacity,
               handle_format print_format);  // converting a number of any
                                             // capacity to a string
int unsigned_num_to_str(uint64_t val, char *position, int capacity,
                        handle_format print_format);
void string_shift(char *str, int shift);
void reverse_string_shift(char *str, int shift);
int write_in_line(const char *from, char *to, int len);
int double_to_str(long double val, char *position, handle_format print_format);
int handle_float_significant(long double val, char *position,
                             handle_format print_format);
int handle_float_fractional_part(long double val, char *position,
                                 handle_format print_format);
int prefix_for_ox(handle_format print_format, char *position);
int add_exponent(char *position, int pow, char sign,
                 handle_format print_format);
int remove_dangling_zeroes(char *position);
int dot_fix_gG(char *position, handle_format print_format);
int handle_abnormal(long double val, char *position);
void to_upper(char *position);
void reverse_line(char *position, int line_start, int line_end);

#endif  // SRC_S21_SPRINTF_H_
