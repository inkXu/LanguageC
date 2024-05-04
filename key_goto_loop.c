#include<stdio.h>

void main()
{
  int ii = 0;
  NEXT:
  printf("I Love You Forever!\n");
  ii ++;
  if(ii < 10)
  {
    goto NEXT;
  }
}
