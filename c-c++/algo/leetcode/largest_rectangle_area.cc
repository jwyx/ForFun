#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// credit: http://blog.csdn.net/dgq8211/article/details/7740610
// 算法基本思路是：
// 对每个元素计算左宽和右宽
// 如何减少计算量，是此方法的核心
//
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

int main(void) {
  int a[] = { 2,1,5,6,2,3 };
  vector<int> v (a, a + sizeof(a)/sizeof(int));
  cout << largestRectangleArea(v) << endl;
}

//对于每个高度，它的作用无非两个：1、以自己作高，向外扩展        2、以别人作高，自己被扩展
//【当以自己作高完毕以后，它的高度就没有什么意义了，为了方便，我们可以把它的高度看做与之后栈顶元素相等，即之后的栈顶元素可以看做是大于左面全部的元素】
