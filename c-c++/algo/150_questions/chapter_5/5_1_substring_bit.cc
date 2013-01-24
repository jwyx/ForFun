#include <iostream>
using namespace std;

int updateBits(int n, int m, int i, int j) {
  int maxVal = ~0;
  int left = maxVal - ((1 << j) - 1);
  int right = (1 << i) - 1;
  int mask = left | right;
  return (n & mask) | (m << i);
}

int main(void) {
  int n = 0x0400;
  int m = 0x0015;
  int i = 2;
  int j = 6;
  cout << "0x" << hex << updateBits(n, m, i, j) << endl;
}

