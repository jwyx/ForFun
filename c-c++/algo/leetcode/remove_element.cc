int removeElement(int A[], int n, int elem) {
  int curr = -1;
  for (int i = 0; i < n; i ++) {
    if (A[i] != elem)
      A[++ curr] = A[i];
  }
  return curr + 1;
}
