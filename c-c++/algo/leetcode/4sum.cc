vector<vector<int> > fourSum(vector<int> &num, int target) {
  set<vector<int> > s;
  vector<vector<int> > v;
  vector<int> comb (4);
  int k = 0, l = 0, sum = 0;

  sort(num.begin(), num.end());

  for (int i = 0; i < num.size(); i++) {
    for(int j = i + 1; j < num.size(); j++) {
      k = j + 1;
      l = num.size() - 1;

      while(k < l) {
        sum = num[i] + num[j] + num[k] + num[l];
        if (sum == target) {
          comb[0] = num[i];
          comb[1] = num[j];
          comb[2] = num[k];
          comb[3] = num[l];
          s.insert(comb);
          ++ k;
          -- l;
        }
        else if (sum > target)
          -- l;
        else
          ++ k;
      }
    }
  }
  v.assign(s.begin(), s.end());

  return v;
}
