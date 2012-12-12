/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// credit: http://blog.csdn.net/maqingli87/article/details/8010563
vector<TreeNode *> generateTrees(int n) {
  vector<TreeNode *> result;
  dfs(result, 1, n);
  return result;
}

void dfs(vector<TreeNode *> &result, int left, int right) {
  if (left > right) {
    result.push_back(NULL);
    return;
  }
  for (int i = left; i <= right; i ++) {
    vector<TreeNode *> L;
    dfs(L, left, i - 1);
    vector<TreeNode *> R;
    dfs(R, i + 1, right);
    for (int j = 0; j < L.size(); j ++) {
      for (int k = 0; k < R.size(); k ++) {
        TreeNode *root = new TreeNode(i);
        root->left = L[j];
        root->right = R[k];
        result.push_back(root);
      }
    }
  }
}
