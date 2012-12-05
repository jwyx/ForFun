#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

//https://evernotechallenge.interviewstreet.com/challenges/dashboard/#problem/4fd6ce6a9efb8

int main(int argc, char *argv[]) {
  int max_size = 0;
  int size = 0;
  cin >> size;

  string tmp ("");
  map<string, int> frequent_dict;

  while (size > 0) {
    cin >> tmp;
    if (frequent_dict.count(tmp) == 0)
      frequent_dict[tmp] = 0;
    frequent_dict[tmp] += 1;
    max_size = max(frequent_dict[tmp], max_size);
    tmp.clear();
    size --;
  }

  map<int, vector<string> > res_map;
  map<string, int>::iterator it = frequent_dict.begin();
  for (it = frequent_dict.begin(); it != frequent_dict.end(); ++ it) {
    if (res_map.count((*it).second) == 0) {
      res_map[(*it).second] = vector<string>();
    }
    res_map[(*it).second].push_back((*it).first);
  }

  cin >> size;

  while (max_size > 0 && size > 0) {
    if (res_map.count(max_size) != 0) {
      vector<string> &vec = res_map[max_size];
      for (size_t i = 0; i < vec.size() && size > 0; ++ i, -- size)
        cout << vec[i] << endl;
    }
    -- max_size;
  }

  return 0;
}
