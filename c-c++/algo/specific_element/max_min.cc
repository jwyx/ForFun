// 3(n/2) comparisons
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> FindMaxMin(vector<int> &v) {
  // if use first element here, than the times of comparison should meet:
  // 比较次数是3(n/2)，如果n为偶数，那比较为3(n/2)-2次
  int max_val = INT_MIN;
  int min_val = INT_MAX;
  int greater = 0;
  int less = 0;
  int i = 0;
  int count = 0;
  for (i = 0; i < v.size(); i += 2) {
    if (i + 1 < v.size()) {
      if (v[i] > v[i + 1]) {
        count ++;
        greater = v[i];
        less = v[i + 1];
      }
      else {
        greater = v[i + 1];
        less = v[i];
      }
    }
    else {
      greater = v[i];
      less = v[i];
    }

    if (greater > max_val)
      max_val = greater;
    if (less < min_val)
      min_val = less;
    count += 2;
  }
  cout << count << endl;
  return pair<int, int>(max_val, min_val);
}

int main (int argc, char *argv[]) {
  int a[] = { 4, 2, 3, -1 };
  vector<int> v (a, a + sizeof(a) / sizeof(int) );
  pair<int, int> res = FindMaxMin(v);
  cout << res.first <<  " " << res.second << endl;
}
