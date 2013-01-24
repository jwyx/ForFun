#include <iostream>
using namespace std;

// if a is signed and it overflow
//  what will happend when if shift back?
//    the value of sign bit affects the sign of this new value

int main(void) {
  // int a = 6;
  int a = 7;
  a <<= 31;
  a >>= 31;
  cout << a << endl;
}
