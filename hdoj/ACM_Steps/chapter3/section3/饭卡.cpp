#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
int dp[1002];
int main()
{
	int n;
	while(cin>>n,n)
	{
		memset(dp,0,sizeof(dp));
		int v[n+1],maxv=0,t;
		for(int i=0;i!=n;i++)
		{
			cin>>v[i];
		//	maxv=max(v[i],maxv);
			if(v[i]>maxv){maxv=v[i];t=i;}
		}
		
		int m;
		cin>>m;
		if(m<5)
		{
			cout<<m<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(t==i)continue;
			for(int j=m;j>=v[i];j--)
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
		}
		cout<<m-dp[m-5]-maxv<<endl;	
	}
}
