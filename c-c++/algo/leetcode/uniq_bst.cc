int numTrees(int n) {
  if (0 == n)
    return 1;
  int sum = 0;
  for (int i = 0; i < n; i ++)
    sum += (numTrees(i) * numTrees(n - 1 - i));
  return sum;
}

// memoization, DP from up to bottom
int numTrees(int n) {
  vector<int> buffer (n + 1, -1);
  buffer[0] = 1;
  return numTrees(n, buffer);
}

int numTrees(int n, vector<int> &buffer) {
  // if calculated
  if (buffer[n] > 0)
    return buffer[n];
  else
    return numTreesCalulation(n, buffer);
}

int numTreesCalulation(int n, vector<int> &buffer) {
  int sum = 0;
  for (int i = 0; i < n; i ++)
    sum += (numTrees(i, buffer) * numTrees(n - 1 - i, buffer));
  // store new n
  buffer[n] = sum;
  return sum;
}

// TODO: DP, from bottom to up

// TODO: catalan number
