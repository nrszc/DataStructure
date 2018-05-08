#include<stdio.h>
#include<stdlib.h>
#define MaxSize 1024
struct duilie
{
    int data[MaxSize];
    int rear,front;
    int num;
};
typedef struct duilie SeQueue;
SeQueue *InitSeQueue();
int InSeQueue(SeQueue *q,int x);
int OutSeQueue(SeQueue *q,int *x);
int ReadSeQueue(SeQueue *q,int *x);
int EmptySeQueue(SeQueue *q);
int main()
{
     SeQueue *q;
     int i,a,x;
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
             case 1:q=InitSeQueue(); break;
             case 2:printf("请输入入队元素值\n");
                    scanf("%d",&x);
                    i=InSeQueue(q,x);
                    if(i>0) printf("入队成功\n");
                    break;
             case 3:i=OutSeQueue(q,&x);
                    if(i>0){
                    printf("出队成功\n");
                    printf("出队元素值为:%d\n",x);}
                    break;
             case 4:i=ReadSeQueue(q,&x);
                    if(i>0)
                    printf("对头元素值为:%d\n",x);
                    break;
             case 5:i=EmptySeQueue(q);
                    if(i>0) printf("队空\n");
                    else printf("队不为空\n");
                    break;
         }
     }
}

SeQueue *InitSeQueue()
{
    SeQueue *q;
    q=(SeQueue *)malloc(sizeof(SeQueue));
    q->front=q->rear=MaxSize-1;
    q->num=0;
    return q;
}

int InSeQueue(SeQueue *q,int x)
{
    if(q->num==MaxSize-1)
    {
        printf("队满\n");
        return -1;
    }
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=x;
    q->num++;
    return 1;
}

int OutSeQueue(SeQueue *q,int *x)
{
    if(q->num==0) {
    printf("队空\n");
    return -1;}
    q->front=(q->front+1)%MaxSize;
    *x=q->data[q->front];
    q->num--;
    return 1;
}

int ReadSeQueue(SeQueue *q,int *x)
{
    if(q->num==0){
        printf("队空\n");
        return -1;
    }
    *x=q->data[(q->front+1)%MaxSize];
    return 1;
}

int EmptySeQueue(SeQueue *q)
{
    if(q->num==0) return 1;
    return 0;
}
