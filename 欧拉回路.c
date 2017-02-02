#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_VERTEX_NUM 100//�����������

typedef struct 
{
	int num;//�������
	//int data;//������Ϣ
}VERTEX;//����

typedef struct
{
	int n;//�������
	int e;//�ߵ�����
	VERTEX vexs[MAX_VERTEX_NUM];//һά���鴢�涥��
	int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ά���鴢���
}MGraph;//ͼ

int visited[MAX_VERTEX_NUM];//ȫ�ֱ������ڶԶ���������������������ʱ�ĸ�����������
int Euleriancycle(MGraph *mg);//�ж϶���Ķ����Ƿ�ȫΪż����������ʱ���0��ȫΪż��ʱ���1
MGraph *creat_MGraph();//��ͼת��Ϊ�ڽӾ��󴢴������������ڽӾ�����׵�ַ
int  dfs_trave(MGraph *mg);//���������������
void dfs(MGraph *mg,int i);//�����������


void main()
{
	int num,m;//num�������ն�������жϵĽ����m��������ͼ�Ƿ�Ϊ��ͨͼ�Ľ��
	MGraph *mg;
	mg=creat_MGraph();//�����ڽӾ���
	//--------------------------------------------------------------------------------------------------------------------------------------
	printf("�ߵ�����%d\n\n\n",mg->e);
	printf("��1 2  Ϊ %d\n\n\n",mg->edges[1][2]);
	printf("��1 3  Ϊ %d\n\n\n",mg->edges[1][3]);
	printf("��2 2  Ϊ %d\n\n\n",mg->edges[2][2]);
	printf("��2 3  Ϊ %d\n\n\n",mg->edges[2][3]);                     //���ԡ���֤
	printf("����ĸ���Ϊ %d\n\n\n",mg->n);
	/*printf("����1Ϊ%d\n\n\n",mg->vexs[1].data);
	printf("����2Ϊ%d\n\n\n",mg->vexs[2].data);
	printf("����3Ϊ%d\n\n\n",mg->vexs[3].data);
	printf("����4Ϊ%d\n\n\n",mg->vexs[4].data);
	printf("����5Ϊ%d\n\n\n",mg->vexs[5].data);//%cʱ������������*/
	//--------------------------------------------------------------------------------------------------------------------------------------

	num=Euleriancycle(mg);//�ж϶���Ķ����Ƿ�ȫΪż����ȫΪż��ʱnum=1������num=0
	/*m=dfs_trave(mg);//�ж�ͼ�Ƿ�Ϊ��ͨͼ
	if((num==1)&&(m==1))//���ͼ����ͨͼ�������ж���Ķ���ȫΪż��ʱ����ͼΪŷ��ͼ������ŷ����·
		printf("����ŷ����·��\n");
	else                //������ŷ��ͼ��û��ŷ����·
		printf("������ŷ����·��\n");
	printf("������%d��dfs\n\n",m);//����...*/
	if(num!=1)
	{
	printf("������ŷ��ͼ��\n");
	getchar();
	exit(0);
	}
	m=dfs_trave(mg);//�ж�ͼ�Ƿ�Ϊ��ͨͼ
	if(m!=1)
		printf("������ŷ��ͼ��\n");
	else
		printf("����ŷ��ͼ��\n");
	getch();
}

MGraph *creat_MGraph()//�����ڽӾ���
{
	int i,j,k,n,e;
	//int c;
	MGraph *mg=malloc(sizeof(MGraph));
	printf("�����붥��ĸ�����");
	scanf("%d",&n);
	printf("������ߵ�������");
	scanf("%d",&e);
	mg->n=n;
	mg->e=e;
	getchar();
	/*printf("�����붥����Ϣ��");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c);//�����i���������Ϣ
		mg->vexs[i].data=c;//ָ����������
		mg->vexs[i].num=i;//
	}*/
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			mg->edges[i][j]=0;//��ʼ���ڽӾ����ʾ�����б�
		printf("������ߵ���Ϣ:");
		for(i=1;i<=e;i++)
		{
			scanf("%d%d",&j,&k);
			mg->edges[j][k]=1;mg->edges[k][j]=1;//��Ǵ��ڵı�
		}
		return mg;//�����ڽӾ�����׵�ַ
}

int Euleriancycle(MGraph *mg)//�ж��Ƿ����ŷ����·
{
	int i,j,num;
	for(i=1;i<=mg->n;i++)//�ӵ�һ�����㿪ʼ���ж϶���Ķ���
	{
		num=0;//��ʼ��ÿ������Ķ���Ϊ0
		for(j=1;j<=mg->n;j++)
		{
			if(mg->edges[i][j]!=0)//�������i��j�ıߴ��ڶ�����1
				num=num+1;
		}
		if(num%2==1)//������ĸ�����Ķ���Ϊ������ֱ���˳�ѭ��������0
			return 0;	
	}
	//if(num%2==1)
	//	return 0;
	//else 
		return 1;//�����еĶ��㶼�ж���ɻ�û���˳�������˵�����ж��������Ϊż��������1
}

int  dfs_trave(MGraph *mg)//���������������
{
	int i,m=0;
	for(i=1;i<=mg->n;i++)//����������ȫ����ʼ��Ϊ0����������û�б����ʹ�
		visited[i]=0;
	for(i=1;i<=mg->n;i++)
		if(visited[i]==0)//��û�з��ʹ��Ķ��㣬�������������������
		{
			dfs(mg,i);//�����������
			m=m+1;//����Ƿ���ͨͼ��Ҫ����1�����ϣ�m������¼����dfs�����Ĵ���
		}
		
		return m;//���ص���dfs�����Ĵ���
}

void dfs(MGraph *mg,int i)//�����������
{
	int j;
	visited[i]=1;//���ʸö���
	for(j=1;j<=mg->n;j++)
		if((visited[j]==0)&&(mg->edges[i][j]==1))//������û�б����ʹ�������������ڱ�
			dfs(mg,j);//�Ըö��������������
}
