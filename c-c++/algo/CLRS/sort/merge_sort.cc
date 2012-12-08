#include <vector>
#include <iostream>
#include <climits>

// credit: http://blog.csdn.net/coder_xia/article/details/6615578
using namespace std;

// with sentinel
void Merge(vector<int> &v, int low , int mid, int high) {
  // store length
  int n1 = mid - low + 1; // include mid
  int n2 = high - mid;
  int i, j, k;

  vector<int> l, r;

  // store data
  for (i = 0; i < n1; i ++)
    l.push_back(v[low + i]);
  for (j = 0; j < n2; j ++)
    r.push_back(v[mid + j + 1]);

  // sentinel
  l.push_back(INT_MAX);
  r.push_back(INT_MAX);

  // merge
  for (i = 0, j = 0, k = low; k <= high; k ++) {
    if (l[i] <= r[j])
      v[k] = l[i++];
    else
      v[k] = r[j++];
  }
}

// without sentinel
void MergeNo(vector<int> &v, int low , int mid, int high) {
  // store length
  int n1 = mid - low + 1; // include mid
  int n2 = high - mid;
  int i, j, k;

  vector<int> l, r;

  // store data
  for (i = 0; i < n1; i ++)
    l.push_back(v[low + i]);
  for (j = 0; j < n2; j ++)
    r.push_back(v[mid + j + 1]);

  // merge
  for (i = 0, j = 0, k = low; i < n1 && j < n2; k ++) {
    if (l[i] <= r[j])
      v[k] = l[i++];
    else
      v[k] = r[j++];
  }

  // handle the rest
  while (i < n1)
    v[k++] = l[i++];
  while (j < n2)
    v[k++] = r[j++];
}

void MergeSort(vector<int> &v, int low, int high) {
  if (low < high) {
    // divide and conquer
    int mid = low + (high - low) / 2;
    MergeSort(v, low, mid);
    MergeSort(v, mid + 1, high);
    // combine
    Merge(v, low, mid, high);
    // MergeNo(v, low, mid, high);
  }
}

int main(int argc, char *argv[]) {
  int a[] = { 1, 4, 1, 3, 2, 2 };
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  MergeSort(v, 0, v.size() - 1);
  for (auto &val : v)
    cout << val << endl;
}
