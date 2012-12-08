ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *p1 = l1, *p2 = l2, *p3 = NULL;
  ListNode *head = NULL, *tail = NULL;
  int carry = 0;

  while(p1 || p2 || carry) {
    // 处理存储空间和carry
    p3 = new ListNode(carry);

    // 处理头
    if (!head)
      head = p3;

    // 处理val和carry
    if (p1)
      p3->val += p1->val;
    if (p2)
      p3->val += p2->val;

    if (p3->val >= 10) {
      carry = 1;
      p3->val %= 10;
    }
    else
      carry = 0;

    // 接上新队列
    if (tail)
      tail->next = p3;
    tail = p3;

    // 处理指针
    if (p1)
      p1 = p1->next;
    if (p2)
      p2 = p2->next;
  }

  return head;
}
