vector<vector<int> > permute(vector<int> &num) {
  vector<vector<int> > result;
  sort(num.begin(), num.end());
  result.push_back(num);
  while (nextPermutation(num, result))
    ;
  return result;
}

bool nextPermutation(vector<int> &num, vector<vector<int> > &result) {
  int i = 0, j = 0;
  for (i = num.size() - 2; i >= 0 && num[i] >= num[i + 1]; -- i)
    ;
  if (i < 0)
    return false;
  for (j = num.size() - 1; j >= 0 && num[i] >= num[j]; -- j)
    ;
  swap(num[i], num[j]);
  reverse(num.begin() + i + 1, num.end());
  result.push_back(num);
  return true;
}

