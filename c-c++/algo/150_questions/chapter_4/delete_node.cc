#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *lVal = NULL, TreeNode *rVal = NULL) : val(x), left(lVal), right(rVal) {}
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

TreeNode *deleteNode(TreeNode *&root, int value) {
  // TODO:
}

int main(void) {
  TreeNode n1(1);
  TreeNode n2(3);
  TreeNode n3(2, &n1, &n2);
  TreeNode n4(0);
  TreeNode *head = &n3;

  insertNode(head, &n4);
  preOrderTraverse(head);

  return 0;
}

