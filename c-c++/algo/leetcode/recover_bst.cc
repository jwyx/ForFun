// inorder travel + swap
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void recoverTree(TreeNode *root) {
  stack<TreeNode *> stk;
  TreeNode *n1 = NULL, *n2 = NULL;
  TreeNode *curr = root, *prev = NULL;
  while (!stk.empty() || curr) {
    if (curr) {
      stk.push(curr);
      curr = curr->left;
    }
    else {
      curr = stk.top();
      // prev and curr node
      if (prev && curr) {
        if (prev->val > curr->val)
          if (!n1) {
            // first disorder
            n1 = prev;
            n2 = curr;
          }
          else {
            // second disorder
            n2 = curr;
            break;
          }
        prev = curr;
      }
      if (!prev)
        prev = curr;
      stk.pop();
      curr = curr->right;
    }
  }
  if (n1 && n2)
    swap(n1->val, n2->val);
}

int main(void) {
  TreeNode t1 (2);
  TreeNode t2 (1);
  t1.right = &t2;

  recoverTree(&t1);
  cout << t1.val << " " << t2.val << endl;
}
