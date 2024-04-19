#include "../s21_math.h"

long double s21_exp(double x) {
  long double res = 1;
  if (S21_IS_INF(x) || S21_IS_NAN(x)) {
    res = (x == S21_INF_NEG) ? 0 : x;
  } else if (x < -17) {
    res = 0;
  } else if (x > 11356.6) {
    res = S21_INF;
  } else {
    long double term = 1;
    for (int i = 1; i < 1000; i++) {
      term *= x / i;
      res += term;
    }
  }
  return res;
}