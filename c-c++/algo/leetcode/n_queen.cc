#include <iostream>
#include <vector>
#include <string>
using namespace std;

// credit: http://blog.csdn.net/maqingli87/article/details/7992782
bool isOK(vector<int> &board, int curr, int val) {
  for (int i = 0; i < curr; i ++) {
    if (val == board[i] || abs(val - board[i]) == abs(curr - i))
      return false;
  }
  return true;
}

void dfs(int curr, vector<int> &board, vector<vector<string> > &result) {
  if (curr == board.size()) {
    string row(board.size(), '.');
    vector<string> v(board.size(), row);
    for (int i = 0; i < board.size(); i ++)
      v[board[i]][i] = 'Q';
    result.push_back(v);
  }
  else {
    for (int i = 0; i < board.size(); i ++) {
      if (isOK(board, curr, i)) {
        board[curr] = i;
        dfs(curr+1, board, result);
        // because board[curr] will be assigned again if it's necessary
        // board[curr] = -1;
      }
    }
  }
}

vector<vector<string> > solveNQueens(int n) {
  vector<int> board(n, -1);
  vector<vector<string> > result;
  dfs(0, board, result);
  return result;
}

int main (void) {
  int n = 0;
  cin >> n;
  vector<vector<string> > result = solveNQueens(n);
  for (auto &board : result) {
    for (auto &row : board) {
      cout << row << endl;
    }
    cout << endl;
  }
}
