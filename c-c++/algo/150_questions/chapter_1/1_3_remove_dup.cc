#include <string>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

// 1. can change order?
// 2. can use constant bytes?
// 3. can use string?

// change the order, not good!
string &RemoveDup(string &str) {
  sort(str.begin(), str.end());
  string::iterator it = str.begin();
  string::iterator it2 = str.begin();
  while (it != str.end()) {
    while(*it == *it2)
      ++ it2;
    if (*(it + 1) != *it2)
      it2 = str.erase(it+1, it2);
    it = it2;
  }
  return str;
}

// use bitset to count, 32 byte
string &RemoveDup1(string &str) {
  bitset<256> char_set;
  string::iterator it = str.begin();
  while (it != str.end()) {
    if (char_set.test(*it))
      it = str.erase(it);
    else
      char_set.set(*it++);
  }
  return str;
}

// use char[], 256 bytes
char *RemoveDup2(char str[]) {
  if (!str)
    return str;

  bool char_set[256] = { 0 };
  char *ptr_str = str;
  char *ptr_tmp = str;
  while (*ptr_str) {
    if (!char_set[*ptr_str]) {
      char_set[*ptr_str] = 1;
      *ptr_tmp = *ptr_str;
      ++ ptr_tmp;
    }
    ++ ptr_str;
  }
  *ptr_tmp = 0;
  return str;
}

// FOLLOW UP
// change the definition of duplicate
// 1. only the continuous duplicate, leave one or leave nothing

// if continuous duplicate, leave one
string &RemoveDup3(string &str) {
  string::iterator it = str.begin();
  string::iterator it2 = str.begin();
  while (it != str.end()) {
    while(*it == *it2)
      ++ it2;
    if (*(it + 1) != *it2)
      it2 = str.erase(it+1, it2);
    it = it2;
  }
  return str;
}

// if continuous duplicate, leave nothing
string &RemoveDup4(string &str) {
  string::iterator it = str.begin();
  string::iterator it2 = str.begin();
  while (it != str.end()) {
    while(*it == *it2)
      ++ it2;
    if (*(it + 1) != *it2)
      it2 = str.erase(it, it2);
    it = it2;
  }
  return str;
}

// char[] version, leave one
char *RemoveDup5(char str[]) {
  if (!str)
    return str;

  char *ptr_str = str;
  char *ptr_tmp = str;
  while (*ptr_tmp) {
    while (*ptr_str == *ptr_tmp)
      ++ ptr_str;
    * ++ptr_tmp = *ptr_str;
  }
  return str;
}

// char[] version, leave nothing
char *RemoveDup6(char str[]) {
  if (!str)
    return str;

  // second ptr
  char *ptr_str = str + 1;
  // first ptr
  char *ptr_tmp = str;
  while (*ptr_tmp) {
    // if two contigurous chars are same
    if (*ptr_tmp == *ptr_str) {
      // find the first different
      while (*ptr_tmp == *ptr_str)
        ++ ptr_str;
      // copy the different char, and more second ptr to next
      *ptr_tmp = *ptr_str++;
    }
    else
      // copy the unique char and move first ptr to next
      * ++ptr_tmp = *ptr_str;
  }
  return str;
}

int main (int argc, char *argv[]) {
  // string str;
  // test case: abcd, aaa, NULL, aabb, ababab
  char str[200] = { 0 };
  cin >> str;
  cout << RemoveDup6(str) << endl;
}


