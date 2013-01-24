#include <iostream>
using namespace std;

// 1. 取平方
size_t IntHash(int key) {
  // overflow is ok
  unsigned int h = key * key;
  return h % 3001;
}

// Credit: blog.csdn.net/v_july_v/article/details/6256463
// 2. Fabonacci hash
// 16 bits: 40503
// 32 bits: 2654435769
// 64 bits: 11400714819323198485
size_t IntHash1(int key) {
  unsigned int h = key * 2654435769;
  // should be the size of array
  return h % 3001;
}

int main(int argc, char *argv[]) {
  unsigned t;
  cin >> t;
  size_t hash = IntHash1(t);
  cout << hash << endl;
}
