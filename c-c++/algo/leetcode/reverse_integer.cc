//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//Have you thought about this?
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//
//Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
//
#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

int reverse(int x) {
  long y = 0;

  if (!x)
    return 0;
  int sign = 1;
  if (x < 0) {
    sign = -1;
    x = abs(x);
  }
  while (x > 0) {
    // handle exception
    y = y * 10 + x % 10;
    x /= 10;
  }
  y *= sign;
  assert(y <= INT_MAX && y >= INT_MIN);
  return y;
}

int main(void) {
  cout << reverse(1000000003) << endl;
}
