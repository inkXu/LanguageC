/*
 * author: inkXu
 * date:   2022.7.19
 *
 * 随机读写
 * 
 * void rewind(FILE *stream)  将文件流指针移动到文件头
 * long ftell(FILE *stream)  返回文件流目前的读写位置，错误时返回-1
 * void fseek(FILE *stream, long offset, int whence)
 *     一般用于二进制文件(打开文件方式为rb、wb之类的)
 *     whence起始点有三种（头SEEK_SET 0，当前位置SEEK_CUR 1，末尾SEEK_END 2）
 *     offset为相对与起始点的偏移量
 */
#include<stdio.h>

void main()
{
  FILE *fp = NULL; 
  if((fp = fopen("/home/noval/c/c_bili/file_operate/test_file.txt", "w+")) == NULL)
  {
    printf("fail to fopen!\n");
    return ;
  }
  fprintf(fp, "welcome to china!");

  //移动到头部
  //rewind(fp);
  //fseek(fp, 0, SEEK_SET);

  //移动到倒数第6个字符
  long index = 0;
  index = ftell(fp);
  printf("before move index: %d\n", index);
  fseek(fp, -6, SEEK_END);
  index = ftell(fp);
  printf("after move index: %d\n", index);

  char buf[32] = "";
  while(fgets(buf, 32, fp) != NULL)
  {
    printf("%s\n", buf);
  }
  fclose(fp);
}
