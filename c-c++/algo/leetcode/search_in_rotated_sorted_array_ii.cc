// credit : http://blog.csdn.net/zhiyu27/article/details/8207664
bool search(int A[], int n, int target) {
  if (n <= 0 || !A)
    return false;

  int left = 0, right = n - 1, mid = -1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (A[mid] == target)
      return true;
    else if (A[mid] > A[right]) { // left
      if (A[left] <= target && target < A[mid])
        right = mid - 1;
      else
        left = mid + 1;
    }
    else if (A[mid] < A[right]) {
      if (target <= A[right] && target > A[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }
    else {
      right --;
    }
  }
  return false;
}

// O(n)
// TODO: why choose right??!! NEED SOME TEST
