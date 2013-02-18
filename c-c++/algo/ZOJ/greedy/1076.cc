// 思路：类似于会议安排，选择结束时间最早的贪心

#include <iostream>
#include <algorithm>

#define N 1000

using namespace std;

struct exons {
  long start; // choose long because at most 50000 basis
  long end;
  int pos;
};

bool comp(const exons &a, const exons &b) {
  return (a.end <= b.end);
}

int main(int argc, char *argv[])
{
  int n = 0;
  exons data[N];
  cin >> n;

  while (n) {

    for (int i = 0; i < n; i++) {
      cin >> data[i].start >> data[i].end;
      data[i].pos = i+1;
    }

    sort(data, data + n, comp);

    long end = data[0].end;
    cout << data[0].pos;
    for (int i = 1; i < n; i++) {
      if (end <= data[i].start) {
        cout << " " << data[i].pos;
        end = data[i].end;
      }
    }
    cout << endl;

    cin >> n;
  }
}
