/*
 * author: inkXu
 * date:   2022.7.12
 *
 * 位段
 *
 * 定义：
 *   在结构体中，以位为单元的成员称之为位段（位域）
 * 
 * 注意：不能对位段成员取地址，因为位段成员可能不够1字节
 *       位段成员的类型必须指定为整型或字符型；
 *       一个位段必须存放在一个存储单元中，不能跨越两个单元，第一个单元空间不
 *       能容纳下一个位段，则该空间不用，而从下一个单元起存放该位段
 */
#include<stdio.h>

void test1();  //测试位段结构体大小
void test2();  //位段的引用，和结构体成员引用相似
void test3();  //将一个位段从另一个存储单元开始
void test4();  //无意义位段

struct{
  unsigned char a:7;
  unsigned short b:15;
  unsigned int c:6;
  unsigned long d:6;
  unsigned int e;
} data;

void main()
{
  test4();
}

void test1()
{
  printf("sizeof(data) = %d\n", sizeof(data));
  printf("&data = %p\n", &data);
  printf("&data.e = %p\n", &(data.e));
}

void test2()
{
  data.c = 63;
  printf("data.c = %d\n", data.c);

  //编译提示警告，数据溢出，溢出位为最大位，共7位，取后6位数值
  //data.d = 65;
  //printf("data.d = %d\n", data.d);
}

struct{
  char a:2;
  char b:3;
  //存在时，为2字节，不存在时为1字节
  char:0;
  char c:2;
} temp;

struct{
  unsigned int a:4;
  unsigned int b:3;
  //存在时，为8字节，不存在时为4字节
  unsigned int:0;
  unsigned int c:3;
} tmp;

void test3()
{
  printf("sizeof(temp) = %d\n", sizeof(temp));
  printf("sizeof(tmp) = %d\n", sizeof(tmp));
}

struct{
  signed a:3;
  signed:2;
  signed:0;
  signed b:3;
}none;

void test4()
{
  printf("sizeof(signed) = %d\n", sizeof(signed));
  printf("sizeof(none) = %d\n", sizeof(none));
}





