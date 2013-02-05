#include <iostream>
#include <vector>
#include <algorithm>

// 冒泡排序核心思想：两两比较相邻记录的关键字，如果反序则交换，直到没有反序记录为止

using namespace std;

// bubble sort 冒泡／交换排序
// 最好情况O(n-1) = O(n)
// 最坏情况O(n(n-1)/2) = O(n^2)

// V1: 比较正宗的冒泡
void bubble_sort(vector<int> &v)
{
  for (int i = 0; i < v.size(); i ++) {
    for (int j = v.size() - 1; j > i; j --) {
      if (v[j-1] > v[j])
        swap(v[j-1], v[j]);
    }
  }
}

// V2: 优化，如果已经没有逆序，则停止
void bubble_sort1(vector<int> &v)
{
  bool swapped = true;
  for (int i = 0; i < v.size() && swapped; i ++) {
    swapped = false;
    for (int j = v.size() - 1; j > i; j --) {
      if (v[j-1] > v[j]) {
        swap(v[j-1], v[j]);
        swapped = true;
      }
    }
  }
}

// Followup: two side bubble from http://blog.csdn.net/coder_xia/article/details/6615578

int main(int argc, char *argv[]) {
  int a[] = { 4, 2, 3, -1, 8 };
  vector<int> v (a, a + sizeof(a) / sizeof(int) );
  bubble_sort1(v);
  for (auto &val : v)
    cout << val << endl;
}

