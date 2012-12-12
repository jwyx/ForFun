bool isValidSudoku(vector<vector<char> > &board) {
  set<char> filled;

  for (int i = 0; i < 9; i ++) {
    filled.clear();
    for (int j = 0; j < 9; j ++) {
      if (board[i][j] != '.')
        if (filled.count(board[i][j]) > 0)
          return false;
        else
          filled.insert(board[i][j]);
    }
  }

  for (int i = 0; i < 9; i ++) {
    filled.clear();
    for (int j = 0; j < 9; j ++) {
      if (board[j][i] != '.')
        if (filled.count(board[j][i]) > 0)
          return false;
        else
          filled.insert(board[j][i]);
    }
  }

  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      filled.clear();
      for (int k = 0; k < 3; k ++) {
        for (int l = 0; l < 3; l ++) {
          if (board[i + k][j + l] != '.')
            if (filled.count(board[i + k][j + l]) > 0)
              return false;
            else
              filled.insert(board[i + k][j + l]);
        }
      }
    }
  }

  return true;
}
