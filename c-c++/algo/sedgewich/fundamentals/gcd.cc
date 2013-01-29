/*
 *  Question:
 *    "Reduce a given fraction to its lowest terms; Or find the greatest common divisor (gcd)
 *    of the numerator and the denominator: the largest integer which divides them both"
 *
 *  Solution:
 *    Euclid algorithm
 *    Based on the fact that:
 *      If u is greater than v then the greatest common divisor of u and v is the same as the
 *      greatest common divisor of v and u - v
 *
 *    => the greatest common divisor of u and v is the same as the greatest common divisor of
 *       v and u % v (u >= v)
 *
 *    辗转相除法
 *    核心观点: v 和 u 的最大公因素能整除 v 和 u % v
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int gcd_recur(int u, int v)
{
  if (v == 0) return u;
  if (u < v)
    swap(u, v);
  u %= v;
  return gcd_recur(v, u);
}

int gcd(int u, int v)
{
  // If negative
  u = abs(u);
  v = abs(v);

  while (u > 0) {
    if (u < v)
      swap(u, v);
    u %= v;
  }
  return v;
}

// 扩展1, reduce a given fraction to lowest terms
struct fraction {
  int numerator;
  int denominator;
};

fraction &reduce_fraction(fraction &f)
{
  int gcd_number = gcd(f.numerator, f.denominator);
  if (gcd_number > 1) {
    f.numerator /= gcd_number;
    f.denominator /= gcd_number;
  }
  return f;
}

// 扩展2, 列出所有可能的fraction形式
// 思路: 分解质因素，然后求所有质因素的组合(不包括空集)

// 因式分解
vector<int> factorize(int n)
{
  vector<int> result;

  for (int i = 2; i <= n; i ++) {
    while (n % i == 0) {
      n /= i;
      result.push_back(i);
    }
  }

  return result;
}

// 所有约数，包括重复
vector<int> all_dividors(vector<int> &factors)
{
  vector<int> result(1, 1);

  for (int i = 0; i < factors.size(); i ++) {
    for (int j = result.size() - 1; j >= 0; j --) {
      result.push_back(result[j] * factors[i]);
    }
  }

  return result;
}

vector<fraction> all_fractions(fraction &f)
{
  vector<fraction> result;
  vector<int> factorize_result = factorize(gcd(f.numerator, f.denominator));
  vector<int> dividors = all_dividors(factorize_result);
  // 去除重复
  set<int> distinct_dividors (dividors.begin(), dividors.end());

  for (auto &x : distinct_dividors) {
    fraction temp = f;
    temp.numerator /= x;
    temp.denominator /= x;
    result.push_back(temp);
  }

  return result;
}

// 扩展3, 三个数的最大公约数
// 思路: 调用两次gcd
int gcd_three(int u, int v, int w)
{
  int gcd_number = gcd(u, v);
  if (gcd_number > 1) {
    gcd_number = gcd(gcd_number, w);
  }
  return gcd_number;
}

int main (int argc, char *argv[])
{
  int u, v, w;
  cin >> u >> v >> w;
  cout << u << " " << v << " " << gcd_recur(u, v) << endl;

  // 扩展1
//  fraction f;
//  f.numerator = u;
//  f.denominator = v;
//  reduce_fraction(f);
//  cout << f.numerator << " " << f.denominator << " " << endl;

  // 扩展2
//  vector<int> result = factorize(gcd(u, v));
//  for (auto &x : result)
//    cout << x << " ";
//  cout << endl;
//
//  vector<int> dividors = all_dividors(result);
//  set<int> distinct_dividors (dividors.begin(), dividors.end());
//  for (auto &x : distinct_dividors)
//    cout << x << " ";
//  cout << endl;

//  fraction f;
//  f.numerator = u;
//  f.denominator = v;
//  vector<fraction> fractions = all_fractions(f);
//  for (auto &x : fractions)
//    cout << x.numerator << " " << x.denominator << " ";
//  cout << endl;

  // 扩展3
//  cout << u << " " << v << " " << w << " " << gcd_three(u, v, w) << endl;
}
