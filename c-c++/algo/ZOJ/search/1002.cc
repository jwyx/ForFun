// 问题：输入一个n*n的地图，其中包括障碍物，求最大的碉堡数
// 思路：类似N皇后问题，回溯法

#include <string>
#include <iostream>
#include <vector>

#define DIRECTIONS 4

using namespace std;

bool is_valid(const vector<string> &board, const int x, const int y)
{
  // left, right, top, bottom, top_left, top_right, bottom_left, bottom_right
  int dx_set[DIRECTIONS] = { -1, 1, 0, 0 };
  int dy_set[DIRECTIONS] = { 0, 0, -1, 1 };

  int min_x = 0;
  int max_x = board.size() - 1;
  int min_y = 0;
  int max_y = board[0].size() - 1;
  int new_x = x, new_y = y;

  // 判断当前位置
  if (new_x < min_x || new_x > max_x || new_y < min_y || new_y > max_y ||
      board[x][y] == 'X')
    return false;

  // 从中心开始向四个方向扩散
  for (int i = 0; i < DIRECTIONS; i++) {
    new_x = x + dx_set[i];
    new_y = y + dy_set[i];

    while (new_x >= min_x && new_x <= max_x && new_y >= min_y && new_y <= max_y) {
      // 如果发现有碉堡
      if (board[new_x][new_y] == 'O')
        return false;
      // 如果发现有障碍
      else if (board[new_x][new_y] == 'X')
        break;

      new_x += dx_set[i];
      new_y += dy_set[i];
    }
  }
  return true;
}

void dfs(const int x, int y, int num, vector<string> &board, int &result)
{
  if (x == board.size()) {
    if (num > result)
      result = num;

  } else {
    // 同一层
    for (; y < board[x].size(); y++) {
      if (is_valid(board, x, y)) {
        // 占位字符用'O'
        board[x][y] = 'O';
        dfs(x, y+1, num+1, board, result);
        // 回退
        board[x][y] = '.';
      }
    }
    // 下一层
    dfs(x+1, 0, num, board, result);
  }
}

int main (int argc, char *argv[])
{
  int n = 0;
  string temp;
  cin >> n;

  while (n) {
    vector<string> board = vector<string>(n, "");
    int result = 0;

    for (int i = 0; i < n; i++) {
      cin >> temp;
      board[i].assign(temp.begin(), temp.end());
    }

    dfs(0, 0, 0, board, result);

    cout << result << endl;
    cin >> n;
  }
}
