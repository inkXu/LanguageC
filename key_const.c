#include<stdio.h>

void test1();   //修饰全局变量时
void test2();   //修饰局部变量时
void test3();   //const于指针相关时

void main()
{
  test3();
}

//const修饰的全局变量保存在文字常量区，不能修改其值，因为它为常量
const int global = 100;
//const修饰的全局变量，如果其他文件需要使用，可以使用extern关键字声明外部可用，外部文件声明如下
//extern const int global;
void test1()
{
  printf("global = %d\n", global);
  //直接赋值编译报错
  //global = 200;
  //printf("global = %d\n", global);

  //编译时有警告，不报错，运行程序崩溃
  int *p = &global;
  *p = 55;
  printf("global = %d\n", global);
}

void test2()
{
  //const修饰的局部变量保存在栈区，可通过指针修改其值
  const int local = 100;

  //直接赋值编译报错
  //local = 200;
  //printf("local = %d\n", local);

  //程序不报错，有警告，能成功改变局部变量的值
  int *p = &local;
  *p = 200;
  printf("local = %d\n", local);
}

//若const修饰指针变量的类型，无法通过指针变量修改地址的值
//若const修饰指针变量，无法修改指针变量保存的地址
void test3()
{
  int a = 100;
  printf("a = %d\n", a);

  int *p = &a;
  //const int *p = &a;
  //int * const p = &a;
  //const int * const p = &a;

  a = 200;
  printf("*p = %d\n", *p);

  //const int *p时，编译报错，p指向的数值为const
  *p = 555;
  printf("*p = %d\n", *p);

  //int * const p时，编译报错，地址为const类型
  int b = 777;
  p = &b;
  printf("*p = %d\n", *p);
}




