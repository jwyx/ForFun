// credit: http://blog.csdn.net/maqingli87/article/details/7997649
double pow(double x, int n) {
  if (0 == n)
    return 1.0;
  if (0 == x)
    return 0.0;

  int sign = 1;
  if (n < 0) {
    sign = -1;
    n = abs(n);
  }

  double result = 1, tmp = x;
  while (n > 0) {
    if (n&1 == 1)
      result *= tmp;
    tmp *= tmp;
    n >>= 1;
  }
  return -1 == sign ? 1/result : result;
}
