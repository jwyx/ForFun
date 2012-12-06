#include <iostream>
#include <vector>

using namespace std;

// the max digit number of all numbers in v is k
// all number is decimal
void RadixSort(vector<int> &v, int k) {
  vector<int> b (v.size(), 0);
  vector<int> c (10, 0);
  int tmp = 0;
  int rate = 1;

  for (int i = 0; i < k; i ++, rate *= 10) {
    c.assign(10, 0);
    for (int j = 0; j < v.size(); j ++) {
      tmp = v[j] / rate % 10;
      c[tmp] += 1;
    }
    for (int j = 1; j < c.size(); j ++)
      c[j] += c[j - 1];
    // NOTE: reverse order, larger number should put near the end
    for (int j = v.size() - 1; j >= 0; j --) {
      tmp = v[j] / rate % 10;
      b[--c[tmp]] = v[j];
    }
    for (int j = 0; j < v.size(); j ++)
      v[j] = b[j];
  }
}

int main(int argc, char *argv[]) {
  int a[] = { 0, 123, 113, 33, 222 };
  vector<int> arr (a, a + sizeof(a) / sizeof(int));

  RadixSort(arr, 3);

  for (int i = 0; i < arr.size(); i ++)
    cout << arr[i] << " ";
  cout << endl;
}
