/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> res;
  inorder_traversal(root, res);
  return res;
}

// recursive
void inorder_traversal(TreeNode *root, vector<int> &res) {
  if (!root)
    return;
  inorder_traversal(root->left, res);
  res.push_back(root->val);
  inorder_traversal(root->right, res);
}

// iterative
void inorder_traversal_iter(TreeNode *root, vector<int> &res) {
  stack<TreeNode *> s;
  TreeNode *curr = root;
  while(!s.empty() || curr) {
    if (curr) {
      s.push(curr);
      curr = curr->left;
    }
    else {
      curr = s.top();
      s.pop();
      res.push_back(curr->val);
      curr = curr->right;
    }
  }
}
