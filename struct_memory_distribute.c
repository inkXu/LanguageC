/*
 * author: inkXu
 * date:   2022.7.12
 *
 * 结构体内存分配问题
 *
 * 规则1：以多少个字节为单位的时候，会去结构体变量中找基本类型的成员，
 *        哪个基本类型的成员占字节数多，就以它大小为单位开辟内存。
 *        在gcc中出现的double类型例外
 *    1、成员中只有char类型数据，以1字节为单位开辟内存。
 *    2、成员中出现了short类型数据，没有更大字节数的基本数据类型，
 *       以2字节为单位开辟内存。
 *    3、成员中出现了int float类型数据，没有更大字节数的基本数据类型，
 *       以4字节为单位开辟内存。
 *    4、成员中出现了double类型数据，没有更大字节数的基本数据类型，
 *       在gcc中以4字节为单位开辟内存，在vc中以8字节开辟内存。
 * 注意：
 *    如果在结构体中出现了数组，数组可以看成多个变量的集合，
 *    如果出现指针的话，没有占字节数更大的类型的，以4字节为单位开辟。
 *    *在内存中存储结构体成员的时候，按定义的结构体成员的顺序存储。
 *
 * 规则2：字节对齐
 *    1、char  1字节对齐，即存放char型的变量，内存单元编号是1的倍数即可。
 *    2、short 2字节对齐，即存放short int型的变量，内存单元编号是2的倍数即可。
 *    3、int   4字节对齐，即存放int型的变量，内存单元编号是4的倍数即可。
 *    4、long  在32位平台，4字节对齐，即存放long int型的变量，内存单元编号是4的倍数即可。
 *    5、float 4字节对齐，即存放float型的变量，内存单元编号是4的倍数即可。
 *    6、double
 *         vc下，8字节对齐，即存放double型变量的起始地址，必须是8的倍数
 *         gcc下，4字节对齐，即存放double型变量的起始地址，必须是4的倍数
 * 注意：
 *    如果在结构体中出现了数组，数组可以看成多个变量的集合，
 *    在开辟内存时，从上向下依次按定义的结构体成员的顺序开辟内存。
 *
 * 作用：用空间换取时间
 *
 * 使用#pragma pack改变默认对其原则(test2())(不建议使用)
 *   格式：#pragma pack(value)，value值只能是1、2、4、8等
 */
#include<stdio.h>

//16 byte
struct{
  char sex;
  short age;
  int date;
  double mark;
} xm;

//24 byte
//一申请就申请8个字节，gcc中每四个字节对齐
//so 一开始的8个字节，前4个字节存了age，后4个存了date，后又申请8个字节，
//   char用了1个，剩下7个不够用来存double，又申请了8个字节
struct{
  short age;   //2    4
  int date;    //4    4
  char sex;    //1    8
  double mark; //8    8
} xh;

//4 byte
struct{
  short age;
  char sex;
} xb;

void test1();
void test2();

void main()
{
  test1();
}

void test2()
{
//以两字节开辟空间
  #pragma pack(2)
    struct{
      char a;
      int b;
    } xl;
}

void test1()
{
  printf("sizeof(xm) = %d\n", sizeof(xm));
  printf("sizeof(xh) = %d\n", sizeof(xh));
  printf("sizeof(xb) = %d\n", sizeof(xb));
  printf("sizeof(int) + sizeof(char) + sizeof(double) + sizeof(short) = %d, %d, %d, %d\n", \
          sizeof(int), sizeof(char), sizeof(double), sizeof(short));
}
