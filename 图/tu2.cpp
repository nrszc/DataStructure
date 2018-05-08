#include<stdio.h>
#include<stdlib.h>
#define N 6
#define MAX 100
typedef struct
{
    char vexs[N];
    int edges[N][N];
    int n,e;
}MGragh;
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
Vertex AdjList[N];
void Adjlist();
void Adjmatrix();
MGragh *CreateMGragh();
void DFSMGragh1(MGragh *G);
void DFSMGragh2(MGragh *G,int v);
void BFSMGragh1(MGragh *G);
void BFSMGragh2(MGragh *G,int i);
void CreateALGreph();
void DFSALGreph1();
void DFSALGreph2(Vertex AdjList[],int i);
void BFSALGreph();
int visit1[N]={0};
int visit2[N]={0};
int flag1[N]={0};
int flag2[N]={0};

int main()
{
    int i,x;
    while(1)
    {
        printf("请选择：\n");
        printf("-------------------------------------\n");
        printf("1-邻接矩阵   2-邻接表   0-退出\n");
        printf("-------------------------------------\n");
        scanf("%d",&i);
        if(i==0) break;
        switch(i)
        {
            case 1:Adjlist(); break;
            case 2:Adjmatrix(); break;
        }
    }
}

void Adjlist()
{
    int i,x;
    MGragh *G;
    while(1){
    printf("------------------------------------------------\n");
    printf("请输入:\n");
    printf("1-图的初始化    2-深度优先搜索    3-广度深度搜索\n");
    printf("0-退出\n");
    printf("------------------------------------------------\n");
    scanf("%d",&i);
        if(i==0) break;
    switch(i)
    {
        case 1:G=CreateMGragh(); break;
        case 2:DFSMGragh1(G); printf("\n"); break;
        case 3:BFSMGragh1(G); printf("\n"); break;
    }
            }
}

void Adjmatrix()
{
    int i,x;
    while(1){
    printf("------------------------------------------------\n");
    printf("请输入:\n");
    printf("1-图的初始化    2-深度优先搜索    3-广度深度搜索\n");
    printf("0-退出\n");
    printf("------------------------------------------------\n");
    scanf("%d",&i);
        if(i==0) break;
    switch(i)
    {
        case 1:CreateALGreph(); break;
        case 2:DFSALGreph1(); printf("\n"); break;
        case 3:BFSALGreph(); printf("\n"); break;
    }
            }
}


MGragh *CreateMGragh()
{
    MGragh *G;
    int i,j,k,w,E;
    char ch;
    G=(MGragh *)malloc(sizeof(MGragh));
    printf("请输入各顶点：\n");
       scanf("%s",(G->vexs));
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        G->edges[i][j]=0;
    printf("请输入边的数目：");
    scanf("%d",&E);
    printf("是否为有向图（0/1)：");
    scanf("%d",&i);
    printf("请输入有邻接关系的两点：\n");
    if(i==0){
    for(k=0;k<E;k++)
    {
        scanf("%d%d",&i,&j);
        G->edges[i][j]=1;
        G->edges[j][i]=1;
    }}
    else{
        for(k=0;k<E;k++)
    {
        scanf("%d%d",&i,&j);
        G->edges[i][j]=1;
    }
    }
     for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        printf("%d ",G->edges[i][j]);
        printf("\n");}
    return G;

}


void DFSMGragh1(MGragh *G)
{
    int u;
    for(u=0;u<N;u++)
        if(visit1[u]!=1)
        DFSMGragh2(G,u);
}

void DFSMGragh2(MGragh *G,int u)
{
    int v;
    visit1[u]=1;
    printf("%3c",G->vexs[u]);
    for(v=0;v<N;v++)
        if(visit1[v]!=1&&G->edges[u][v]==1)
        DFSMGragh2(G,v);
}

void BFSMGragh1(MGragh *G)
{
    int i;
    for(i=0;i<N;i++)
        if(visit2[i]!=1)
            BFSMGragh2(G,i);
}

void BFSMGragh2(MGragh *G,int i)
{
    int j;
    int Q[MAX],rear,front;
    front=0; rear=-1;
    printf("%3c",G->vexs[i]);
    visit2[i]=1;
    rear++; Q[rear]=i;
    while(front<=rear)
    {
        i=Q[front]; front++;
        for(j=0;j<N;j++)
            if(G->edges[i][j]==1&&visit2[j]!=1)
        {
            printf("%3c",G->vexs[j]);
            visit2[j]=1;
            rear++; Q[rear]=j;
        }
    }

}

void CreateALGreph()
{
    int i,j,k,E;
    Edge *s1,*s2,*p;
    printf("请输入各顶点：");
    for(i=0;i<N;i++)
    {
        getchar();
        scanf("%c",&(AdjList[i].vertex));
        AdjList[i].first=NULL;
    }

    printf("请输入边的条数：");
    scanf("%d",&E);
    printf("是否为有向图（0/1)：");
    scanf("%d",&i);
    printf("请输入有邻接关系的两点：\n");
    if(i){
    for(k=0;k<E;k++)
    {
        scanf("%d %d",&i,&j);
        s1=(Edge *)malloc(sizeof(Edge));
        s1->adjvex=j;
        s1->next=AdjList[i].first;
        AdjList[i].first=s1;
    }}
    else
        for(k=0;k<E;k++){
        scanf("%d %d",&i,&j);
        s1=(Edge *)malloc(sizeof(Edge));
        s1->adjvex=i;
        s1->next=AdjList[i].first;
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
        if(flag1[i]!=1) DFSALGreph2(AdjList,i);
}

void DFSALGreph2(Vertex AdjList[],int i)
{
    Edge *p;
    int j;
    printf("%3c",AdjList[i].vertex);
    flag1[i]=1;
    p=AdjList[i].first;
    while(p)
    {
        j=p->adjvex;
        if(flag1[j]!=1)
        DFSALGreph2(AdjList,j);
        p=p->next;
    }

}

void BFSALGreph()
{
    int i,j,k;
	int Q[MAX],front,rear;
	front=0; rear=-1;
	Edge *p;
	for(i=0;i<N;i++)
	{

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
				p=AdjList[j].first;
				while(p)
				{
					if(!flag2[p->adjvex])
					{
						printf("%3c",AdjList[p->adjvex].vertex);
						flag2[p->adjvex]=1;
						rear++; Q[rear]=p->adjvex;
					}
					p=p->next;
				}
			}
		}
	}

}
