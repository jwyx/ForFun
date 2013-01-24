// write two integers without using any comparative operators
#include <iostream>
using namespace std;

bool equal(int n1, int n2) {
  return !(n1 - n2);
}

bool equal1(int n1, int n2) {
  return !(n1 & ~n2);
}

int main(void) {
  int n1, n2;
  cin >> n1 >> n2;
  cout << equal(n1, n2) << endl;
  cout << equal1(n1, n2) << endl;
  return 0;
}
