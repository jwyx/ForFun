// BFS
// using
//  deque<TreeNode *> level;
//  vector<vector<int> > result;
//
//  key code:
//
//    if (root)
//      level.push_back(root);
//
//    while (!level.empty()) {
//      int size = level.size();
//      result.push_back(vector<int> ());
//      for (int i = 0; i < size; i ++) {
//        TreeNode *curr = level.front();
//        result.back().push_back(curr->val);
//        if (curr->left)
//          level.push_back(curr->left);
//        if (curr->right)
//          level.push_back(curr->right);
//      }
//    }
