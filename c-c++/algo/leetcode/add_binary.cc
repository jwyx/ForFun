string addBinary(string a, string b) {
  string res;
  int carry = 0;
  int sum = 0;
  int i = 0, j = 0;

  for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i --, j --) {
    sum = a[i] - '0' + b[j] - '0' + carry;
    carry = sum / 2;
    sum %= 2;
    res.insert(0, 1, '0' + sum);
  }
  for (; i >= 0; i --) {
    sum = a[i] - '0' + carry;
    carry = sum / 2;
    sum %= 2;
    res.insert(0, 1, '0' + sum);
  }
  for (; j >= 0; j --) {
    sum = b[j] - '0' + carry;
    carry = sum / 2;
    sum %= 2;
    res.insert(0, 1, '0' + sum);
  }
  if (1 == carry)
    res.insert(0, 1, '1');
  return res;
}
