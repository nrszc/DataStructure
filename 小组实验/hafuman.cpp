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
        printf("������0~4\n");
        printf("1-����  2-����  3-����\n");
        printf("4-���  0-�˳�\n");
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

void CreateHuffMTree() //������������
{
    system("cls");
    int m1,x1,m2,x2;
    int i,j;
    printf("�������������");
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
        printf("�������ַ���");
        scanf("%c",&HuffMTree[i]->data);
        printf("�������ַ���Ȩֵ��");
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
    printf("���س�����");
    getchar();getchar();
}

void HaffmanCode() //����
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
    printf("�ַ���Ϣ--������Ϣ\n");
    for(i=0;i<n;i++)
    {
        printf("%c:",HuffMTree[i]->data);
        for(j=HuffCode[i]->start;j<n;j++)
        printf("%d",HuffCode[i]->bit[j]);
        printf("\n");
    }
    printf("������������Ҫ������ַ���,����Ԫ��Ϊ��");
    for(i=0;i<n-1;i++)
    printf("%c,",HuffMTree[i]->data);
    printf("%c",HuffMTree[i]->data);
    printf("��\n");
    char data[100];
    scanf("%s",data);
    int f;
    f=strlen(data);
    printf("�ַ��������Ϊ:");
    if((fp=fopen("c:\\123.txt","w"))==NULL)
    {
        printf("�ļ��򲻿�\n");
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
     printf("\n���������ļ��Ѿ��洢��c��\n");
     fclose(fp);
     printf("���س�����");
    getchar();getchar();
}

void DeCode() //����
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
        printf("�ļ��򲻿�\n");
        return;
    }
    if((fp=fopen("c:\\123.txt","r"))==NULL)
    {
        printf("�ļ��򲻿�\n");
        return;
    }
	printf("���ļ��ж����ı���Ϊ:");
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
    printf("�����Ϊ:");
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
   printf("���������ļ��Ѿ��洢��c��\n");
   fclose(fp);
   fclose(fp1);
   printf("���س�����");
    getchar();getchar();
}

void Output() //���
{
    int i,j;
    system("cls");
    printf("��ʾ������������Ϣ\n");
    printf("�ַ�\tȨֵ\t����\t�Һ���\t˫��\t\n");
    for(i=0;i<2*n-1;i++)
    {
        printf("%c\t",HuffMTree[i]->data);
        printf("%d\t%d\t%d\t%d\n",HuffMTree[i]->weight,HuffMTree[i]->lchild,HuffMTree[i]->rchild,HuffMTree[i]->parent);
    }
    printf("�ַ���Ϣ--������Ϣ\n");
    for(i=0;i<n;i++)
    {
        printf("%c:",HuffMTree[i]->data);
        for(j=HuffCode[i]->start;j<n;j++)
        printf("%d",HuffCode[i]->bit[j]);
        printf("\n");
    }
    printf("���س�����");
    getchar();
    getchar();
}
