#include <iostream>
using namespace std;

// credit: http://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html
/// @brief FNV Hash Function
/// @detail Unix system系统中使用的一种著名hash算法，后来微软也在其hash_map中实现。
template<typename T>
size_t FNVHash(const T* str)
{
  if(!*str)   // 这是由本人添加，以保证空字符串返回哈希值0
    return 0;
  register size_t hash = 2166136261;
  while (size_t ch = (size_t)*str++)
  {
    hash *= 16777619;
    hash ^= ch;
  }
  return hash;
}

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

/// @detail 由于在Unix的Extended Library Function被附带而得名的一种hash算法，它其实就是PJW Hash的变形。
template<typename T>
size_t ELFHash(const T *str)
{
  static const size_t TotalBits       = sizeof(size_t) * 8;
  static const size_t ThreeQuarters   = (TotalBits  * 3) / 4;
  static const size_t OneEighth       = TotalBits / 8;
  static const size_t HighBits        = ((size_t)-1) << (TotalBits - OneEighth);
  register size_t hash = 0;
  size_t magic = 0;
  while (size_t ch = (size_t)*str++)
  {
    hash = (hash << OneEighth) + ch;
    if ((magic = hash & HighBits) != 0)
    {
      hash ^= (magic >> ThreeQuarters);
      hash &= ~magic;
    }
  }
  return hash;
}

// simpler version
size_t ELFHash1(const char *str) {
  unsigned int g, h = 0;
  char *key = const_cast<char *>(str);
  while(*key) {
    h = (h << 4) + (*key++);
    if (g = h & 0xf0000000) {
      // g is unsigned, so right shift add 0
      // effect the last 4 bits with the first 4 bits
      h ^= g >> 24;
      // clear the first 4 bit
      h &= ~g;
    }
  }
  // ensure in the range, use big prime here
  return h;
}

int main(int argc, char *argv[]) {
  string s ("hello world");
  cout << (BKDRHash(s.c_str()) % 100003) << endl;
  cout << (ELFHash(s.c_str()) % 100003) << endl;
  cout << (FNVHash(s.c_str()) % 100003) << endl;
}

