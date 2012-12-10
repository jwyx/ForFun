// credit: http://blog.csdn.net/maqingli87/article/details/7992782
bool isOK(vector<int> &board, int curr, int val) {
  for (int i = 0; i < curr; i ++) {
    if (val == board[i] || abs(val - board[i]) == abs(curr - i))
      return false;
  }
  return true;
}

void dfs(int curr, vector<int> &board, int &total) {
  if (curr == board.size())
    total += 1;
  else {
    for (int i = 0; i < board.size(); i ++) {
      if (isOK(board, curr, i)) {
        board[curr] = i;
        dfs(curr+1, board, total);
        // board[curr] = -1;
      }
    }
  }
}

int totalNQueens(int n) {
  vector<int> board(n, -1);
  int total = 0;
  dfs(0, board, total);
  return total;
}

