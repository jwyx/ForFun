// Credit: http://blog.csdn.net/v_july_v/article/details/6712171
// Question:
// 1．一个文件中含有n个元素，只能遍历一遍，要求等概率随机取出其中之一。

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

string uniform_random_pick(const char* filename) {
  string result;
  fstream fin (filename);
  if (fin.is_open()) {
    string line;
    unsigned long len = 1;
    while (getline(fin, line)) {
      if (rand() % len == 0)
        result = line;
      ++ len;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "usage: xx test_data_file" << endl;
    return 1;
  }

  srand(time(0));

  cout << uniform_random_pick(argv[1]) << endl;

  return 0;
}
