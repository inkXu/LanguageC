/*
 * author: inkXu
 * Date:   2022.7.6
 *
 * 数组指针
 * 定义一个整型数组(int a[10];)，对其取地址，即&a，它表示的是一个数组指针(int (*p)[10];)
 * 定义一个指针(int *p;)，对其取地址，即&p，它表示的是一个指针的指针(int **q;q = &p)
 */

#include<stdio.h>

void sum(int (*p)[5]);
void test1();

void main()
{
  int arr[][5] = {{1,2,3,4,5},{3,4,22,35,13}};
  //主要用于函数形参的定义，将一个二维数组传入函数内
  sum(arr);
  test1();
}

//求一个每行有五个整数的数组每一行的和，最大为两行
void sum(int (*p)[5])
{
  int i = 0;
  int sum = 0;
  for(; i < 5; i++)
  {
    sum += p[0][i];
  }
  printf("The first line's sum is:%d\n", sum);

  sum = 0;
  for(i = 0; i < 5; i++)
  {
    sum += p[1][i];
  }
  printf("The second line's sum is:%d\n", sum);
}

//二维数组的降级问题
/* 二维数组的数组名默认是一个行指针，加一表示下一行数据的首地址
 * 当对一个二维数组取*的时候，表示地址的降级，行指针降为列指针，
 *    加一表示下一个元素的地址，它所表示的是列的内容
 *
 * 一位数组的数组名默认是一个列指针，加一表示下一个元素的地址
 * 一位数组的数组名取&，则是地址的升级，将列指针升级为行指针，
 *    加一表示下一行数据的首地址
 */
void test1()
{
  int nums[][4] = {1,2,3,4,5,6,7,8};

  printf("nums = %p\n", nums);
  printf("nums + 1 = %p\n", nums + 1);
  printf("*nums = %p\n", *nums);
  printf("*nums + 1 = %p\n", (*nums) + 1);
}


