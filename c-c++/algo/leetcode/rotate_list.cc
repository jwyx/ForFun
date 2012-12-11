#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {
  if (!head)
    return NULL;

  // calculate len
  int len = 0;
  ListNode *p = head;
  while (p) {
    p = p->next;
    ++ len;
  }
  k %= len;

  ListNode **curr = &head, **tail = &head;
  for (int i = 0; i < k; ++i) {
    assert(*tail);
    tail = &(*tail)->next;
  }
  while(*tail) {
    curr = &(*curr)->next;
    tail = &(*tail)->next;
  }
  *tail = head;
  head = *curr;
  *curr = NULL;
  return head;
}

int main (void) {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  int a;
  cin >> a;
  ListNode *head = rotateRight(&n1, a);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
