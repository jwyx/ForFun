vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
  vector<vector<int> > res;
  int sum = 0;
  vector<int> comb;
  // 递减
  sort(candidates.begin(), candidates.end(), greater<int>());
  dfs(candidates, 0, sum, comb, target, res);
  return res;
}

void dfs(const vector<int> &candidates, int start_index, int sum, vector<int> &comb, const int target, vector<vector<int> > &res) {
  if (sum > target)
    return;
  else if (sum == target)
    res.push_back(comb);
  else {
    for (int i = start_index; i < candidates.size(); i ++) {
      comb.insert(comb.begin(), candidates[i]);
      // i 保证答案没有重复
      dfs(candidates, i, sum + candidates[i], comb, target, res);
      comb.erase(comb.begin());
    }
  }
}
