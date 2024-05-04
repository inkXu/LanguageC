/*
 * author: inkXu
 * date:   2022.7.12
 *
 * 枚举
 *
 * 定义于结构体和共用体差不多
 *
 * 枚举中成员的值默认是从0开始，逐渐递增，定义时才能修改其初始值，后面不能修改
 * 其值从每次赋值的位置逐渐递增
 */
#include<stdio.h>

enum Day { monday = 1, tuesday, wendesday, thursday = 1, friday, saterday, sunday};

void main()
{
  enum Day day = tuesday;
  printf("day = %d\n", day);

  day = monday;
  printf("day = %d\n", day);

  day = friday;
  printf("day = %d\n", day);

  day = sunday;
  printf("day = %d\n", day);
}
