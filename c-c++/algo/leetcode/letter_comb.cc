#include <iostream>
#include <string>
#include <vector>
using namespace std;

// credit: http://blog.csdn.net/zhiyu27/article/details/8192857
vector<string> letterCombinations(string digits) {
  char* str[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  vector<string> result;
  result.push_back("");
  for(int i=0;i<digits.size();++i){
    vector<string> next;
    for(vector<string>::iterator iter=result.begin();
        iter!=result.end();++iter){
      if(digits[i]>'1'&&digits[i]<='9'){
        int j = 0;
        while(str[digits[i]-'2'][j]){
          next.push_back((*iter)+str[digits[i]-'2'][j]);
          ++j;
        }
      }
      else
        next.push_back(*iter);
    }
    result=next;
  }
  return result;
}

int main(void) {
  string tmp;
  cin >> tmp;
  vector<string> v = letterCombinations(tmp);
  for (int i = 0; i < v.size(); i ++) {
    cout << v[i] << endl;
  }
}
