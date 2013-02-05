// Gridland
//
// Question:
//   旅行者问题
//
// Solution:
//   枚举

#include <iostream>
#include <iomanip>
using namespace std;

// 画出m,n不同情况下的解题方案
// 证明为最短，然后直接计算路径长
// 4 * 4
// * - * - * - *
// |           |
// *   * - * - *
// |   |
// *   * - * - *
// |           |
// * - * - * - *
//
// 3 * 3
// * - * - *
// |       |
// * - *   *
//   /     |
// * - * - *
// 证明：不存在没有对角线的方案??
//
// 3 * 4
// * - *   * - *
// |   |   |   |
// *   * - *   *
// |           |
// * - * - * - *
// 证明：构成解，且值最小，而且能扩展

float solve1(int m, int n)
{
  if (m % 2 == 0 || n % 2 == 0)
    return m * n;
  else
    return m * n + 1.41 - 1.0; //sqrt(2) - 1
}

int main ()
{
  int num = 0;
  int m = 0, n = 0;

  cin >> num;
  for (int i = 1; i <= num; i ++) {
    cin >> m >> n;
    cout << "Scenario #" << i << ":" << endl;
    cout << setiosflags(ios::fixed) << setprecision(2) << solve1(m, n) << endl << endl;
  }
  return 0;
}
