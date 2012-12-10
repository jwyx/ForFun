/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int minDepth(TreeNode *root) {
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 1;

  int result = INT_MAX;
  if (root->left)
    result = min(result, minDepth(root->left));
  if (root->right)
    result = min(result, minDepth(root->right));
  return 1 + result;
}

int minDepth(TreeNode *root) {
  if (!root)
    return 0;
  int left = minDepth(root->left);
  int right = minDepth(root->right);
  int result = 1;
  if (left && !right)
    result += left;
  else if (!left && right)
    result += right;
  else if (left && right)
    result += min(left, right);
  return result;
}

