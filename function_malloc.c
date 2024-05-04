/*
 * author: inkXu
 * date:   2022.7.8
 *
 * 动态内存管理
 * 使用malloc可以动态申请堆区的空间，包含的头文件为stdlib.h
 * void *malloc(unsigned int size)
 * 申请成功返回首地址
 * 申请失败返回NULL
 *
 * 注意：
 *   1、在调用malloc后，一定要判断一下是否申请成功
 *   2、在多次malloc申请的内存中，每次申请的内存不是连续的
 *   3、使用malloc开辟的空间需要保存好首地址，但是由于不确定空间用于做什么，
 *      所以本身返回值类型为void *，所以在带哦用该函数时要根据接收者的类型对其进行强制转换
 */
#include<stdio.h>
#include<stdlib.h>

char *fun_one()
{
  char *str = (char *)malloc(sizeof(char) * 100);
  if(str == NULL)
    return 0;
  str[0] = 'y';
  str[1] = 'e';
  str[2] = 's';

  return str;
}

void main()
{
  char *p = NULL;

  p = fun_one();

  printf("p = %s\n", p);
}
