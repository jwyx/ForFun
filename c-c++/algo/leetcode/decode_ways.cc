int numDecodings(string s) {
  int n = s.size();
  int* counts = new int[n+1];
  int res = 0;

  for (int i = 1; i <= min(n, 1); i ++) {
    counts[i] = valid_code(s, i - 1, i - 1);
  }

  for (int i = 2; i <= min(n, 2); i ++) {
    counts[i] = valid_code(s, i - 2, i - 1) +
      valid_code(s, i - 1, i - 1) * counts[i - 1];
  }

  for (int i = 3; i <= n; i ++) {
    counts[i] = valid_code(s, i - 2, i - 1) * counts[i - 2] +
      valid_code(s, i - 1, i - 1) * counts[i - 1];
  }

  res = counts[n];
  delete [] counts;
  return res;
}

// 1 valid, 0 not valid
int valid_code(string &s, int start, int end) {
  if (start > end)
    return 0;
  else {
    string tmp (s, start, end - start + 1);
    int num = atoi(tmp.c_str());

    if (end - start == 0) {
      if (num <= 9 && num > 0)
        return 1;
      else
        return 0;
    }
    else {
      if (num <= 26 && num >= 10)
        return 1;
      else
        return 0;
    }
  }
}

// fabonacci modified version!!!
// credit: http://blog.csdn.net/zhiyu27/article/details/8190380

int numDecodings(string s) {
  int a = 1, b = 1;
  // zero or one element
  if (s.empty() || '0' == s[0])
    return 0;
  // two elements
  for (int i = 1; i < s.size(); i ++) {
    int tmp = a;
    // new f(n-1)
    if ('0' == s[i])
      a = 0;
    // f(n-2) 判断
    int d2 = (s[i-1]-'0')*10 + (s[i]-'0');
    // new f(n) = f(n-1) + f(n-2)
    if (d2 >= 10 && d2 <= 26)
      a += b;
    // new f(n-2)
    b = tmp;
    // not possible
    if (!a && !b)
      break;
  }
  return a;
}
