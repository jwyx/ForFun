#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// do not allocate extra memory
void nextPermutation(vector<int> &num) {
  int i = 0, j = 0;
  for (i = num.size() - 2; i >= 0 && num[i] >= num[i+1]; -- i)
    ;
  // handle all permutations other than last one
  if (i >= 0) {
    for (j = num.size() - 1; j >= 0 && num[j] <= num[i]; -- j)
      ;
    swap(num[i], num[j]);
  }
  reverse(num.begin() + i + 1, num.end());
}

int main(void) {
  int a[] = { 3, 1, 2 };
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  nextPermutation(v);
  for (auto &val : v)
    cout << val;
  cout << endl;
}
