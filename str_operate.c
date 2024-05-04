/*
 * author: inkXu
 * date:   2022.7.8
 *
 * 字符串操作
 *
 * 头文件string.h
 * strlen 测长
 * strcpy/strncpy 拷贝
 * strcmp/strncmp 比较
 * strcat/strncat 追加
 * strchr 找字符
 * strstr 找字符串
 * char *strtok(char *str, const char *delim); 切割字符串
 *   在str指向的字符串中发现了delim字符串中的字符，就将其变为'\0'
 *   调用一次strtok只切割一次，切割一次后，再去切割的时候
 *   strtok的第一个参数传NULL，意思是接着上次切割的位置继续
 *
 * 头文件strlib.h
 * atoi 字符串数字转int型
 * atof 字符串数字转float型
 * atod 字符串数字转double型
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void test1();  //atoi  atof  使用
void test2();  //strtok 使用
void test3();  //测试strcpy返回值

void main()
{
  test2();
}

void test3()
{
  char str[32] = "12345678";
  char str1[32] = "isaogho";
  printf("str1 => str: %s\n", strcpy(str, str1));
}

void test2()
{
  char str[] = "abc:abcc:111:22222:32333:3234235:ashgo";
  char str1[] = "abc::abcc:111:22222:32333:3234235:ashgo";
  char *ret;
  //char temp[32];

  //第一次切割
  ret = strtok(str, ":");
  printf("str : %s\n", ret);
  //strcpy(temp, strtok(str, ":"));
  //printf("str : %s\n", temp);

  //其余切割
/*
  while(strcpy(temp, strtok(NULL, ":")) != NULL)
  {
    printf("str : %s\n", temp);
  }
*/

  while((ret = strtok(NULL, ":")) != NULL)
  {
    printf("str : %s\n", ret);
  }


  ret = strtok(str1, ":");
  printf("str1 : %s\n", ret);
  while((ret = strtok(NULL, ":")) != NULL)
  {
    printf("ret = %s\n", ret);
  }
}

void test1()
{
  char strnum1[] = "32";
  char strnum2[] = "5";
  char strnum3[] = "3.1415926";

  int num1 = atoi(strnum1);
  int num2 = atoi(strnum2);
  float num3 = atof(strnum3);

  printf("num3 = %f\n", num3);
  printf("num1 * num2 = %d\n", num1 * num2);
}



