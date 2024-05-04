#include<stdio.h>

void test1();
void test2();

void main()
{
  test1();
  test2();
}

void test2()
{
  int a = 100;
  int *p1;

  p1 = &a;

  printf("&a = %p\n", &a);
  printf("a = %d\n", a);
  printf("p1 = %#x\n", p1);
  printf("*p1 = %d\n", *p1);
}

void test1()
{
  int a = 100;
  int *p;
  //指针的直接初始化，下面语句等价于p2 = &a;
  int *p2 = &a;

  p = &a;

  printf("=%d=\n",*p);
  printf("=%d=\n",a);

  printf("=%p=\n",p);
  printf("=%p=\n",&a);

  printf("=%d=\n",sizeof(p));
}
