int numTrees(int n) {
  if (0 == n)
    return 1;
  int sum = 0;
  for (int i = 0; i < n; i ++)
    sum += (numTrees(i) * numTrees(n - 1 - i));
  return sum;
}
