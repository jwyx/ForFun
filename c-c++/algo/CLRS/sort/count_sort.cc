#include <iostream>
#include <vector>

using namespace std;

// input are a small range of integers
// when k = O(n), use it!
void CountSort(vector<int> &v, int k) {
  // extra space need!
  vector<int> counts(k + 1, 0);

  for (int i = 0; i < v.size(); i ++) // O(n)
    counts[v[i]] += 1;

  for (int i = 0, j = 0; i < counts.size(); i ++) { // O(k + n)
    while(counts[i]-- > 0)
      v[j++] = i;
  }
}

int main(int argc, char *argv[]) {
  int a[] = { 1, 0, 0, 3, 2 };
  vector<int> arr (a, a + sizeof(a) / sizeof(int));

  CountSort(arr, 3);

  for (int i = 0; i < arr.size(); i ++)
    cout << arr[i] << " ";
  cout << endl;
}

