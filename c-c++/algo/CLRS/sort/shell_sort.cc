#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// credit: http://en.wikipedia.org/wiki/Shellsort

// 不稳定
// shell sort 希尔排序
void shell_insert(vector<int> &v, int gap)
{
  int i, j;
  for (i = gap; i < v.size(); i ++)
  {
    int temp = v[i];
    for (j = i; j >= gap && temp < v[j - gap] ; j -= gap)
      v[j] = v[j - gap] ;
    v[j] = temp;
  }
}

void shell_sort(vector<int> &v, const vector<int> &gaps)
{
  for (int k = 0; k < gaps.size(); k ++)
    shell_insert(v, gaps[k]);
}

int main(int argc, char *argv[]) {
  int a[] = { 4, 2, 3, -1, 8 };
  int g[] = { 701, 301, 132, 57, 23, 10, 4, 1 };
  vector<int> v (a, a + sizeof(a) / sizeof(int) );
  vector<int> gaps (g, g + sizeof(g) / sizeof(int) );
  shell_sort(v, gaps);
  for (auto &val : v)
    cout << val << endl;
}

