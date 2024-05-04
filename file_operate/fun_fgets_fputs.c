/*
 * author: inkXu
 * date:   2022.7.17
 *
 * 一次读写字符串
 * int fgets(char *buf, int size, FILE *stream)
 *   每次读取size-1个字符，size-1是因为字符串有一个'\0'结尾，
 *   若碰到换行符'\n'则停止读取，读取完返回NULL
 * int fputs(char *buf, FILE *stream)
 *   返回写入的字符个数
 *
 * 注意：
 */
#include<stdio.h>

void test1();
void test2();

void main()
{
  test2(); 
}
void test1()
{
  FILE *fp = NULL;
  if((fp = fopen("/home/noval/c/c_bili/file_operate/test_file.txt", "r")) == NULL)
  {
    printf("fail to fopen!\n");
    return ;
  }
  char buf[32] = "";
  while( fgets(buf, 8, fp) != NULL)
  {
    printf("buf = %s\n", buf);
  }
  fclose(fp);
}
void test2()
{
  FILE *fp = NULL;
  fp = fopen("/home/noval/c/c_bili/file_operate/test_file.txt", "a");
  if(fp == NULL)
  {
    printf("fail to fopen!\n");
    return ;
  }
  char buf[32] = "thank you for your love\n";
  fputs(buf, fp);
  fclose(fp);
}



