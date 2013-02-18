// 问题：放置方块使相邻部分数字相同
// 思路：回溯 + 相同方块判断一次的剪枝
//
// FIXME: TLE

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
// #include <ctime>

#define MAX_NUM 25
#define DIRECTION_NUM 4

using namespace std;

enum { kTop = 0, kRight, kBottom, kLeft };

struct square {
  int tri[DIRECTION_NUM];
  square(string square_str) {
    for (int i = 0; i < DIRECTION_NUM; i++)
      tri[i] = square_str[i];
  }
  square() {
    for (int i = 0; i < DIRECTION_NUM; i++)
      tri[i] = -1;
  }
};


bool is_valid(const int n, vector<square> &board, int current_index)
{
  int x = current_index / n;
  int y = current_index % n;

  if (x-1 >= 0 && board[(x-1)*n+y].tri[kRight] != board[current_index].tri[kLeft])
    return false;

  if (y-1 >= 0 && board[x*n+(y-1)].tri[kBottom] != board[current_index].tri[kTop])
    return false;

  return true;
}

bool check(const int bounds[], const int n, int current_index) {
  int x = current_index / n;
  int y = current_index % n;

  if (bounds[kTop] > (x == 0 ? (n-y-1) : 0) ||
      bounds[kRight] > (y == n-1 ? (n-x) : (n-x-1)) ||
      bounds[kBottom] > (x == n-1 ? (n-y-1) : n) ||
      bounds[kLeft] > n-x-1)
    return false;
  else
    return true;
}


bool dfs(const int n, const bool (*is_bound)[MAX_NUM], int bounds[],
    vector<square> &board, vector<square> &distinct_square,
    vector<int> &squere_count, int current_index)
{
  int size = n*n;
  int x = current_index / n;
  int y = current_index % n;

  if (current_index == size) {
    return true;

  } else {
    for (int i = 0; i < distinct_square.size(); i++) {

      if (squere_count[i] > 0) {
        board[current_index] = distinct_square[i];

        if (is_valid(n, board, current_index)) {

          // bounds[kTop] -= ((x == 0 && is_bound[kTop][i]) ? 1 : 0);
          // bounds[kRight] -= ((y == n-1 && is_bound[kRight][i]) ? 1 : 0);
          // bounds[kBottom] -= ((x == n-1 && is_bound[kBottom][i]) ? 1 : 0);
          // bounds[kLeft] -= ((y == 0 && is_bound[kLeft][i]) ? 1 : 0);

          squere_count[i] -= 1;
          if (// check(bounds, n, current_index) &&
              dfs(n, is_bound, bounds, board, distinct_square, squere_count, current_index+1))
            return true;
          squere_count[i] += 1;

          // bounds[kTop] += ((x == 0 && is_bound[kTop][i]) ? 1 : 0);
          // bounds[kRight] += ((y == n-1 && is_bound[kRight][i]) ? 1 : 0);
          // bounds[kBottom] += ((x == n-1 && is_bound[kBottom][i]) ? 1 : 0);
          // bounds[kLeft] += ((y == 0 && is_bound[kLeft][i]) ? 1 : 0);
        }
      }
    }
    return false;
  }
}

int main(int argc, char *argv[])
{
  int n = 0, size = 0, case_index = 1;
  int temp = 0;
  string temp_str("");
  map<string, int> dict;
  vector<int> squere_count;
  vector<square> distinct_square;
  vector<square> board(MAX_NUM, square());
  int bounds[DIRECTION_NUM] = { 0 };
  bool is_bound[DIRECTION_NUM][MAX_NUM] = { { false } };
  bool is_possible = true;

  // time_t start_time;
  // start_time = time (NULL);

  squere_count.reserve(MAX_NUM);
  distinct_square.reserve(MAX_NUM);

  cin >> n;

  while (n) {
    size = n*n;
    is_possible = true;

    dict.clear();
    distinct_square.clear();
    squere_count.clear();

    memset(bounds, 0, sizeof(bounds));

    for (int i = 0; i < size; i++) {
      temp_str.clear();
      for (int j = 0; j < DIRECTION_NUM; j++) {
        cin >> temp;
        temp_str.push_back(temp+'0');
      }
      dict[temp_str] += 1;
    }

    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
      distinct_square.push_back(square((*it).first));
      squere_count.push_back((*it).second);
    }

    for (int i = 0; i < DIRECTION_NUM; i++) {
      for (int j = 0; j < distinct_square.size(); j++) {
        is_bound[i][j] = true;
        for (int k = 0; k < distinct_square.size(); k++) {
          if (j != k && distinct_square[j].tri[i] == distinct_square[k].tri[(i+2)%4]) {
            is_bound[i][j] = false;
            break;
          }
        }
      }
      for (int j = 0; j < distinct_square.size(); j++) {
        if (is_bound[i][j])
          bounds[i] += squere_count[i];
      }
      if (bounds[i] > n) {
        is_possible = false;
        break;
      }
    }

    if (is_possible && dfs(n, is_bound, bounds, board, distinct_square, squere_count, 0))
      cout << "Game " << case_index++ << ": Possible" << endl;
    else
      cout << "Game " << case_index++ << ": Impossible" << endl;

    cin >> n;

    if (n)
      cout << endl;
  }

  // cout << (time(NULL) - start_time) << endl;

}
