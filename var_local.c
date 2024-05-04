/*
 * author: inkXu
 * Date:   2022.7.5
 *
 * 局部变量只能在它定义的函数或复合语句中有效。
 * 静态的局部变量在第一次调用函数的时候，开辟空间赋值，函数结束后不释放，以后再调用函数的时候，就不再为其开辟空间，也不赋值，用的是以前的那个变量。
 */

#include<stdio.h>

void function()
{
//普通局部变量未初始化时，其值为随机值
  int num = 100;
  num ++;
  printf("=%d=\n", num);
}

void function_static()
{
//静态局部变量未初始化，系统会进行初始化为0
  static int num = 100;
  num ++;
  printf("=%d=\n", num);
}

void main()
{
  function();
  function();
  function();

  function_static();
  function_static();
  function_static();
}
