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
        printf("请输入0~5\n");
        printf("1-置空栈      2-判栈空      3-入栈\n");
        printf("4-出栈        5-取栈顶元素  0-退出\n");
        printf("------------------------------\n");
        scanf("%d",&a);
        if(a==0) break;
        switch(a)
        {
            case 1:top=InitLinkStack(top); break;
            case 2:i=EmptyLinkStack(top);
                   if(i>0) printf("此栈为空栈\n");
                   else printf("此栈不是空栈\n");
                   break;
            case 3:printf("请输入入栈元素\n");
                   scanf("%d",&x);
                   top=PushLinkStack(top,x);
                   printf("已成功存入栈内\n");
                   break;
            case 4:top=PopLinkStack(top);
                   break;
            case 5:TopLinkStack(top,&x);
                   if(top==NULL) printf("栈为空\n");
                   else printf("栈顶元素值为:%d\n",x);
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
        printf("栈为空\n");
        return top;
    }
    p=top;
    printf("出栈元素值为:%d\n",top->data);
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
