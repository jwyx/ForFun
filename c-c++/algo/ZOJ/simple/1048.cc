// Financial Management

#include <iostream>
using namespace std;

int main ()
{
  float balance_total = 0.0;
  float balance = 0.0;
  int num = 12;
  while (num --) {
    cin >> balance;
    balance_total += balance;
  }
  cout << "$" << (balance_total/12.0) << endl;
}
