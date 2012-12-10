// Tip: from back to front
void merge(int A[], int m, int B[], int n) {
  for (int k = m + n - 1, i = m - 1, j = n - 1; k >= 0; -- k) {
    if (i >= 0 && j >= 0) {
      if (A[i] > B[j])
        A[k] = A[i--];
      else
        A[k] = B[j--];
    }
    else if (j >= 0)
      A[k] = B[j--];
  }
}
