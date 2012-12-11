/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *deleteDuplicates(ListNode *head) {
  if (!head)
    return NULL;
  ListNode** curr = &head;
  ListNode* nextElem = NULL;
  while (*curr) {
    nextElem = (*curr)->next;
    if (nextElem && (*curr)->val == nextElem->val)
      *curr = nextElem;
    else
      curr = &(*curr)->next;
  }
  return head;
}

ListNode *deleteDuplicates(ListNode *head) {
  if (!head)
    return NULL;
  ListNode** curr = &head;
  while (*curr) {
    if ((*curr)->next && (*curr)->val == (*curr)->next->val)
      *curr = (*curr)->next;
    else
      curr = &(*curr)->next;
  }
  return head;
}
