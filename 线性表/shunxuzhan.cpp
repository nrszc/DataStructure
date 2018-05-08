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
        printf("������0~5\n");
        printf("1-�ÿ�ջ      2-��ջ��      3-��ջ\n");
        printf("4-��ջ        5-ȡջ��Ԫ��  0-�˳�\n");
        printf("------------------------------\n");
        scanf("%d",&a);
        if(a==0) break;
        switch(a)
        {
            case 1:s=InitSeqStack(); break;
            case 2:i=EmptySeqStack(s);
                   if(i==1) printf("��ջΪ��ջ\n");
                   else printf("��ջ���ǿ�ջ\n");
                   break;
            case 3:printf("��������ջԪ��\n");
                   scanf("%d",&x);
                   i=PushSeqStack(s,x);
                   if(i==0) printf("ջ����\n");
                   else printf("�ѳɹ�����ջ��\n");
                   break;
            case 4:i=PopSeqStack(s,&x);
                   if(i==0) printf("ջΪ��\n");
                   else printf("��ջԪ��ֵΪ:%d\n",x);
                   break;
            case 5:i=TopSeqStack(s,&x);
                   if(i==0) printf("ջΪ��\n");
                   else printf("ջ��Ԫ��ֵΪ:%d\n",x);
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
