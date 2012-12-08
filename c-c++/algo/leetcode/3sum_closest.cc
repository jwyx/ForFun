int threeSumClosest(vector<int> &num, int target) {
  int res = INT_MAX;
  int min = INT_MAX;
  int j = 0, k = 0, sum = 0, diff = 0;
  // O(n logn)
  sort(num.begin(), num.end());

  // O(n)
  for (int i = 0; i < num.size(); i ++) {
    j = i + 1;
    k = num.size() - 1;
    // O(n)
    while (j < k) {
      sum = num[i] + num[j] + num[k];
      diff = abs(sum - target);

      if (diff < min) {
        res = sum;
        min = diff;
      }

      if (sum >= target)
        -- k;
      else
        ++ j;
    }
  }
  return res;
}
