#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void insert_sort(vector<int> &arr, size_t left, size_t len) {
  int tmp = 0;
  for (size_t i = left + 1; i < len + left; i ++) {
    tmp = arr[i];
    for (size_t j = i; j > left; j --) {
      if (arr[j - 1] < tmp)
        swap(arr[j], arr[j - 1]);
      else {
        arr[j] = tmp;
        break;
      }
    }
  }
}

int find_median(vector<int> arr) {
  insert_sort(arr, 0, arr.size());
  return arr[arr.size() / 2];
}

size_t find_median_of_median(vector<int> &arr, size_t left, size_t len) {
  assert (!arr.empty());

  vector<int> medians;
  vector<size_t> median_indexes;

  size_t mid = left + len / 2;
  medians.push_back(arr[left]);
  median_indexes.push_back(left);

  medians.push_back(arr[mid]);
  median_indexes.push_back(mid);

  medians.push_back(arr[left + len - 1]);
  median_indexes.push_back(left + len - 1);

  int median_of_median = find_median(medians);
  for (size_t i = 0; i < medians.size(); i ++) {
    if (medians[i] == median_of_median)
      return median_indexes[i];
  }

  assert(false);
  return 0;
}

size_t partition(vector<int> &arr, size_t left, size_t right) {
  assert (left <= right);
  size_t i = left;
  if (left < right) {
    size_t median_pos = find_median_of_median(arr, left, right - left + 1);
    swap(arr[median_pos], arr[right]);
    for (size_t j = i; j < right; j ++) {
      if (arr[j] >= arr[right]) {
        swap(arr[j], arr[i++]);
      }
    }
    swap(arr[i], arr[right]);
  }

  return i;
}

void top_kth_select(vector<int> &arr, size_t left, size_t right, int k) {
  if (k <= 0 || k > right || left > right)
    return;

  size_t p = partition(arr, left, right);
  if (p == k)
    return;
  else if (p < k)
    top_kth_select(arr, p + 1, right, k - p - 1);
  else
    top_kth_select(arr, left, p - 1, k);
}

int main(int argc, char *argv[]) {
  int size = 0;
  cin >> size;

  vector<int> data;
  int tmp = 0;
  while (size > 0) {
    cin >> tmp;
    data.push_back(tmp);
    tmp = 0;
    size --;
  }

  top_kth_select(data, 0, data.size() - 1, 4);

  insert_sort(data, 0, 4);

  for (size_t i = 0; i < 4; i ++) {
    cout << data[i] << endl;
  }
}


