/*
 * author: inkXu
 * date:   2022.7.8
 *
 * void *calloc(unsigned int nmemb, unsigned int size)
 * nmemb为要申请的空间块数，size为每块空间的大小
 * calloc(3, 100) <==> malloc(300)
 *
 * 注意：
 *   该函数申请的内存会将原有的值清空成0，malloc不会进行这个操作，它申请的空间内容是随机的
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
  char *p = NULL;
  p = (char *)calloc(3, 20);
  if(p == NULL)
    return ;
  strcpy(p, "yes");
  printf("p = %s\n", p);
}








