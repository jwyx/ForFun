// 问题：解码
// 思路：模拟

#include <iostream>
#include <cstring>

#define N 71

using namespace std;

int main(int argc, char *argv[])
{
  int key = 0;
  char c[N] = { 0 };
  char p[N] = { 0 };
  cin >> key;

  while (key) {
    memset(c, 0, sizeof(c));
    memset(p, 0, sizeof(p));

    cin >> c;

    int len = strlen(c);
    for (int i = 0; i < len; i++) {
      switch(c[i]) {
        case '.': c[i] = 27; break;
        case '_': c[i] = 0; break;
        default: c[i] = c[i] - 'a' + 1; break;
      }
      p[key*i % len] = (c[i] + i) % 28;
    }

    for (int i = 0; i < len; i++) {
      switch(p[i]) {
        case 27: p[i] = '.'; break;
        case 0:  p[i] = '_'; break;
        default: p[i] = p[i] - 1 + 'a'; break;
      }
    }
    cout << p << endl;
    cin >> key;
  }

}
