// 汉诺塔 递归经典题
// 接口hanoi(A,B,C,n): 借助B, 从A到C移动n个塔

#include <iostream>

using namespace std;

void hanoi(char a, char b, char c, int n)
{
  if (n == 1) {
    cout << "Move disk " << n << " from " << a << " to " << c << endl;

  } else {
    hanoi(a, c, b, n-1);
    cout << "Move disk " << n << " from " << a << " to " << c << endl;
    hanoi(b, a, c, n-1);

  }
}

int main (int argc, char *argv[])
{
  int n = 0;
  cin >> n;

  hanoi('A', 'B', 'C', n);
}
