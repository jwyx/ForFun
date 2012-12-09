#include <iostream>

using namespace std;

// credit : http://www.leetcode.com/2010/10/implement-strstr-to-find-substring-in.html
char* strStr(char *haystack, char *needle) {
  if (!*needle)
    return haystack;
  char *p1 = (char*)haystack, *p2 = (char*)needle;
  char *p1Adv = (char*)haystack;
  while (*++p2)
    p1Adv++;
  while (*p1Adv) {
    char *p1Begin = p1;
    p2 = (char*)needle;
    while (*p1 && *p2 && *p1 == *p2) {
      p1++;
      p2++;
    }
    if (!*p2)
      return p1Begin;
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
