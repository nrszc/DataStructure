#include<stdio.h>
#include<stdlib.h>
#define N 6;
typedef struct node
{
    int adjvex;
    struct node *next;
}Edge;
typedef struct vnode
{
    char vertex;
    Edge *first;
}Vertex;
void CreateALGreph();
void DFSALGreph1();
void DFSALGreph2(Vertex AdjList[],int i);
void BFSALGreph1();
void BFSALGreph2();
int flag1[N]={0};
int flag2[N]={0};
int main()
{
    Vertex AdjList[N];
    int i,x;
    while(1){
    printf("------------------------------------------------\n");
    printf("请输入:\n");
    printf("1-图的初始化    2-深度优先搜索    3-广度深度搜索\n");
    printf("4-释放图\n");
    printf("------------------------------------------------\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:CreateALGreph(); break;
        case 2:DFSALGreph1(); printf("\n"); break;
        case 3:BFSALGreph1(); printf("\n"); break;
    }
            }
}

void CreateALGreph();
{
    int i,j,k,E;
    Edge *s1,*s2;
    printf("请输入各顶点：")；
    for(i=0;i<N;i++)
    {
        scanf("%c",&(AdjList[i].vertex));
        AdjList[i].first=NULL;
    }
    printf("请输入边的条数：");
    scanf("%d",&E);
    printf("是否为有向图（0/1)：");
    scanf("%d",&i);
    printf("请输入有邻接关系的两点：\n");
    if(i){
    for(k=0;k<E;i++)
    {
        scanf("%d %d",&i,&j);
        s1=(Edge *)malloc(sizeof(Edge));
        s1->adjvex=j;
        s1->next=AdjList.first;
        AdjList[i].first=s1;
    }}
    else{
        scanf("%d %d",&i,&j);
        s1=(Edge *)malloc(sizeof(Edge));
        s1->adjvex=i;
        s1->next=AdjList.first;
        AdjList[j].first=s1;
        s2=(Edge *)malloc(sizeof(Edge));
        s2->adjvex=i;
        s2->next=AdjList[j].first;
        AdjList[j].first=s2;
    }
}

void DFSALGreph1()
{
    int i;
    for(i=0;i<N;i++)
        if(flag1[i]!=0) DFS(AdjList,i);
}

void DFSALGreph2(Vertex AdjList[],int i)
{
    Edge *p;
    printf("%3c",AdjList[i].vertex);
    flag1[i]=1;
    p=AdjList[i].first;
    while(p)
    {
        j=p->adjvex;
        if(flag!=1)
        DFSALGreph2();
        p=p->next;
    }

}

void BFSALGreph1()
{
    int i,j,k;
	int Q[N],front,rear;
	front=0; rear=-1;
	Edge *p;
	for(i=0;i<N;i++)
	{
	    if()
		if(flag2[i]!=1)
		{
			flag2[i]=1;
			printf("%3c",AdjList[i].vertex);
			rear++;
			Q[rear]=i;
			while(front<=rear)
			{
				j=Q[front];
				front++;
				p=vertex[j].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						printf("广度优先遍历:结点%c\n", graph->vertexs[p->adjvex].vertex);
						visited[p->adjvex] = TRUE;
						q.push(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}

}
