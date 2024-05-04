/*
 * author: inkXu
 * date:   2022.7.8
 *
 * 内存泄漏
 * 但你申请了一块空间（堆区、栈区等），你不小心把这块空间给弄丢了，找不回来了，即为内存泄漏
 * 当你的程序多次调用这导致内存泄漏的代码，会导致内存空间的不足
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//该函数内动态申请了堆区的一块空间，没有将申请的空间首地址返回出去
//其内也没有释放这块空间，内存发生泄漏
void fun()
{
  char *str = (char *)calloc(4, 8);
  strcpy(str, "none,none,none.");
}

void main()
{
  fun();

  //p指向的地址为堆区的地址
  char *p = (char *)malloc(100);
  printf("&p = %p\n", p);
  //free有用，释放的是堆区空间
  //free(p);
  //p = NULL;

  //p指向的是文字常量区的地址
  p = "Hello";
  printf("&p = %p\n", p);
  //free无用，p指向的是文字常量区
  //free(p);
  //p = NULL;
}
