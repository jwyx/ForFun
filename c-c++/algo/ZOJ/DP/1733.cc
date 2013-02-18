// 问题：求最长公共子序列
// 思路：DP，dp[i][j] a串中前i个字符和b串中前j个字符的公共最长子序列长度

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  string a, b, line;
  vector<vector<int> > dp;

  while (cin >> a) {
    cin >> b;

    dp = vector<vector<int> >(a.size()+1, vector<int>(b.size()+1, 0));
    for (int i = 1; i <= a.size(); i++) {
      for (int j = 1; j <= b.size(); j++) {
        if (a[i-1] == b[j-1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }

    cout << dp[a.size()][b.size()] << endl;
  }

}
