string longestCommonPrefix(vector<string> &strs) {
  string result ("");
  if (!strs.empty()) {
    result = strs[0];
    for (int i = 0; i < result.size(); i ++) {
      // compare each bit
      for (int j = 1; j < strs.size(); j ++) {
        if (i >= strs[j].size() || strs[j][i] != result[i]) {
          result = result.substr(0, i);
          return result;
        }
      }
    }
  }
  return result;
}

// credit: http://blog.csdn.net/zhiyu27/article/details/8192862
string longestCommonPrefix(vector<string> &strs) {
  if (strs.empty())
    return "";
  string result = strs[0];
  // compare each bit
  for (int i = 1; i < strs.size(); i ++) {
    for (int j = 0; j < result.size(); j ++) {
      if (j >= strs[i].size() || strs[i][j] != result[j]) {
        result = result.substr(0, j);
        break;
      }
    }
  }
  return result;
}

