vector<int> getRow(int rowIndex) {
  vector<int> next;
  if (rowIndex < 0)
    return next;
  next.push_back(1);
  for (int i = 0; i < rowIndex; i ++) {
    next.push_back(0);
    for (int j = next.size() - 1; j > 0; -- j)
      next[j] += next[j-1];
  }
  return next;
}
// O(rowIndex)
