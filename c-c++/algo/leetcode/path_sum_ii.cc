/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > pathSum(TreeNode *root, int sum) {
  vector<vector<int> > result;
  vector<int> path;
  dfs(root, sum, path, result);
  return result;
}

void dfs(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result) {
  if (!root)
    return;

  path.push_back(root->val);
  sum -= root->val;

  if (!root->left && !root->right && !sum) {
    result.push_back(path);
    path.pop_back();
    return;
  }

  dfs(root->left, sum, path, result);
  dfs(root->right, sum, path, result);

  path.pop_back();
}
