int removeDuplicates(int A[], int n) {
  if (n <= 1)
    return n;
  int curr = 1; // compare with the element before the end
  for (int i = 2; i < n; ++ i) {
    if (A[curr - 1] != A[i])
      A[++curr] = A[i];
  }
  return curr + 1;
}
