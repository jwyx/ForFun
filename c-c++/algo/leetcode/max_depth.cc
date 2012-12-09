/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxDepth(TreeNode *root) {
  int max_depth = 0;
  dfs(root, 0, max_depth);
  return max_depth;
}

void dfs(TreeNode *node, int depth, int &max_depth) {
  if (!node) {
    if (max_depth < depth)
      max_depth = depth;
    return;
  }

  dfs(node->left, depth + 1, max_depth);
  dfs(node->right, depth + 1, max_depth);
}

// credit: http://blog.csdn.net/zhiyu27/article/details/8197767

int maxDepth(TreeNode *root) {
  if (!root)
    return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
