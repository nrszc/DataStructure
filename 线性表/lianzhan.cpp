#include<stdio.h>
#include<stdlib.h>
typedef struct snode
{
    int data;
    struct snode *next;
}StackNode,*LinkStack;
LinkStack InitLinkStack(LinkStack top);
int EmptyLinkStack(LinkStack top);
LinkStack PushLinkStack(LinkStack top,int x);
LinkStack PopLinkStack(LinkStack top);
void TopLinkStack(LinkStack top,int *x);
int main()
{
    LinkStack top;
    int i,a,x;
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
            case 1:top=InitLinkStack(top); break;
            case 2:i=EmptyLinkStack(top);
                   if(i>0) printf("��ջΪ��ջ\n");
                   else printf("��ջ���ǿ�ջ\n");
                   break;
            case 3:printf("��������ջԪ��\n");
                   scanf("%d",&x);
                   top=PushLinkStack(top,x);
                   printf("�ѳɹ�����ջ��\n");
                   break;
            case 4:top=PopLinkStack(top);
                   break;
            case 5:TopLinkStack(top,&x);
                   if(top==NULL) printf("ջΪ��\n");
                   else printf("ջ��Ԫ��ֵΪ:%d\n",x);
                   break;
        }
    }
}

LinkStack InitLinkStack(LinkStack top)
{
    top=NULL;
    return top;
}

int EmptyLinkStack(LinkStack top)
{
    if(top==NULL)
        return 1;
    return 0;
}

LinkStack PushLinkStack(LinkStack top,int x)
{
    StackNode *p;
    p=(StackNode *)malloc(sizeof(StackNode));
    p->data=x;
    p->next=top;
    top=p;
    return top;
}

LinkStack PopLinkStack(LinkStack top)
{
    StackNode *p;
    if(EmptyLinkStack(top))
    {
        printf("ջΪ��\n");
        return top;
    }
    p=top;
    printf("��ջԪ��ֵΪ:%d\n",top->data);
    top=top->next;
    free(p);
    return top;
}

void TopLinkStack(LinkStack top,int *x)
{
    if(EmptyLinkStack(top))
    {
        return;
    }
    *x=top->data;
}
