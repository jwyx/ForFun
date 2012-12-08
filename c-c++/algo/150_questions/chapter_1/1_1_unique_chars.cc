// Question:
// Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
//
#include <iostream>
#include <unordered_set>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

// should ask the size of the set of characters, and can assume it's 256, and logic is same

// using unordered_set, time O(n), space O(n)
bool UniqueChars(string &str) {
  unordered_set<char> word_set;
  for (string::iterator it = str.begin(); it != str.end(); it ++) { // n
    if (word_set.find(*it) != word_set.end()) // O(1)
      return false;
    word_set.insert(*it); // Average O(1)
  }
  return true;
}

// using arrays, sizeof(bool) = 1 byte
// space 256 byte
bool UniqueChars1(string &str) {
  bool word_set[256] = { 0 };
  for (string::iterator it = str.begin(); it != str.end(); it ++) { // n
    if (word_set[*it]) // O(1)
      return false;
    word_set[*it] = 1; // Average O(1)
  }
  return true;
}

// less space, bitmap
// assume that 256 charactors, 32 bytes
bool UniqueChars2(string &str) {
  for (string::iterator it = str.begin(); it != str.end(); it ++) {
    bitset<256> word_set;
    if (word_set.test(*it))
      return false;
    word_set.set(*it);
  }
  return true;
}

// no extra space, O(n^2)
bool UniqueChars3(string &str) {
  for (string::iterator it = str.begin(); it != str.end(); it ++) {
    for (string::iterator it2 = (it + 1); it2 != str.end(); it2 ++) {
      if (*it == *it2)
        return false;
    }
  }
  return true;
}

// no extra space, and can distroy the structure of string
bool UniqueChars4(string &str) {
  sort(str.begin(), str.end()); // O(nlogn)
  for (string::iterator it = str.begin(), it2 = str.begin() + 1; it2 != str.end(); it ++, it2 ++) {
    if (*it == *it2)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  string str;
  cin >> str;
  cout << UniqueChars4(str) << endl;
}
