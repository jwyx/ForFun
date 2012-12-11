/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// credit: http://blog.csdn.net/zhiyu27/article/details/8218690
TreeLinkNode *get_next(TreeLinkNode *root) {
  if (!root)
    return NULL;
  if (root->left)
    return root->left;
  if (root->right)
    return root->right;
  return get_next(root->next);
}

void connect(TreeLinkNode *root) {
  TreeLinkNode *left = root;
  while (left) {
    root = left;
    while (root) {
      if (root->left && root->right) {
        root->left->next = root->right;
        root->right->next = get_next(root->next);
      }
      else if (root->left || root->right)
        get_next(root)->next = get_next(root->next);
      root = root->next;
    }
    left = get_next(left);
  }
}
