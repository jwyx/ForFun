// credit: http://blog.csdn.net/maqingli87/article/details/7997938
bool isMatch(const char *s, const char *p) {
  if(0 == *p)
    return 0 == *s;//模式串已结束，字符串还有内容
  if('*' == *(p+1))//模式串下一个字符是'*'
  {
    //字符串当前字符与模式串当前字符匹配，且模式串下一个字符为'*'
    while(*s == *p || ('.' == *p && 0 != *s))
    {
      //字符串与模式串匹配0/1/2...个字符的情况
      if(isMatch(s++, p+2))
        return true;
    }
    //字符串与模式串不能匹配(字符不相同，或已到达结尾)，跳过当前字符和下一个'*';
    return isMatch(s, p+2);
  }
  else//模式串下一个字符不是'*'
  {
    if(*p == *s || ('.' == *p && 0 != *s))//能匹配，且没有'*'
      return isMatch(s+1, p+1);//都向前走一步
    return false;
  }
}

