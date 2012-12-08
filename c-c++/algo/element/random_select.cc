// RANDOMIZED-SELECT(A, p, r, i)
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int partition(vector<int> &v, int p, int r) {
  int x = v[r];
  int i = p - 1, j = p;
  for (j = p; j < r; j ++) {
    if (v[j] <= x)
      swap(v[++i], v[j]);
  }
  swap(v[++i], v[r]);
  return i;
}

int randomized_partition(vector<int> &v, int p, int r) {
  int i = p + rand() % (r - p + 1);
  swap(v[i], v[r]);
  return partition(v, p, r);
}

int randomized_select(vector<int> &v, int p, int r, int i) {
  if (p == r)
    return v[p];

  int q = randomized_partition(v, p, r);
  int k = q - p + 1;
  if (k == i)
    return v[q];
  else if (k > i)
    return randomized_select(v, p, q - 1, i);
  else
    return randomized_select(v, q + 1, i - k, i);
}

int main(int argc ,char *argv[])
{
  int arr[100];
  int test;
  srand(time(NULL));
  for (int i = 0; i < 100; i ++)
    arr[i] = rand() % 1000;
  vector<int> v (arr, arr + sizeof(arr) / sizeof(int));

  sort(arr, arr + sizeof(arr) / sizeof(int));
  for (int i = 0; i < 100; i ++) {
    cout << arr[i] << " " ;
    if ((i+1)%10 ==0 )
      cout << endl;
  }

  cout << " 输入想查第几小的数 : " ;
  cin >> test;
  cout << randomized_select(v, 0 , 100 - 1, test) << endl;
  return 0;
}

