string countAndSay(int n) {
  string res;
  string tmp;
  int count = 0;
  int size = 0;

  while (n--) {
    if (res.empty())
      res.push_back('1');
    else {
      tmp.clear();
      size = res.size();
      for (int i = 0; i < size; i ++) {
        count = 1;
        while (i + 1 < size && res[i] == res[i + 1]) {
          count += 1;
          i ++;
        }
        // if count > 9 , then have problem
        tmp.push_back(count + '0');
        tmp.push_back(res[i]);
      }
      res = tmp;
    }
  }
  return res;
}
