#include<iostream>
#include<string.h>
using namespace std;
int n,m;
int s[21];
bool pri[44],vis[21];

void fun()
{
	pri[2]=pri[3]=pri[5]=pri[7]=pri[11]=pri[13]=pri[17]=pri[19]=true;
	pri[23]=pri[29]=pri[31]=pri[37]=pri[41]=true;
}

void dfs(int o)
{
	if(o==n)
	{
		if(!pri[s[o-1]+s[0]])
			return;
		cout<<s[0];
		for(int i=1;i!=n;i++)
			cout<<" "<<s[i];
		cout<<endl;
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i])
			{
				if(pri[s[o-1]+i])
				{
					s[o]=i;
					vis[i]=1;
					dfs(o+1);
				}
				vis[i]=false;
			}
		}
	}
}

int main()
{
	fun();
	m=0;
	while(cin>>n)
	{
		cout<<"Case "<<++m<<":"<<endl;
		memset(vis,false,sizeof(vis));
		s[0]=1;
		dfs(1);
		cout<<endl;
	}
	
} 
