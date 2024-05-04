/*
 * author: inkXu
 * date:   2022.7.7
 *
 * 指针函数
 *
 * 本质是一个函数，当一个函数返回一个指针时称作指针函数
 */
#include<stdio.h>

void test1();
void test2();
void test3();
void test4();
char *fun_one();

void main()
{
  test1();
}

void test1()
{
  char *str;

  str = fun_one();

  printf("str = %s\n", str);
}

char *fun_one()
{
  //str为局部变量，该变量存储在栈区，在栈区的数据会在该函数结束时释放开辟的空间
  //char str[] = "Welcome to China";
  //所以要加static关键字，static关键字声明的变量在静态区，它不会随着该代码块的结束而释放空间
  static char str[] = "Welcome to China";
  return str;
}





