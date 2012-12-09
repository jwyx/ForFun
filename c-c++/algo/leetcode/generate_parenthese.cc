vector<string> generateParenthesis(int n) {
  vector<string> res;
  string tmp;
  generate_parenthesis(n, n, tmp, res);
  return res;
}

void generate_parenthesis(int l, int r, string &tmp, vector<string> &res) {

  if (l < 0 || l > r)
    return;

  if (!l && !r)
    res.push_back(tmp);
  else {
    tmp.push_back('(');
    generate_parenthesis(l - 1, r, tmp, res);
    tmp.erase(tmp.size() - 1);

    tmp.push_back(')');
    generate_parenthesis(l, r - 1, tmp, res);
    tmp.erase(tmp.size() - 1);
  }
}
