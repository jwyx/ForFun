// great!!
// credit: http://blog.csdn.net/zhiyu27/article/details/8214582
vector<vector<int> > subsets(vector<int> &S) {
  vector<vector<int> > result;
  sort(S.begin(), S.end());
  result.push_back(vector<int>());
  for (int i = 0; i < S.size(); ++ i) {
    // each iterate!
    for (int j = result.size() - 1; j >= 0; -- j) {
      result.push_back(result[j]);
      result.back().push_back(S[i]);
    }
  }
  return result;
}
