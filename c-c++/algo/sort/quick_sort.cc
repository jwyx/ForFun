#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int> &v, int low, int high) {
  int x = v[high];
  //choise last element as pilot
  int i = low - 1;
  for (int j = low; j < high; j ++) {
    if (v[j] <= x)
      swap(v[++i], v[j]);
  }
  swap(v[++i], v[high]);
  return i;
}

int QuickSort(vector<int> &v, int low, int high) {
  if (low < high) {
    int mid = Partition(v, low, high);
    QuickSort(v, low, mid - 1);
    QuickSort(v, mid + 1, high);
  }
}


int main (int argc, char *argv[]) {
  int a[] = { 3, 1, 2, 6, 5, 2 };
  vector<int> arr (a, a + sizeof(a) / sizeof(int));

  QuickSort(arr, 0, arr.size() - 1);

  for (int i = 0; i < arr.size(); i ++)
    cout << arr[i] << " ";
  cout << endl;
}



