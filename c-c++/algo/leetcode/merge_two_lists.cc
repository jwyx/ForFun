/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode *head = NULL, *curr = NULL;
  ListNode *p1 = l1, *p2 = l2, *p = NULL;
  while (p1 && p2) {
    if (p1->val < p2->val) {
      p = p1;
      p1 = p1->next;
    }
    else {
      p = p2;
      p2 = p2->next;
    }

    if (!head)
      head = p;
    if (curr)
      curr->next = p;
    curr = p;
  }
  p = (p1 ? p1 : p2);
  if (curr)
    curr->next = p;
  else
    head = p;
  return head;
}
