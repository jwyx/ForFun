/*
 *  Question:
 *    给定4个整数，求解所有可能的24点解法；允许的操作包括+,-,*,/,()
 *
 *  Solution:
 *    DFS
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define ERROR_RANGE 0.0001

using namespace std;

void MiniSolver(pair<float, string> &next_number, vector<pair<float, string> > &numbers, set<string> &result);
void Solver(vector<pair<float, string> > &numbers, set<string> &result);

void MiniSolver(pair<float, string> &next_number, vector<pair<float, string> > &numbers, set<string> &result)
{
  numbers.push_back(next_number);
  Solver(numbers, result);
  numbers.pop_back();
}

void Solver(vector<pair<float, string> > &numbers, set<string> &result)
{
  if (numbers.empty())
    return;

  string formula;
  pair<float, string> next_number;
  pair<float, string> first_number;
  pair<float, string> second_number;

  if (numbers.size() == 1) {
    if (fabs(numbers.back().first - 24) <= ERROR_RANGE)
      result.insert(numbers.back().second);
  }
  else {
    for (int i = 0; i < numbers.size(); i ++) {
      for (int j = i + 1; j < numbers.size(); j ++) {
        // record original numbers
        first_number = numbers[i];
        second_number = numbers[j];
        numbers.erase(numbers.begin() + j);
        numbers.erase(numbers.begin() + i);

        // +
        formula = "(" + first_number.second + "+" + second_number.second + ")";
        next_number = pair<float, string>(first_number.first + second_number.first, formula);
        MiniSolver(next_number, numbers, result);

        // *
        formula = "(" + first_number.second + "*" + second_number.second + ")";
        next_number = pair<float, string>(first_number.first * second_number.first, formula);
        MiniSolver(next_number, numbers, result);

        // -
        formula = "(" + first_number.second + "-" + second_number.second + ")";
        next_number = pair<float, string>(first_number.first - second_number.first, formula);
        MiniSolver(next_number, numbers, result);

        formula = "(" + second_number.second + "-" + first_number.second + ")";
        next_number = pair<float, string>(second_number.first - first_number.first, formula);
        MiniSolver(next_number, numbers, result);

        // /
        formula = "(" + first_number.second + "/" + second_number.second + ")";
        next_number = pair<float, string>(first_number.first / second_number.first, formula);
        MiniSolver(next_number, numbers, result);

        formula = "(" + second_number.second + "/" + first_number.second + ")";
        next_number = pair<float, string>(second_number.first / first_number.first, formula);
        MiniSolver(next_number, numbers, result);

        // restore
        numbers.insert(numbers.begin() + i, first_number);
        numbers.insert(numbers.begin() + j, second_number);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  vector<pair<float, string> > numbers;
  set<string> result;

  numbers.push_back(pair<float, string>(1, "1"));
  numbers.push_back(pair<float, string>(5, "5"));
  numbers.push_back(pair<float, string>(5, "5"));
  numbers.push_back(pair<float, string>(5, "5"));

  Solver(numbers, result);

  for (auto &x : result) {
    cout << x << endl;
  }
}
