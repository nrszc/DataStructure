#include<stdio.h>
#include<stdlib.h>
#define MaxSize 1024
struct Stack
{
    int data[MaxSize];
    int top;
};
typedef struct Stack SeqStack;
SeqStack *InitSeqStack();
int EmptySeqStack(SeqStack *s);
int PushSeqStack(SeqStack *s,int x);
int PopSeqStack(SeqStack *s,int *x);
int TopSeqStack(SeqStack *s,int *x);
int main()
{
    SeqStack *s;
    int i,a,x;
    int b;
    while(1)
    {
        printf("------------------------------\n");
        printf("请输入0~5\n");
        printf("1-置空栈      2-判栈空      3-入栈\n");
        printf("4-出栈        5-取栈顶元素  0-退出\n");
        printf("------------------------------\n");
        scanf("%d",&a);
        if(a==0) break;
        switch(a)
        {
            case 1:s=InitSeqStack(); break;
            case 2:i=EmptySeqStack(s);
                   if(i==1) printf("此栈为空栈\n");
                   else printf("此栈不是空栈\n");
                   break;
            case 3:printf("请输入入栈元素\n");
                   scanf("%d",&x);
                   i=PushSeqStack(s,x);
                   if(i==0) printf("栈已满\n");
                   else printf("已成功存入栈内\n");
                   break;
            case 4:i=PopSeqStack(s,&x);
                   if(i==0) printf("栈为空\n");
                   else printf("出栈元素值为:%d\n",x);
                   break;
            case 5:i=TopSeqStack(s,&x);
                   if(i==0) printf("栈为空\n");
                   else printf("栈顶元素值为:%d\n",x);
                   break;
        }
    }


}

SeqStack *InitSeqStack()
{
    SeqStack *s;
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

int EmptySeqStack(SeqStack *s)
{
    if(s->top==-1) return 1;
    else return 0;
}

int PushSeqStack(SeqStack *s,int x)
{
    if(s->top==MaxSize-1) return 0;
    s->top++;
    s->data[s->top]=x;
    return 1;
}

int PopSeqStack(SeqStack *s,int *x)
{
    if(EmptySeqStack(s)) return 0;
    *x=s->data[s->top];
    s->top--;
    return 1;
}

int TopSeqStack(SeqStack *s,int *x)
{
    if(EmptySeqStack(s)) return 0;
    *x=s->data[s->top];
    return 1;
}
