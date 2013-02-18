// Credit
//    http://blog.csdn.net/immortality/article/details/1695296

#include <iostream>
#include <algorithm>
#include <cstring>

#define N 201

using namespace std;

int main(int argc, char *argv[])
{
  int count = 0, n = 0, start = 0, end = 0, result = 0;
  int data[N] = { 0 };
  cin >> count;

  while (count--) {
    cin >> n;

    result = 0;
    // sizeof已经返回byte数
    memset(data, 0, sizeof(data));

    for (int i = 0; i < n; i ++) {
      cin >> start >> end;
      if (start > end)
        swap(start, end);
      start = (start+1) / 2;
      end = (end+1) / 2;
      for (int j = start; j <= end; j++)
        data[j] += 1;
    }
    // 直接通过计数得到重叠部分的不同程度，然后将其分层
    result = *max_element(data+1, data+N);
    cout << result*10 << endl;
  }
}
