#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// string, sort
bool isAnagram(string str1, string str2) {
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  return str1 == str2;
}

// string, hash
bool isAnagram1(const string &str1, const string &str2) {
  int counts[256] = { 0 };

  if (str1.size() != str2.size())
    return false;

  for (string::const_iterator it1 = str1.begin(), it2 = str2.begin(); it1 != str1.end(); it1 ++, it2 ++) {
    counts[*it1] += 1;
    counts[*it2] -= 1;
  }
  for (int i = 0; i < 256; i ++) {
    if (counts[i])
      return false;
  }
  return true;
}

// char version
bool isAnagram2(const char str1[], const char str2[]) {
  if (!str1 && !str2)
    return true;
  if (!str1 || !str2)
    return false;

  int counts[256] = { 0 };
  const char *ptr1, *ptr2;
  for (ptr1 = str1, ptr2 = str2; *ptr1 && *ptr2; ptr1 ++, ptr2 ++) { // O(n)
    counts[*ptr1] += 1;
    counts[*ptr2] -= 1;
  }
  if (*ptr1 != *ptr2)
    return false;
  for (int i = 0; i < 256; i ++) {
    if (counts[i])
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  string str1, str2;
  // char str1[200] = { 0 };
  // char str2[200] = { 0 };
  cin >> str1 >> str2;
  cout << isAnagram1(str1, str2) << endl;
}
