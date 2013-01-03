/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *p3 = head;//*p2 = head,
  ListNode **parent = &head;
  int step = n;
  while (p3 && step > 0) {
    p3 = p3->next;
    -- step;
  }
  if (step && !p3)
    return head;

  while (p3) {
    p3 = p3->next;
    // p2 = p2->next;
    parent = &(*parent)->next;
  }
  *parent = (*parent)->next;
  return head;
}

// simplify
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *p = head;
  ListNode **parent = &head;
  while (p && n > 0) {
    p = p->next;
    -- n;
  }
  // not long enough
  if (n && !p)
    return head;

  while (p) {
    p = p->next;
    parent = &(*parent)->next;
  }
  *parent = (*parent)->next;
  return head;
}
