int minDistance(string word1, string word2) {
  const int n = word1.size();
  const int m = word2.size();
  // 对于matrix的创建, 可以使用此方法, 竟然数组有局限性
  vector<int> row (m + 1, 0);
  vector<vector<int> > table (n + 1, row);

  // base case
  for (int i = 0; i <= n; i ++)
    table[i][m] = n - i;

  for (int j = 0; j <= m; j ++)
    table[n][j] = m - j;

  for (int i = n - 1; i >= 0; i --) {
    for (int j = m - 1; j >= 0; j --) {
      if (word1[i] == word2[j])
        table[i][j] = table[i + 1][j + 1];
      else {
        // NOTE: 此处需要考虑替换
        table[i][j] = 1 + min(table[i + 1][j], table[i][j + 1]);
        table[i][j] = min(table[i][j], 1 + table[i + 1][j + 1]);
      }
    }
  }

  return table[0][0];
}

// 从i到结束，和 从j到结束的两个字符串比较
