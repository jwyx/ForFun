// 问题：
// 思路：模拟＋判断不可能的情况，避免死循环

#include <iostream>
#include <cstring>

#define MAX_MINUTE 60

using namespace std;

int main(int argc, char *argv[])
{
  int s, d, result = 0;
  bool flags[MAX_MINUTE] = { false };

  cin >> s >> d;

  while (s > 0 &&  d > 0) {
    result = 0;
    memset(flags, 0, sizeof(flags));

    flags[s] = true;

    while (s != 0) {
      s = (s + d*s) % MAX_MINUTE;
      if (flags[s])
        break;
      flags[s] = true;
      result += 1;
    }

    if (s == 0)
      cout << result << endl;
    else
      cout << "Impossible" << endl;

    cin >> s >> d;
  }

}
