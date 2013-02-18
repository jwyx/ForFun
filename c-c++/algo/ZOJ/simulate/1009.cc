// 思路：模拟

#include <iostream>
#include <cstring>
#include <string>

#define MAX_NUM 26
#define ENIGMA_NUM 3

using namespace std;

int main(int argc, char *argv[])
{
  int n = 0, case_num = 0;
  int e_bases[ENIGMA_NUM] = { 0 };
  string temp_str;
  char p[MAX_NUM], c[MAX_NUM];
  int e[ENIGMA_NUM][MAX_NUM] = { {0} };
  int map[MAX_NUM] = { 0 };

  cin >> n;

  while (n) {

    for (int i = 0; i < ENIGMA_NUM; i++) {
      cin >> temp_str;
      for (int j = 0; j < n; j++) {
        e[i][j] = temp_str[j]-'A';
      }
    }

    cin >> case_num;

    for (int i = 0; i < case_num; i++) {
      cin >> temp_str;
      memset(e_bases, 0, sizeof(e_bases));
      memset(map, 0, sizeof(map));

      for (int j = 0; j < temp_str.size(); j++) {
        for (int k = 0; k < ENIGMA_NUM; k++) {
          // TODO

        }
      }
    }

    cin >> n;
  }

}
