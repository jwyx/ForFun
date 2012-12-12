struct number {
  int val;
  int index;
  number(int v, int i) : val(v), index(i) {}
};

struct comp {
  bool operator() (const number &a, const number &b) {
    return a.val < b.val;
  }
};

vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> result (2, 0);
  vector<number> sortNums;
  for (int i = 0; i < numbers.size(); i ++)
    sortNums.push_back(number(numbers[i], i + 1));
  sort(sortNums.begin(), sortNums.end(), comp());
  int i = 0, j = sortNums.size() - 1;
  while (i < j) {
    if (sortNums[i].val + sortNums[j].val == target) {
      result[0] = min(sortNums[i].index, sortNums[j].index);
      result[1] = max(sortNums[i].index, sortNums[j].index);
      break;
    }
    else if (sortNums[i].val + sortNums[j].val < target)
      ++ i;
    else
      -- j;
  }
  return result;
}
// O(n logn)

