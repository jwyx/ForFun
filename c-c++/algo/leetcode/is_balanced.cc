/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isBalanced(TreeNode *root) {
  int height = 0;
  return isBalanced(root, height);
}

bool isBalanced(TreeNode *root, int &h) {
  if (!root) {
    h = 0;
    return true;
  }

  int hl = 0, hr = 0;
  if (isBalanced(root->left, hl) && isBalanced(root->right, hr) && abs(hl - hr) <= 1) {
    h = max(hl, hr) + 1;
    return true;
  }
  return false;
}

// TODO: iterator 版本的实现 !!
