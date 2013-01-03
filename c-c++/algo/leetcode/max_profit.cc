#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// http://blog.csdn.net/zhiyu27/article/details/8185037
// I
int maxProfit(vector<int> &prices) {
  int min_val = INT_MAX;
  int profit = 0;
  for (int i = 0; i < prices.size(); i ++) {
    if (min_val > prices[i])
      min_val = prices[i];
    else if (prices[i] - min_val > profit)
      profit = prices[i] - min_val;
  }
  return profit;
}

int maxProfit1(vector<int> &prices) {
  if (prices.empty())
    return 0;

  int curr = prices[0], total = 0;
  for (int i = 1; i < prices.size(); ++ i) {
    // 确定当前的最小值，记录之后的差值
    if (prices[i] > curr)
      total = max(prices[i] - curr, total);
    else
      // 最小值记录
      curr = prices[i];
  }
  return total;
}

// II
int maxProfit2(vector<int> &prices) {
  if (prices.empty())
    return 0;

  int curr = prices[0], total = 0;
  for(int i = 1; i < prices.size(); ++i){
    if(prices[i] > curr)
      total += prices[i] - curr;
    curr = prices[i];
  }
  return total;
}

// III, DP
// 分成两个数组，分别寻找两个数组的最大股票
int maxProfit3(vector<int> &prices) {
  if (prices.empty())
    return 0;

  vector<int> totals (prices.size(), 0);
  int curr = prices[0], curr1 = prices.back();
  int diff = 0, diff1 = 0;
  for(int i = 1, j = prices.size() - 2; i < prices.size(); ++ i, -- j){
    if (prices[i] > curr)
      diff = max(prices[i] - curr, diff);
    else
      curr = prices[i];

    if (prices[j] < curr1)
      diff1 = max(curr1 - prices[j], diff1);
    else
      curr1 = prices[j];

    totals[i] += diff;
    totals[j] += diff1;
  }
  return *max_element(totals.begin(), totals.end());
}

int main(void) {
  int a[] = { 11,7,2,4,1 };
  vector<int> v (a, a + sizeof(a) / sizeof(int));
  cout << maxProfit3(v) << endl;
}
