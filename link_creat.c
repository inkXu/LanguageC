#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book {
  char bookName[32];
  unsigned int price;
  struct book *next;
} BOOK;

void list_create(BOOK **list, BOOK *newBook);
void list_printf(BOOK *L);                 //遍历打印数据
void list_free(BOOK *L);                   //释放空间
BOOK *list_find(BOOK *L, char *name);      //查找数据
int list_delete(BOOK **L, int position);   //删除数据
void list_insert(BOOK **L, BOOK *node);    //按从小到达插入
void list_sort(BOOK **L, char *type);      //排序
BOOK *list_reverse(BOOK *L);               //逆序

void main()
{
  BOOK *list = NULL;
  int i = 0, n = 0;
  printf("please enter numbers of book:");
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    BOOK *new = (BOOK *)malloc(sizeof(BOOK));
    printf("please enter book name and book price:\n");
    scanf("%s %d", new->bookName, &new->price);
    list_create(&list, new); 
  }
  list_printf(list);
#if 0
  char *name = (char *)malloc(32);
  printf("please enter a book name of you want find:");
  scanf("%s", name);
  BOOK *find = list_find(list, name);
  if(find != NULL)
    printf("The Book Name is: %s, and price is: %d\n", find->bookName, find->price);
  else
    printf("no result!\n");
#endif
#if 0
  int posi = 0, flag = 0;
  printf("please enter a position of you want delete element:");
  scanf("%d", &posi);
  flag = list_delete(&list, posi);
  if(flag == 1)
  {
    printf("delete right!\n");
  }
  else
  {
    printf("please enter a right position!\n");
  }
#endif
#if 0
  BOOK *newnode = (BOOK *)malloc(sizeof(BOOK));
  printf("please enter book name and price of you want:\n");
  scanf("%s %d", newnode->bookName, &newnode->price);
  list_insert(&list, newnode);
#endif
#if 1
  list_sort(&list, "bookName");
  printf("**************************************\n");
#endif
  list_printf(list);
#if 1
  list = list_reverse(list);
  printf("**************************************\n");
#endif
  list_printf(list);
  list_free(list);
}

BOOK *list_reverse(BOOK *L)
{
  BOOK *pr, *pa = L, *pb = pa->next;
  pa->next = NULL;
  while(pb != NULL)
  {
    pr = pb->next;
    pb->next = pa;
    pa = pb;
    pb = pr;
  }
  L->next = NULL;
  L = pa;
  return L;
}
void list_sort(BOOK **L, char *type)
{
  if(strcmp(type, "price") == 0)
  {
    BOOK *pa = *L, *pb = NULL, temp;
    while(pa != NULL)
    {
      pb = pa->next;
      while(pb != NULL)
      {
        if(pa->price > pb->price)
        {
          temp = *pa;
          *pa = *pb;
          *pb = temp;
          //地址也要交换
          temp.next = pa->next;
          pa->next = pb->next;
          pb->next = temp.next;
        }
        pb = pb->next;
      }
      pa = pa->next;
    }
  }
  else if(strcmp(type, "bookName") == 0)
  {
    BOOK *pa = *L, *pb = NULL, temp;
    while(pa != NULL)
    {
      pb = pa->next;
      while(pb != NULL)
      {
        if(strcmp(pa->bookName ,pb->bookName) > 0)
        {
          temp = *pa;
          *pa = *pb;
          *pb = temp;
          //地址也要交换
          temp.next = pa->next;
          pa->next = pb->next;
          pb->next = temp.next;
        }
        pb = pb->next;
      }
      pa = pa->next;
    }
  }
  return ;
}
void list_insert(BOOK **L, BOOK *node)
{
  BOOK *pf, *pb = NULL;
  pf = *L;
  if((*L) == NULL)
  {
    (*L) = node;
    return ;
  }
  //这里的等于号牛批，少了头和尾都出错
  while(pf != NULL && strcmp(node->bookName, pf->bookName) >= 0)
  {
    pb = pf;
    pf = pb->next;
  }
  if(strcmp(node->bookName, (*L)->bookName) < 0)
  {
    node->next = pf;
    (*L) = node;
  }
  else
  {
    pb->next = node;
    node->next = pf;
  }
  return ;
}
//这里得用二级指针，为啥呢？
int list_delete(BOOK **L, int position)
{
  if(*L != NULL)
  {
    BOOK *del = *L;
    if(position == 1)
    {
      *L = del->next;
      free(del);
      del = NULL;
      return 1;
    }
    else if(position > 1)
    {
      int i = 0;
      BOOK *move = *L;
      for(i = 1; i < position - 1; i++)
      {
        move = move->next;
      }
      BOOK *del = move->next;
      move->next = move->next->next;
      free(del);
      del = NULL;
      return 1;
    }
    else
      return 0;
  }
  return 0;
}
BOOK *list_find(BOOK *L, char *name)
{
  BOOK *temp = L;
  while(temp != NULL)
  {
    printf("temp->bookName, temp->price:%s %d\n", temp->bookName, temp->price);
    if(strcmp(temp->bookName, name) == 0)
    {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}
void list_free(BOOK *L)
{
  //这么做只能释放第一个
  //BOOK *p = L;
  //while(p->next != NULL)
  //{
  //  free(p);
  //  p = p->next;
  //}
  //p = NULL;
  BOOK *p = L;
  while(L->next != NULL)
  {
    L = L->next;
    free(p);
    p = L;
  }
  free(p);
  p = NULL;
}
void list_create(BOOK **list, BOOK *newBook)
{
  if(*list == NULL)
  {
    *list = newBook;
    newBook->next = NULL;
  }
  else
  {
    BOOK *tmp = *list;
    while(1)
    {
      if(tmp->next != NULL)
      {
        tmp = tmp->next;
        continue;
      }
      tmp->next = newBook;
      newBook->next = NULL;
      break;
    }
  }
}
void list_printf(BOOK *L)
{
  BOOK *list = L;
  while(list != NULL)
  {
    printf("The Book Name is: %s, and price is: %d\n", list->bookName, list->price);
    list = list->next;
  }
}
