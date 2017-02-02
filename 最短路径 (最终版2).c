#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAX_VERTEX_NUM 100
#define max 65536

typedef struct 
{
	int distance;
	int cost;
}EDG;

typedef struct 
{
	int n;
	int e;
	int vexs[MAX_VERTEX_NUM];
	EDG edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MGraph;

void shortpat_FLOYED(MGraph *mg);
MGraph *creat_MGraph();//�����ڽӾ���

void main()
{
	int m,n;
	MGraph *mg;
	mg=creat_MGraph();//�����ڽӾ���
	printf("������Ҫ��������������ţ�");
	scanf("%d%d",&m,&n);
	shortpat_FLOYED(mg);
	printf("����%d�붥��%d�����·���ľ��룺%d����Ϊ��%d\n",m,n,mg->edges[m][n].distance,mg->edges[m][n].cost);
	printf("�������\n");
}

void shortpat_FLOYED(MGraph *mg)
{
	int i,j,k;
	for(k=1;k<=mg->n;k++)
		for(i=1;i<=mg->n;i++)
			for(j=1;j<=mg->n;j++)
			{
				if(mg->edges[i][k].distance+mg->edges[k][j].distance<mg->edges[i][j].distance)
				{
					mg->edges[i][j].distance=mg->edges[i][k].distance+mg->edges[k][j].distance;
					mg->edges[i][j].cost=mg->edges[i][k].cost+mg->edges[k][j].cost;
				}
				else if(mg->edges[i][k].distance+mg->edges[k][j].distance==mg->edges[i][j].distance)
				{
					if(mg->edges[i][k].cost+mg->edges[k][j].cost<mg->edges[i][j].cost)
						
						mg->edges[i][j].cost=mg->edges[i][k].cost+mg->edges[k][j].cost;
					
				}
				else 
					;//�����
			}
}

MGraph *creat_MGraph()//�����ڽӾ���
{
	int i,j,k,n,e,d,c;
	MGraph *mg=malloc(sizeof(MGraph));
	printf("�����붥��ĸ�����");
	scanf("%d",&n);
	printf("������ߵ�������");
	scanf("%d",&e);
	mg->n=n;
	mg->e=e;
	getchar();
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			mg->edges[i][j].distance=max;//��ʼ���ڽӾ����ʾ�����б�
			mg->edges[i][j].cost=max;
		}
		printf("������ߵ���Ϣ:\n");
		for(i=1;i<=e;i++)
		{
			scanf("%d%d%d%d",&j,&k,&d,&c);
			mg->edges[j][k].distance=d;
			mg->edges[j][k].cost=c;
			mg->edges[k][j].distance=d;
			mg->edges[k][j].cost=c;//��Ǵ��ڵı�
		}
		return mg;//�����ڽӾ�����׵�ַ
}
