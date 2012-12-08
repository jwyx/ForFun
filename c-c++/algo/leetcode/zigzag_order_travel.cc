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
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
  vector<vector<int> > res;
  deque<TreeNode *> level;
  vector<int> tmp;
  int size = 0;

  if (root)
    level.push_back(root);

  bool flag = false;
  while (!level.empty()) {
    tmp.clear();
    size = level.size();
    // process each level
    for (int i = 0; i < size; i ++) {
      TreeNode *curr = level.front();
      if (curr->left)
        level.push_back(curr->left);
      if (curr->right)
        level.push_back(curr->right);
      tmp.push_back(curr->val);
      level.pop_front();
    }
    if (flag)
      reverse(tmp.begin(), tmp.end());
    flag = !flag;
    res.push_back(tmp);
  }

  return res;
}
