#include<stdio.h>
#include<stdlib.h>
typedef struct bitnode
{
    int data;
    struct bitnode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree CreateBiTree();
void PreOrderBiTree(BiTree bt);
void InOrderBiTree(BiTree bt);
void PostOrderBiTree(BiTree bt);
BiTree SearchBiTree(BiTree bt,int x);
BiTree InsertLBiTree(BiTree bt,int x);
BiTree InsertRBiTree(BiTree bt,int x);
BiTree DeleteLBiTree(BiTree bt,int x);
BiTree DeleteRBiTree(BiTree bt,int x);


int main()
{
    int a,i,x,n=0;
    BiTree bt,p;
    while(1)
    {
        printf("������0~5\n");
        printf("------------------------------------------------------\n");
        printf("1-����������     2-�������     3-�������\n");
        printf("4-�������       5-��ֵ����     6-�����\n");
        printf("7-�Ҳ���         8-ɾ��������   9-ɾ��������   0-�˳�\n");
        printf("------------------------------------------------------\n");
        scanf("%d",&a);
        if(a==0)
            break;
        switch(a)
        {
            case 1:bt=CreateBiTree(); break;
            case 2:PreOrderBiTree(bt); break;
            case 3:InOrderBiTree(bt); break;
            case 4:PostOrderBiTree(bt); break;
            case 5:printf("������Ҫ���ҵ���ֵ��");
                   scanf("%d",&x);
                   p=SearchBiTree(bt,x);
                   if(p!=NULL){
                   printf("�ҵ���ֵ\n");
                  }
                   else
                   printf("û���ҵ�\n");
                   break;
            case 6:printf("������Ҫ����λ��ǰ���ֵ��");
                   scanf("%d",&x);
                   bt=InsertLBiTree(bt,x);
                   break;
            case 7:printf("������Ҫ����λ��ǰ���ֵ��");
                   scanf("%d",&x);
                   bt=InsertRBiTree(bt,x);
                   break;
            case 8:printf("������Ҫɾ����������˫��Ԫ��ֵ��");
                   scanf("%d",&x);
                   bt=DeleteLBiTree(bt,x);
                   break;
            case 9:printf("������Ҫɾ����������˫��Ԫ��ֵ��");
                   scanf("%d",&x);
                   bt=DeleteRBiTree(bt,x);
                   break;

        }
    }
}


BiTree CreateBiTree()
{
    BiTree bt;
    int a;
    printf("����Ԫ��ֵ��������0ʱΪ������Ϊ�գ�");
    scanf("%d",&a);
    if(a==0)
       bt=NULL;
    else
    {
        bt=(BiTNode *)malloc(sizeof(BiTNode));
        bt->data=a;
        bt->lchild=CreateBiTree();
        bt->rchild=CreateBiTree();
    }
    return bt;
}

void PreOrderBiTree(BiTree bt)
{
    if(bt==NULL)
        return;
    printf("%d ",bt->data);
    PreOrderBiTree(bt->lchild);
    PreOrderBiTree(bt->rchild);
}

void InOrderBiTree(BiTree bt)
{
    if(bt==NULL)
        return;
    InOrderBiTree(bt->lchild);
    printf("%d ",bt->data);
    InOrderBiTree(bt->rchild);
}

void PostOrderBiTree(BiTree bt)
{
    if(bt==NULL)
        return;
    PostOrderBiTree(bt->lchild);
    PostOrderBiTree(bt->rchild);
    printf("%d ",bt->data);
}

BiTree SearchBiTree(BiTree bt,int x)
{
    BiTree p=NULL;
    if(bt)
    {
        if(bt->data==x) return bt;
        if(bt->lchild)  p=SearchBiTree(bt->lchild,x);
        if(p) return p;
        if(bt->rchild)  p=SearchBiTree(bt->rchild,x);
        if(p) return p;
    }
    return NULL;
}

BiTree InsertLBiTree(BiTree bt,int x)
{
    BiTree p,q;
    p=SearchBiTree(bt,x);
    if(p==NULL)
    {
        printf("û�и�ֵ\n");
        return bt;
    }
    printf("������Ҫ����λ�õ�ֵ��");
    scanf("%d",&x);
    q=(BiTNode *)malloc(sizeof(BiTNode));
    q->data=x;
    q->lchild=p->lchild;
    q->rchild=NULL;
    p->lchild=q;
    return bt;
}

BiTree InsertRBiTree(BiTree bt,int x)
{
    BiTree p,q;
    p=SearchBiTree(bt,x);
    if(p==NULL)
    {
        printf("û�и�ֵ\n");
        return bt;
    }
    printf("������Ҫ����λ�õ�ֵ��");
    scanf("%d",&x);
    q=(BiTNode *)malloc(sizeof(BiTNode));
    q->data=x;
    q->lchild=NULL;
    q->rchild=p->rchild;
    p->rchild=q;
    return bt;
}

BiTree DeleteLBiTree(BiTree bt,int x)
{
    BiTree p,q;
    if(bt==NULL||bt->lchild==NULL)
    {
        printf("ɾ������\n");
        return bt;
    }
    p=SearchBiTree(bt,x);
    if(p==NULL)
    {
        printf("û���ҵ���ֵ\n");
        return bt;
    }
    if(p->lchild==NULL)
    {
        printf("�ý��û��������\n");
        return bt;
    }
    q=p->lchild;
    p->lchild=NULL;
    free(q);
    return bt;
}

BiTree DeleteRBiTree(BiTree bt,int x)
{
    BiTree p,q;
    if(bt==NULL||bt->rchild==NULL)
    {
        printf("ɾ������\n");
        return bt;
    }
    p=SearchBiTree(bt,x);
    if(p==NULL)
    {
        printf("û���ҵ���ֵ\n");
        return bt;
    }
    if(p->rchild==NULL)
    {
        printf("�ý��û��������\n");
        return bt;
    }
    q=p->rchild;
    p->rchild=NULL;
    free(q);
    return bt;
}

