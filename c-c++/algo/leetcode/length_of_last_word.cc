// credit: http://blog.csdn.net/zhiyu27/article/details/8192856
// GOOD!!!
int lengthOfLastWord(const char *s) {
  const char *p1 = s, *p2 = s;
  int last=0;
  do{
    p1 = p2;
    while(*p1 == ' ')
      ++ p1;
    if(* p1 == '\0')
      break;
    p2 = p1;
    while (*p2 != ' ' && *p2 != '\0')
      ++ p2;
    last = p2-p1;
  } while(*p2);

  return last;
}
