// 题目：最大子矩阵
// 思路：将第i到j行的值按列累加，然后使用最大连续子串求解
//       O(n^3)

#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

#define N 100

using namespace std;

// time O(n)
int max_subarray(const int array[], const int n)
{
  int sum = 0, max_val = 0;

  for (int i = 0; i < n; i++) {
    if (sum >= 0)
      sum += array[i];
    else
      sum = array[i];

    if (max_val < sum)
      max_val = sum;
  }
  return max_val;
}


int main(int argc, char *argv[])
{
  int n = 0, size = 0, result = INT_MIN;
  int data[N][N] = { { 0 } };
  int sum[N] = { 0 };
  cin >> n;

  size = n*n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> data[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    memset(sum, 0, sizeof(sum));

    for (int j = i; j < n; j++) {

      for (int k = 0; k < n; k++)
        sum[k] += data[k][j];

      result = max(result, max_subarray(sum, n));
    }
  }
  cout << result << endl;
}
