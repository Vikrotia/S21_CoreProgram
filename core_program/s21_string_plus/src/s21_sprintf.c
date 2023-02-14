#include "s21_sprintf.h"

#define STR_SIZE 512

int s21_sprintf(char *str, const char *format, ...) {
  int folded_char_index = 0;
  char buffer[STR_SIZE] = {'\0'};
  handle_format print_format = {0};
  va_list arguments;
  va_start(arguments, format);
  for (char *ch = (char *)format; *ch; ch++) {
    if (*ch != '%') {
      buffer[folded_char_index] = *ch;
      folded_char_index++;
      // % handler && prevent going beyond the borders
    } else if (*(ch + 1)) {
      char *spec_end = s21_NULL;  // pointer to this position
      if ((spec_end = s21_strpbrk(ch + 1, SPECIFIERS_LIST))) {
        int spec_position = 0;  // position of spicifier after %
        spec_position = spec_end - ch;
        get_flags(ch, &print_format, spec_position);
        get_width(ch, &print_format, arguments, spec_position);
        get_precision(ch, &print_format, arguments, spec_position);
        get_length(ch, &print_format, spec_position);
        get_specifier(ch, &print_format, spec_position);
        // make decision and print it into str with right format
        folded_char_index += format_handler(
            buffer + folded_char_index, buffer, print_format,
            arguments);  // now insert specifier with right format
        ch += spec_position;
      } else {
        // specifiers not found
      }
    } else {
      // on the last place
      // preventing from SEGFAULT
    }
    s21_memset(&print_format, 0,
               sizeof(handle_format));  // nullify print_format = {0}
  }
  s21_strcpy(str, buffer);
  str[folded_char_index] = '\0';
  str[folded_char_index + 1] = '\0';
  va_end(arguments);
  return folded_char_index;
}

void get_flags(const char *format, handle_format *print_format,
               int spec_position) {
  for (int shift = 1; shift < spec_position; shift++) {
    if (format[shift] == '-') {
      print_format->flag_minus = true;
    } else if (format[shift] == '+') {
      print_format->flag_plus = true;
    } else if (format[shift] == ' ') {
      print_format->flag_space = true;
    } else if (format[shift] == '#') {
      print_format->flag_numsign = true;
    } else if (format[shift] == '0' and !isdigit(format[shift - 1]) and
               format[shift - 1] != '.') {
      print_format->flag_zero = true;
    }
  }
}

void get_width(const char *format, handle_format *print_format,
               va_list arguments, int spec_position) {
  for (int shift = 1; shift < spec_position; shift++) {
    if (format[shift] == '*') {
      print_format->width = va_arg(arguments, int);
    } else if (isdigit(format[shift])) {
      int width_length = s21_strspn(format + shift, NUMBERS);
      char buffer[BUFSIZE] = {'\0'};
      for (int i = 0; i < width_length; i++) {
        buffer[i] = format[shift + i];
      }
      print_format->width = atoi(buffer);
      shift += width_length - 1;
      // now skip shift if here [.precision] not [width]
    } else if (format[shift] == '.') {
      if (format[shift + 1] == '*') {
        shift += 1;
      } else if (isdigit(format[shift + 1])) {
        int width_length = s21_strspn(format + shift + 1, NUMBERS);
        shift += width_length;
      }
    }
  }
}

void get_precision(const char *format, handle_format *print_format,
                   va_list arguments, int spec_position) {
  for (int shift = 1; shift < spec_position; shift++) {
    if (format[shift] == '.') {
      if (format[shift + 1] == '*') {
        print_format->is_precision = true;
        print_format->precision = va_arg(arguments, int);
      } else if (isdigit(format[shift + 1])) {
        int precision_length = s21_strspn(format + shift + 1, NUMBERS);
        char buffer[BUFSIZE] = {'\0'};
        for (int i = 0; i < precision_length; i++) {
          buffer[i] = format[shift + 1 + i];
        }
        print_format->precision = atoi(buffer);
        print_format->is_precision = true;
        shift += precision_length;
      } else {
        print_format->is_precision = true;
        print_format->precision = 0;
      }
    }
  }
}

void get_length(const char *format, handle_format *print_format,
                int spec_position) {
  for (int shift = 1; shift < spec_position; shift++) {
    if (format[shift] == 'h') {
      print_format->length = 'h';
    } else if (format[shift] == 'l') {
      print_format->length = 'l';
    } else if (format[shift] == 'L') {
      print_format->length = 'L';
    }
  }
}

