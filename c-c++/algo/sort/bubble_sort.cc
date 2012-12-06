#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bubble sort 冒泡／交换排序
// O(n(n-1)/2) = O(n^2)
void BubbleSort(vector<int> &v)
{
  int len = v.size();
  while(len > 1) {
    // improve
    bool swapped = false;

    // 只处理无序区域, 将最大的数移至数组尾部
    for (int i = 0; i < len - 1; i ++) {
      if (v[i] > v[i + 1]) {
        // swap
        swap(v[i], v[i + 1]);
        swapped = true;
      }
    }
    len--;

    // already finish
    if (!swapped)
      break;
  }
  cout << "len left: " << len << endl;
}

// Followup: two side bubble from http://blog.csdn.net/coder_xia/article/details/6615578

int main(int argc, char *argv[]) {
  int a[] = { 4, 2, 3, -1, 8 };
  vector<int> v (a, a + sizeof(a) / sizeof(int) );
  BubbleSort(v);
  for (auto &val : v)
    cout << val << endl;
}

