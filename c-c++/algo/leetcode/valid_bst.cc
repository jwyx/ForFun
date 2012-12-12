/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// v1
// credit: http://blog.csdn.net/maqingli87/article/details/8011334
bool isValidBST(TreeNode *root) {
  vector<int> result;
  inorder_travel(root, result);
  for (int i = 1; i < result.size(); i ++)
    if (result[i] <= result[i - 1])
      return false;
  return true;
}

void inorder_travel(TreeNode *root, vector<int> &result) {
  if(NULL != root) {
    inorder_travel(root->left, result);
    result.push_back(root->val);
    inorder_travel(root->right, result);
  }
}

// v2
// dfs
bool isValidBST(TreeNode *root) {
  if (!root)
    return true;
  pair<int, int> pairs;
  return dfs(root, pairs);
}

bool dfs(TreeNode *root, pair<int, int> &pairs) {
  assert(root);
  bool result = true;
  // the min and max of left tree
  // the min and max of right tree
  pair<int, int> left(INT_MAX, INT_MIN), right(INT_MAX, INT_MIN);
  if (root->left)
    result = result && dfs(root->left, left);
  if (root->right)
    result = result && dfs(root->right, right);
  if (!result || root->val <= left.second || root->val >= right.first)
    return false;
  pairs = pair<int, int>(min(left.first, root->val),\
      max(right.second, root->val));
  return true;
}
