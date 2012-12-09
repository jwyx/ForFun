#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// credit: http://blog.csdn.net/zhiyu27/article/details/8195349
int lengthOfLongestSubstring(string s) {
  map<char,int> mymap;
  vector<int> pos;
  for(int i = 0; i < s.size(); ++i){
    pos.push_back(mymap[s[i]]);
    mymap[s[i]] = i + 1; // 表示上一个重复项后面的那一项
  }

  int result = 0, curr = 0;
  for(int j = 0; j < s.size(); ++j){
    // 说明之前处理过的每一项都是去重的
    curr = max(curr, pos[j]);
    // 当前位置到没有重复项的第一项的长度
    result = max(result, j-curr+1);
  }
  return result;
}

int main(void) {
  lengthOfLongestSubstring(string("bbbb"));
}

// credit: http://www.leetcode.com/2011/05/longest-substring-without-repeating-characters.html
int lengthOfLongestSubstring(string s) {
  int n = s.length();
  int i = 0, j = 0;
  int maxLen = 0;
  bool exist[256] = { false };
  while (j < n) {
    if (exist[s[j]]) {
      maxLen = max(maxLen, j-i);
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  maxLen = max(maxLen, n-i);
  return maxLen;
}

