#include <vector>
#include <iostream>
using namespace std;

// TODO: 重构
int bs_boundary(int A[], int left, int right, int target, bool asc) {
  int mid = 0;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (A[mid] == target &&\
        (!asc && (mid - 1 >= left && A[mid - 1] < target || mid == left) ||\
        (asc && (mid + 1 <= right && A[mid + 1] > target || mid == right))))
      return mid;
    else if (A[mid] > target || A[mid] == target && !asc)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return mid;
}

vector<int> searchRange(int A[], int n, int target) {
  vector<int> result (2, -1);

  if (n <= 0)
    return result;

  int left = 0, right = n - 1, mid = 0, found = -1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (A[mid] == target) {
      found = mid;
      break;
    }
    else if (A[mid] > target)
      right = mid - 1;
    else
      left = mid + 1;
  }

  if (found < 0)
    return result;

  result[0] = bs_boundary(A, 0, found, target, false);
  result[1] = bs_boundary(A, found, n - 1, target, true);

  return result;
}


int main (void) {
  int a[] = {2, 2};
  vector<int> result = searchRange(a, 2, 2);
  cout << result[0] << " " << result[1] << endl;
}
