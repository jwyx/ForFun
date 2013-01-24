// successor operation for BST in CLRS
#include "tree.h"
using namespace std;

TreeNode *minTreeNode(TreeNode *root) {
  if (!root)
    return NULL;
  while (root->left)
    root = root->left;
  return root;
}

TreeNode *successor(TreeNode *root) {
  if (!root)
    return NULL;

  if (root->right)
    return minTreeNode(root->right);

  TreeNode *parent = root->parent;
  while (parent && parent->right == root) {
    root = parent;
    parent = root->parent;
  }
  return parent;
}

// TODO: predecessor, maxTreeNode

int main (void) {
  TreeNode n1(1);
  TreeNode n4(4);
  TreeNode n2(5, &n4);
  TreeNode n3(2, &n1, &n2);
  n1.parent = &n3;
  n2.parent = &n3;
  n4.parent = &n2;

  TreeNode *s = successor(&n1);
  cout << (s ? s->val : -1) << endl;

  return 0;
}
