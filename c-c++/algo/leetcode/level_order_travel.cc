/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// I
vector<vector<int> > levelOrder(TreeNode *root) {
  vector<vector<int> > result;
  deque<TreeNode *> level;
  vector<int> temp;
  int size = 0;

  if (root)
    level.push_back(root);

  while (!level.empty()) {
    size = level.size();
    temp.clear();
    for (int i = 0; i < size; i ++) {
      TreeNode *curr = level.front();
      if (curr->left)
        level.push_back(curr->left);
      if (curr->right)
        level.push_back(curr->right);
      temp.push_back(curr->val);
      level.pop_front();
    }
    result.push_back(temp);
  }
  return result;
}


// II
vector<vector<int> > levelOrderBottom(TreeNode *root) {
  vector<vector<int> > result;
  deque<TreeNode *> level;
  vector<int> temp;
  int size = 0;

  if (root)
    level.push_back(root);

  while (!level.empty()) {
    temp.clear();
    size = level.size();
    for (int i = 0; i < size; i ++) {
      TreeNode *curr = level.front();
      if (curr->left)
        level.push_back(curr->left);
      if (curr->right)
        level.push_back(curr->right);
      temp.push_back(curr->val);
      level.pop_front();
    }
    result.insert(result.begin(), 1, temp);
  }

  return result;
}
