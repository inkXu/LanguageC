#include<stdio.h>

//宏定义
#define PI 3.1415926

//带参宏
#define SUM(a, b) a*b
//这样写不会出下面的问题
#define _SUM(a, b) ((a)*(b))

void main()
{
  double i = PI;
  printf("=%lf=\n", i);

//取消宏定义，不咋用
#undef PI

#define PI 3.14

  i = PI;
  printf("=%d=\n", i);

  printf("=%d=\n", SUM(5, 3));

//输出为17，带参宏里的参数不会加括号，它只是简答的替换一下
//计算为：5+4*3 = 17
  printf("=%d=\n", SUM(5 + 4, 3));

  printf("=%d=\n", _SUM(5, 3));

//计算为：((5+4)*(3)) = 27
  printf("=%d=\n", _SUM(5 + 4, 3));
}
