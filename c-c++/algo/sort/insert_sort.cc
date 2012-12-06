#include <vector>
#include <iostream>
using namespace std;

// O(n^2)
template<typename T>
void InsertSort(vector<T> &v) {
  T tmp;
  size_t j;
  for (size_t i = 1; i < v.size(); i ++) {
    if (v[i] < v[i-1]) {
      tmp = v[i];
      for (j = i - 1; v[j] > tmp; j--)
        v[j+1] = v[j];
      v[j+1] = tmp;
    }
  }
}

template<typename T>
void BInsertSort(vector<T> &v) {
  T tmp;
  for (int i = 1; i < v.size(); i ++) {
    if (v[i] < v[i - 1]) { // it's ncessary
      tmp = v[i];
      int low = 0, high = i;
      // find the point that high + 1 is the first element larger than tmp
      // it success when high has changed at least once
      while(low <= high) {
        int mid = low + (high - low) / 2;
        if (tmp < v[mid])
          high = mid - 1;
        else
          low = mid + 1;
      }
      // should insert to high + 1, so move the rest one position later
      for (int j = i - 1; j > high; j --)
        v[j + 1] = v[j];
      v[high + 1] = tmp;
    }
  }
}

// recursive version
template<typename T>
void BInsertSortRecu(vector<T> &v, int n) {
  if (n > 0) {
    BInsertSortRecu(v, n - 1);

    if (v[n - 1] > v[n]) {
      T tmp = v[n];
      int low = 0, high = n;
      // find the point that high + 1 is the first element larger than tmp
      // it success when high has changed at least once
      while(low <= high) {
        int mid = low + (high - low) / 2;
        if (tmp < v[mid])
          high = mid - 1;
        else
          low = mid + 1;
      }
      // should insert to high + 1, so move the rest one position later
      for (int j = n - 1; j > high; j --)
        v[j + 1] = v[j];
      v[high + 1] = tmp;
    }
  }
}

int main(int argc, char *argv[]) {
  int a[] = { 1, 4, 1, 3, 2 };
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  // InsertSort(v);
  // BInsertSort(v);
  BInsertSortRecu(v, v.size() - 1);
  for (auto &val : v)
    cout << val << endl;
}

// g++-4.7 --std=c++11 insert_sort.cc -o main
