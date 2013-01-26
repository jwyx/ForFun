/*
 *  Question:
 *    prints all the prime numbers less than 1000
 *
 *  Solution:
 *    the "sieve of Eratosthenes"
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> primes(int n)
{
  vector<int> result;
  vector<int> marks (n + 1, 1);

  for (int i = 2; i <= n/2; i ++) {
    // skip non-prime
    if (0 == marks[i])
      continue;

    // set non-prime to 0
    for (int j = 2; i * j <= n; j ++)
      marks[i * j] = 0;
  }

  // find all primes
  for (int i = 1; i <= n; i ++) {
    if (marks[i])
      result.push_back(i);
  }

  return result;
}

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  vector<int> result = primes(n);
  for (auto &x : result)
    cout << x << " ";
  cout << endl;
}
