/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// credit: http://blog.csdn.net/maqingli87/article/details/7993367
// COOL!!
ListNode *partition(ListNode *head, int x) {
  // 用于记录<x的所有元素
  ListNode* ret = NULL;
  // 指向next指针的指针
  ListNode** small = &ret;
  ListNode** curr = &head;
  while(*curr != NULL) {
    if((*curr)->val < x) {
      // append new small element to next pointer
      *small = *curr;
      // 得到最后一个元素的新的next指针地址
      small = &(*small)->next;
      // skip middle element, 包括head的处理
      *curr = (*curr)->next;
    }
    else
      // get the next pointer of curr
      curr = &(*curr)->next;
  }
  *small = head;
  return ret;
}
