#include <iostream>
#include <ctime>
using namespace std;

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

int main(int argc, char *argv[]) {
  string s("hello worl1");
  time_t start_time = time(0);
  size_t hash = FNVHash(s.c_str());
  cout << hash << " " << (time(0) - start_time) << endl;
}

