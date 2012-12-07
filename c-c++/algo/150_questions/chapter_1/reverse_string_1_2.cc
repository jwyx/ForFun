#include <iostream>
#include <algorithm>
using namespace std;

// Q: Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

char *ReverseString(char *str) {
  if (!str) return str;

  char *ptr_head = str;
  char *ptr_tail = str;
  while (*(ptr_tail + 1))
    ++ ptr_tail;
  while (ptr_head < ptr_tail)
    swap(*ptr_head++, *ptr_tail--);
  return str;
}

int main(int argc, char *argv[]) {
  char str[256] = { 0 };
  cin >> str;
  // test NULL, empty string, normal string, weild string
  cout << ReverseString(str) << endl;
}
