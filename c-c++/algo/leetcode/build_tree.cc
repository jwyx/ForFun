#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// credit: http://blog.csdn.net/zhiyu27/article/details/8188152
// ======================= inorder and postorder
typedef vector<int>::iterator vec_t;

void buildNode(TreeNode * &root, vec_t t1, vec_t t2, vec_t t3, vec_t t4) {
  if(t1 == t2)
    return;
  root = new TreeNode(*(t4 - 1));
  vec_t next = find(t1, t2, *(t4 - 1));
  buildNode(root->left, t1, next, t3, t3 + (next - t1));
  buildNode(root->right, next + 1, t2, t3 + (next - t1), t4 - 1);
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  if (!inorder.size() || !postorder.size() || inorder.size() != postorder.size())
    return NULL;
  TreeNode *head = NULL;
  buildNode(head, inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
  return head;
}

// ======================= inorder and preorder
void buildNode1(TreeNode * &root, vec_t t1, vec_t t2, vec_t t3, vec_t t4) {
  if(t1 == t2)
    return;
  root = new TreeNode(*t1);
  vec_t next = find(t3, t4, *t1);
  buildNode1(root->left, t1 + 1, t1 + 1 + (next - t3), t3, next);
  buildNode1(root->right, t1 + 1 + (next - t3), t2, next + 1, t4);
}

TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder) {
  if (!preorder.size() || !inorder.size() || preorder.size() != inorder.size())
    return NULL;
  TreeNode *head = NULL;
  buildNode1(head, preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  return head;
}

int main(void) {
  int a[] = {1,3,2};
  vector<int> va (a, a + sizeof(a) / sizeof(int));
  int b[] = {3,2,1};
  vector<int> vb (b, b + sizeof(b) / sizeof(int));
  buildTree1(va, vb);
}
