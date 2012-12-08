string addBinary(string a, string b) {
  string& l = (a.size() >= b.size() ? a : b);
  string& s = (l == a ? b : a);
  string res;
  int carry = 0;
  int sum = 0;
  int i = 0, j = 0;

  // Note: char vs int
  // it's binary not decimal
  // has more neat version!
  for (i = l.size() - 1, j = s.size() - 1; j >= 0; i--, j--) {
    sum = l[i] - '0' + s[j] - '0' + carry;
    carry = sum / 2;
    sum %= 2;
    res.insert(0, 1, '0' + sum);
  }

  for (; i >= 0; i--) {
    sum = l[i] - '0' + carry;
    carry = sum / 2;
    sum %= 2;
    res.insert(0, 1, '0' + sum);
  }

  if (carry == 1) {
    res.insert(0, 1, '1');
  }

  return res;
}
