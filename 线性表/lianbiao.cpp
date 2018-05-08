#include<stdio.h>
#include<stdlib.h>
struct lnode
{
    int data;
    struct lnode *next;
};
typedef struct lnode Lnode,*Linklist;
Linklist CreatLinklist(Linklist L);
void InsertLinklist(Linklist L,int r,int i);
int LengthLinklist(Linklist L);
Linklist GetLinklist1(Linklist L,int b,int *a);
Linklist GetLinklist2(Linklist L,int r);
void DeleteLinklist(Linklist L,int r);
void OutputLinklist(Linklist L);
void FreeLinklist(Linklist L);
int main()
{
    int a,b,i,r;
    Linklist L;
    Lnode *p;
    while(1)
    {
        printf("������ѡ��Ĳ���0~8\n");
        printf("--------------------------------\n");
        printf("1-��������         2-����\n");
        printf("3-���           4-��ֵ����\n");
        printf("5-��λ�ò���       6-ɾ��\n");
        printf("7-�������         8-�������\n");
        printf("0-�˳�\n");
        printf("--------------------------------\n");
        scanf("%d",&a);
        if(a==0) break;
        switch(a)
        {
            case 1:L=CreatLinklist(L); break;
            case 2:printf("����������λ�ú���ֵ\n");
                   scanf("%d%d",&r,&i);
                   InsertLinklist(L,r,i); break;
            case 3:i=LengthLinklist(L);
                   printf("��Ϊ:%d\n",i); break;
            case 4:printf("������Ҫ���ҵ�Ԫ��ֵ\n");
                   scanf("%d",&b);
                   p=GetLinklist1(L,b,&a);
                   if(a<0) printf("û�ҵ�\n");
                   else printf("λ��Ϊ:%d\n",a);
                   break;
            case 5:printf("������Ҫ���ҵ�λ��");
                   scanf("%d",&r);
                   p=GetLinklist2(L,r);
                   if(p==NULL) printf("û�ҵ�\n");
                   else printf("����ֵΪ:%d\n",p->data);
                   break;
            case 6:printf("������Ҫɾ����λ��\n");
                   scanf("%d",&r);
                   DeleteLinklist(L,r); break;
            case 7:OutputLinklist(L); break;
            case 8:FreeLinklist(L); break;
            default: printf("��������\n"); break;
        }
    }
}

Linklist CreatLinklist(Linklist L)
{
    L=NULL;
    Lnode *s,*r=NULL;
    int x;
    printf("���������ݣ�����Ϊ0ʱ����\n");
    scanf("%d",&x);
    while(x!=0)
    {
        s=(Lnode *)malloc(sizeof(Lnode));
        s->data=x;
        if(L==NULL)
            L=s;
        else
            r->next=s;
        r=s;
        printf("���������ݣ�����Ϊ0ʱ����\n");
        scanf("%d",&x);
    }
    if(r!=NULL)
        r->next=NULL;
    s=(Lnode *)malloc(sizeof(Lnode));
    s->next=L;
    L=s;
    return L;
}

void InsertLinklist(Linklist L,int r,int i)
{
    Lnode *p,*s;
    p=GetLinklist2(L,r-1);
    if(p==NULL)
        {printf("�Ҳ�����λ��\n"); return;}
    else
        {
            s=(Lnode *)malloc(sizeof(Lnode));
            s->data=i;
            s->next=p->next;
            p->next=s;
        }
}
int LengthLinklist(Linklist L)
{
    Lnode *p;
    p=L;
    int i=0;
    while(p->next){
        p=p->next;
        i++;}
        return i;
}

Linklist GetLinklist1(Linklist L,int b,int *a)
{
    Lnode *p=L->next;
    int i;
    for(i=1;p!=NULL;p=p->next,i++)
        if(p->data==b)
        break;
        if(p==NULL) *a=-1;
        else *a=i;
        return p;
}

Linklist GetLinklist2(Linklist L,int r)
{
    Lnode *p=L;
    int j;
    for(j=0;p!=NULL;p=p->next,j++)
        if(j==r)
        break;
    if(p==NULL) return NULL;
    else return p;
}

void DeleteLinklist(Linklist L,int r)
{
    Lnode *p,*s;
    p=GetLinklist2(L,r-1);
    if(p==NULL)
        {printf("��r-1����㲻����\n"); return;}
    else if(p->next==NULL)
        {printf("��r����㲻����\n"); return;}
    else
    {
        s=p->next;
        p->next=s->next;
        free(s);
    }
}
void OutputLinklist(Linklist L)
{
    Lnode *p;
    p=L->next;
    printf("����Ϊ:");
    while(p){
        printf("  %d",p->data);
        p=p->next;}
        printf("\n");
}

void FreeLinklist(Linklist L)
{
    Lnode *p,*q;
    p=L->next;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    L->next=NULL;
}
