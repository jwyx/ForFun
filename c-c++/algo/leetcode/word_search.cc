bool exist(vector<vector<char> > &board, string word) {
  if (word.empty() || board.empty() || board[0].empty())
    return false;
  // all start
  string temp;
  for (int x = 0; x < board.size(); x ++) {
    for (int y = 0; y < board[x].size(); y ++) {
      temp.clear();
      if (dfs(word, x, y, board, temp))
        return true;
    }
  }
  return false;
}

bool dfs(const string word, const int x, const int y, vector<vector<char> > &board, string &temp) {
  if (word == temp)
    return true;
  // out of boundary or reach again
  if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || !board[x][y])
    return false;
  // IMPORTANT! temp word size > word or the last letters are different
  if (word.size() <= temp.size() || word[temp.size()] != board[x][y])
    return false;

  bool result = false;

  temp.push_back(board[x][y]);
  board[x][y] = 0;

  // up
  result = result || dfs(word, x, y - 1, board, temp);
  // down
  result = result || dfs(word, x, y + 1, board, temp);
  // left
  result = result || dfs(word, x - 1, y, board, temp);
  // right
  result = result || dfs(word, x + 1, y, board, temp);

  board[x][y] = temp[temp.size() - 1];
  temp.erase(temp.end() - 1);

  return result;
}
