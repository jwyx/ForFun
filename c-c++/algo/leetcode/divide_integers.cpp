#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

int divide(int dividend, int divisor) {
  int sign_divisor = (divisor < 0 ? -1 : 1);
  int sign_dividend = (dividend < 0 ? -1 : 1);
  int tmp_dividend = abs(dividend);
  int tmp_divisor = abs(divisor);
  int sum = 0;

  while(tmp_divisor <= tmp_dividend) {
    tmp_divisor <<= 1;
  }

  tmp_divisor >>= 1;
  while (tmp_divisor >= sign_divisor * divisor) {
    sum <<= 1;
    if (tmp_dividend >= tmp_divisor) {
      tmp_dividend -= tmp_divisor;
      sum += 1;
    }
    tmp_divisor >>= 1;
  }

  cout << sum << endl;
  if ((sign_divisor ^ sign_dividend + 1) == -1) {
    sum = sum ^ -1 + 1;
  }
  cout << sum << endl;
  return sum ;
}

int main (int argc, char* argv[]) {
  assert(argc >= 3);
  int d1 = atoi(argv[1]);
  int d2 = atoi(argv[2]);
  cout << divide(d1, d2)  << endl;
  return 0;
}

// FIXME: broken