void get_specifier(const char *format, handle_format *print_format,
                   int spec_position) {
  print_format->specifier = format[spec_position];
}

// handle specifier and return number of printed characters
int format_handler(char *position, char *start, handle_format print_format,
                   va_list arguments) {
  int ret = 0;
  *position = '\0';
  if (print_format.specifier == 'c') {
    ret = handle_char(print_format, position, arguments);
  } else if (print_format.specifier == 'd' or print_format.specifier == 'i') {
    ret = handle_int(print_format, position, arguments);
  } else if (print_format.specifier == 'e' or print_format.specifier == 'E') {
    ret = handle_mantissa(print_format, position, arguments);
  } else if (print_format.specifier == 'f') {
    ret = handle_float(print_format, position, arguments);
  } else if (print_format.specifier == 'g' or print_format.specifier == 'G') {
    ret = handle_shortest_float(print_format, position, arguments);
  } else if (print_format.specifier == 'o') {
    ret = handle_octal_numb(print_format, position, arguments);
  } else if (print_format.specifier == 's') {
    ret = handle_string(print_format, position, arguments);
  } else if (print_format.specifier == 'u') {
    ret = handle_uint(print_format, position, arguments);
  } else if (print_format.specifier == 'x' or print_format.specifier == 'X') {
    ret = handle_hex_numb(print_format, position, arguments);
  } else if (print_format.specifier == 'p') {
    ret = handle_pointer(print_format, position, arguments);
  } else if (print_format.specifier == 'n') {
    int *printed_counter = va_arg(arguments, int *);
    *printed_counter = s21_strlen(start);
  } else if (print_format.specifier == '%') {
    ret = handle_percent(print_format, position);
  }
  if (print_format.specifier == 'E' or print_format.specifier == 'G' or
      print_format.specifier == 'X') {
    to_upper(position);
  }
  return ret;
}

int handle_char(handle_format print_format, char *position, va_list arguments) {
  int ret = 0;
  bool is_wide_char = false;

  if (print_format.length == 'l') {
    wchar_t wch = va_arg(arguments, wchar_t);
    char buffer[8] = {'\0'};
    wcstombs(buffer, &wch, 8);
    s21_strcat(position, buffer);
    ret = 2;
  } else {
    char ch = va_arg(arguments, int);
    *position = ch;
    ret = 1;
  }
  *(position + ret + is_wide_char) = '\0';
  ret += handle_flags_and_width(print_format, position);

  return ret + is_wide_char;
}

