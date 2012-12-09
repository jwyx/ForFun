int firstMissingPositive(int A[], int n) {
  if (!n) return 1;

  int i = 0, j = n - 1, tmp = 0;

  while (i <= j) {
    if (A[i] <= 0)
      i ++;
    else if (A[j] > 0)
      j --;
    else {
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
      i ++;
      j --;
    }
  }

  return find_first_positive(A, i, n - i);
}

int find_first_positive(int A[], int s, int len)
{
  int i = 0;

  for (i = 0; i < len; i ++) {
    if (abs(A[i + s]) > 0 && abs(A[i + s]) <= len)
      if (A[abs(A[i + s]) + s - 1] > 0)
        A[abs(A[i + s]) + s - 1] *= -1;
  }

  for (i = 0; i < len; i ++) {
    if (A[i + s] > 0)
      break;
  }

  return i+1;
}

// credit: http://blog.csdn.net/zhiyu27/article/details/8191129
int firstMissingPositive(int A[], int n) {
  // put i + 1 into A[i] pos
  for (int i = 0; i < n; i ++) {
    while (A[i] != i + 1) {
      if (A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i])
        swap(A[A[i] - 1], A[i]);
      else
        break;
    }
  }
  for (int i = 0; i < n; i ++) {
    if (A[i] != i + 1)
      return i + 1;
  }
  return n + 1;
}
