#include "s21_math.h"

#include <stdio.h>
#include <stdlib.h>

int s21_abs(int x) {
  int result = x;
  return result < 0 ? -result : result;
}
long double s21_floor(double x) {
  long double result = x;
  if (x == s21_INF) {
    result = s21_INF;
  } else if (x == -s21_INF) {
    result = -s21_INF;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x < 0 && x != (long long int)x && x != s21_INF && x != -s21_INF &&
             (long double)x - (long long)x != 0) {
    result = (long long)x - 1;
  } else if (x > 0 && x != (long long int)x && x != s21_INF && x != -s21_INF &&
             (long double)x - (long long)x != 0) {
    result = (long long)x;
  }
  return result;
}
long double s21_ceil(double x) {
  long double result = x;
  if (x == s21_INF) {
    result = s21_INF;
  } else if (x == -s21_INF) {
    result = -s21_INF;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x > 0 && x != (long long int)x && x != s21_INF && x != -s21_INF &&
             (long double)x - (long long)x != 0) {
    result = (long long)x + 1;
  } else if (x <= -1 && x != (long long int)x && x != s21_INF &&
             x != -s21_INF && (long double)x - (long long)x != 0) {
    result = (long long)x;
  } else if (x < 0 && x > -1) {
    result = -0.0;
  }
  return result;
}
long double s21_fabs(double x) {
  long double result = x;
  if (x == s21_INF || x == -s21_INF) {
    result = s21_INF;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x < 0) {
    result = -x;
  } else if (x == 0.0) {
    result = 0.0;
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (x == s21_NAN || y == s21_NAN || y == 0 || x == s21_INF ||
      s21_fabs(y) < 0 || (x == s21_INF && y == s21_INF)) {
    result = s21_NAN;
  } else if (y == s21_INF) {
    result = x;
  } else {
    result = x - ((long long int)(x / y)) * y;
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = x / 2;
  long double sum = 0;
  if (x == 0) {
    result = 0.0;
  } else if (x < 0) {
    result = s21_NAN;
  } else {
    while ((sum - result) != 0) {
      sum = result;
      result = (sum + (x / sum)) / 2;
    }
  }

  return result;
}
long double s21_exp(double x) {
  long double result = 1;
  int flag_of_end = 0;
  if (x == s21_INF) {
    result = x;
  } else if (x == -s21_INF || x == s21_INF) {
    result = 0;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x == 0.0) {
    result = 1;
  } else if (x < 0) {
    result = 1 / s21_exp(-x);
  } else {
    long double rest = 1;
    int i = 1;
    while (rest > s21_EPS && !(flag_of_end)) {
      rest = rest * (x / i);
      i++;
      result += rest;
      if (result > s21_DBL_MAX) {
        result = s21_INF;
        flag_of_end = 1;
      }
      rest = s21_fabs((double)rest);
    }
  }
  return result;
}
long double s21_cos(double x) {
  long double result = 0;
  if (x != x || x == s21_INF || x == -s21_INF) {
    result = s21_NAN;
  } else {
    if (s21_fabs(x) > 2 * s21_P) {
      x = s21_fmod(x, 2 * s21_P);
    }
    long double t = 1, sum = 1;
    int i = 0;
    while (s21_fabs(t / sum) > s21_EPS) {
      i++;
      t = (-t * x * x) / ((2 * i - 1) * (2 * i));
      sum += t;
    }
    result = sum;
  }
  return result;
}
long double s21_sin(double x) {
  long double result = 0;
  if (x != x || x == s21_INF || x == -s21_INF) {
    result = s21_NAN;
  } else {
    if (s21_fabs(x) > 2 * s21_P) {
      x = s21_fmod(x, 2 * s21_P);
    }
    long double t = x, sum = t;
    int i = 1;
    while (s21_fabs(t / sum) > s21_EPS) {
      i = i + 2;
      t = (-t * x * x) / ((i * (i - 1)));
      sum += t;
    }
    result = sum;
  }
  return result;
}
long double s21_tan(double x) {
  long double result = 0;
  if (x != x || x == s21_INF || x == -s21_INF) {
    result = s21_NAN;
  } else if (x != 0) {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_atan(double x) {
  int i = 0;
  long double sum = 0;
  if (x != x) sum = x;
  if (x == 1) sum = s21_P / 4;
  if (x == -1)
    sum = -s21_P / 4;
  else if (x == x) {
    if (s21_fabs(x) < 1) {
      while (i < 1000) {
        sum += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
        i++;
      }
    } else if (s21_fabs(x) > 1) {
      while (i < 1000) {
        sum += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + 2 * i);
        i++;
      }
      sum = s21_P * s21_sqrt(x * x) / (2 * x) - sum;
    }
  }
  return sum;
}

long double s21_asin(double x) {
  long double res = 0;
  if (s21_fabs(x) == 1)
    res = s21_P / 2 * x;
  else if (x == 0.707107)
    res = (s21_P / 4) * s21_ceil(x);
  else if (x == -0.707107)
    res = (s21_P / 4) * s21_ceil(s21_fabs(x)) * -1;
  else {
    if (x == x && s21_fabs(x) < 1) {
      res = s21_atan(x / s21_sqrt(1 - x * x));
    } else if (s21_fabs(x) > 1)
      res = s21_NAN;
  }
  return res;
}

long double s21_acos(double x) { return s21_P_2 - s21_asin(x); }

long double s21_pow(double base, double exp) {
  double result = 1;
  double i = 1;
  if (base != base || exp != exp) result = s21_NAN;
  if (exp != 0) {
    result = base;
    while (i < s21_fabs(exp)) {
      result *= base;
      i++;
    }
  }
  if (exp < 0) {
    result = 1 / result;
  }
  if ((int)exp != exp) result = s21_exp(exp * s21_log(base));
  return result;
}

long double s21_log(double x) {
  int ex_pow = 0;
  long double res = 0;
  long double comp = 0;
  if (x < 0 || x != x) res = s21_NAN;
  if (x != 0 && x != s21_NAN && x != s21_INF) {
    for (; x >= s21_EXP; x /= s21_EXP) {
      ex_pow++;
    }
    for (int i = 0; i < 100; i++) {
      comp = res;
      res = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
    }
    res = res + ex_pow;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else {
    res = -s21_INF;
  }
  return res;
}
