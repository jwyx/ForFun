int maximalRectangle(vector<vector<char> > &matrix) {
  int maxVal = 0;
  if (matrix.empty() || matrix[0].empty())
    return maxVal;

  // change char representation to int
  for (int j = 0; j < matrix[0].size(); j ++)
    matrix[0][j] -= '0';

  for (int i = 1; i < matrix.size(); i ++) {
    for (int j = 0; j < matrix[i].size(); j ++) {
      matrix[i][j] -= '0';
      if (matrix[i][j] > 0)
        matrix[i][j] = matrix[i][j] + matrix[i - 1][j];
    }
  }

  for (int i = 0; i < matrix.size(); i ++)
    maxVal = max(maxVal, largestRectangleAreaChar(matrix[i]));
  return maxVal;
}

int largestRectangleAreaChar(vector<char> &heightChar) {
  vector<int> height;
  for (int i = 0; i < heightChar.size(); i ++)
    height.push_back(heightChar[i]);
  return largestRectangleArea(height);
}

int largestRectangleArea(vector<int> &height) {
  stack<int> s; // 高度从低到高的单调栈
  stack<int> w; // s中对应高度的虚拟宽度 (自己和直方图中左边所有高于自己的元素的总宽度)
  int ans = 0, h = 0;

  for (int i = 0; i <= height.size(); i ++) {
    // h = 0是为了使所有元素出栈,因为最大值的计算只发生在出栈
    h = (height.size() == i ? 0 : height[i]);

    // 如果h > s.top(), 入栈
    if (s.empty() || h > s.top()) {
      s.push(h);
      // 左宽为自己
      w.push(1);
    }
    else {
      // 连续出栈中的第一个出栈, 右宽为0
      int cnt = 0;
      while (!s.empty() && h <= s.top()) {
        // cnt 右宽, 不包括自己 + w.top() 左宽,包括自己 -> 总宽
        // cnt 出栈的元素的宽度累计, 出栈的元素都大于栈内元素，所以为右宽
        // w.top() 看成是s.top()高度的宽度，此宽度包含了之前出栈元素的信息，既为左宽的一部分
        ans = max(ans, (cnt + w.top()) * s.top());
        cnt += w.top();
        s.pop();
        w.pop();
      }
      s.push(h);
      // cnt + 1 相当于当前高度的宽度, 其他出栈元素可以看成与此高度的一部分，因为都大于此高度
      w.push(cnt + 1);
    }
  }
  return ans;
}
