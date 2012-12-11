// credit : http://blog.csdn.net/zhiyu27/article/details/8207898
// time: O(m*n), space: O(1)
void setZeroes(vector<vector<int> > &matrix) {
  if (matrix.empty() || matrix[0].empty())
    return;
  // next 记录之前的所有额外的0数
  // count 减去当前遇到的0数
  int count = 0, next = 0;
  for (int i = 0; i < matrix.size() - 1; ++ i) {
    for (int j = 0; j < matrix[i].size(); ++ j) {
      if (matrix[i][j] == 0) {
        -- count;
        // 将之前行的0都记录到下一行
        if (matrix[i+1][j] != 0)
          ++ next;
        matrix[i+1][j] = 0;
      }
    }
    if (count < 0)
      matrix[i].assign(matrix[i].size(), 0);
    // 消除前面所有行产生0的影响
    count = next;
    next = 0;
  }
  // 处理所有列
  for (int j = 0; j < matrix.back().size(); ++ j) {
    if (matrix.back()[j] == 0) {
      -- count;
      for (int k = 0; k < matrix.size() - 1; ++ k)
        matrix[k][j] = 0;
    }
  }
  if (count < 0)
    matrix.back().assign(matrix.back().size(), 0);
}
