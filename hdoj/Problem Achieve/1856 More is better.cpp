#include<cstdio>
const int MAXN=10000001;
int root[MAXN],count[MAXN];
int t,a,b,res;

int get_root(int a)
{
	int t1=a,t2=a;
	while(root[a]!=a)
		a=root[a];
	while(t1!=a)//¼ôÖ¦ 
	{
		t2=root[t1];
		root[t1]=a;
		t1=t2;
	}
	return a;
}

void merge(int a,int b)
{
	int ra=get_root(a);
	int rb=get_root(b);
	if(ra!=rb)
	{
		count[rb]+=count[ra];
		res=count[rb]>res?count[rb]:res;
		root[ra]=rb;
	}
}

int main()
{
	while(scanf("%d",&t)!=EOF)
	{
		res=1;
		for(int i=0;i!=MAXN;i++)
		{
			root[i]=i;
			count[i]=1;
		}
		for(int i=0;i!=t;i++)
		{
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		printf("%d\n",res);
	}
} 
