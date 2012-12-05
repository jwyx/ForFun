#include <iostream>
using namespace std;

size_t IntHash(int key) {
  // overflow is ok
  unsigned int h = key * key;
  return h % 3001;
}

int main(int argc, char *argv[]) {
  size_t hash = IntHash(50000);
  cout << hash << endl;
}
