// search in Young matrix!!
bool searchMatrix(vector<vector<int> > &matrix, int target) {
  int m = matrix.size();    // rows
  int n = matrix[0].size(); // cols

  int left = 0, right = m - 1, mid = 0, row = 0;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (matrix[mid][0] == target)
      break;
    else if (matrix[mid][0] > target) {
      if (mid - 1 >= 0 && matrix[mid-1][0] < target) {
        mid = mid - 1;
        break;
      }
      right = mid - 1;
    }
    else {
      if (mid + 1 < m && matrix[mid+1][0] > target)
        break;
      left = mid + 1;
    }
  }

  left = 0;
  right = n - 1;
  row = mid;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (matrix[row][mid] == target)
      return true;
    else if (matrix[row][mid] > target)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return false;
}

// TODO: add more methods
// Credit:
//  blog.csdn.net/zhanglei8893/article/details/6234564
//  blog.chinaunix.net/space.php?uid=24728651&do=blog&id=2592261
