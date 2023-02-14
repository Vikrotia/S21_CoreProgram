#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_INF 1.0 / 0.0
#define s21_E 2.718281828459045
#define s21_EXP 2.71828182845904523536
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-17
#define s21_DBL_MAX 1.79769313486231570814527423731704357e+308L
#define s21_P 3.14159265358979323846
#define s21_P_2 1.57079632679
#define s21_P_3 1.0471975512
#define s21_P_4 0.78539816339
#define s21_P_6 0.52359877559
#define s21_2P 6.28318530718
#define s21_2P_3 2.09439510239
#define s21_3P_4 2.35619449019
#define s21_5P_6 2.61799387799
#define s21_7P_6 3.66519142919
#define s21_5P_4 3.92699081699
#define s21_4P_3 4.18879020479
#define s21_3P_2 4.71238898038
#define s21_5P_3 5.23598775598
#define s21_7P_4 5.49778714378
#define s21_11P_6 5.75958653158
#define s21_5P_3 5.23598775598

int s21_abs(int x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
long double s21_log(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

#endif  //  SRC_S21_MATH_H_