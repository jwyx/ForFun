// 问题：所有位累加，得到的数，如果是个位数，则输出，否则重复之前的操作，直到输出
// 思路：模拟, 注意输入的数可能很大
//
// 整数的所有位之和对9取余等于该整数本身对9取余
// 证明：将整数按位拆分，321 = 3*100 + 2*10 + 1 = 3*(99 + 1) + 2*(9 + 1) + 1 = (3*11 + 2*1)*9 + (3 + 2 + 1)
// Credit:
//   http://theodore.webege.com/?p=119

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
  string n;
  cin >> n;

  while (n.size() > 1 || n[0] != '0') {
    int result = 0;

    for (int i = 0; i < n.size(); i ++)
      result += n[i]-'0';
    result %= 9;

    if (result == 0)
      result = 9;

    cout << result << endl;

    cin >> n;
  }

}

// FIXME: WA
//int main (int argc, char *argv[])
//{
//  string n, n1;
//  int carry, sum;
//  cin >> n;
//
//  while (n.size() > 1 || n[0] != '0') {
//
//    while (n.size() > 1) {
//      n1 = "0";
//
//      for (int i = n.size()-1; i >= 0; i--) {
//        carry = 0;
//        for (int j = n1.size()-1; j >= 0; j--) {
//          sum = n1[j] - '0' + n[i] - '0' + carry;
//          if (sum > 9) {
//            n1[j] = sum%10 + '0';
//            carry = 1;
//          } else {
//            n1[j] = sum + '0';
//            carry = 0;
//            break;
//          }
//        }
//        if (carry) {
//          n1.insert(0, 1, carry + '0');
//        }
//      }
//
//      n = n1;
//    }
//
//    cout << n << endl;
//
//    cin >> n;
//  }
//}

