#include <cstdio>
using namespace std;

int main()
{
  int i;
  i = 10;
  printf("i : %d\n", i);
  printf("sizeof(i++) is: %d\n", sizeof(i++));
  printf("i : %d\n", i);
  return 0;
}

// 10 4 10
// 因为sizeof是一个操作符而非函数调用，在编译期间编译器就会计算出sizeof(i )的值，表达式i 并不会被真正执行。实际上，编译器只是将 i 的类型（当然是int）作为sizeof操作符的操作数，在编译时就将sizeof(i )的值确定好了。
// 因为编译器需要知道的只是sizeof(i++)的值是多少，这个值在编译时计算出来后被拿来直接替代整个sizeof(i++)
