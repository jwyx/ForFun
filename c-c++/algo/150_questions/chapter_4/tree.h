#include <iostream>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *parent;
  TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL, TreeNode *p = NULL) : val(x), left(l), right(r), parent(p) {}
};

void preOrderTraverse(TreeNode *root) {
  if (!root)
    return;
  std::cout << root->val << std::endl;
  preOrderTraverse(root->left);
  preOrderTraverse(root->right);
}

// recursive
void inorderTraverse(TreeNode *root) {
  if (!root)
    return;
  inorderTraverse(root->left);
  std::cout << root->val << std::endl;
  inorderTraverse(root->right);
}

