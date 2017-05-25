#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
double money[50],dp[50];
int main()
{
	double total,t;
	while(cin>>total>>t,t)
	{
		int len=0;
		memset(money,0,sizeof(money));
		memset(dp,0,sizeof(dp));
		for(int i=0;i!=t;i++)
		{
			int flag=1,n,m;
			double A=0,B=0,C=0,q;
			char ch;
		    cin>>n;
		    for(int j=0;j<n;j++)
		    {
				scanf(" %c:%lf",&ch,&q);
		    	if(ch!='A'&&ch!='B'&&ch!='C'||q>600)
				{
			    	flag=0;
			    	break;
			    }
		        if(ch=='A') 
					A+=q;
		        else if(ch=='B') 
					B+=q;
		        else if(ch=='C') 
					C+=q;
		    }
			if(flag && A+B+C<=1000&&A<=600&&B<=600&&C<=600)
		    	money[len++]=A+B+C;
		}
		
		for(int i=0;i<=len;i++)
		{
			for(int j=len;j>=1;j--)
			{
				if(j==1||dp[j-1]>0&&dp[j-1]+money[i]<=total)
                	dp[j]=max(dp[j],dp[j-1]+money[i]);
			}
		}
		int sum=0;
		for(int i=1;i<=len;i++)
		{
			if(dp[sum]<dp[i])
				sum=i;
		}
		printf("%.2lf\n",dp[sum]);
	}
	return 0;
}
