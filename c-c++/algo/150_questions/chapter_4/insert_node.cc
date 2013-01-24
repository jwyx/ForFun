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

void insertNode(TreeNode *&head, TreeNode *newNode) {
  if (!head) {
    head = newNode;
    return;
  }

  if (head->val > newNode->val) {
    if (head->left)
      insertNode(head->left, newNode);
    else
      head->left = newNode;
  }
  else {
    if (head->right)
      insertNode(head->right, newNode);
    else
      head->right = newNode;
  }
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
