int climbStairs(int n) {
  int a = 1;
  int b = 1;

  while (--n > 0) {
    a += b;
    b = a - b;
  }
  return a;
}
