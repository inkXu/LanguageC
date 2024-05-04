/*
 * author: inkXu
 * date:   2022.7.9
 *
 * 格式化输出
 */
#include<stdio.h>
#include<stdlib.h>

//正则表达式基本用法
void test1();
void test2();
//正则表达式特殊用法
void test3();

void main()
{
  //test1();
  //test2();
  test3();
}

void test1()
{
  char *str = (char *)malloc(64);

  sprintf(str, "%d:%02d:%02d", 2022,7,9);

  printf("str = %s\n", str);

  free(str);
  str = NULL;
}

void test2()
{
  int *str[4];
  int a, b, c;

  sscanf("2022:07:09", "%d:%d:%d", str, str+1, str+2);
  sscanf("2022:07:09", "%d:%d:%d", &a, &b, &c);

  printf("str[0] = %d\n", str[0]);
  printf("str[1] = %d\n", str[1]);
  printf("str[2] = %d\n", str[2]);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
}

void test3()
{
  char buf[32];

  //跳过数据：%*s或%*d
  sscanf("25825 shga 125224", "%*d %*s %s", buf);
  printf("buf = %s\n", buf);
  sscanf("25825,shga 125224", "%*d,%s %*d", buf);
  printf("buf = %s\n", buf);

  //读指定宽度数据：%[width]s
  sscanf("I Love You Forever!", "%5s", buf);
  printf("buf = %s\n", buf);
  int i = 0;
  for(; i < 3; i++)
  {
    printf("buf[%d] = %c\n", i, buf[i]);
    printf("buf[%d] = %d\n", i, buf[i]);
  }

  //集合操作：只支持获取字符串
  //   %[a-z]   表示获取a到z中任意字符(尽可能的多匹配)
  //   %[aBc]   匹配a、F、c中一员，贪婪性
  //   %[^aFc]  匹配非a、F、c中的任意字符，贪婪性
  //   %[^a-z]  表示获取在该字符串中除了小写a到z的字符
  sscanf("welcome to China", "%[a-z]", buf);
  printf("buf = %s\n", buf);
  sscanf("Welcome To China", "%[aCz]", buf);
  printf("buf = %s\n", buf);
  sscanf("Welcome To China", "%[^a-z]", buf);
  printf("buf = %s\n", buf);
  sscanf("Welcome To China", "%[^aCz]", buf);
  printf("buf = %s\n", buf);
}
