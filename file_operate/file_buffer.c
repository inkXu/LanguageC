/*
 * author: inkXu
 * date:   2022.7.16
 *
 * 文件缓冲区
 * 行缓冲区：文件需要刷新缓冲区才能将打印的内容显示到终端
 */
#include<stdio.h>

void test1();      //行缓冲区

void main()
{
  test1();
}

void test1()
{
  //no result,the line buffer not end
  //printf("000");

  //方法1，使用换行符
  //printf("000\n");

  //方法2，程序正常结束
  //printf("000");
  //return ;

  //方法3，使用fflush函数
  //printf("000");
  //fflush(stdout);

  //方法4，当缓冲区满时自动刷新
  //默认行缓冲区大小为1024字节
  //只输出了1024个字符，一共有1332个字符，剩下的308因为没有满也没有换行符，所以没有输出来
  int i = 0;
  for(i = 0; i < 444; i++)
  {
    printf("xux");
  }

  while(1) ;
}
