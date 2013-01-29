//  Question:
//    假设已知一个整数对序列，其中每个整数代表某种类型的一个对象，
//    而且将p-q对解释为“p与q连通”。连通可传递，编写一个程序从集合
//    中过滤掉额外连通对：当程序输入一个对p-q时，仅当程序此时已经
//    看到的对不能通过可传递性证明p与q连通时，它才输出该对。
//
//  Solution:
//    连通问题，使用union-find
//      union: 通过union操作替换包含两个已知项的集合
//      find: 查找包含已知项的集合
//    使用一个整数数组（一个整数对应一个对象）来保存能够实现union和find的必备信息
//

#include <vector>
#include <iostream>
#include <cstdio>
#include <cassert>

#define N 100

using namespace std;

// V1: quick-find
//    当且仅当第p个和第q个数组项相等时，p与q连通。将第i个数组项初始化为i，其中0<=i<N。
//  为了对p与q实现并集运算，历遍数组，将所有具有相同名字p的项更改为具有相同名字q。
//  这种选择是任意的，可以将所有具有相同名字q的项更改为具有相同名字p。
//    生成快速查找树
//
int main()
{
  int p = 0, q = 0, id[N] = { 0 };
  // Initiate set ids
  for (int i = 0; i < N; i ++)
    id[i] = i;
  // Process input online
  while (scanf("%d %d", &p, &q) == 2) { // O(M)
    assert(p>=0 && p<N && q>=0 && q<N);
    if (id[p] == id[q]) continue;
    for (int t = id[p], i = 0; i < N; i ++) // O(N)
      if (id[i] == t) id[i] = id[q];
    printf("%d-%d\n", p, q);
  }
}
// time: O(M*N)

// V2: quick-union
//   在一个没有环路的结构中，每个对象指向同一个集合中的另一个对象。
// 为了判断两个对象是否位于同一个集合，跟踪每个对象的指针，
// 直到到达指向自身的对象。当且仅当这个过程得到同一个对象时，
// 这些对象才位于同一个稽核中，如果它们不位于相同的集合中，我们最后
// 得到不同的对象（它们指向自身）。为了形成并集，连接一个对象与
// 另一个对象执行并集运算。
//   生成快速并集树
int main()
{
  int i = 0, j = 0, p = 0, q = 0, id[N] = { 0 };
  // Initiate set ids
  for (i = 0; i < N; i ++)
    id[i] = i;
  // Process input online
  while (scanf("%d %d", &p, &q) == 2) { // O(M)
    for (i = p; i != id[i]; i = id[i]) { } // O(N/2)
    for (j = q; j != id[j]; j = id[j]) { }
    if (i == j) continue;
    // Union trees
    id[i] = j;
    printf("%d-%d\n", p, q);
  }
}
// time: O(M*N/2)

// V3: weighted quick-union
//   跟踪每棵树中的节点的数量，总是连通较小树与较大树。
//   需要另外一个数组来保存节点数。
int main()
{
  int i = 0, j = 0, p = 0, q = 0, id[N] = { 0 }, weight[N] = { 0 };
  // Initiate set ids
  for (i = 0; i < N; i ++) {
    id[i] = i;
    weight[i] = 1;
  }
  // Process input online
  while (scanf("%d %d", &p, &q) == 2) { // O(M)
    for (i = p; i != id[i]; i = id[i]) { } // O(lgN)
    for (j = q; j != id[j]; j = id[j]) { }
    if (i == j) continue;
    // Union smaller tree to larger tree
    if (weight[i] < weight[j]) {
      id[i] = j;
      weight[j] += weight[i];
    } else {
      id[j] = i;
      weight[i] += weight[j];
    }
    printf("%d-%d\n", p, q);
  }
}
// time: O(M*lgN)

// V4: weight quick-union with path compression by halving
//
//   Path compression by halving:
//     比完全路径压缩容易，但是获得了相同效果。
//     通过一次处理两个链表，同时将底端链接设置为指向顶端链接所指向的同一个节点，
//     在沿着树上移的过程中，我们可以大致对分路径长度。
//     对每条历遍路径执行这个运算的最终结果与完全路径压缩相似。
int main()
{
  int i = 0, j = 0, p = 0, q = 0, id[N] = { 0 }, weight[N] = { 0 };
  // Initiate set ids
  for (i = 0; i < N; i ++) {
    id[i] = i;
    weight[i] = 1;
  }
  // Process input online
  while (scanf("%d %d", &p, &q) == 2) { // O(M)
    for (i = p; i != id[i]; i = id[i])
      id[i] = id[id[i]];
    for (j = q; j != id[j]; j = id[j])
      id[j] = id[id[j]];
    if (i == j) continue;
    // Union smaller tree to larger tree
    if (weight[i] < weight[j]) {
      id[i] = j;
      weight[j] += weight[i];
    } else {
      id[j] = i;
      weight[i] += weight[j];
    }
    printf("%d-%d\n", p, q);
  }
}
// time: O(M)

// V5: weight quick-union with path compression
//
//   Path compression:
//     在Union运算中，添加另一遍次经过每条路径，将路径中对应于每个顶点的id项设置成指向根。
//     最终结果是几乎把树压平，接近快速查找算法的理想情况。
//
int main()
{
  int i = 0, j = 0, p = 0, q = 0, id[N] = { 0 }, weight[N] = { 0 };
  // Initiate set ids
  for (i = 0; i < N; i ++) {
    id[i] = i;
    weight[i] = 1;
  }
  // Process input online
  while (scanf("%d %d", &p, &q) == 2) { // O(M)
    for (i = p; i != id[i]; i = id[i]) { }
    for (int k = p; k != i; k = id[k])
      id[k] = i;
    for (j = q; j != id[j]; j = id[j]) { }
    for (int k = q; k != j; k = id[k])
      id[k] = j;
    if (i == j) continue;
    // Union smaller tree to larger tree
    if (weight[i] < weight[j]) {
      id[i] = j;
      weight[j] += weight[i];
    } else {
      id[j] = i;
      weight[i] += weight[j];
    }
    printf("%d-%d\n", p, q);
  }
}
// time: O(M)

