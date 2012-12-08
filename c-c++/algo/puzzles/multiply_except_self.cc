#include <iostream>
#include <vector>
#include <cassert>

// https://evernotechallenge.interviewstreet.com/challenges/dashboard/#problem/500d1c6f1d7ea
using namespace std;

int main (int argc, char *argv[]) {
  int size = 0;
  long long tmp = 0;
  long long multi = 1;
  vector<size_t> zeros_pos;
  vector<long long> input_arr;

  cin >> size;
  input_arr.reserve(size);

  while (size > 0) {
    cin >> tmp;
    input_arr.push_back(tmp);
    -- size;
  }

  for (size_t i = 0; i < input_arr.size(); i ++) {
    if (input_arr[i] == 0)
      zeros_pos.push_back(i);

    if (zeros_pos.size() > 1)
      continue;
    if (zeros_pos.size() == 0 || zeros_pos.size() == 1 && i != zeros_pos[0])
      multi *= input_arr[i];
  }

  for (size_t i = 0; i < input_arr.size(); i ++) {
    if (zeros_pos.empty())
      cout << multi/input_arr[i] << endl;
    else if (zeros_pos.size() == 1) {
      if (zeros_pos[0] == i)
        cout << multi << endl;
      else
        cout << 0 << endl;
    }
    else
      cout << 0 << endl;
  }

  return 0;
}

