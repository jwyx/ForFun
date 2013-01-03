// credit : http://blog.csdn.net/maqingli87/article/details/8009430
void sortColors(int A[], int n) {
  if (!A || !n)
    return;

  int left = 0, right = n - 1, curr = 0;
  while (curr <= right) {
    // handle left 0
    while (left <= right && 0 == A[left])
      ++ left;
    // handle right 2
    while (left <= right && 2 == A[right])
      -- right;
    // handle curr
    curr = left;
    while (curr <= right) {
      if (0 == A[curr]) {
        swap(A[curr], A[left]);
        break;
      }
      else if (2 == A[curr]) {
        swap(A[curr], A[right]);
        break;
      }
      ++ curr;
    }
  }
}

// rewrited!! work!
void sortColors(int A[], int n) {
  if (!A || !n)
    return;

  int left = 0, right = n - 1, curr = 0;
  while (curr <= right) {
    // after swap, curr is not necessarily sorted
    if (0 == A[curr]) {
      swap(A[curr], A[left]);
      left ++;
      curr = left;
    }
    else if (2 == A[curr]) {
      swap(A[curr], A[right]);
      right --;
    }
    else
      ++ curr;
  }
}

