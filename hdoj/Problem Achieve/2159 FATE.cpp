#include<cstdio>
#include<string.h>
int dp[101],ww[101],get[101],cost[2101];
int n,m,k,s;

int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&k,&s))
	{
		for(int i=1;i<=k;i++)
			scanf("%d%d",&get[i],&cost[i]);
		memset(dp,0,sizeof(dp));
		memset(ww,0,sizeof(ww));
		for(int i=1;i<=k;i++)
			for(int j=cost[i];j<=m;j++)
			{
				if(dp[j]<dp[j-cost[i]]+get[i])
				{
					dp[j]=dp[j-cost[i]]+get[i];
					ww[j]=ww[j-cost[i]]+1;
				}
			}
		int res=0x3f3f3f3f;
		for(int i=m;i>=0;i--)
		{
			if(dp[i]>=n&&ww[i]<=s)
				if(i<res)
					res=i;
		}
		if(m-res<0)
			printf("-1\n");
		else
			printf("%d\n",m-res);
	}
} 
