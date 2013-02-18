// 问题：给出两个罐子，允许倒满，清空，互相之间倒水，求出给定水量的一个倒水方案
// 思路：模拟，数论，不定方程

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int a, b, ca, cb, n;

  while (cin >> ca) {
    cin >> cb >> n;
    b = 0;

    while (b != n) {
      b += ca;
      cout << "fill A" << endl;
      cout << "pour A B" << endl;

      if (b > cb) {
        b -= cb;
        cout << "empty B" << endl;
        cout << "pour A B" << endl;
      }
    }
    cout << "success" << endl;
  }
}
