#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <fstream>
using namespace std;

// 字典序法
void perm(string &str) {
  sort(str.begin(), str.end());

  int len = str.size();
  int i = 0;
  int j = 0;

  while (true) {
    cout << str;

    // j=max{i|Pi<Pi+1}
    for (i = len - 2; i >= 0 && str[i] >= str[i + 1]; i --);

    // if finished
    if (i == -1)
      break;

    // k=max{i|Pi>Pj}
    for (j = len - 1; j > i && str[j] <= str[i]; j --);

    swap(str[i], str[j]);
    reverse(str.begin() + i + 1, str.end());

    cout << ",";
  }
  cout << endl;
}

int main (int argc, char *argv[]) {
  assert(argc >= 2);

  string w;

  ifstream fin (argv[1], ios_base::in);
  while (fin.good()) {
    getline(fin, w);
    if (w.size() == 0)
      continue;
    else
      perm(w);
    w.clear();
  }
  fin.close();
  return 0;
}

/*
  (1)	字典序法
  对给定的字符集中的字符规定了一个先后关系，在此基础上按照顺序依次产生每个排列。
  [例]字符集{1,2,3},较小的数字较先,这样按字典序生成的全排列是:123,132,213,231,312,321。
  生成给定全排列的下一个排列 所谓一个的下一个就是这一个与下一个之间没有字典顺序中相邻的字符串。
  这就要求这一个与下一个有尽可能长的共同前缀，也即变化限制在尽可能短的后缀上。
  算法思想：
  设P是[1,n]的一个全排列。
  P=P1P2…Pn=P1P2…Pj-1PjPj+1…Pk-1PkPk+1…Pn,
  j=max{i|Pi<Pi+1}, k=max{i|Pi>Pj} ,对换Pj，Pk，将Pj+1…Pk-1PjPk+1…Pn翻转，
  P’= P1P2…Pj-1PkPn…Pk+1PjPk-1…Pj+1即P的下一个
  例子:839647521的下一个排列.
  从最右开始,找到第一个比右边小的数字4(因为4<7，而7>5>2>1),
  再从最右开始,找到4右边比4大的数字5(因为4>2>1而4<5),
  交换4、5,此时5右边为7421,倒置为1247,即得下一个排列:839651247.
  该方法支持数据重复，且在C++ STL中被采用。
  http://hi.baidu.com/zxb19880518/item/af05702e71a8f40872863e81
 */
