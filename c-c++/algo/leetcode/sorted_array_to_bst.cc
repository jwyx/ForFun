TreeNode *sortedArrayToBST(vector<int> &num) {
  // return sorted_array_to_bst(num, 0, num.size() - 1);
  TreeNode *head = NULL;
  sorted_array_to_bst1(head, num.begin(), num.end());
  return head;
}

TreeNode *sorted_array_to_bst(const vector<int> &num, int start, int end) {
  TreeNode *curr = NULL;
  if (start <= end) {
    int mid = start + (end - start) / 2;
    curr = new TreeNode(num[mid]);
    curr->left = sorted_array_to_bst(num, start, mid - 1);
    curr->right = sorted_array_to_bst(num, mid + 1, end);
  }
  return curr;
}

// 或者使用iterator
// credit: http://blog.csdn.net/zhiyu27/article/details/8189143
typedef vector<int>::iterator vec_t;

void sorted_array_to_bst1(TreeNode *&root, vec_t t1, vec_t t2) {
  if (t1 == t2)
    return;
  vec_t mid_t = t1 + (t2 - t1) / 2;
  root = new TreeNode(*mid_t);
  sorted_array_to_bst1(root->left, t1, mid_t);
  sorted_array_to_bst1(root->right, mid_t + 1, t2);
}

// O(n), 类似于binary search的方法
