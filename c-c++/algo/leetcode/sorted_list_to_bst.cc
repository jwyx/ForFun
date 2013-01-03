TreeNode *sortedListToBST(ListNode *head) {
  int len = 0;
  ListNode *tmp = head;
  while (tmp) {
    tmp = tmp->next;
    len += 1;
  }
  return sorted_list_to_bst(head, 0, len - 1);
}

// the list must be reference
TreeNode *sorted_list_to_bst(ListNode* &list, int start, int end) {
  if (start > end)
    return NULL;
  int mid = start + (end - start) / 2;
  TreeNode *left = sorted_list_to_bst(list, start, mid - 1);
  TreeNode *parent = new TreeNode(list->val);
  // change the value of this reference
  // the execution order if inorder, so the list valuable is correct
  list = list->next;
  parent->left = left;
  parent->right = sorted_list_to_bst(list, mid + 1, end);
  return parent;
}
// O(n)
