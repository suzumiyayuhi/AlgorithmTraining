#include<cstdio>
int s[2001],vis[2001];
bool flag;

int f(int x)
{
	int tem=x;
	while(tem!=s[tem])
		tem=s[tem];
	return tem;
}

void sol(int a,int b)
{
	int x=f(a);
	int y=f(b);
	if(x==y||flag)
		flag=true;
	else
	{
		if(vis[x])
			s[vis[x]]=y;
		if(vis[y])
			s[vis[y]]=x;
		vis[x]=y;
		vis[y]=x;
	}
}
 
int main()
{
	int t,m,n,a,b,zz=0;
	scanf("%d",&t);
	while(t--)
	{
		flag=false;
		scanf("%d%d",&m,&n);
		for(int i=1;i<=m;i++)
		{
			s[i]=i;
			vis[i]=0;
		}
		while(n--)
		{
			scanf("%d%d",&a,&b);
			sol(a,b);
		}
		printf("Scenario #%d:\n",++zz);
		if(flag)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
	return 0;
}
