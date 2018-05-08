#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 21
#define MAXVALUE 10000
typedef struct{
    char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodetype;
typedef struct{
	int bit[MAX];
	int start;
}HCodetype;
HNodetype *HuffMTree[2*MAX-1];
HCodetype *HuffCode[MAX];
int n;
void CreateHuffMTree();
void HaffmanCode();
void DeCode();
void Output();


int main()
{
    int i,a;
    while(1)
    {
        system("cls");
        printf("-----------------------------------------\n");
        printf("请输入0~4\n");
        printf("1-建树  2-编码  3-译码\n");
        printf("4-输出  0-退出\n");
        printf("-----------------------------------------\n");
        scanf("%d",&a);
        if(a==0)
            break;
        switch(a)
        {
            case 1:CreateHuffMTree(); break;
            case 2:HaffmanCode(); break;
            case 3:DeCode(); break;
            case 4:Output(); break;
        }
    }
}

void CreateHuffMTree() //建立哈夫曼树
{
    system("cls");
    int m1,x1,m2,x2;
    int i,j;
    printf("请输入结点个数：");
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++)
    {
        HuffMTree[i]=(HNodetype *)malloc(sizeof(HNodetype));
        HuffMTree[i]->weight=0;
        HuffMTree[i]->parent=HuffMTree[i]->lchild=HuffMTree[i]->rchild=-1;
        HuffMTree[i]->data='0';
    }

    for(i=0;i<n;i++){
            getchar();
        printf("请输入字符：");
        scanf("%c",&HuffMTree[i]->data);
        printf("请输入字符的权值：");
        scanf("%d",&HuffMTree[i]->weight);}
	for(i=0;i<n-1;i++)
    {
        x1=x2=MAXVALUE;
        m1=m2=0;
        for(j=0;j<n+i;j++)
        {
            if(HuffMTree[j]->parent==-1&&HuffMTree[j]->weight<x1)
            {
                x2=x1;m2=m1;
                x1=HuffMTree[j]->weight; m1=j;
            }
            else if(HuffMTree[j]->parent==-1&&HuffMTree[j]->weight<x2)
            {
                x2=HuffMTree[j]->weight;
                m2=j;
            }
        }
        HuffMTree[m2]->parent=n+i; HuffMTree[m1]->parent=n+i;
        HuffMTree[n+i]->weight=HuffMTree[m1]->weight+HuffMTree[m2]->weight;
        HuffMTree[n+i]->lchild=m2; HuffMTree[n+i]->rchild=m1;
        HuffMTree[n+i]->data='0';
    }
    printf("按回车继续");
    getchar();getchar();
}

void HaffmanCode() //编码
{
    system("cls");
    HCodetype *cd=(HCodetype *)malloc(sizeof(HCodetype));
    int i,j,c,p;
    FILE *fp;
    for(i=0;i<n;i++)
    {
        cd->start=n-1;
        c=i;
        p=HuffMTree[c]->parent;
        while(p!=-1)
        {
            if(HuffMTree[p]->lchild==c)
                cd->bit[cd->start]=0;
            else
                cd->bit[cd->start]=1;
            cd->start--;
            c=p;
            p=HuffMTree[c]->parent;
        }
        HuffCode[i]=(HCodetype *)malloc(sizeof(HCodetype));
        for(j=cd->start+1;j<n;j++)
            HuffCode[i]->bit[j]=cd->bit[j];
        HuffCode[i]->start=cd->start+1;
    }
    printf("字符信息--编码信息\n");
    for(i=0;i<n;i++)
    {
        printf("%c:",HuffMTree[i]->data);
        for(j=HuffCode[i]->start;j<n;j++)
        printf("%d",HuffCode[i]->bit[j]);
        printf("\n");
    }
    printf("请输入请输入要编码的字符串,基本元素为（");
    for(i=0;i<n-1;i++)
    printf("%c,",HuffMTree[i]->data);
    printf("%c",HuffMTree[i]->data);
    printf("）\n");
    char data[100];
    scanf("%s",data);
    int f;
    f=strlen(data);
    printf("字符串编码后为:");
    if((fp=fopen("c:\\123.txt","w"))==NULL)
    {
        printf("文件打不开\n");
        return;
    }
    for(int x=0;x<f;x++)
	  {
         for(i=0;i<n;i++)
		 {
			 if(data[x]==HuffMTree[i]->data)
			 {
				 for(j=HuffCode[i]->start;j<n;j++)
				 {
				     fprintf(fp,"%20d",HuffCode[i]->bit[j]);
					 printf("%d",HuffCode[i]->bit[j]);
				 }
			 }
		 }
	  }
     printf("\n解码内容文件已经存储在c盘\n");
     fclose(fp);
     printf("按回车继续");
    getchar();getchar();
}

void DeCode() //译码
{
    system("cls");
    int i;
    int tempcode[100];
	int num=0;
	FILE *fp,*fp1;
	for(i=0;i<100;i++)
		tempcode[i]=-1;
    if((fp1=fopen("c:\\abc.txt","w+"))==NULL)
    {
        printf("文件打不开\n");
        return;
    }
    if((fp=fopen("c:\\123.txt","r"))==NULL)
    {
        printf("文件打不开\n");
        return;
    }
	printf("从文件中读出的编码为:");
	while(!feof(fp))
	{
		fscanf(fp,"%d",&tempcode[num]);
		num++;
	}
	for(i=0;i<num;i++)
		printf("%d",tempcode[i]);
		printf("\n");
    int m=2*n-2;
    i=0;
    printf("译码后为:");
    while(i<num)
    {
	    while(HuffMTree[m]->lchild!=-1&&HuffMTree[m]->rchild!=-1)
		{
	        if(tempcode[i]==0)
			{
				m=HuffMTree[m]->lchild;
				i++;
			}
			else if(tempcode[i]==1)
			{
				m=HuffMTree[m]->rchild;
				i++;
			}
		}
        printf("%c",HuffMTree[m]->data);
		fprintf(fp1,"%20c",HuffMTree[m]->data);
		m=2*n-2;
	}
   printf("\n");
   printf("译码内容文件已经存储在c盘\n");
   fclose(fp);
   fclose(fp1);
   printf("按回车继续");
    getchar();getchar();
}

void Output() //输出
{
    int i,j;
    system("cls");
    printf("显示哈夫曼树的信息\n");
    printf("字符\t权值\t左孩子\t右孩子\t双亲\t\n");
    for(i=0;i<2*n-1;i++)
    {
        printf("%c\t",HuffMTree[i]->data);
        printf("%d\t%d\t%d\t%d\n",HuffMTree[i]->weight,HuffMTree[i]->lchild,HuffMTree[i]->rchild,HuffMTree[i]->parent);
    }
    printf("字符信息--编码信息\n");
    for(i=0;i<n;i++)
    {
        printf("%c:",HuffMTree[i]->data);
        for(j=HuffCode[i]->start;j<n;j++)
        printf("%d",HuffCode[i]->bit[j]);
        printf("\n");
    }
    printf("按回车继续");
    getchar();
    getchar();
}
