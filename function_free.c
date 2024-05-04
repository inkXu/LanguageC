/*
 * author: inkXu
 * date:   2022.7.8
 *
 * void free(*ptr)
 *
 * 只能释放堆区申请的空间
 * free释放空间必须是malloc、calloc或relloc的返回值对应的空间，释放的是全部空间，不是一部分
 * 在堆区申请的内存只能释放一次
 * 使用free释放后，p仍旧存放了之前使用的地址，但我们不能使用p了，它成了野指针
 * 使用free后的指针最好赋NULL值，防止其它程序申请到该地址，而p莫名被调用，读取到其它程序的数据
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *fun()
{
  char *str = (char *)malloc(100);
  strcpy(str,"welcome to China");
  return str;
}

void main()
{
  char *p;
  p = fun();
  printf("p = %s\n", p);
  free(p);
  //防止野指针
  p = NULL;
}
