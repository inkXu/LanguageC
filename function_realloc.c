/*
 * author: inkXu
 * date:   2022.7.8
 *
 * void* realloc(void *s, unsigned int newsize)
 * 在原先指向的内存上重新申请内存，新的内存大小为new_size个字节，
 * 若原先内存后面有足够大的空间，就追加，若原先内存后面没有足够大的空间，则在堆区找一个有newsize个字节大小的内存中申请一块内存，将原先内存中的内容拷贝过来，然后释放原先的内存
 * malloc、realloc、calloc只有在使用free或程序结束时才会释放空间
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
  char *a = NULL;

  a = (char *)malloc(64);

  strcpy(a, "123456789abcdef");

  printf("a = %s\n", a);
  printf("&a = %p\n", a);

  a = (char *)realloc(a, 128);

  printf("a = %s\n", a);
  printf("&a = %p\n", a);

  free(a);
  a = NULL;
}
