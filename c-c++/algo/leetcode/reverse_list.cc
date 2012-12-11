#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// credit: http://blog.csdn.net/maqingli87/article/details/8007519
ListNode *reverseBetween(ListNode *head, int m, int n) {
  ListNode **front = &head;
  for (int i = 1; i < m; ++ i)
    front = &(*front)->next;
  ListNode **tail = &(*front)->next;
  ListNode *tempHead = NULL;
  for (int i = m; i <= n; ++ i) {
    ListNode *temp = *front;
    *front = (*front)->next;
    temp->next = tempHead;
    tempHead = temp;
  }
  *tail = *front;
  *front = tempHead;
  return head;
}
// 0->NULL
// m = 1, n = 1
int main (void) {
  ListNode t1 (0);
  ListNode *l = reverseBetween(&t1, 1, 1);
  while (l) {
    cout << l->val << " ";
    l = l->next;
  }
  cout << endl;
}
