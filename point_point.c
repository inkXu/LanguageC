/*
 * author: inkXu
 * Date:   2022.7.6
 *
 * 二维指针
 */
#include<stdio.h>

void main()
{
  int a = 100;
  int *p, **q, ***m;

  p = &a;
  q = &p;
  m = &q;

  printf("a = %d, p = %d, q = %d, m = %d\n", a, *p, **q, ***m);

  printf("&a = %#x, %#x, %#x, %#x\n", &a, p, *q, **m);
  printf("&p = %#x, %#x, %#x\n", &p, q, *m);
  printf("&q = %#x, %#x\n", &q, m);
  printf("&m = %#x\n", &m);
}
