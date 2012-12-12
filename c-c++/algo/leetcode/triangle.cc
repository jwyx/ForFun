// too much time
int minimumTotal(vector<vector<int> > &triangle) {
  if (triangle.empty() || triangle[0].empty())
    return 0;
  int minVal = INT_MAX;
  dfs(triangle, 0, 0, 0, minVal);
  return minVal;
}

void dfs(vector<vector<int> > &triangle, int row, int index, int sum, int &minVal) {
  if (row == triangle.size()) {
    if (sum < minVal)
      minVal = sum;
  }
  else {
    sum += triangle[row][index];
    dfs(triangle, row + 1, index, sum, minVal);
    dfs(triangle, row + 1, index + 1, sum, minVal);
  }
}

// DP
int minimumTotal(vector<vector<int> > &triangle) {
  if (triangle.empty() || triangle[0].empty())
    return 0;
  for (int i = triangle.size() - 2; i >= 0; i --) {
    for (int j = 0; j < triangle[i].size(); j ++)
      triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
  }
  return triangle[0][0];
}
