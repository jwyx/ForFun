#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// select sort
// O(n(n-1)/2) = O(n^2)
void SelectSort(vector<int> &v)
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
  SelectSort(v);
  for (auto &val : v)
    cout << val << endl;
}
