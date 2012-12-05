#include <iostream>
using namespace std;

// credit: http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
/// @brief BKDR Hash Function
/// @detail 本 算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得 名，是一种简单快捷的hash算法，也是Java目前采用的字符串的Hash算法（累乘因子为31）。
template<typename T>
size_t BKDRHash(const T *str) {
  register size_t hash = 0;
  while (size_t ch = (size_t)*str++) {
    hash = hash * 131 + ch; // 也可以乘以31、131、1313、13131、131313..
    // hash = hash << 7 + hash << 1 + hash + ch;
  }
  return hash;
}

int main(int argc, char *argv[]) {
  string s ("hello world");
  cout << BKDRHash(s.c_str()) << endl;
}
