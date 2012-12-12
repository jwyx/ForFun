/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isSymmetric(TreeNode *root) {
  if (!root)
    return true;
  return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode *p, TreeNode *q) {
  if (!p && q || p && !q || p && q && p->val != q->val)
    return false;
  return !p && !q || isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}
