#include <iostream>
using namespace std;

// credit : http://blog.csdn.net/maqingli87/article/details/8009186
int search(int A[], int n, int target) {
  if (n <= 0 || !A)
    return -1;

  int left = 0, right = n - 1, mid = -1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (A[mid] == target)
      return mid;
    else if (A[mid] > A[right]) { // left
      if (A[left] <= target && target < A[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    else {
      if (target <= A[right] && target > A[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return -1;
}

// if i use A[left], work!!!
int search(int A[], int n, int target) {
  if (n <= 0 || !A)
    return -1;

  int left = 0, right = n - 1, mid = -1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (A[mid] == target)
      return mid;
    else if (A[mid] < A[left]) { // left
      if (A[mid] < target && target <= A[right])
        left = mid + 1;
      else
        right = mid - 1;
    }
    else {
      if (target < A[mid] && target >= A[left])
        right = mid - 1;
      else
        left = mid + 1;
    }
  }
  return -1;
}

// if I only found pivot, TODO!

int main(void) {
  int a[] = { 4,5,6,7,0,1,2 };
  cout << search(a, sizeof(a)/sizeof(int), 0) << endl;;
  for (auto &val : a)
    cout << val << " ";
  cout << endl;
}
