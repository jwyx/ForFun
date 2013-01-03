#include <iostream>
using namespace std;

// credit : http://blog.csdn.net/maqingli87/article/details/8009281
int searchInsert(int A[], int n, int target) {
  if(!A || 0 == n)
    return 0;
  int left = 0, right = n-1, mid = 0;
  while(left <= right) {
    // finally, left + 1 = right
    // mid = left, and have two situations:
    //  target < A[mid], then right = left-1
    //  target > A[mid], then left = right
    mid = left + (right-left)/2;
    if(target == A[mid])
      return mid;
    else if(target < A[mid])
      right = mid - 1;
    else
      left = mid + 1;
      // 如果没有找到target：那么left - 1指向小于target的最大的数，right + 1 指向大于target的最小的数
      // cout << left - 1 << " " << right + 1 << endl;
  }
  return left;
}

int main (void) {
  int a[] = { 1,3,5 };
  cout << searchInsert(a, sizeof(a)/sizeof(int), 2) << endl;
}
