/*
 * author: inkXu
 * date:   2022.7.15
 *
 * 双向链表
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct student {
  char no[16];
  char name[64];
  unsigned int score;
  struct student *front;
  struct student *next;
} STU;

//创建，插入和删除为啥都用二级指针
void double_link_create(STU **L, STU *new);
void double_link_printf(STU *L);
void double_link_delete(STU **L, char *name);
void double_link_insert(STU **L, STU *new);

void main()
{
  STU *list = NULL, *new = NULL; 
  int num = 0, ii = 0;
  printf("please enter numbers of student:");
  scanf("%d", &num);
  for(; ii < num; ii++)
  {
    new = (STU *)malloc(sizeof(STU));
    printf("please enter message of student(no name score):\n");
    scanf("%s %s %d", new->no, new->name, &new->score);
    double_link_create(&list, new);
  }
  double_link_printf(list);
#if 0
  char *del = (char *)malloc(64);
  printf("please enter student name of you want delete:\n");
  scanf("%s", del);
  double_link_delete(&list, del);
  free(del);
  del = NULL;
#endif
#if 1
  printf("please enter student's message of you want add(no name score):\n");
  STU *add = (STU *)malloc(sizeof(STU));
  scanf("%s %s %d", add->no, add->name, &add->score);
  printf("add->no = %s, add->name = %s, add->score = %d\n", add->no, add->name, add->score);      
  double_link_insert(&list, add);
#endif
  double_link_printf(list);
}

#if 0
void double_link_insert(STU **L, STU *new)
{
  STU *pa = NULL, *pb = NULL;
  if(*L == NULL)                                                  //判断链表是否为空
  {
    *L = new;
    new->next = NULL;
    new->front = NULL;
  }
  else                                                           //链表不为空时
  {
    pa = *L;
    while((pa->next != NULL) && (strcmp(new->name, pa->name) >= 0))  //遍历到比new->name大一个的位置
    {
      pa = pa->next;
    }
    if(pa->next == NULL)                                         //链表只有一个节点时
    {
      if(strcmp(new->name, pa->name) >= 0)
      {
        pa->next = new;
        new->front = pa;
        new->next = NULL;
      }
      else
      {
        pa->front = new;
        new->next = pa;
        new->front = NULL;
        *L = new;
      }
    }
    else
    {
      if(strcmp(new->name, (*L)->name) < 0)
      {
        pa->front = new;
        new->next = pa;
        new->front = NULL;
        *L = new;
      }
      else
      {
        pb = pa->front;
        pb->next = new;
        new->front = pb;
        new->next = pa;
        pa->front = new;
      }
    }
  }
}
#endif
#if 1
void double_link_insert(STU **L, STU *new)
{
  STU *pa = NULL, *pb = NULL;
  if(*L == NULL)                                                  //判断链表是否为空
  {
    *L = new;
    new->next = NULL;
    new->front = NULL;
    return ;
  }
  else                                                           //链表不为空时
  {
    pa = *L;
    while((pa->next != NULL) && (strcmp(new->name, pa->name) >= 0))  //遍历到比new->name大一个的位置
    {
      pa = pa->next;
    }
    if((strcmp(new->name, (*L)->name) <= 0) && pa == (*L))                        //指针在头节点，且插在头节点前时
    {
      pa->front = new;
      new->next = pa;
      new->front = NULL;
      *L = new;
      return ;
    }
    else
    {
      if((strcmp(new->name, pa->name) <= 0))                           //插入节点插在链表中间时，插到指针pa前
      {
        pb = pa->front;
        pb->next = new;
        new->front = pb;
        new->next = pa;
        pa->front = new;
        return ;
      }
      else                                                            //插入节点在最尾部时
      {
        pa->next = new;
        new->front = pa;
        new->next = NULL;
        return ;
      }
    }
  }
}
#endif

void double_link_delete(STU **L, char *name)
{
  if(*L == NULL)
  {
    printf("the double link is NULL\n");
    return ;
  }
  STU *pa = *L;
  while(pa != NULL && strcmp(pa->name, name) != 0)
  {
    pa = pa->next;
  }
  if(pa == *L)             //删除头节点时
  {
    if(pa->next != NULL)   //链表有多个节点
    {
      *L = pa->next;
      (*L)->front = NULL;
    }
    else                   //链表只有一个节点
      *L = NULL;
  }
  else                    //删除非头节点时
  {
    if(pa->next != NULL)
    {
      pa->next->front = pa->front;
      pa->front->next = pa->next;
    }
    else
    {
      pa->front->next = NULL;
    }
  }
  free(pa);
  pa = NULL;
  return ;
}
void double_link_printf(STU *L)
{
  STU *pa = L;
  if(pa == NULL)
  {
    printf("double link is NULL!\n");
    return ;
  }
  //顺序输出
  while(pa->next != NULL)
  {
    printf("Your No is: %s, Name is: %s, Score is: %d\n", pa->no, pa->name, pa->score);
    pa = pa->next;
  }
  printf("Your No is: %s, Name is: %s, Score is: %d\n", pa->no, pa->name, pa->score);
  printf("***********************************************\n");
  //逆序输出
  while(pa != NULL)
  {
    printf("Your No is: %s, Name is: %s, Score is: %d\n", pa->no, pa->name, pa->score);
    pa = pa->front;
  }
}
void double_link_create(STU **L, STU *new)
{
  STU *pa = *L;
  if(*L == NULL)
  {
    *L = new;
    new->front = NULL;
    new->next = NULL;
  }
  else
  {
    while(pa->next != NULL)
    {
      pa = pa->next;
    }
    pa->next = new;
    new->front = pa;
    new->next = NULL;
  }
  return ;
}












