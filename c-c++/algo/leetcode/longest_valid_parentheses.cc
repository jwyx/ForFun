// credit: http://haixiaoyang.wordpress.com/2012/08/05/longest-valid-parenthesis/
int longestValidParentheses(const char* str) {
  assert(str);
  int nMax = 0;
  const char* p = str;
  stack<const char*> stk;
  while (*p != 0) {
    if (*p == '(')
      stk.push(p);
    else if (*p == ')') {
      if (!stk.empty() && *stk.top() == '(') {
        stk.pop();
        nMax = max(p - (stk.empty() ? str-1 : stk.top()), nMax);
      }
      else stk.push(p);
    }
    p++;
  }
  return nMax;
}


int longestValidParentheses(string s) {
  int result = 0, prev = 0;
  stack<int> stk;
  for (int i = 0; i < s.size(); i ++) {
    if (s[i] == '(')
      stk.push(i);
    else if (s[i] == ')') {
      if (!stk.empty() && s[stk.top()] == '(') {
        stk.pop();
        // the start of valid parentheses string
        prev = stk.empty() ? -1 : stk.top();
        result = max(i - prev, result);
      }
      else
        stk.push(i);
    }
  }
  return result;
}

