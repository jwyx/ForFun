// 问题：通过 push 和 pop 操作从一个字符串变成指定的字符串，输出所有的方案
// 思路：回溯

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void dfs(const string &source, const string &target,
    string &temp, string &operations, stack<char> &s)
{
  int next_index = temp.size() + s.size();

  if (temp.size() == target.size()) {
    if (temp == target)
      cout << operations << endl;

  } else {
    if (next_index < source.size()) {
      operations.append("i ");
      s.push(source[next_index]);

      dfs(source, target, temp, operations, s);

      operations.erase(operations.size()-2);
      s.pop();
    }

    if (!s.empty()) {
      temp.push_back(s.top());
      operations.append("o ");
      s.pop();

      dfs(source, target, temp, operations, s);

      s.push(temp[temp.size()-1]);
      operations.erase(operations.size()-2);
      temp.erase(temp.size()-1);
    }
  }
}

int main (int argc, char *argv[])
{
  string source, target;

  while (cin >> source) {
    cin >> target;

    stack<char> s;
    string operations(""), temp("");
    cout << "[" << endl;
    dfs(source, target, temp, operations, s);
    cout << "]" << endl;
  }

}
