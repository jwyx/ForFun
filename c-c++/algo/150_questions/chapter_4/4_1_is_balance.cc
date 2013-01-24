// 1. understand problem
//  it's different from normal balanced!!
//  a balanced tree is defined to be a tree such that
//    no two leaf nodes differ in distance from the root by more than one

#include <iostream>
#include <cmath>
#include "tree.h"
using namespace std;

int minDepth(TreeNode *root) {
  if (!root)
    return 0;
  return 1 + min(minDepth(root->left), minDepth(root->right));
}

int maxDepth(TreeNode *root) {
  if (!root)
    return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(TreeNode *root) {
  return maxDepth(root) - minDepth(root) <= 1;
}

int main (void) {
  TreeNode n5(-1);
  TreeNode n4(0, &n5);
  TreeNode n1(1, &n4);
  TreeNode n2(3);
  TreeNode n3(2, &n1, &n2);

  cout << isBalanced(&n3) << endl;
}
