#include <vector>
#include <iostream>
#include <algorithm>

// 思路：每一趟在n-i+1(i=1,2,...,n-1)个记录中选取关键字最小的记录作为有序序列的第i个记录

using namespace std;

// select sort
// O(n(n-1)/2) = O(n^2)
void select_sort(vector<int> &v)
{
  // for 0 to len-1
  for (int i = 0; i < v.size(); i ++) {
    // select min
    int min_index = i;
    for (int j = i + 1; j < v.size(); j ++) {
      if (v[min_index] > v[j])
        min_index = j;
    }
    // swap
    swap(v[i], v[min_index]);
  }
}

int main(int argc, char *argv[]) {
  int a[] = { 4, 2, 3, -1, 8 };
  vector<int> v (a, a + sizeof(a) / sizeof(int) );
  select_sort(v);
  for (auto &val : v)
    cout << val << endl;
}