int handle_int(handle_format print_format, char *position, va_list arguments) {
  int64_t val = va_arg(arguments, int64_t);

  if (print_format.length == 0) {
    val = (int32_t)val;
  } else if (print_format.length == 'h') {
    val = (int16_t)val;
  }

  int ret = num_to_str(val, position, 10, print_format);
  ret += format_precision_diouxX(print_format, position);
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_mantissa(handle_format print_format, char *position,
                    va_list arguments) {
  int pow = 0;
  long double val = 0;

  if (print_format.length == 'L') {
    val = va_arg(arguments, long double);
  } else {
    val = va_arg(arguments, double);
  }
  char sign = (int)val == 0 ? '-' : '+';
  if (!print_format.is_precision) {
    print_format.precision = 6;
  } else if (print_format.precision == 0 and val != 0) {
    // print_format.precision = 1;
  }
  if ((int)val - val) {
    while ((int)(double)val == 0 and pow < 4997) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  if (print_format.precision > 4) {
    while ((int)val / 10 != 0 and pow < 4997) {
      pow++;
      val /= 10;
    }
  } else {
    while ((int)roundl(val) / 10 != 0 and pow < 4997) {
      pow++;
      val /= 10;
    }
  }

  int ret = double_to_str((double)val, position, print_format);
  ret += add_exponent(position, pow, sign, print_format);
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_float(handle_format print_format, char *position,
                 va_list arguments) {
  int ret = 0;
  int init_len = s21_strlen(position);
  long double val = 0;

  if (print_format.length == 'L') {
    val = va_arg(arguments, long double);
  } else {
    val = va_arg(arguments, double);
  }

  // set default precision
  if (!print_format.is_precision) {
    print_format.precision = 6;
  }
  ret += double_to_str(val, position, print_format);
  ret += handle_flags_and_width(print_format, position);

  *(position + init_len + ret) = '\0';
  return ret;
}

int handle_shortest_float(handle_format print_format, char *position,
                          va_list arguments) {
  int ret = 0;
  int pow = 0;
  int mode = REG_MODE;
  long double val = 0;
  if (print_format.length == 'L') {
    val = va_arg(arguments, long double);
  } else {
    val = va_arg(arguments, double);
  }

  char sign = (int)val == 0 ? '-' : '+';
  long double save = val;
  if (!print_format.is_precision) {
    print_format.precision = 6;
  } else if (print_format.precision == 0) {
    print_format.precision = 1;
  }
  if ((int)val - val) {
    while ((int)(double)(val) == 0 and pow <= 4997) {
      pow++;
      val *= 10;
      if (pow >= 5) mode = EXP_MODE;
    }
  } else {
    sign = '+';
  }
  if (print_format.precision > 4) {
    while ((int)(double)val / 10 != 0 and pow <= 4997) {
      pow++;
      val /= 10;
      if (pow >= print_format.precision) mode = EXP_MODE;
    }
  } else {
    while ((int)(double)val / 10 != 0 and pow <= 4997) {
      pow++;
      val /= 10;
    }
    if ((int)(double)val + 1 == 10) {
      pow++;
      val = roundl(val);
    }
    if (pow >= print_format.precision and pow >= 5) mode = EXP_MODE;
  }
  if (print_format.is_precision and print_format.precision > pow)
    mode = REG_MODE;
  if (save == 0) {
    mode = EXP_MODE;
  }
  if (pow >= 7 and pow < 4937) {
    // val = roundl(val);
    if (roundl(save) == 0) {
      mode = EXP_MODE;
    }
  }
  if (!isnormal(val)) {
    mode = REG_MODE;
  }
  if (mode == EXP_MODE) {
    int saved_precision = print_format.precision;
    ret += double_to_str((double)val, position, print_format);
    ret += format_precision_gG(position, saved_precision);
  } else if (mode == REG_MODE) {
    if (sign == '+') {
      print_format.precision = print_format.precision - pow - 1;
    } else {
      if (print_format.precision <= 6 and pow != 1) {
        print_format.precision = 6;
      }
    }
    ret += double_to_str(save, position, print_format);
    if (!print_format.flag_numsign) {
      ret += remove_dangling_zeroes(position);
    }
  }
  if (mode == EXP_MODE) {
    if (!print_format.flag_numsign) ret += remove_dangling_zeroes(position);
    if (pow != 0) {
      ret += add_exponent(position, pow, sign, print_format);
    }
    ret += dot_fix_gG(position, print_format);
  }
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_octal_numb(handle_format print_format, char *position,
                      va_list arguments) {
  uint64_t val = va_arg(arguments, uint64_t);

  if (print_format.length == 0) {
    val = (uint32_t)val;
  } else if (print_format.length == 'h') {
    val = (uint16_t)val;
  }

  if (!print_format.is_precision) {
    print_format.precision = 1;
  }

  int ret = unsigned_num_to_str(val, position, 8, print_format);
  ret += format_precision_opxX(print_format, position, 0);
  if (print_format.flag_numsign) {
    ret += prefix_for_ox(print_format, position);
  }
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_string(handle_format print_format, char *position,
                  va_list arguments) {
  int ret = 0;
  bool is_wide = false;

  if (print_format.length == 'l') {
    wchar_t *wide_str = va_arg(arguments, wchar_t *);
    is_wide = true;
    char buffer[512] = {'\0'};
    wcstombs(buffer, wide_str, 512);
    s21_strcat(position, buffer);
    ret += s21_strlen(position);
  } else {
    int str_len = 0;
    char *buffer = va_arg(arguments, char *);
    str_len = s21_strlen(buffer);
    ret += write_in_line(buffer, position, str_len);
  }
  ret -= format_precision_s(print_format, position, ret);
  *(position + ret + is_wide) = '\0';

  handle_flags_and_width(print_format, position);

  return s21_strlen(position);
}

int handle_uint(handle_format print_format, char *position, va_list arguments) {
  uint64_t val = va_arg(arguments, uint64_t);

  if (print_format.length == 0) {
    val = (uint32_t)val;
  } else if (print_format.length == 'h') {
    val = (uint16_t)val;
  }

  if (!print_format.is_precision) {
    print_format.precision = 1;
  }

  int ret = unsigned_num_to_str(val, position, 10, print_format);
  ret += format_precision_diouxX(print_format, position);
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_hex_numb(handle_format print_format, char *position,
                    va_list arguments) {
  uint64_t val = va_arg(arguments, uint64_t);

  if (print_format.length == 0) {
    val = (uint32_t)val;
  } else if (print_format.length == 'h') {
    val = (uint16_t)val;
  }
  if (!print_format.is_precision) {
    print_format.precision = 1;
  }

  int ret = unsigned_num_to_str(val, position, 16, print_format);
  ret += format_precision_opxX(print_format, position, 0);
  if (print_format.flag_numsign and val != 0) {
    ret += prefix_for_ox(print_format, position);
  }
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_pointer(handle_format print_format, char *position,
                   va_list arguments) {
  uint64_t val = va_arg(arguments, uint64_t);
  if (!print_format.is_precision) {
    print_format.precision = 1;
  }

  int ret = unsigned_num_to_str(val, position, 16, print_format);
  ret += prefix_for_ox(print_format, position);
  ret += format_precision_opxX(print_format, position, 2);
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int handle_flags_and_width(handle_format print_format, char *position) {
  int increased_width = 0;
  int addictions = 0;
  int is_sign = 0;
  int init_len = s21_strlen(position);
  bool abnormal = false;
  if (s21_strchr("dieEfgGxX", print_format.specifier)) {
    bool is_nan = false;
    if (s21_strstr(position, "inf") or s21_strstr(position, "nan")) {
      abnormal = true;
    }
    if (s21_strstr(position, "nan")) {
      is_nan = true;
    }
    if (print_format.flag_plus and !is_nan) {
      if (*position != '-') {
        string_shift(position, 1);
        *position = '+';
        addictions++;
      }
      is_sign = 1;
    } else if (print_format.flag_space and !is_nan) {
      if (*position != '-') {
        string_shift(position, 1);
        *position = ' ';
        addictions++;
      }
      is_sign = 1;
    }
    if (*position == '-') {
      is_sign = 1;
    }
  } else if (s21_strchr("opxX", print_format.specifier)) {
    if (print_format.specifier == 'p') {
    } else if (print_format.flag_numsign) {
      is_sign = 2;
      if (print_format.specifier == 'o') {
        is_sign = 1;
      }
    }
  }
  *(position + is_sign + init_len) = '\0';
  if (print_format.width > (int)s21_strlen(position)) {
    increased_width = print_format.width - s21_strlen(position);
    if ((s21_strchr("di", print_format.specifier) and
         print_format.is_precision) or
        abnormal) {  // тут условие на if nan и inf
      print_format.flag_zero = 0;
    }
    if (!print_format.flag_minus) {
      string_shift(position, increased_width);
      s21_memset(position, ' ', increased_width);

      if (print_format.flag_zero) {
        if (is_sign) {
          char *sign = s21_strpbrk(position, "-+");
          if (sign) {
            *(sign - increased_width) = *sign;
            *sign = ' ';
          }
        }
        if (is_sign == 2) {
          char *prefix = NULL;
          if (s21_strchr("xXp", print_format.specifier)) {
            prefix = s21_strstr(position, "0x");
            if (prefix) {
              *(prefix - increased_width) = *prefix;
              *(prefix - increased_width + 1) = *(prefix + 1);
              *prefix = ' ';
              *(prefix + 1) = ' ';
            }
          } else if (print_format.specifier == 'o') {
          }
        }
        if (!s21_strchr("pouxX", print_format.specifier))
          s21_memset(position + is_sign, '0', increased_width);
      }
    } else {
      s21_memset(position + s21_strlen(position), ' ', increased_width);
    }
  }
  *(position + init_len + increased_width + addictions) = '\0';

  return increased_width + addictions;
}

int num_to_str(int64_t val, char *position, int capacity,
               handle_format print_format) {
  int success_printed = 0;
  bool is_negative = false;
  *position = '\0';
  // sign handler
  if (val < 0) {
    is_negative = true;
    val = val * -1;
    *position = '-';
    success_printed++;
  }

  // zero handler
  if (val == 0 and print_format.precision != 0 or
      (val == 0 and !print_format.is_precision)) {  // add if
    *(position + success_printed) = '0';
    success_printed++;
  }

  // put numb in our string via devide numb
  while (val % 10 != 0 or val > 0) {
    char char_ins = NUMBERS_16[val % capacity];
    val /= capacity;
    *(position + success_printed) = char_ins;
    success_printed++;
  }

  // roll back to reverse out numb
  // reverse numb
  reverse_line(position, is_negative, success_printed);
  *(position + success_printed) = '\0';

  return success_printed;
}

int format_precision_diouxX(handle_format print_format, char *position) {
  int init_len = s21_strlen(position);
  int length = s21_strspn(position, FIND_NUMB);
  bool is_sign = false;
  int print_len = 0;

  if (*position == '-') {
    length--;
    is_sign = true;
  }
  if (print_format.precision > length) {
    print_len = print_format.precision - length;
    string_shift(position + is_sign, print_len);
    s21_memset(position + is_sign, '0', print_len);
  }
  *(position + print_len + init_len) = '\0';

  return print_len;
}

int format_precision_gG(char *position, int saved_precision) {
  int ret = 0;
  int save_value = 0;

  if (saved_precision > 1 and saved_precision < 7) {
    save_value = saved_precision - 1;
  } else if (saved_precision <= 1) {
    save_value = 0;
  } else {
    save_value = 6;
  }
  if (*(position) == '-') position++;
  int len = s21_strlen(position);

  for (int i = 0; i < len - 2 - save_value; i++) {
    *(position + len - 1 - i) = '\0';
    ret--;
  }

  return ret;
}

int format_precision_s(handle_format print_format, char *position, int len) {
  int cut_chars = 0;
  int coef = 1;
  bool is_wide = false;

  if (print_format.length == 'l') {
    coef = 2;
    is_wide = true;
  }
  if (print_format.is_precision and print_format.precision < len) {
    cut_chars = len - print_format.precision;
    for (int i = 0; i < cut_chars; i++) {
      position[print_format.precision + i] = '\0';
    }
  }

  return is_wide ? cut_chars * coef - 2 : cut_chars * coef;
}

void string_shift(char *str, int shift) {
  int init_len = (int)s21_strlen(str);
  for (int i = 0; i < init_len; i++) {
    *(str + init_len - 1 + shift - i) = *(str + init_len - 1 - i);
    if ((i + 1) == init_len) {
      *(str + init_len + shift) = '\0';
    }
  }
  // *(str + s21_strlen(str) - 1 + shift) = '\0';
  *(str + init_len + shift) = '\0';
  *(str + init_len + shift + 1) = '\0';
}

void reverse_string_shift(char *str, int shift) {
  for (int i = 0; i < (int)s21_strlen(str); i++) {
    *(str - shift + i) = *(str + i);
  }
}

int write_in_line(const char *from, char *to, int len) {
  int ret = 0;

  for (int i = 0; i < len; i++) {
    *(to + i) = from[i];
    ret++;
  }

  return ret;
}

int unsigned_num_to_str(uint64_t val, char *position, int capacity,
                        handle_format print_format) {
  int success_printed = 0;

  // zero handler
  if (val == 0 and print_format.precision != 0) {
    *(position + success_printed) = '0';
    success_printed++;
  }
  // put numb in our string via devide numb
  while ((val % 10 != 0 or val > 0) and capacity > 0) {
    char char_ins = NUMBERS_16[val % capacity];
    val /= capacity;
    *(position + success_printed) = char_ins;
    success_printed++;
  }
  reverse_line(position, 0, success_printed);
  *(position + success_printed) = '\0';

  return success_printed;
}

int handle_percent(handle_format print_format, char *position) {
  int ret = 0;

  *position = '%';
  *(position + 1) = '\0';
  ret += 1;
  ret += handle_flags_and_width(print_format, position);

  return ret;
}

int double_to_str(long double val, char *position, handle_format print_format) {
  int ret = 0;
  int init_len = s21_strlen(position);
  if (isnormal(val) or val == 0) {
    long double significant = 0;
    long double fractional_part = modfl(val, &significant);

    if (print_format.precision == 0) {
      significant = roundl(val);
      fractional_part = 0;
    }
    ret += handle_float_significant(significant, position, print_format);
    ret += handle_float_fractional_part(fractional_part, position + ret,
                                        print_format);
  } else {
    ret += handle_abnormal(val, position);
  }

  *(position + init_len + ret) = '\0';
  return ret;
}

int handle_float_significant(long double val, char *position,
                             handle_format print_format) {
  int success_printed = 0;
  bool is_negative = false;

  if (val < 0) {
    is_negative = true;
    val = val * -1;
    *position = '-';
    success_printed++;
  }
  if (val == 0) {
    *position = '0';
    success_printed++;
  }
  if (signbit(val) and s21_strchr("di", print_format.specifier)) {
    is_negative = true;
    val = val * -1;
    *position = '-';
    *(position + 1) = '0';
    success_printed += 1;
  }
  long long left = val;
  while (left % 10 != 0 or left > 0) {
    char char_ins = left % 10 + 48;
    left /= 10;
    *(position + success_printed) = char_ins;
    success_printed++;
  }
  reverse_line(position, is_negative, success_printed);

  return success_printed;
}

int handle_float_fractional_part(long double val, char *position,
                                 handle_format print_format) {
  int success_printed = 0;
  if (val < 0) {
    val *= -1;
  }
  if (print_format.precision != 0 or print_format.flag_numsign) {
    *position = '.';
    success_printed++;
  }
  for (int i = 0; i < print_format.precision; i++) {
    val = val * 10;
  }
  long long right = roundl(val);
  for (int i = 0; i < print_format.precision; i++) {
    char char_ins = (int)(right % 10) + 48;
    right /= 10;
    *(position + success_printed) = char_ins;
    success_printed++;
  }
  reverse_line(position, 1, success_printed);
  *(position + success_printed) = '\0';
  return success_printed;
}

int prefix_for_ox(handle_format print_format, char *position) {
  int ret = 0;
  int init_len = s21_strlen(position);

  if (print_format.specifier == 'o') {
    if (print_format.flag_numsign) {
      string_shift(position, 1);
      ret++;
    }
    *position = '0';
  } else if (print_format.specifier == 'x' or print_format.specifier == 'X' or
             print_format.specifier == 'p') {
    string_shift(position, 2);
    ret += 2;
    *position = '0';
    *(position + 1) = 'x';
  }
  *(position + init_len + ret) = '\0';

  return ret;
}

int add_exponent(char *position, int pow, char sign,
                 handle_format print_format) {
  int len = s21_strlen(position);

  *(position + len) = 'e';
  *(position + len + 1) = sign;
  if (pow <= 9) {
    *(position + len + 2) = '0';
    if (pow == 0) {
      *(position + len + 3) = '0';
    } else {
      num_to_str(pow, position + len + 3, 10, print_format);
    }
  } else {
    num_to_str(pow, position + len + 2, 10, print_format);
  }
  return s21_strlen(position) - len;
}

int dot_fix_gG(char *position, handle_format print_format) {
  int ret = 0;

  if (*position == '-') position++;
  if (isdigit(*(position + 1))) {
    string_shift(position, 1);
    *(position + 1) = '.';
    ret++;
  } else if ((*(position + 1) == '.') and
             (!isdigit(*(position + 2)) or (*(position + 2) == 0)) and
             !print_format.flag_numsign) {
    reverse_string_shift(position + 2, 1);
    ret--;
    position[s21_strlen(position) - 1] = '\0';
  }

  return ret;
}

int remove_dangling_zeroes(char *position) {
  int ret = 0;

  char *p = position + s21_strlen(position) - 1;

  if (p) {
    int i = 0;
    while (*(p - i) == '0') {
      p[-i] = '\0';
      ret--;
      i++;
    }
    if (*(p - i) == '.') {
      *(p - i) = '\0';
      ret--;
    }
  }

  return ret;
}

int handle_abnormal(long double val, char *position) {
  int ret = 0;

  if (isinf(val)) {
    // +inf
    if (signbit(val) == 0) {
      s21_strcat(position, "inf");
      ret = 3;
      // -inf
    } else {
      s21_strcat(position, "-inf");
      ret = 4;
    }
  } else if (isnan(val)) {
    // nan
    s21_strcat(position, "nan");
    ret = 3;
  }

  return ret;
}

int format_precision_opxX(handle_format print_format, char *position,
                          int prefix_len) {
  int ret = 0;
  int length = s21_strlen(position + prefix_len);

  if (print_format.precision > length) {
    ret = print_format.precision - length;
    string_shift(position + prefix_len, ret);
    s21_memset(position + prefix_len, '0', ret);
  }

  return ret;
}

void to_upper(char *position) {
  for (int i = 0; i < (int)s21_strlen(position); i++) {
    if (*(position + i) > 96 and *(position + i) < 123) {
      *(position + i) = *(position + i) - 32;
    }
    if (i + 1 == (int)s21_strlen(position)) {
      *(position + i + 1) = '\0';
    }
  }
}

void reverse_line(char *position, int line_start, int line_end) {
  for (int start = line_start, end = line_end - 1;
       start - line_start < line_end / 2; start++, end--) {
    char swap = *(position + start);
    *(position + start) = *(position + end);
    *(position + end) = swap;
  }
}
