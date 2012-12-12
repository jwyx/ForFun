vector<vector<int> > generateMatrix(int n) {
  vector<vector<int> > result(n, vector<int>(n, 0));
  int num = 1;
  for (int k = 0; k < n / 2; k ++) {
    for (int i = k; i < n - 1 - k; i ++)
      result[k][i] = num++;
    for (int j = k; j < n - 1 - k; j ++)
      result[j][n - 1 -k] = num++;
    for (int i = k; i < n - 1 - k; i ++)
      result[n - 1 - k][n - 1 - i] = num++;
    for (int j = k; j < n - 1 - k; j ++)
      result[n - 1 - j][k] = num++;
  }

  if (n % 2 == 1)
    result[n / 2][n / 2] = num;

  return result;
}
