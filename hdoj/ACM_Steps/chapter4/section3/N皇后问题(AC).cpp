#include<iostream>
using namespace std;
int res[11],map[11];
int t,tem;

int dfs(int a,int n)
{
	bool flag;
	if(a>n)
		return ++tem;
	else
	{
		for(int i=1;i<=n;i++)
		{
			map[a]=i;
			flag=true;
			for(int j=1;j<a;j++)
			{
				if(map[j]==i||i-a==map[j]-j||i+a==map[j]+j)
				{
					flag=false;
					break;
				}
			}
			if(flag)
				dfs(a+1,n);
		}
	}
}

int main()
{
	for(int i=1;i!=11;i++)
	{
		tem=0;
		dfs(1,i);
		res[i]=tem;
	}
	while(cin>>t,t)
		cout<<res[t]<<endl;
}
