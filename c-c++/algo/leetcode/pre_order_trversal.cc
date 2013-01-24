// pre-order
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL) : val(x), left(l), right(r) {}
};

// recursive
void preOrderTraverse(TreeNode *head) {
  if (!head)
    return;

  // handle head->val
  cout << head->val << endl;
  preOrderTraverse(head->left);
  preOrderTraverse(head->right);
}

// iterative
void preOrderTraverseIter(TreeNode *head) {
  if (!head)
    return;

  queue<TreeNode *> treeQueue;
  treeQueue.push(head);
  while (!treeQueue.empty()) {
    TreeNode *curr = treeQueue.front();
    if (curr->left)
      treeQueue.push(curr->left);
    if (curr->right)
      treeQueue.push(curr->right);
    cout << curr->val << endl;
    treeQueue.pop();
  }
}

int main(void) {
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3, &n1, &n2);

  preOrderTraverseIter(&n3);

  return 0;
}
