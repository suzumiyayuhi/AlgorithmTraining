//����һ�����У�Ҫ���ҳ����ĵ��������У����ճ��ȴ�С��������Ԫ�ذ��ֵ���
//Ȼ������ǰm��������
/*
	�������һ��һ��������������Ѱ�Ҹò�������������Ԫ��ʱ��
	Ҫ�ж�֮ǰ�Ƿ���ֹ�����ָ֮ǰ�Ҹò�ʱ�Ƿ���ֹ���ȵ�Ԫ�أ�
	���֮ǰ���ֹ���continue�Ϳ����ˡ�
	û�еĻ���������ǰλ�õ�ֵ
	����2 3 3 4
	������һ���ҵ�2�ˣ���һ�����ҵ�3����Ϊ3û���ֹ�����pre=3��
	Ȼ��ѭ�����������ҵ��ò������������һ��3(3>=2)����Ϊ֮ǰ�Ѿ����ֹ�һ��3�ˣ�����continue�Ϳ����ˡ�
	Ȼ��������ҵ������һ��4(4>=2)��4֮ǰû���ֹ�������pre=4;
*/
#include"stdio.h"
#include"string.h"
#include"algorithm"
using namespace std;
#define N 101

int a[N];
int n,m;
struct node 
{
	int n,pos;
}A[N];
int f;
int cnt;
int len;
int path[N];
bool cmp(node a,node b)
{
	if(a.n!=b.n)
	return a.n<b.n;
	return a.pos<b.pos;
}

void print(int len)
{
	int i;
	for(i=0;i<len-1;i++)
		printf("%d ",path[i]);
	printf("%d\n",path[i]);

}
//depΪ���,posΪ������λ�ã�repos��ʾ�ظ���λ��
int dfs(int dep,int pos,int repos)
{
	if(dep==len)
	{
		cnt++;
		print(len);
		if(cnt==m)return 1;
		return 0;
	}
	int pre;
	int f=0;
	for(int i=pos;i<=n;i++)
	{
		//�Ӵ����±�Ҳ�ǵ�����
		if(A[i].pos>repos)
		{
			if(f==0){f=1;pre=A[i].n;}//����
			//�����ȵĻ���˵�����صģ�continue
			else if(pre==A[i].n)continue;//����
			pre=A[i].n;//�������ȵĻ�������ǰλ�õ�ֵ
			path[dep]=A[i].n;
			if(dfs(dep+1,i+1,A[i].pos))return 1;
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&A[i].n);
			A[i].pos=i;
		}
		sort(A+1,A+1+n,cmp);
		cnt=0;
		for(i=1;i<n;i++)
		{
			len=i;
			if(dfs(0,1,0))break;
		}
		printf("\n");
	}
	return 0;
}
