/*
 * author: inkXu
 * date:   2022.7.17
 *
 * 一次读写一个字符
 * int fgetc(FILE *stream)  读取一个字符
 *   读取一个字节，将字节值返回
 *   以t的方式：读取文件结尾返回EOF(-1)
 *   以b的方式：读取文件结尾，使用feof判断结尾
 * int fputc(FILE *stream)  写入一个字符
 *   输出成功，返回输出的字节值
 *   输出失败，返回EOF(-1)
 *
 * 注意：
 *   打开文件时，默认读写的位置为开始位置，以a的方式打开读写位置
 *   在末尾。读取或写入时，读写位置会往文件末尾方向偏移，
 *   读写多少个字节，位置就往末尾偏移几个字节，就是有一个文件指针
 */
#include<stdio.h>

void test1();
void test2();

void main()
{
  test1(); 
}
void test1()
{
  FILE *fp = NULL;
  if((fp = fopen("/home/noval/c/c_bili/file_operate/test_file.txt", "w")) == NULL)
  {
    printf("fail to fopen!\n");
    return ;
  }
  fputc(97, fp);
  fputc('\n', fp);
  fclose(fp);
}
void test2()
{
  FILE *fp = NULL;
  fp = fopen("/home/noval/c/c_bili/file_operate/test_file.txt", "r");
  if(fp == NULL)
  {
    printf("fail to fopen!\n");
    return ;
  }
  int c;
  //c = fgetc(fp);
  //printf("fp[0] = %c - %d\n", c, c);
  //c = fgetc(fp);
  //printf("fp[1] = %c - %d\n", c, c);
  while(c = fgetc(fp) != EOF)
  {
    printf("c = [%c] - [%d]\n", c, c);
  }
  fclose(fp);
}



