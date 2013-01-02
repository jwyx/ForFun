// http://leetcode.com/questions/15/3sum
//
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.

// time: O(n^2)
vector<vector<int> > threeSum(vector<int> &num) {
  sort(num.begin(), num.end());
  int sum = 0;
  int i, j, k;
  vector<vector<int> > v;
  vector<int> elem(3);

  for (i = 0; i < num.size(); i++) {
    j = i + 1;
    k = num.size() - 1;
    while (j < k) {
      sum = num[i] + num[j] + num[k];
      if (0 == sum) {
        elem[0] = num[i];
        elem[1] = num[j];
        elem[2] = num[k];
        v.push_back(elem);
        // move to next different num[k] & num[j]
        while (k > 0 && num[k] == elem[2])
          -- k;
        while (j < num.size() - 1 && num[j] == elem[1])
          ++ j;
      }
      else if (sum > 0)
        -- k;
      else
        ++ j;
    }
    // move to next different num[i]
    while (i < num.size() - 1 && num[i] == num[i + 1])
      ++ i;
  }
  return v;
}

// using built-in set, time: O(n * nlogn)
vector<vector<int> > threeSum(vector<int> &num) {
  sort(num.begin(), num.end());
  int sum = 0;
  int i, j, k;
  set<vector<int> > s;
  vector<vector<int> > v;
  vector<int> elem(3);

  for (i = 0; i < num.size(); i++) {
    j = i + 1;
    k = num.size() - 1;
    while (j < k) {
      sum = num[i] + num[j] + num[k];
      if (0 == sum) {
        elem[0] = num[i];
        elem[1] = num[j];
        elem[2] = num[k];
        s.insert(elem);
        ++ j;
        -- k;
      }
      else if (sum > 0)
        -- k;
      else
        ++ j;
    }
  }
  v.assign(s.begin(), s.end());
  return v;
}

