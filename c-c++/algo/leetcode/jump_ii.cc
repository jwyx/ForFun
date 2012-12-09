// bad time!! DP
int jump(int A[], int n) {
  // table[n]: can we reach index n from first index (0)
  // table[n] = && all table[i] (i is with index from which can reach n with one step, and i != n)
  // base case: table[0] = true
  //
  // how to find all indexes meeting requirements
  // check all the index before curr, check valid one

  vector<int> table (n, INT_MAX);

  // base case
  table[0] = 0;

  // general case
  int start = 0;
  for (int i = 1; i < n; i ++) {
    bool flag = true;
    for (int j = start; j < i; j ++) {
      if (A[j] + j >= i) {
        if (table[j] + 1 < table[i])
          table[i] = table[j] + 1;
        flag = false;
      }
      else if (flag)
        start += 1;
    }
  }

  return table[n - 1];
}

// greedy!!! TODO: prove
// credit: http://blog.csdn.net/zhiyu27/article/details/8192833
int jump1(int A[], int n) {
  int curr = 0,count = 0;
  while (1){
    if(curr == n-1)
      return count;
    if(A[curr] + curr >= n-1)
      return ++count;
    int maxi = curr + 1, maxsum = 0;
    // select the next index which can jump furthest
    for(int i = curr + 1; i <= curr + A[curr]; ++i) {
      if(maxsum < A[i] + i){
        maxsum = A[i] + i;
        maxi = i;
      }
    }
    if(maxsum > A[curr] + curr) {
      curr = maxi;
      ++ count;
    }
    else {
      return 0;
    }
  }
  return 0;
}
