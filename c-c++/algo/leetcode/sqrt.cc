// 1+3+5+7+...+(2n-1)=n*n
// credit: http://blog.csdn.net/zhiyu27/article/details/8214512
int sqrt(int x) {
  if (x < 0)
    return -1;

  int i = 1;
  while (x >= 0) {
    x -= i;
    i += 2;
  }
  return (i - 1) / 2 - 1;
}

// 牛顿迭代
// credit : http://blog.csdn.net/tingmei/article/details/8040068
int sqrt(int x) {
  assert(x >= 0);
  if (x == 0) return 0;
  double val = x;
  double last;
  do {
    last = val;
    val = (val + x/val)/2.0;
  } while(abs(val-last) > 0.000001);
  return val;
}

// credit: http://blog.csdn.net/maqingli87/article/details/8009513
int sqrt(int x) {
  if (x < 0)
    return -1;
  long long left = 0, right = x, mid = 0, temp = 0;
  while(left <= right) {
    mid = left + (right-left) / 2;
    temp = mid * mid;
    if(temp == x)
      return mid;
    else if(temp < x)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return right;
}

// TODO: miracle of binary search !!!
