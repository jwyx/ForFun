// Question: 倒转链表
// Solution: 维护三个连续的指针

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int v, ListNode *n = NULL) : val(v), next(n) { }
};

void traverse(ListNode *head)
{
  while (head != NULL) {
    cout << (head->val) << " ";
    head = head->next;
  }
  cout << endl;
}

// 普通版本
ListNode *reverse(ListNode *head)
{
  // r指向已处理表部分的指针
  // y指向当前处理节点
  // t指向原列表中位于y后面的节点
  ListNode *t = NULL, *y = head, *r = NULL;
  while (y != NULL) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  return r;
}

// 指针的指针版本
// 从原链表头步开始删除节点，并不断将删除的节点添加到新的链表中，
// 返回新链表的头指针，即为倒转链表
ListNode *reverse1(ListNode *head)
{
  ListNode *r = NULL, *t = NULL;
  ListNode **curr = &head, **front = &r;
  while (*curr) {
    t = *curr;
    *curr = (*curr)->next;
    t->next = *front;
    *front = t;
  }
  return r;
}

// Question: 重排表中节点，将其中的项按序排列
// Solution:
//   在每个表的开始保持一个哑节点，称做头节点(head node).
//   我们忽略头节点的项域(item field)，并保持其链接，作为包含表中第一项的节点的指针
//   程序中使用两个表：
//       一个用来在第一个循环中搜集随机输入
//       另一个用来在第二个循环中搜集排序后的输入
//   time: O(N^2)

// 普通版本
ListNode *select_sort(ListNode *head)
{
  ListNode *head2 = new ListNode(0);
  ListNode *temp = head, *prev = head2;

  while (temp != NULL) {
    // Initiate variable
    prev = head2;
    head = head->next;

    // Find insert position
    while (prev->next != NULL) {
      if (prev->next->val > temp->val)
        break;
      prev = prev->next;
    }

    // Insert to sorted list
    temp->next = prev->next;
    prev->next = temp;

    // Get next item to be inserted
    temp = head;
  }
  // Release resource
  head = head2->next;
  delete head2;

  return head;
}

// 指针的指针版本
ListNode *select_sort1(ListNode *head)
{
  ListNode *head2 = NULL, *temp = head;
  ListNode **curr = &head2;

  while (temp != NULL) {
    // Initiate variable
    curr = &head2;
    head = head->next;

    // Find insert position
    while (*curr != NULL) {
      if ((*curr)->val > temp->val)
        break;
      curr = &(*curr)->next;
    }
    // Insert to sorted list
    temp->next = *curr;
    *curr = temp;
    // Get next item to be inserted
    temp = head;
  }
  return head2;
}

int main()
{
  ListNode n0(0);
  ListNode n1(1, &n0);
  ListNode n2(2, &n1);

  traverse(&n2);
  traverse(select_sort(&n2));
}
