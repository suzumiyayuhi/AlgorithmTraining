#include<cstdio>
const int MAXN=10000005;
const int MK=1000000007;
int root[MAXN];
int n,m,count;

int get_root(int a)
{
	int t1=a,t2=a;
	while(root[a]!=a)
		a=root[a];
	while(t1!=a)
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
		root[ra]=rb;
		count++;
	}
}

long long sol(int a)
{
	long long res=1,tem=26;
	while(a)
	{
		if(a&1)
			res=(res*tem)%MK;
		tem=(tem*tem)%MK;
		a>>=1;
	}
	return res;
}

int main()
{
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		count=0;
		for(int i=1;i<=n+1;i++)
			root[i]=i;
		for(int i=0;i!=m;i++)
		{
			scanf("%d%d",&a,&b);
			merge(a,b+1);
		}
		printf("%lld\n",sol(n-count)%MK);
	}
}
