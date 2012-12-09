bool isInterleave(string s1, string s2, string s3) {
  if (s3.size() != s1.size() + s2.size())
    return false;

  // if s1[m] == s3[l] or s2[n] == s3[l]
  // table[l][m][n] = max(table[l-1][m-1][n], table[l-1][m][n-1])
  //
  // base case:
  // table[0][0][0] = 1
  // table[i][0][i] = min(table[i-1][0][i-1], (s3[i] == s2[i] ? 1 : 0)), table[j][j][0], i = 0..n, j = 0..m

  vector<int> v1 (s1.size() + 1, 0);
  vector<vector<int> > v2 (s2.size() + 1, v1);
  vector<vector<vector<int> > > table (s3.size() + 1, v2);

  // base cases
  table[0][0][0] = 1;
  for (int i = 1; i <= s1.size(); i ++)
    table[i][0][i] = min(table[i-1][0][i-1], (s3[i - 1] == s1[i - 1] ? 1 : 0));
  for (int j = 1; j <= s2.size(); j ++)
    table[j][j][0] = min(table[j-1][j-1][0], (s3[j - 1] == s2[j - 1] ? 1 : 0));

  for (int k = 1; k <= s3.size(); k ++) {
    for (int j = 1; j <= s2.size(); j ++) {
      for (int i = 1; i <= s1.size(); i ++) {
        table[k][j][i] = max(
            min(table[k-1][j-1][i], (s3[k - 1] == s2[j - 1] ? 1 : 0)),
            min(table[k-1][j][i-1], (s3[k - 1] == s1[i - 1] ? 1 : 0)));
      }
    }
  }
  return table[s3.size()][s2.size()][s1.size()];
}

// improve memory
bool isInterleave(string s1, string s2, string s3) {
  if (s3.size() != s1.size() + s2.size())
    return false;

  // if s1[m] == s3[l] or s2[n] == s3[l]
  // table[l][m][n] = max(table[l-1][m-1][n], table[l-1][m][n-1])
  // table[i][0][i] = min(table[i-1][0][i-1], (s3[i] == s2[i] ? 1 : 0)), table[j][j][0], i = 0..n, j = 0..m
  //
  // base case:
  // table[0][0][0] = 1

  vector<int> v1 (s1.size() + 1, 0);
  vector<vector<int> > v2 (s2.size() + 1, v1);
  vector<vector<vector<int> > > table (2, v2);

  // base cases
  table[0][0][0] = 1;

  for (int k = 1; k <= s3.size(); k ++) {
    int curr = k % 2;
    int prev = (k - 1) % 2;
    table[curr] = v2;

    if (k >= 1 && k <= s1.size())
      table[curr][0][k] = min(table[prev][0][k-1], (s3[k - 1] == s1[k - 1] ? 1 : 0));
    if (k >= 1 && k <= s2.size())
      table[curr][k][0] = min(table[prev][k-1][0], (s3[k - 1] == s2[k - 1] ? 1 : 0));

    for (int j = 1; j <= s2.size(); j ++) {
      for (int i = 1; i <= s1.size(); i ++) {
        table[curr][j][i] = max(
            min(table[prev][j-1][i], (s3[k - 1] == s2[j - 1] ? 1 : 0)),
            min(table[prev][j][i-1], (s3[k - 1] == s1[i - 1] ? 1 : 0)));
      }
    }
  }
  return table[s3.size() % 2][s2.size()][s1.size()];
}

// TODO: v2 can be 2, also

// better!!
// credit: http://blog.csdn.net/zhiyu27/article/details/8192565
bool isInterleave(string s1, string s2, string s3) {
  if (s3.size() != s1.size() + s2.size())
    return false;

  // because s3.size() == s1.size() + s2.size(), so only two vairables
  // table[m][n] is: whether s3 is formed by the interleaving of s1[0..n-1] and s2[0..m-1]
  vector<int> v1 (s1.size() + 1, false);
  vector<vector<int> > table (s2.size() + 1, v1);

  // base cases
  table[0][0] = true;

  for (int i = 1; i <= s1.size(); i ++)
    table[0][i] = table[0][i-1] && (s3[i-1] == s1[i-1]);
  for (int j = 1; j <= s2.size(); j ++)
    table[j][0] = table[j-1][0] && (s3[j-1] == s2[j-1]);

  for (int j = 1; j <= s2.size(); j ++) {
    for (int i = 1; i <= s1.size(); i ++) {
      table[j][i] = table[j-1][i] && (s3[i+j-1] == s2[j-1]) || table[j][i-1] && (s3[i+j-1] == s1[i-1]);
    }
  }
  return table[s2.size()][s1.size()];
}
