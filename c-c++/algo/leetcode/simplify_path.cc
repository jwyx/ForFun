// credit : http://blog.csdn.net/zhiyu27/article/details/8207989
string simplifyPath(string path) {
  vector<string> result;
  string temp;
  for (int i = 0; i < path.size(); i ++) {
    // normal elements
    if (path[i] != '/')
      temp += path[i];
    // the content between / and / or / and end
    if ('/' == path[i] || i == path.size() - 1) {
      // duplicate /
      if (temp.empty())
        continue;
      // previous dir
      if (".." == temp) {
        if (!result.empty())
          result.pop_back();
      }
      // not current dir
      else if (temp != ".")
        result.push_back(temp);
      // clear content
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
