#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;


void get_ip(const string &s, vector<string> &parts, set<string> &resultUniq) {
  if (s.size() > 3 * (4 - parts.size()) || s.size() < (4 - parts.size()) ||\
      !parts.empty() && atoi(parts.back().c_str()) > 255)
    return;

  if (4 == parts.size()) {
    string str = parts[0];
    for (int i = 1; i < parts.size(); i ++) {
      str.push_back('.');
      str.append(parts[i]);
    }
    resultUniq.insert(str);
  }
  else {
    string next_str = "", curr_str = "";
    int max_i = (s[0] == '0' ? 1 : min(3, int(s.size())));
    for (int i = 1; i <= max_i; i ++) {
      curr_str = s.substr(0, i);
      next_str = (i < s.size() ? s.substr(i, s.size()) : "");
      parts.push_back(curr_str);
      get_ip(next_str, parts, resultUniq);
      parts.pop_back();
    }
  }
}

vector<string> restoreIpAddresses(string s) {
  vector<string> parts;
  set<string> resultUniq;
  get_ip(s, parts, resultUniq);
  vector<string> result(resultUniq.begin(), resultUniq.end());
  return result;
}


int main (void) {
  string tmp;
  cin >> tmp;
  vector<string> v = restoreIpAddresses(tmp);
  for (auto &val : v)
    cout << val << endl;
}
