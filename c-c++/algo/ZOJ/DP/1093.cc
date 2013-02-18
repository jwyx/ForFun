// 问题：给定n种block，表示为(x, y, z)，可以reoriented，
//       保证上方的箱子的底面两条边分别严格小于下方箱子的底面对应边(不是同时小于两条边)，
//       求出能叠出的最大高度
// 思路：DP 最大高度非降序列

#include <iostream>
#include <algorithm>

#define N (3*30)

using namespace std;

struct block {
  int bs; // base small dimension
  int bl; // base large dimension
  int h;  // height
};

bool comp(const block &a, const block &b) {
  return (a.bl < b.bl || (a.bl == b.bl && a.bs <= b.bs));
}

int main(int argc, char *argv[])
{
  int n = 0, result = 0, base_i = 0, size = 0;
  int case_index = 1;
  int d[3] = { 0 };
  int sum[N] = { 0 }; // the largest height for tower include block i
  block data[N];
  cin >> n;

  while (n) {

    for (int i = 0; i < n; i++) {
      base_i = 3*i;

      cin >> d[0] >> d[1] >> d[2];
      sort(d, d+3);

      // create 3 kinds of block for each block
      data[base_i].h = d[0];
      data[base_i].bs = d[1];
      data[base_i].bl = d[2];

      data[base_i+1].h = d[1];
      data[base_i+1].bs = d[0];
      data[base_i+1].bl = d[2];

      data[base_i+2].h = d[2];
      data[base_i+2].bs = d[0];
      data[base_i+2].bl = d[1];
    }

    size = 3*n;
    sort(data, data+size, comp);

    // time O(n^2)
    for (int i = 0; i < size; i++) {
      sum[i] = data[i].h;
      for (int j = i-1; j >= 0; j--) {
        if (data[j].bl < data[i].bl && data[j].bs < data[i].bs &&
            sum[i] < data[i].h + sum[j])
          sum[i] = data[i].h + sum[j];
      }
    }

    result = 0;
    for (int i = 0; i < size; i++) {
      if (result < sum[i])
        result = sum[i];
    }

    cout << "Case " << case_index++ << ": maximum height = " << result << endl;

    cin >> n;
  }

}
