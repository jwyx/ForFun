// DP
int minPathSum(vector<vector<int> > &grid) {
  if (grid.empty() || grid[0].empty())
    return 0;

  vector<int> v(grid[0].size(), 0);
  vector<vector<int> > table(grid.size(), v);

  // base case
  table[0][0] = grid[0][0];
  for (int i = 1; i < table.size(); i ++)
    table[i][0] = table[i-1][0] + grid[i][0];
  for (int j = 1; j < table[0].size(); j ++)
    table[0][j] = table[0][j-1] + grid[0][j];
  for (int i = 1; i < table.size(); i ++) {
    for (int j = 1; j < table[i].size(); j ++) {
      table[i][j] = min(table[i-1][j], table[i][j-1]) + grid[i][j];
    }
  }
  return table.back().back();
}
