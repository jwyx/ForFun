// 问题：输出所有满足条件的4位数
// 思路：穷举

#include <iostream>

using namespace std;

int get_sum(int n, int divisor)
{
  int sum = 0;
  while (n) {
    sum += n%divisor;
    n /= divisor;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int n = 2992;
  cout << n << endl;

  ++ n;
  while (n < 10000) {
    int sum = get_sum(n, 10);
    if (sum == get_sum(n, 12) && sum == get_sum(n, 16))
      cout << n << endl;

    ++ n;
  }

}
