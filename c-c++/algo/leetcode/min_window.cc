// credit: http://www.leetcode.com/2010/11/finding-minimum-window-in-s-which.html
string minWindow(string S, string T) {
  int tLen = T.size();
  int sLen = S.size();

  int needToFound[256] = { 0 };
  for (int i = 0; i < tLen; i ++)
    needToFound[T[i]] ++;

  int hasFound[256] = { 0 };
  int count = 0;
  int minLen = INT_MAX, minStart = 0, minEnd = 0;
  for (int start = 0, end = 0; end < sLen; end ++) {
    if (!needToFound[S[end]])
      continue;

    hasFound[S[end]] ++;
    if (hasFound[S[end]] <= needToFound[S[end]])
      count ++;

    // if window constraint is satisfied, keep going without break it
    if (count == tLen) {
      while (hasFound[S[start]] > needToFound[S[start]] || !needToFound[S[start]]) {
        if (hasFound[S[start]] > needToFound[S[start]])
          hasFound[S[start]] --;
        start ++;
      }

      int len = end - start + 1;
      if (len < minLen) {
        minLen = len;
        minStart = start;
        minEnd = end;
      }
    }
  }
  // NOTE: usage of substr function
  return (count == tLen ? S.substr(minStart, minLen) : "");
}
// O(n)
