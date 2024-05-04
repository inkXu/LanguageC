/*
 * author: inkXu
 * date:   2022.7.7
 *
 * 函数指针数组
 *
 * 本质是一个数组，该数组存放的是函数指针
 * 主要作用：定义一个回调函数(callback)，作为回调函数的参数
 * 使用回调函数的目的：可能加减乘除这些函数是已经封装好了的，他们封装好了的函数的参数值没有事先知道
 */
#include<stdio.h>

int add(int a, int b);
int div(int a, int b);
int reduce(int a, int b);
int mul(int a, int b);
int process(int(*p)(int, int), int a, int b);

void main()
{
  int a = 10, b = 4;
  int result = 0;

  result = process(add, a, b);
  printf("result of add: %d\n", result);

  result = 0;
  result = process(div, a, b);
  printf("result of div: %d\n", result);

  result = 0;
  result = process(mul, a, b);
  printf("result of mul: %d\n", result);

  result = 0;
  result = process(reduce, a, b);
  printf("result of reduce: %d\n", result);
}

int process(int(*p)(int, int), int a, int b)
{
  int result = 0;
  result = p(a, b);
  //result = (*p)(a, b);
  return result;
}

int add(int a, int b)
{
  return a + b;
}

int div(int a, int b)
{
  return a / b;
}

int reduce(int a, int b)
{
  return a - b;
}

int mul(int a, int b)
{
  return a * b;
}



