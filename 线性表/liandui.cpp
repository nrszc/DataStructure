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
         printf("请输入0~5\n");
         printf("1-队列初始化    2-入队    3-出队\n");
         printf("4-读队头        5-判队空  0-退出\n");
         printf("--------------------------------\n");
         scanf("%d",&a);
         if(a==0) break;
         switch(a)
         {
             case 1:q=InitLQueue(); break;
             case 2:printf("请输入入队元素值\n");
                    scanf("%d",&x);
                    i=InLQueue(q,x);
                    if(i>0) printf("入队成功\n");
                    break;
             case 3:i=OutLQueue(q,&x);
                    if(i>0){
                    printf("出队成功\n");
                    printf("出队元素值为:%d\n",x);}
                    break;
             case 4:i=ReadLQueue(q,&x);
                    if(i>0)
                    printf("队头元素值为:%d\n",x);
                    break;
             case 5:i=EmptyLQueue(q);
                    if(i>0) printf("队空\n");
                    else printf("队不为空\n");
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
        printf("队空\n");
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
        printf("队空\n");
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
