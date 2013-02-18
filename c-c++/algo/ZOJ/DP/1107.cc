// Credit
//   http://www.fookwood.com/archives/188

// dp[i][j] 从i,j作为开始点所能得到的最多的cheese数，从最大cheese数的位置开始处理

#include <iostream>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

struct point {
  int x;
  int y;
  int cheese;
};

bool comp(const point &a, const point &b)
{
  return (a.cheese > b.cheese);
}

int main (int argc, char *argv[])
{
  int n, k;
  cin >> n >> k;

  long dp[MAX_NUM][MAX_NUM] = { { 0 } };
  int grid[MAX_NUM][MAX_NUM] = { { 0 } }; // store cheese count
  point grid_list[MAX_NUM*MAX_NUM];

  // left, up, right, bottom
  int dx[4] = { -1, 0, 1, 0 };
  int dy[4] = { 0, -1, 0, 1 };

  while (n != -1 && k != -1) {

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int k = i*n+j;

        cin >> grid_list[k].cheese;
        grid_list[k].x = i;
        grid_list[k].y = j;

        dp[i][j] = grid_list[k].cheese;
        grid[i][j] = grid_list[k].cheese;
      }
    }

    // 保证处理所有情况, cheese从大到小排序
    sort(grid_list, grid_list + n*n, comp);

    int size = n*n;
    int xx = 0, yy = 0, x = 0, y = 0;
    long max_val = 0;

    for (int i = 0; i < size; i++) {
      x = grid_list[i].x;
      y = grid_list[i].y;

      max_val = 0;
      // four directions
      for (int j = 0; j < 4; j++) {
        xx = x;
        yy = y;

        // 找到所有可行解
        for (int l = 0; l < k; l++) {
          xx += dx[j];
          yy += dy[j];

          if (xx < 0 || xx >= n || yy < 0 || yy >= n)
            break;

          if (grid[xx][yy] > grid[x][y] &&
              max_val < dp[xx][yy])
            max_val = dp[xx][yy];
        }
      }
      dp[x][y] += max_val;
    }
    cout << dp[0][0] << endl;

    cin >> n >> k;
  }

}

