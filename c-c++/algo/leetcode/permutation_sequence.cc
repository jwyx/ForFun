string getPermutation(int n, int k) {
  assert(k >= 1);

  int fac = 1, d = 0;
  for (int i = 1; i <= n; i ++) {
    fac *= i;
    if (fac >= k) {
      fac /= i;
      k -= fac;
      d = i - 1;
      break;
    }
  }

  string result;
  for (int i = 1; i <= n; i ++)
    result.push_back(i + '0');

  reverse(result.end() - d, result.end());

  for (int i = 0; i < k; ++ i)
    nextPermutation(result);

  return result;
}

void nextPermutation(string &result) {
  int i = 0, j = 0;
  for (i = result.size() - 2; i >= 0 && result[i] >= result[i + 1]; -- i)
    ;
  for (j = result.size() - 1; j >= 0 && result[i] >= result[j]; -- j)
    ;
  swap(result[i], result[j]);
  reverse(result.begin() + i + 1, result.end());
}
