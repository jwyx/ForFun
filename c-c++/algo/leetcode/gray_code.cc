vector<int> grayCode(int n) {
  vector<int> res;
  if (n >= 0) {
    // deque is necessary, if you use iterator
    deque<int> q;
    int base = 1;
    q.push_back(0);
    for (int i = 0; i < n; i ++) {
      // 末位加1, 翻倍
      for (deque<int>::reverse_iterator rit = q.rbegin(); rit != q.rend(); rit ++)
        // why valid?
        q.push_back(base + (*rit));
      base <<= 1;
    }
    res.assign(q.begin(), q.end());
  }
  return res;
}

// rewrite!! work!
// the operater[] is safe !!
// but the iterator is not , if you change the vector
vector<int> grayCode(int n) {
  vector<int> res;
  if (n >= 0) {
    int base = 1;
    res.push_back(0);
    for (int i = 0; i < n; ++ i) {
      // 末位加1, 翻倍
      for (int j = res.size() - 1; j >= 0; -- j)
        // why valid?
        res.push_back(base + res[j]);
      base <<= 1;
    }
  }
  return res;
}
