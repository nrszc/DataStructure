#include<stdio.h>
#include<stdlib.h>
#define N 6
typedef struct
{
    char vexs[N];
    int edges[N][N];
    int n,e;
}MGragh;
MGragh *CreateMGragh();
void DFSMGragh1(MGragh *G);
void DFSMGragh2(MGragh *G,int v);
void BFSMGragh1(MGragh *G);
void BFSMGragh2(MGragh *G,int i);
void DestroyGragh(MGragh **G);
int visit1[N]={0};
int visit2[N]={0};

int main()
{
    MGragh *G;
    int i,x;
    while(1){
    printf("------------------------------------------------\n");
    printf("请输入:\n");
    printf("1-图的初始化    2-深度优先搜索    3-广度深度搜索\n");
    printf("------------------------------------------------\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:G=CreateMGragh(); break;
        case 2:DFSMGragh1(G); printf("\n"); break;
        case 3:BFSMGragh1(G); printf("\n"); break;
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
    int Q[N],rear,front;
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
