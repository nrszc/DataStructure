#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Qnode;
typedef struct
{
    Qnode *front,*rear;
}LQueue;

LQueue *InitLQueue();
int InLQueue(LQueue *q,int x);
int OutLQueue(LQueue *q,int *x);
int ReadLQueue(LQueue *q,int *x);
int EmptyLQueue(LQueue *q);
int main()
{
    LQueue *q;
    int i,x,a;
    while(1)
    {
         printf("--------------------------------\n");
         printf("������0~5\n");
         printf("1-���г�ʼ��    2-���    3-����\n");
         printf("4-����ͷ        5-�жӿ�  0-�˳�\n");
         printf("--------------------------------\n");
         scanf("%d",&a);
         if(a==0) break;
         switch(a)
         {
             case 1:q=InitLQueue(); break;
             case 2:printf("���������Ԫ��ֵ\n");
                    scanf("%d",&x);
                    i=InLQueue(q,x);
                    if(i>0) printf("��ӳɹ�\n");
                    break;
             case 3:i=OutLQueue(q,&x);
                    if(i>0){
                    printf("���ӳɹ�\n");
                    printf("����Ԫ��ֵΪ:%d\n",x);}
                    break;
             case 4:i=ReadLQueue(q,&x);
                    if(i>0)
                    printf("��ͷԪ��ֵΪ:%d\n",x);
                    break;
             case 5:i=EmptyLQueue(q);
                    if(i>0) printf("�ӿ�\n");
                    else printf("�Ӳ�Ϊ��\n");
                    break;
         }
    }
}

LQueue *InitLQueue()
{
    LQueue *q;
    Qnode *p;
    q=(LQueue *)malloc(sizeof(LQueue));
    p=(Qnode *)malloc(sizeof(Qnode));
    p->next=NULL;
    q->front=p;
    q->rear=p;
    return q;
}

int InLQueue(LQueue *q,int x)
{
    Qnode *p;
    p=(Qnode *)malloc(sizeof(Qnode));
    p->data=x;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return 1;
}

int OutLQueue(LQueue *q,int *x)
{
    if(EmptyLQueue(q))
    {
        printf("�ӿ�\n");
        return 0;
    }
    Qnode *p;
    p=q->front->next;
    q->front->next=p->next;
    *x=p->data;
    free(p);
    if(q->front->next==NULL)
       q->rear=q->front;
    return 1;
}

int ReadLQueue(LQueue *q,int *x)
{
    if(EmptyLQueue(q))
    {
        printf("�ӿ�\n");
        return 0;
    }
    *x=q->front->next->data;
    return 1;
}

int EmptyLQueue(LQueue *q)
{
    if(q->front==q->rear)
        return 1;
    return 0;
}
