#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct u
{
	int w;
	double v;
};
double dp[100010];
int main()
{
	int m,n;
	while(cin>>m>>n,m+n)
	{
		memset(dp,0,sizeof(dp));
		u us[n];
		for(int i=0;i!=n;i++)
			cin>>us[i].w>>us[i].v;
		
		for(int i=0;i!=n;i++)
			for(int j=m;j>=us[i].w;j--)
					dp[j]=max(dp[j],dp[j-us[i].w]+us[i].v-us[i].v*dp[j-us[i].w]);
		printf("%.1f", dp[m]*100.0);
        cout <<"%"<<endl;
	}
}
