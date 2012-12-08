/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxPathSum(TreeNode *root) {
  int local = INT_MIN;
  int global = maxSum(root, local);
  return max(global, local);
}

int maxSum(TreeNode *root, int &local) {
  if (!root)
    return 0;

  int left = maxSum(root->left, local);
  int right = maxSum(root->right, local);

  // include or exclude root->val
  local = max(local, root->val + left + right);
  if (root->left)
    local = max(left, local);
  if (root->right)
    local = max(right, local);

  // root->val as one end
  return max(root->val, max(root->val + left, root->val + right));
}
