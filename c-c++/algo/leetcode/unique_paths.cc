int uniquePaths(int m, int n) {
  long long result = 1;
  for (int i = m + n - 2; i > max(m, n) - 1; -- i)
    result *= i;
  for (int i = min(m, n) - 1; i >= 1; -- i)
    result /= i;
  return result;
}

int uniquePaths(int m, int n) {
  vector<vector<int> > table(m, vector<int> (n, 0));

  table[0][0] = 1;
  for (int i = 1; i < m; i ++)
    table[i][0] = table[i - 1][0];
  for (int j = 1; j < n; j ++)
    table[0][j] = table[0][j - 1];
  for (int i = 1; i < m; i ++) {
    for (int j = 1; j < n; j ++) {
      table[i][j] = table[i - 1][j] + table[i][j - 1];
    }
  }
  return table[m - 1][n - 1];
}
