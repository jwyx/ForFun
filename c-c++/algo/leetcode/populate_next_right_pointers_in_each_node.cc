/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void connect(TreeLinkNode *root) {
  TreeLinkNode *left = root;
  // left, keep the left node for each level
  while (left && left->left && left->right) {
    root = left;
    while (root) {
      root->left->next = root->right;
      if (root->next)
        root->right->next = root->next->left;
      root = root->next;
    }
    left = left->left;
  }
}
