/*
 *  Question:
 *    We imagine that N people have decided to commit mass suicide by arranging themselves in a circle
 *    and killing the Mth person around the circle, closing ranks as each person drops out of the circle.
 *    The problem is to find out which person is the last to die (through perhaps that person would have
 *    a change of heart at the end), or to find the order in which the people are executed.
 *
 *  Solution:
 *    用List模拟/数学计算
 */

#include <iostream>
#include <cassert>
using namespace std;

struct node {
  int key;
  node *next;
  node(int key_val, node *next_val = NULL) : key(key_val), next(next_val) {}
};

// 模拟方式实现
int solve(int n, int m)
{
  assert(n>0 && m>0);
  node *head = NULL;
  node *temp = NULL;
  node **curr = &head;
  m %= n;

  // create list
  for (int i = 1; i <= n; i ++) {
    *curr = new node(i);
    (*curr)->key = i;
    curr = &((*curr)->next);
  }
  // 形成环形链表
  *curr = head;

  // 重新定位开始指针
  curr = &head;
  while (curr != &((*curr)->next)) {
    for (int i = 1; i < m; i ++)
      curr = &((*curr)->next);
    // 删除出局者
    temp = *curr;
    *curr = (*curr)->next;
    // 输出出局者信息
    cout << (temp->key) << endl;
    delete temp;
  }

  int result = (*curr)->key;
  // 删除最后一个结点
  temp = *curr;
  delete temp;

  return result;
}

// 扩展1: 数学方法实现
int solve1(int n, int m)
{
  assert(n>0 && m>0);
  m %= n;
  int result = 0;

  // 当前位置:   result
  // 上一轮位置: (result + m) % 上一轮的人数i
  for (int i  = 2; i <= n; i ++)
    result = (result + m) % i;

  return result + 1;
}

int main (int argc, char *argv[])
{
  int n, m;
  cin >> n >> m;
  cout << solve1(n, m) << endl;
}
