#include<stdio.h>
#include<string.h>

void test1();
void test2();
void test3();

void main()
{
  //test1();
  //test2();
  test3();
}

void test3()
{
  //指针数组一般用于保存多个字符串
  char *q[] = {"I","love","you","forever"};

  int i = 0;
  for(; i < 4; i++)
  {
    printf("q[%d] = %s\n", i, q[i]);
  }
}

void test1()
{
  int a = 1, b = 2, c = 3;
  int *p[3];

  //指针数组的赋值，注意*p[0]=&a;是错的，*p[0]=a;也是错的
  p[0] = &a;
  //者两个赋值方式没懂
  *(p + 1) = &b;
  *(p + 2) = &c;

  //printf("a = %d\n",a);
  //打印出的是指针数组的值
  printf("*p[0] = %d\n", *p[0]);
  printf("*p[1] = %d\n", *p[1]);
  printf("*p[2] = %d\n", *p[2]);
  //打印出的是地址
  printf("*p + 0 = %#x\n", *p + 0);
  printf("*p + 1 = %#x\n", *p + 1);
  printf("*p + 2 = %#x\n", *p + 2);
}

void test2()
{
  int ii[] = {1,2,3,4,5};
  int *p1 = &ii[0];
  int *p2 = &ii[4];

  printf("p1 address:%#x\n", p1);
  printf("p2 address:%#x\n", p2);
  //同一数组内，指针相减得到的是元素的个数差，不是地址差
  printf("p2 - p1 = %d\n", p2 - p1);
}
