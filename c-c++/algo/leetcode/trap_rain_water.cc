// credit: http://blog.csdn.net/maqingli87/article/details/8010455
int trap(int A[], int n) {
  if (!A || n <= 0)
    return 0;

  vector<int> left(n, 0), right(n, 0);
  int maxHeight = 0;
  for (int i = 0; i < n; i ++) {
    left[i] = maxHeight;
    maxHeight = max(maxHeight, A[i]);
  }

  maxHeight = 0;
  for (int i = n - 1; i >= 0; i --) {
    right[i] = maxHeight;
    maxHeight = max(maxHeight, A[i]);
  }

  int sum = 0, temp = 0;
  for (int i = 0; i < n; i ++) {
    temp = min(left[i], right[i]) - A[i];
    sum += (temp < 0 ? 0 : temp);
  }

  return sum;
}
