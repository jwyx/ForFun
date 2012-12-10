// credit: http://www.mitbbs.com/article_t/JobHunting/32084397.html
string multiply(string num1, string num2) {
  vector<int> res(num1.size() + num2.size(), 0);
  for (int i = 0; i < num1.size(); i++) {
    int carry = 0;
    for (int j = 0; j < num2.size(); j++) {
      int d1 = num1[num1.size() - 1 - i] - '0';
      int d2 = num2[num2.size() - 1 - j] - '0';
      carry = d1 * d2 + res[i + j] + carry;
      res[i + j] = carry % 10;
      carry = carry / 10;
    }
    // put carry in result, reset carry
    // high to low in res is from end to front
    res[i + num2.size()] = carry;
  }

  int i = num1.size() + num2.size() - 1;
  // clear all zero in the high digit, except the last digit
  while (i > 0 && res[i] == 0)
    i--;

  string result;
  while (i >= 0)
    result += char(res[i --] + '0');
  return result;
}
