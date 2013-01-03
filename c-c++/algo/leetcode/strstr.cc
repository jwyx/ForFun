#include <iostream>

using namespace std;

// credit : http://www.leetcode.com/2010/10/implement-strstr-to-find-substring-in.html
char* strStr(char *haystack, char *needle) {
  if (!*needle)
    return haystack;
  char *p1 = haystack, *p2 = needle;
  char *p1Adv = haystack;
  // move to the end, point to the last element of the substring of the length of needle
  // one step less than normal movement
  while (*++p2)
    p1Adv++;
  // check the length of left sentence
  while (*p1Adv) {
    char *p1Begin = p1;
    p2 = needle;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    // match
    if (!*p2)
      return p1Begin;
    // otherwise, next begin and end
    p1 = p1Begin + 1;
    p1Adv++;
  }
  return NULL;
}

int main(void) {
  char a[] = "";
  char b[] = "";

  strStr(a, b);
}
