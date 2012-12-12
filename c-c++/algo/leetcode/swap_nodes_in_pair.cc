/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// e.g. head -> 5 -> 6 -> NULL
//
ListNode *swapPairs(ListNode *head) {
  ListNode **curr = &head;
  ListNode *temp = NULL;
  while (*curr) {
    temp = *curr; // temp -> 5 -> 6 -> NULL
    *curr = (*curr)->next; // head -> 6 -> NULL
    if (*curr) // *curr -> 6 -> NULL
      curr = &(*curr)->next; // curr = 6(next)
    temp->next = *curr; // temp -> 5 -> NULL
    *curr = temp; // head -> 6 -> 5 -> NULL
    curr = &(*curr)->next; // curr = 5(next)
  }
  return head;
}
