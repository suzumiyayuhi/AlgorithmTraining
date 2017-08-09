#include<cstdio>
int res;
int pre[1000],vis[1000];

int f(int a)
{
	int tem1=a;
	while(tem1!=pre[tem1])
		tem1=pre[tem1];
	int tem2=a;
	while(pre[tem2]!=tem1)
	{
		int tem3=pre[tem2];
		pre[tem2]=tem1;
		tem2=tem3;
	}
	return tem1;
}

void merge(int a,int b)
{
	int fx=f(a);
	int fy=f(b);
	if(fx!=fy)
		pre[fy]=fx;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF,n)
	{
		res=0;
		for(int i=1;i<=n;i++)
		{
			pre[i]=i;
			vis[i]=0;
		}
		for(int i=0;i!=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		for(int i=1;i<=n;i++)
			vis[f(i)]=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				res++;
		}
		printf("%d\n",res-1);
	}
} 
