// 问题：从一个grid移出最少的火柴，然后使所有正方形都不玩整，求出最少的火柴数
// 思路：回溯，将状态压缩在一个unsigned long long整数中, assume that unsigned long long at least 64bits

// FIXME: WA
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cstdlib>

#define MAX_NUM 5
#define MAX_EDGE_NUM (2*MAX_NUM*(MAX_NUM+1))

using namespace std;

// 输入火柴序号，得到long表示的所有覆盖的正方形
unsigned long long calculate_edge_square_mapping(int n, int edge_index)
{
  static int offset[MAX_NUM] = { 0, 1, 5, 14, 30 };
  int group_size = n + (n+1);
  int row = edge_index / group_size;
  int col = edge_index % group_size;
  unsigned long long result = 0l;

  // 边长 i
  for (int i = 1; i <= n; i++) {
    int total = (n+1-i)*(n+1-i) - 1;

    if (col < n) { // 水平边
      if (row >= 0 && row <= n-i) { // 此边可作为Top边
        result |= (1l << (offset[n-i] + total - (row*(n-i+1) + col / i)));
      }

      if (row >= i && row <= n) { // 此边可作为Bottom
        result |= (1l << (offset[n-i] + total - ((row-i)*(n-i+1) + col / i)));
      }

    } else { // 竖直边
      col -= n; // 起点归零

      if (col >= 0 && col <= n-i) { // left边
        result |= (1l << (offset[n-i] + total - ((row/i)*(n-i+1) + col / i)));
      }

      if (col >= i && col <= n) { // right边
        result |= (1l << (offset[n-i] + total - ((row/i)*(n-i+1) + (col-i) / i)));
      }

      col += n; // 恢复
    }
  }

  return result;
}

void dfs(const unsigned long long edge_states[], const int n,
    unsigned long long current_state, int current_index,
    int current_steps, int &min_steps)
{
  int edge_count = 2*n*(n+1);

  if (current_index == edge_count) {
    if (current_state == 0l && min_steps > current_steps)
      min_steps = current_steps;

  } else if (current_steps < min_steps) {

    // 改成贪婪算法
    while (current_index < edge_count - 1) {
      if (current_state & edge_states[current_index])
        break;
      current_index ++;
    }

    dfs(edge_states, n, current_state & (~edge_states[current_index]),
        current_index+1, current_steps+1, min_steps);

    dfs(edge_states, n, current_state,
        current_index+1, current_steps, min_steps);

  }

}

int main (int argc, char *argv[])
{
  int case_count = 0, n = 0;
  int edge_count = 0;
  unsigned long long current_state = 0l;
  unsigned long long edge_states[MAX_EDGE_NUM] = { 0l };
  int min_steps = 0, temp = 0;

  string line;

  getline(cin, line);
  case_count = atoi(line.c_str());

  while (case_count--) {

    min_steps = INT_MAX;
    memset(edge_states, 0, sizeof(edge_states));

    // Input
    for (int i = 0; i < 2; i++) {
      getline(cin, line);
      istringstream iss (line, istringstream::in);

      if (i == 0) {
        iss >> n;

        edge_count = 2*n*(n+1);
        current_state = (1l << (n*(n+1)*(2*n+1)/6)) - 1;

        for (int i = 0; i < edge_count; i++) {
          edge_states[i] = calculate_edge_square_mapping(n, i);
        }

      } else {
        while (iss >> temp) {
          current_state &= (~edge_states[temp-1]);
        }
      }
    }

    dfs(edge_states, n, current_state, 0, 0, min_steps);

    cout << min_steps << endl;
  }
}
