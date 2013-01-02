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

    // not include n
    comb.pop_back();
    dfs(num, T, n - 1, comb, res_set);
  }
}

// iterative !!, bad space

bool isSumEqualToTarget(vector<int> &comb, int target) {
  int sum = 0;
  for (vector<int>::iterator it = comb.begin(); it != comb.end(); ++ it) {
    sum += *it;
  }
  return (sum == target);
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
  vector<vector<int> > temp_result;

  if (!num.size())
    return temp_result;

  sort(num.begin(), num.end());
  int prev_val = num.front();
  vector<vector<int> > prev_step (1, vector<int>());

  temp_result.assign(1, vector<int>());
  for (vector<int>::iterator it = num.begin(); it != num.end(); ++ it) {
    if (*it == prev_val) {
      for (vector<vector<int> >::reverse_iterator rit = prev_step.rbegin(); rit != prev_step.rend(); ++ rit)
        (*rit).push_back(*it);
    }
    else {
      prev_step.clear();
      for (vector<vector<int> >::reverse_iterator rit = temp_result.rbegin(); rit != temp_result.rend(); ++ rit) {
        (*rit).push_back(*it);
        prev_step.push_back(*rit);
        (*rit).pop_back();
      }
    }
    prev_val = *it;
    temp_result.insert(temp_result.end(), prev_step.begin(), prev_step.end());
  }

  vector<vector<int> > result;
  for (vector<vector<int> >::iterator it = temp_result.begin(); it != temp_result.end(); ++ it) {
    if (isSumEqualToTarget(*it, target))
      result.push_back(*it);
  }

  return result;
}
