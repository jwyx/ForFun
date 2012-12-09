void flatten(TreeNode *root) {
  flatten_tree(root);
}

TreeNode *flatten_tree(TreeNode *root) {
  if (!root)
    return root;

  TreeNode *last_node = root;
  TreeNode *right_child = root->right;

  if (root->left) {
    root->right = root->left;
    last_node = flatten_tree(root->left);
    root->left = NULL;
  }

  if (right_child) {
    last_node->right = right_child;
    last_node = flatten_tree(last_node->right);
  }
  return last_node;
}

// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal
// other solution: http://blog.csdn.net/zhiyu27/article/details/8191203
