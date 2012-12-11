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
  bool dup = false;
  ListNode** curr = &head;
  while (*curr) {
    if ((*curr)->next && (*curr)->val == (*curr)->next->val) {
      if (!dup)
        dup = true;
      *curr = (*curr)->next;
    }
    else if (dup) { // after check different element, remove left dup element
      *curr = (*curr)->next;
      dup = false;
    }
    else
      curr = &(*curr)->next;
  }
  return head;
}
