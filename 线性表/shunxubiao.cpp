#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
struct LinearList
{
    int list[MaxSize];
    int size;
};
typedef struct LinearList List;
List* InitList();
int InsertList(List *L,int item,int rc);
int FindList(List *L,int item);
void OutputList(List *L);
int DeleteList1(List *L,int item);
int DeleteList2(List *L,int rc);
int main()
{
    List *LL;
    int i,r;
    while(1)
    {
        printf("请输入0~6\n");
        printf("--------------------------------\n");
        printf("1-初始化       2-插入\n");
        printf("3-查找         4-按值删除\n");
        printf("5-按位置删除   6-遍历顺序表\n");
        printf("0-退出\n");
        printf("--------------------------------\n");
        scanf("%d",&r);
        if(r==0) break;
        switch(r)
        {
            case 1:LL=InitList(); break;
            case 2:printf("请输入元素值:");
                   scanf("%d",&i);
                   printf("请输入插入位置:");
                   scanf("%d",&r);
                   InsertList(LL,i,r-1);
                   printf("插入成功\n");
                   break;
            case 3:printf("请输入查找元素值:");
                   scanf("%d",&i);
                   r=FindList(LL,i);
                   if(r<0)
                     printf("没找到\n");
                   else
                     printf("有符合条件的元素，位置为：%d\n",r+1);
                     break;
            case 4:printf("请输入删除元素值:");
                   scanf("%d",&i);
                   r=DeleteList1(LL,i);
                   if(r<0)
                      printf("没找到\n");
                   else
                      printf("有符合条件的元素，位置为：%d\n线性表为:",r+1);
                      break;
            case 5:printf("请输入删除元素位置:");
                   scanf("%d",&r);
                   i=DeleteList2(LL,r-1);
                   if(i<0)
                      printf("位置越界\n");
                   break;
            case 6:OutputList(LL); break;
        }

    }

}

List* InitList()
{
    List *L;
    if((L=(List *)malloc(sizeof(List)))==NULL)
       {
           printf("内存申请错误!\n");
            exit(1);
       }
       L->size=0;
       return L;
}

int InsertList(List *L,int item,int rc)
{
    int i;
    if(MaxSize==L->size)
        return -1;
    if(rc<0)
        rc==0;
    if(rc>L->size)
        rc=L->size;
    for(i=L->size-1;i>=rc;i--)
    L->list[i+1]=L->list[i];
    L->list[rc]=item;
    L->size++;
    return 0;
}

int FindList(List *L,int item)
{
    int i;
    for(i=0;i<L->size;i++)
    if(L->list[i]==item)
    return i;
    return -1;
}

int DeleteList1(List *L,int item)
{
    int i,n;
    for(i=0;i<L->size;i++)
    if(item==L->list[i])
        break;
    if(i<L->size)
    {
        for(n=i;n<L->size-1;n++)
        L->list[n]=L->list[n+1];
        L->size--;
        return i;
    }
}



int DeleteList2(List *L,int rc)
{
    int i;
    if(rc<0)
        return -1;
    if(rc>=L->size)
        return -1;
    printf("有符合条件的元素，元素值为：%d\n",L->list[rc]);
    for(i=rc;i<L->size-1;i++)
        L->list[i]=L->list[i+1];
        L->size--;
    return rc;
}

void OutputList(List *L)
{
    int i;
    for(i=0;i<L->size;i++)
    printf("%d",L->list[i]);
    printf("\n");
}
