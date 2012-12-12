int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
  if (obstacleGrid.empty() || obstacleGrid[0].empty())
    return 0;

  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  vector<vector<int> > table(m, vector<int> (n, 0));

  if (!obstacleGrid[0][0])
    table[0][0] = 1;
  for (int i = 1; i < m; i ++)
    if (!obstacleGrid[i][0])
      table[i][0] = table[i - 1][0];
  for (int j = 1; j < n; j ++)
    if (!obstacleGrid[0][j])
      table[0][j] = table[0][j - 1];
  for (int i = 1; i < m; i ++) {
    for (int j = 1; j < n; j ++) {
      if (!obstacleGrid[i][j])
        table[i][j] = table[i - 1][j] + table[i][j - 1];
    }
  }
  return table[m - 1][n - 1];
}

// if grid have obstacle, keep 0, can not reach the right bottom from here
