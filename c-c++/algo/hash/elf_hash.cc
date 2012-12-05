#include <string>
#include <iostream>
#include <ctime>
using namespace std;

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
  string s("hello worl1");
  time_t start_time = time(0);
  size_t hash = ELFHash(s.c_str());
  cout << hash << " " << (time(0) - start_time) << endl;
}
