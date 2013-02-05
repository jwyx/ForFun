// 题意： 给出3种装备的信息(w, s, d)，3种装备组合后的信息(c1, c2, c3, d)，给出n种货车的信息(w, s)，求出最大防御值的装载方案
// 思路： 背包问题；如果知道每种装备的数量，那么就能简单的求出防御值
//        chart[n][x][y] 表示前n辆车装了x个装备1和y个装备2之后能装的最多的装备3的个数
//
// 改进： 改进空间使用，使用两个数组
//        chart[prev][i][j]数组，存放商队可以放第一种武器i个，第二种j个，第三种carry[i][j]个。最终结果是存放所有装备运输的可能组合。
//        chart[curr][i][j]数组，存放动态规划过程中，到目前为止所有商队，可以运输第一种i个，第二种 j个，第三种trade[i][j]个。
//
// Credit: http://www.cnblogs.com/zuckerTT/archive/2012/05/12/2497288.html
//         http://blog.csdn.net/leohxj/article/details/6001183
//         http://blog.csdn.net/wens07/article/details/6704395

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX_CASE 501

using namespace std;

int main(int argc, char *argv[])
{
  // case index
  int case_index = 1;
  // count of caravans
  int n = 0;
  // weight, size, define
  int w[3] = { 0 };
  int s[3] = { 0 };
  int d[3] = { 0 };
  // helm, armor, boot, the capability of this set
  int c1 = 0, c2 = 0, c3 = 0, d4 = 0;
  int chart[2][MAX_CASE][MAX_CASE];

  cin >> n;

  while (n) {
    // 最大的防御值记录
    int result = 0;
    int prev = 0, curr = 1;

    // 初始化，标记无效数据
    memset(chart[prev], -1, sizeof(chart[prev]));
    chart[prev][0][0] = 0;

    for (int i = 0; i < 3; i++)
      cin >> w[i] >> s[i] >> d[i];
    cin >> c1 >> c2 >> c3 >> d4;
    // 修改成套件产生的额外增加的防御值
    d4 -= c1*d[0] + c2*d[1] + c3*d[2];

    int ni = 0, nj = 0, nk = 0, max_i = 0, max_j = 0;
    int nj_w = 0, nj_s = 0;
    int weight = 0, size = 0;

    while (n--) {
      // 读入第n车的容量参数
      cin >> weight >> size;

      memset(chart[curr], -1, sizeof(chart[curr]));

      // 第n车能装最多的helm数
      ni = min(weight/w[0], size/s[0]);
      for (int i = 0; i <= ni; i++) {
        // 装完i件helms后，第n车能装最多的armor数
        nj_w = weight - i*w[0]; // 为了减少运算
        nj_s = size - i*s[0];
        nj = min(nj_w/w[1], nj_s/s[1]);
        for (int j = 0; j <= nj; j++) {
          // 装完i件helms和j件armors后最多能装的boot数
          nk = min((nj_w - j*w[1])/w[2], (nj_s - j*s[1])/s[2]);
          // 历遍前n-1车所有可能的装车情况，更新所有n车的情况
          for (int a = 0; a <= max_i && i+a < MAX_CASE; a++) {
            for (int b = 0; b <= max_j && j+b < MAX_CASE; b++) {
              // 保证第n车的boot数有效，并且前n-1车的数据有效，才更新
              if (chart[prev][a][b] >= 0 && nk >= 0) {
                if (chart[curr][i+a][j+b] < chart[prev][a][b] + nk)
                  chart[curr][i+a][j+b] = chart[prev][a][b] + nk;
              }
            }
          }
        }
      }

      // 纪录n车数据可能的组合范围
      max_i += min(weight/w[0], size/s[0]);
      max_j += min(weight/w[1], size/s[1]);
      // 防止数组越界
      max_i = min(MAX_CASE - 1, max_i);
      max_j = min(MAX_CASE - 1, max_j);

      // 交换数组
      prev = curr;
      curr = (++curr) % 2;
    }

    for (int i = 0; i <= max_i; i++) {
      for (int j = 0; j <= max_j; j++) {
        if (chart[prev][i][j] >= 0) {
          // 能组成的套件数
          int min_i = i / c1, min_j = j / c2, min_k = chart[prev][i][j] / c3;
          result = max(result, i*d[0] + j*d[1] + chart[prev][i][j]*d[2] + d4*min(min(min_i, min_j), min_k));
        }
      }
    }
    cout << "Case " << case_index++ << ": " << result << endl;
    cin >> n;

    // 调整输出格式
    if (n)
      cout << endl;
  }
}

