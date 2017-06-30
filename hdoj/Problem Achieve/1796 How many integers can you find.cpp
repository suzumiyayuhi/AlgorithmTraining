#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
int s[11],n,m,res,sz;
int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	if(b!=0)
		gcd(b,a%b);
	else
		return a;
}

int dfs(int a,int b,int c)
{
	b=s[a]/gcd(s[a],b)*b;
	if(c&1)
		res+=(n-1)/b;
	else
		res-=(n-1)/b;
	for(int i=a+1;i<=sz;i++)
		dfs(i,b,c+1);
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		res=0;
		sz=0;
		memset(s,0,sizeof(s));
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&s[++sz]);
			if(s[sz]==0)
				--sz;
		}
		for(int i=1;i<=sz;i++)
			dfs(i,s[i],1);
		printf("%d\n",res);
	}
}
