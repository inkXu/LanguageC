/*
 * author: inkXu
 * Date:   2022.7.5
 *
 *
 */

#include<stdio.h>

// declare a gloable variable
// 若没有进行初始化，系统也会将它初始化为0
// 若是从其它文件获取全局变量，要加extern int num;
// 静态全局变量static int num;只能在它定义的.c文件中有效
int num;

void main()
{
  printf("=%d=\n", num);
}
