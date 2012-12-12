void post_order_travesal(TreeNode *root) {
  stack<TreeNode *> s;
  TreeNode *curr = NULL, *prev = NULL;
  int h = 0, lh = 0, rh = 0;
  s.push(root);

  while (!s.empty()) {
    curr = s.top();

    // climbing downward
    if (!prev || prev->left == curr || pre->right == curr) {
      if (curr->left)
        s.push(curr->left);
      else if (curr->right)
        s.push(curr->right);
    }
    else if (curr->left == prev) {
      if (curr->right)
        s.push(curr->right);
    }
    else {
      s.pop();
    }
    prev = curr;
  }
}

// http://www.leetcode.com/2010/10/binary-tree-post-order-traversal.html
