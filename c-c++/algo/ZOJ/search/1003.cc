// 问题：检查两个数存在不重叠的因子集合
// 思路：回溯法
//
// Credit:
//    http://www.blog.smilingsteve.org/?p=204

#include <iostream>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

void dfs(const int a, const int b, const int divisor, bool &a_flag, bool &b_flag)
{
  // 标记状态位, 如果b计算正确，才考虑是否a也计算正确
  if (b == 1) {
    if (a == 1) a_flag = true;
    b_flag = true;
  }

  // 如果找到了答案，就不再处理
  if (a_flag && b_flag || divisor > MAX_NUM || (a<divisor && b<divisor))
    return;

  // 同一个数只能做一个数的因子或者不是任何数的因子
  if (a % divisor == 0)
    dfs(a/divisor, b, divisor+1, a_flag, b_flag);

  if (b % divisor == 0)
    dfs(a, b/divisor, divisor+1, a_flag, b_flag);

  dfs(a, b, divisor+1, a_flag, b_flag);
}

int main(int argc, char *argv[])
{
  int a = 0, b = 0;

  while (cin >> a >> b) {
    bool a_flag = false;
    bool b_flag = false;

    // 将较大值放在a
    if (b > a)
      swap(a, b);

    dfs(a, b, 2, a_flag, b_flag);

    if (b_flag && !a_flag)
      cout << b << endl;
    else
      cout << a << endl;
  }
}
