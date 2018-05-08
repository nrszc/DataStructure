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
        printf("������0~6\n");
        printf("--------------------------------\n");
        printf("1-��ʼ��       2-����\n");
        printf("3-����         4-��ֵɾ��\n");
        printf("5-��λ��ɾ��   6-����˳���\n");
        printf("0-�˳�\n");
        printf("--------------------------------\n");
        scanf("%d",&r);
        if(r==0) break;
        switch(r)
        {
            case 1:LL=InitList(); break;
            case 2:printf("������Ԫ��ֵ:");
                   scanf("%d",&i);
                   printf("���������λ��:");
                   scanf("%d",&r);
                   InsertList(LL,i,r-1);
                   printf("����ɹ�\n");
                   break;
            case 3:printf("���������Ԫ��ֵ:");
                   scanf("%d",&i);
                   r=FindList(LL,i);
                   if(r<0)
                     printf("û�ҵ�\n");
                   else
                     printf("�з���������Ԫ�أ�λ��Ϊ��%d\n",r+1);
                     break;
            case 4:printf("������ɾ��Ԫ��ֵ:");
                   scanf("%d",&i);
                   r=DeleteList1(LL,i);
                   if(r<0)
                      printf("û�ҵ�\n");
                   else
                      printf("�з���������Ԫ�أ�λ��Ϊ��%d\n���Ա�Ϊ:",r+1);
                      break;
            case 5:printf("������ɾ��Ԫ��λ��:");
                   scanf("%d",&r);
                   i=DeleteList2(LL,r-1);
                   if(i<0)
                      printf("λ��Խ��\n");
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
           printf("�ڴ��������!\n");
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
    printf("�з���������Ԫ�أ�Ԫ��ֵΪ��%d\n",L->list[rc]);
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
