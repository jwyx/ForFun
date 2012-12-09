int maxSubArray(int A[], int n) {
  int result = INT_MIN, sum = 0;
  for (int i = 0; i < n; i ++) {
    if (sum < 0)
      sum = 0;
    sum += A[i];
    result = max(result, sum);
  }
  return result;
}

// divide and conquer

