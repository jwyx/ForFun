// credit : http://blog.csdn.net/zhiyu27/article/details/8214616
vector<vector<int> > subsetsWithDup(vector<int> &S) {
  vector<vector<int> > result(1, vector<int> ()), added;
  if (S.empty())
    return result;
  sort(S.begin(), S.end());
  for (int i = 0; i < S.size(); i ++) {
    if (i > 0 && S[i] == S[i - 1]) {
      // only process newly added last time
      for (int j = 0; j < added.size(); j ++) {
        // IMPORTANT: save the state
        added[j].push_back(S[i]);
        result.push_back(added[j]);
      }
    }
    else {
      added.clear();
      for (int j = result.size() - 1; j >= 0; j --) {
        result.push_back(result[j]);
        result.back().push_back(S[i]);
        // store newly added this time
        added.push_back(result.back());
      }
    }
  }
  return result;
}
