// credit: http://blog.csdn.net/maqingli87/article/details/8009464
vector<int> spiralOrder(vector<vector<int> > &matrix) {
  vector<int> result;
  if (matrix.empty() || matrix[0].empty())
    return result;

  int m = matrix.size();
  int n = matrix[0].size();

  for (int k = 0; k < min(m, n)/2; k ++) {
    for (int i = k; i < n - 1 - k; i ++)
      result.push_back(matrix[k][i]);
    for (int j = k; j < m - 1 - k; j ++)
      result.push_back(matrix[j][n - 1 -k]);
    for (int i = k; i < n - 1 - k; i ++)
      result.push_back(matrix[m - 1 - k][n - 1 - i]);
    for (int j = k; j < m - 1 - k; j ++)
      result.push_back(matrix[m - 1 - j][k]);
  }

  int k = min(m, n) / 2;
  if (1 == min(m, n) % 2) {
    if (m > n)
      for (int i = k; i <= m - 1 - k; ++i)
        result.push_back(matrix[i][n / 2]);
    else
      for (int i = k; i <= n - 1 - k; ++i)
        result.push_back(matrix[m / 2][i]);
  }
  return result;
}
