#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// wrong !!
void solve(vector<int> &numbers, pair<string, double> &formula, vector<string> &res) {
  if (numbers.empty()) {
    if (int(formula.second) == 24)
      res.push_back(formula.first);
    // cout << formula.second << endl;
  }
  else {
    for (int i = 0; i < numbers.size(); i ++) {
      pair<string, double> old_formula = formula;
      int curr_number = numbers[i];
      string number_str = to_string(curr_number);

      if (numbers.size() < 4) {
        numbers.erase(numbers.begin() + i);
        // +
        formula.first = "(" + formula.first + "+" + number_str + ")";
        formula.second = formula.second + curr_number;
        solve(numbers, formula, res);
        formula = old_formula;

        // -
        formula.first = "(" + formula.first + "-" + number_str + ")";
        formula.second = formula.second - curr_number;
        solve(numbers, formula, res);
        formula = old_formula;

        formula.first = "(" + number_str + "-" + formula.first + ")";
        formula.second = curr_number - formula.second;
        solve(numbers, formula, res);
        formula = old_formula;

        // *
        formula.first = "(" + formula.first + "*" + number_str + ")";
        formula.second = formula.second * curr_number;
        solve(numbers, formula, res);
        formula = old_formula;

        // /
        formula.first = "(" + formula.first + "/" + number_str + ")";
        formula.second = formula.second / curr_number;
        solve(numbers, formula, res);
        formula = old_formula;

        formula.first = "(" + number_str + "/" + formula.first + ")";
        formula.second = curr_number / formula.second;
        solve(numbers, formula, res);
        formula = old_formula;
        numbers.insert(numbers.begin() + i, curr_number);
      }
      else {
        numbers.erase(numbers.begin() + i);
        formula.first = number_str;
        formula.second = curr_number;
        solve(numbers, formula, res);
        formula = old_formula;
        numbers.insert(numbers.begin() + i, curr_number);
      }
    }
  }
}

// wrong !!
void solve1(const vector<int> &numbers, pair<string, double> &formula, vector<string> &res, int curr) {
  if (curr == numbers.size()) {
    if (int(formula.second) == 24)
      res.push_back(formula.first);
  }
  else {
      pair<string, double> old_formula = formula;
      int curr_number = numbers[curr];
      string number_str = to_string(curr_number);

      if (curr) {
        // +
        formula.first = "(" + formula.first + "+" + number_str + ")";
        formula.second = formula.second + curr_number;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;

        // -
        formula.first = "(" + formula.first + "-" + number_str + ")";
        formula.second = formula.second - curr_number;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;

        formula.first = "(" + number_str + "-" + formula.first + ")";
        formula.second = curr_number - formula.second;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;

        // *
        formula.first = "(" + formula.first + "*" + number_str + ")";
        formula.second = formula.second * curr_number;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;

        // /
        formula.first = "(" + formula.first + "/" + number_str + ")";
        formula.second = formula.second / curr_number;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;

        formula.first = "(" + number_str + "/" + formula.first + ")";
        formula.second = curr_number / formula.second;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;
      }
      else {
        formula.first = number_str;
        formula.second = curr_number;
        solve1(numbers, formula, res, curr + 1);
        formula = old_formula;
      }
  }
}

int main(int argc, char* argv[]) {
  int nums[4] = {5, 5, 5, 1};
  vector<int> numbers (nums, nums + sizeof(nums) / sizeof(int));
  pair<string, double> formula;
  vector<string> res;
  sort(numbers.begin(), numbers.end());
  do {
    solve1(numbers, formula, res, 0);
  } while(next_permutation(numbers.begin(), numbers.end()));
  for (auto &x : res)
    cout << x << endl;
  return 0;
}
