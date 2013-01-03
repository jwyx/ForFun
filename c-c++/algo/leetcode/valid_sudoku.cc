// not very efficient; better method should check each block once
bool isValidSudoku(vector<vector<char> > &board) {
  assert(board.size() == board[0].size());
  for (int i = 0; i < board.size(); i ++) {
    for (int j = 0; j < board[i].size(); j ++) {
      if ('.' != board[i][j]) {
        if (!isValid(board, i, j))
          return false;
      }
    }
  }
  return true;
}

bool isValid(vector<vector<char> > &board, int x, int y) {
  bool flags[9] = { 0 };

  for (int i = 0; i < 9; i ++) {
    if (board[x][i] != '.') {
      if (!flags[board[x][i] - '1'])
        flags[board[x][i] - '1'] = true;
      else
        return false;
    }
  }

  memset(flags, 0, 9);
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
  memset(flags, 0, 9);
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
