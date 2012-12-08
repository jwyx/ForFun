vector<vector<int> > combinationSum2(vector<int> &num, int target) {
  set<vector<int> > res_set;
  vector<int> comb;
  sort(num.begin(), num.end(), greater<int>());
  dfs(num, target, num.size() - 1, comb, res_set);

  vector<vector<int> > res (res_set.begin(), res_set.end());
  return res;
}

void dfs(const vector<int> &num, int T, int n, vector<int> &comb, set<vector<int> > &res_set) {
  if (T < 0)
    return;
  else if (n < 0 && T != 0)
    return;

  if (n < 0)
    res_set.insert(comb);
  else {
    // include n
    comb.push_back(num[n]);
    dfs(num, T - num[n], n - 1, comb, res_set);
    comb.pop_back();

    // not include n
    dfs(num, T, n - 1, comb, res_set);
  }
}

// TODO: iterative version, how to do DP
