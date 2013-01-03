// credit: http://blog.csdn.net/maqingli87/article/details/8010358
bool solveSudoku(vector<vector<char> > &board) {
  for (int i = 0; i < board.size(); i ++) {
    for (int j = 0; j < board[i].size(); j ++) {
      if ('.' == board[i][j]) {
        for (int k = 1; k <= 9; k ++) {
          board[i][j] = '0' + k;
          if (isValid(board, i, j) && solveSudoku(board))
            // all filled and all valid
            return true;
          board[i][j] = '.';
        }
        // if all failed in this block
        return false;
      }
    }
  }
  // if all filled
  return true;
}

bool isValid(vector<vector<char> > &board, int x, int y) {
  bool flags[9] = { 0 };
  size_t num = sizeof(flags)*sizeof(bool);

  for (int i = 0; i < 9; i ++) {
    if (board[x][i] != '.') {
      if (!flags[board[x][i] - '1'])
        flags[board[x][i] - '1'] = true;
      else
        return false;
    }
  }

  memset(flags, 0, num);
  for (int i = 0; i < 9; i ++) {
    if (board[i][y] != '.') {
      if (!flags[board[i][y] - '1'])
        flags[board[i][y] - '1'] = true;
      else
        return false;
    }
  }

  int xs = x / 3 * 3;
  int ys = y / 3 * 3;
  memset(flags, 0, num);
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      if (board[xs + i][ys + j] != '.') {
        if (!flags[board[xs + i][ys + j] - '1'])
          flags[board[xs + i][ys + j] - '1'] = true;
        else
          return false;
      }
    }
  }

  return true;
}
