#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
int res[250002];
int value[5005];
int main()
{
	int n;
	while(cin>>n,n>0)
	{
		memset(res,0,sizeof(res));
		memset(value,0,sizeof(value));
		int sum=0,l=0;
		for(int i=0;i!=n;i++)
		{
			int a,b;
			cin>>a>>b;
			while(b--)
			{
				value[l++]=a;
				sum+=a;
			}
		}
		for(int i=0;i<l;i++)
		{
			for(int j=sum/2;j>=value[i];j--)
			{
				res[j]=max(res[j],res[j-value[i]]+value[i]);
			}
		}
		cout<<sum-res[sum/2]<<" "<<res[sum/2]<<endl;
	}
}
