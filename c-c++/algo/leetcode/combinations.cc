vector<vector<int> > combine(int n, int k) {
  vector<int> comb;
  deque<vector<int> > q;
  vector<vector<int> > res;

  if (k > 0 && n > 0) {
    // initialize q
    for (int i = 1; i <= n; i ++) {
      comb.push_back(i);
      q.push_back(comb);
      comb.pop_back();
    }

    vector<int> curr = q.front();
    while (curr.size() < k) {
      int max = curr.back();
      for (int i = max + 1; i <= n; i ++) {
        curr.push_back(i);
        q.push_back(curr);
        curr.pop_back();
      }
      q.pop_front();
      curr = q.front();
    }
  }

  res.assign(q.begin(), q.end());
  return res;
}
// NOTE: vector 作为queue效率很低, out of time
// TODO: 和recursive的区别
