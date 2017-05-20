#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
int dp[11][10001];

struct shoe
{
	int lp,v;
}shoes[11][10001];

int main()
{
	int N,M,K,num[11];
	while(cin>>N>>M>>K)
	{
		memset(num,0,sizeof(num));
		memset(dp,-1,sizeof(dp));
		int a,b,c;
		for(int i=0;i!=N;i++)
		{
			cin>>a>>b>>c;
			shoes[a][num[a]].lp=b;
			shoes[a][num[a]].v=c;
			num[a]++;
		}
		for(int i=0;i<=M;i++)
			dp[0][i]=0;
		for(int k=1;k<=K;k++)
		{
			for(int i=0;i!=num[k];i++)
			{
				for(int j=M;j>=shoes[k][i].lp;j--)
				{
					if(dp[k][j-shoes[k][i].lp]!=-1)
						dp[k][j]=max(dp[k][j],dp[k][j-shoes[k][i].lp]+shoes[k][i].v);
					if(dp[k-1][j-shoes[k][i].lp]!=-1)
						dp[k][j]=max(dp[k][j],dp[k-1][j-shoes[k][i].lp]+shoes[k][i].v);
				}
			}
		}
		if(dp[K][M]<0)
			cout<<"Impossible"<<endl;
		else
			cout<<dp[K][M]<<endl;
	}
} 
