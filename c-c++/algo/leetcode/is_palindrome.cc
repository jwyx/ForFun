#include <iostream>
using namespace std;

bool isPalindrome(int x) {
  if (x < 0)
    return false;
  long long small = 1;
  long long big = 10;
  while(big <= x)
    big *= 10;
  big /= 10;
  while (small <= big) {
    if (x/big%10 == x/small%10) {
      small *= 10;
      big /= 10;
    }
    else
      return false;
  }
  return true;
}

int main(void) {
  int x = 0;
  cin >> x;
  cout << isPalindrome(x) << endl;
}
