// 问题：给n(<=1000)只老鼠，表示为(weight, speed)， weight和speed的取值范围[1, 10000]，
//       找出一个满足Wi < Wi+1且Si > Si+1的最长子序列
// 思路：DP 最长子序列
//       count[i] 在0~i序列中包含i的最长非降子序列长度
//       back[i] 寻找元素使用

#include <iostream>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

struct mouse {
  int weight;
  int speed;
  int index; // 在原序列中的位置
};

bool comp(const mouse &a, const mouse &b)
{
  return (a.weight < b.weight || a.weight == b.weight && a.speed > b.speed);
}

// 逆序打印
void print_back(const int back[], const mouse data[], const int current)
{
  if (current != back[current]) {
    print_back(back, data, back[current]);
  }
  cout << data[current].index << endl;
}

int main(int argc, char *argv[])
{
  int n = 0;
  mouse data[MAX_NUM];
  int count[MAX_NUM] = { 0 };
  int back[MAX_NUM] = { 0 };

  while (cin >> data[n].weight) {
    cin >> data[n].speed;
    data[n].index = n+1;
    ++n;
  }

  sort(data, data+n, comp);

  // TODO: 探究此处为什么需要max
  for (int i = 0; i < n; i++) {
    back[i] = i;
    count[i] = 1;

    int max_count = count[i];
    int max_back = back[i];
    for (int j = i-1; j >=0; j--) {
      if (data[j].weight < data[i].weight &&
          data[j].speed > data[i].speed &&
          max_count < count[j]+1) {
          max_count = count[j]+1;
          max_back = j;
      }
    }
    count[i] = max_count;
    back[i] = max_back;
  }

  int *ptr = max_element(count, count+n);
  int result = *ptr;
  int result_index = ptr - count;

  cout << result << endl;
  print_back(back, data, result_index);
}
