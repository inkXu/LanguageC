/*
 * author: inkXu
 * Date:   2022.7.7
 *
 * 函数参数之传数值
 * void function_name(type parameter1, type parameter2);
 * 这个参数只起到传递数值的作用，在该函数内对参数的值进行改变，函数外的参数值不会改变
 *
 * 注意：(者部分不是很懂，在65级)
 * 当实参是一个一级指针时(*p)，要想进行地址传参，传入时要使用二级指针的形式fun(**p);
 *                             若是数值传参，则写为fun(*p);例子为test3();
 */
#include<stdio.h>

void test1();  //函数参数之常量参数的数值传递
void test2();  //函数参数之常量参数的地址传递
void test3();  //函数参数之指针参数的数值和地址传递
void test4();  //函数参数之传一维数组
void test5();  //函数参数之传二维数组
void test6();  //函数参数之传指针的指针
void fun_val(int m, int n);
void fun_address(int *m, int *n);
void fun_point(char *p);
void fun_point_point(char **p);
void fun_one(int *a);
void fun_two(int (*a)[4]);
void fun_three(char **p);

void main()
{
  test6();
}

void test6()
{
  char *q = "Welcome";
  char *p[3] = {"Welcome", "to", "China"};
  fun_three(p);
  printf("p = %p\n", p);
  printf("p = %p\n", p+1);
  printf("p = %p\n", p+2);
  printf("p = %s\n", *p);
  printf("p = %s\n", *(p+1));
  printf("p = %s\n", *(p+2));
  printf("p = %s\n", p[0]);
  printf("p = %s\n", p[1]);
  printf("p = %s\n", p[2]);
  //printf("q = %s\n", q);
}

void fun_three(char **p)
{
  int i = 0;
  for(; i < 3; i++)
  {
    printf("p[%d] = %s\n", i, *(p+i));
  }
}

void test5()
{
  int a[][4] = {1, 2, 3, 4, 5, 6, 7, 8};
  fun_two(a);
  printf("a[0][0] = %d, a[0][1] = %d, a[0][2] = %d, a[0][3] = %d\n",\
          a[0][0], a[0][1], a[0][2], a[0][3]);
  printf("a[1][0] = %d, a[1][1] = %d, a[1][2] = %d, a[1][3] = %d\n",\
          a[1][0], a[1][1], a[1][2], a[1][3]);
}

//fun_two(a[][4])
void fun_two(int (*a)[4])
{
  a[0][3] = 88;
  //注意：下面这句话不能写成*(a+1)+3 = 99;
  *(*(a+1)+3) = 99;
}

//fun_one(int a[])
void fun_one(int *a)
{
  a[3] = 66;
}

void test4()
{
  int a[] = {1, 2, 3, 4, 5};

  fun_one(a);
  printf("a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d, a[4] = %d\n",\
          a[0], a[1], a[2], a[3], a[4]);
}

void test3()
{
  char *p = "Hello";
  //注意：字符串指针，它的输出就下面这样写，不知道为啥，后面的参数写p，不写*p
  printf("p = %s\n", p);
  //fun_point(p);
  fun_point_point(&p);
  //注意：字符串指针，它的输出就下面这样写，不知道为啥，后面的参数写p，不写*p
  printf("p = %s\n", p);
}

void fun_point(char *q)
{
  q = "yes";
  //注意：字符串指针，它的输出就下面这样写，不知道为啥，后面的参数写q，不写*q
  printf("q = %s\n", q);
}

void fun_point_point(char **q)
{
  *q = "yes";
  printf("q = %s\n", *q);
}

//函数参数之传数值
void fun_val(int m, int n)
{
  int temp = m;
  m = n;
  n = temp;

  printf("in function:m = %d, n = %d\n", m, n);
  printf("&m = %p, n = %p\n", &m, &n);
}

//函数参数之传地址，对参数的值更改会影响函数外参数的值
void fun_address(int *m, int *n)
{
  int temp;
  temp = *m;
  *m = *n;
  *n = temp;

  printf("in function:m = %d, n = %d\n", *m, *n);
  printf("&m = %p, n = %p\n", m, n);
}

void test1()
{
  int a = 100, b = 20;

  printf("before function: a = %d, b = %d\n", a, b);
  printf("&a = %p, &b = %p\n", &a, &b);

  fun_val(a, b);

  printf("after function: a = %d, b = %d\n", a, b);
  printf("&a = %p, &b = %p\n", &a, &b);
}

void test2()
{
  int a = 100, b = 20;

  printf("before function: a = %d, b = %d\n", a, b);
  printf("&a = %p, &b = %p\n", &a, &b);

  fun_address(&a, &b);

  printf("after function: a = %d, b = %d\n", a, b);
  printf("&a = %p, &b = %p\n", &a, &b);
}
