/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && q || p && !q || p && q && p->val != q->val)
    return false;
  return !p && !q || isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
