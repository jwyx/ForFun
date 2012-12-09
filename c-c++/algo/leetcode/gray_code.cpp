vector<int> grayCode(int n) {
  vector<int> res;
  if (n >= 0) {
    deque<int> q;

    int base = 1;
    q.push_back(0);
    for (int i = 0; i < n; i ++) {
      // 末位加1, 翻倍
      for (deque<int>::reverse_iterator rit = q.rbegin(); rit != q.rend(); rit ++)
        q.push_back(base + (*rit));
      base <<= 1;
    }
    res.assign(q.begin(), q.end());
  }
  return res;
}

