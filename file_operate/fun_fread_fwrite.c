/*
 * author: inkXu
 * date:   2022.7.17
 *
 * 一次读写字符串
 * size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
 *   从stream中读取nmemb个size大小的字节块，放入ptr指向的内存，
 *   ptr可以是结构体哟，返回值为实际读到的块数，读取的字节数必须
 *   大于字节块的整数倍才能算做一块
 *     
 * size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream)
 *   返回读取的字符个数
 *
 */
#include<stdio.h>
#include<string.h>

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
  int num = 0;
  char buf[128] = "";
  num = fread(buf, 6, 5, fp);
  printf("buf = %s\n", buf);
  printf("num = %d\n", num);
  fclose(fp);
}
typedef struct {
  char no[16];
  char name[32];
  unsigned int age;
} STU;
void test2()
{
  FILE *fp = NULL;
  fp = fopen("/home/noval/c/c_bili/file_operate/test2.txt", "w+");
  if(fp == NULL)
  {
    printf("fail to fopen!\n");
    return ;
  }
  STU students[3] = {{"x001", "mike", 19},
                    {"x004", "liu", 18}, {"x007", "yete", 17}};
  fwrite(students, sizeof(STU), 3, fp);

  STU temp[3];
  memset(temp, 0, 3*sizeof(STU));
  //将指向文件中读写位置的指针移到文件的头部
  rewind(fp);
  fread(temp, sizeof(STU), 3, fp);
  int i = 0;
  for(; i < 3; i++)
  {
    printf("student %d: no: %s name:%s age:%d\n",\
           i, temp[i].no, temp[i].name, temp[i].age);
  }
  fclose(fp);
}



