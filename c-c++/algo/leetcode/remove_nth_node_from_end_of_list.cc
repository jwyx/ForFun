/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *p2 = head, *p3 = head;
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
    p2 = p2->next;
    parent = &(*parent)->next;
  }
  *parent = (*parent)->next;
  return head;
}
