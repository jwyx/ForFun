// credit: http://blog.csdn.net/zhiyu27/article/details/8218398
vector<vector<int> > generate(int numRows) {
  vector<vector<int> > result;
  if (numRows <= 0)
    return result;
  vector<int> next (1, 1);
  result.push_back(next);
  for (int i = 1; i < numRows; i ++) {
    next.push_back(0);
    // 1, 1 => 1, 2, 1 : 1, 1, 0 ＋ 1, 1
    for (int j = next.size() - 1; j > 0; j --)
      next[j] += next[j - 1];
    result.push_back(next);
  }
  return result;
}
