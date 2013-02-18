#include <iostream>
#include <algorithm>
#include <bitset>

#define N 5001

using namespace std;

struct stick {
  int length, weight;
  stick(int l = 0, int w = 0) : length(l), weight(w) { }
};

bool comp(const stick &a, const stick &b) {
  return (a.length < b.length || (a.length == b.length && a.weight < b.weight));
}

int main (int argc, char *argv[])
{
  int count = 0, n = 0, result = 0;
  stick data[N];
  bitset<N> flags;
  cin >> count;

  while (count--) {
    cin >> n;

    result = 0;
    flags.reset();
    for (int i = 0; i < n; i++) {
      cin >> data[i].length >> data[i].weight;
    }

    sort(data, data + n, comp);

    for (int i = 0; i < n; i++) {
      if (!flags.test(i)) {
        ++result;
        flags.set(i);

        int weight = data[i].weight;
        for (int j = i+1; j < n; j++) {
          if (!flags.test(j) && weight <= data[j].weight) {
            flags.set(j);
            weight = data[j].weight;
          }
        }
      }
    }
    cout << result << endl;
  }
}
