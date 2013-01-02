bool canJump(int A[], int n) {
  // table[n]: can we reach index n from first index (0)
  // table[n] = && all table[i] (i is with index from which can reach n with one step, and i != n)
  // base case: table[0] = true
  //
  // how to find all indexes meeting requirements
  // one pass to find all indexes each index can reach in one step store in the vector that the index is the destination index,
  // the element is all source indexes that can reach here with one step

  vector<int> v;
  vector<vector<int> > sources (n, v);
  vector<int> table (n, false);

  // base case
  table[0] = true;

  // prepare the data structure
  for (int i = 0; i < n; i ++) {
    for (int j = 1; j <= A[i]; j ++) {
      int next = i + j;
      if (next < n)
        sources[next].push_back(i);
    }
  }

  // general case
  for (int i = 1; i < n; i ++) {
    for (int j = 0; j < sources[i].size(); j ++) {
      table[i] = table[i] || table[sources[i][j]];
      if (table[i])
        break;
    }
  }

  return table[n - 1];
}

// improved space, TODO: bad time ?
bool canJump(int A[], int n) {
  // table[n]: can we reach index n from first index (0)
  // table[n] = && all table[i] (i is with index from which can reach n with one step, and i != n)
  // base case: table[0] = true
  //
  // how to find all indexes meeting requirements
  // check all the index before curr, check valid one

  vector<int> table (n, false);

  // base case
  table[0] = true;

  // general case
  for (int i = 1; i < n; i ++) {
    for (int j = 0; j < i; j ++) {
      if (A[j] + j >= i)
        table[i] = table[i] || table[j];
      if (table[i])
        break;
    }
  }

  return table[n - 1];
}


// dfs
// credit: http://blog.csdn.net/zhiyu27/article/details/8192824
bool canJump(int A[], int n) {
  int curr = 0;
  while (1) {
    bool flag = true;
    // reach end
    if (curr + A[curr] >= n - 1)
      return true;

    // choose different path
    for (int i = curr + 1; i < curr + A[curr] + 1; i ++) {
      // trim useless path
      if (i + A[i] >= curr + A[curr]) {
        // reach further
        curr = i;
        flag = false;
        break;
      }
    }
    if (flag)
      return false;
  }
  return false;
}

// credit: http://leetcode.com/questions/232/jump-game
bool canJump(int A[], int n) {
  if (n == 1)
    return true;

  int curr_max = 0, target = n - 1;
  for (int i = 0; i < n - 1; ++ i) {
    if (A[i] == 0 && curr_max < i + 1)
      return false;
    if (A[i] + i > curr_max && A[i] > 0) {
      curr_max = A[i] + i;
      if (curr_max >= target)
        return true;
    }
  }
  return false;
}
