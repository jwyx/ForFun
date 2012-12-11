// credit : http://blog.csdn.net/zhiyu27/article/details/8207989
string simplifyPath(string path) {
  vector<string> result;
  string temp;
  for (int i = 0; i < path.size(); i ++) {
    if (path[i] != '/')
      temp += path[i];
    if ('/' == path[i] || i == path.size() - 1) {
      if (temp.empty())
        continue;
      if (".." == temp) {
        if (!result.empty())
          result.pop_back();
      }
      else if (temp != ".")
        result.push_back(temp);
      temp.clear();
    }
  }
  string str;
  for (int i = 0; i < result.size(); i ++) {
    str += '/';
    str += result[i];
  }
  return (str.empty() ? "/" : str);
}
