#include <vector>
#include <iostream>
using namespace std;

// improved
int search_boundary(int A[], int left, int right, int target, int isStart) {
  int mid = 0;
  while (left <= right) {
    mid = left + (right - left) / 2;
    // at last, right = left - 1
    if (isStart) {
      // isStart: left = target, right < target
      if (A[mid] == target)
        right = mid - 1;
      else
        left = mid + 1;
    }
    else {
      // not isStart: right > target, left = target
      if (A[mid] == target)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return (isStart ? left : right);
}

vector<int> searchRange(int A[], int n, int target) {
  vector<int> result (2, -1);

  if (n <= 0 || A[n - 1] < target || A[0] > target)
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

  result[0] = search_boundary(A, 0, found, target, true);
  result[1] = search_boundary(A, found, n - 1, target, false);

  return result;
}


int main (void) {
  int a[] = {2, 2};
  vector<int> result = searchRange(a, 2, 2);
  cout << result[0] << " " << result[1] << endl;
}
