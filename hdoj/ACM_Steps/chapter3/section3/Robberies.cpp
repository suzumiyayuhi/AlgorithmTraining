#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
double dp[10001];
struct bank
{
	int m;
	double p;
};
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		double P;
		int N;
		cin>>P>>N;
		bank banks[N];
		int sum=0;
		for(int i=0;i!=N;i++)
		{
			cin>>banks[i].m>>banks[i].p;
			sum+=banks[i].m;
		}
		dp[0]=1;
		for(int i=0;i!=N;i++)
			for(int v=sum;v>=banks[i].m;v--)
				dp[v]=max(dp[v],dp[v-banks[i].m]*(1.0-banks[i].p));
		
		for(int i=sum;i!=-1;i--)
		{
			if(dp[i]>1-P)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
} 
