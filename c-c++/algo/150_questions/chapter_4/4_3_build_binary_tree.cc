#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

TreeNode *buildTree(const vector<int> &array, int left, int right) {
  if (left > right)
    return NULL;
  int mid = left + (right - left) / 2;
  TreeNode *lTree = buildTree(array, left, mid - 1);
  TreeNode *rTree = buildTree(array, mid + 1, right);
  TreeNode *newNode = new TreeNode(array[mid], lTree, rTree);
  return newNode;
}

int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  vector<int> v (a, a + sizeof(a) / sizeof(int));
  TreeNode *root = buildTree(v, 0, v.size() - 1);
  preOrderTraverse(root);
  inorderTraverse(root);
  return 0;
}
