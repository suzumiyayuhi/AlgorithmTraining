#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=101;
int T,N,A,B,K,res,tem,steps;
int ins[MAXN],vis[MAXN][MAXN];

void dfs(int start)
{
	if(steps==K)
	{
//		tem+=ins[start];
		res=res>tem?res:tem;
//		tem-=ins[start];
		return;
	}
	for(int i=A;i<=B;i++)
	{
		if(start+i<N)
		{
			tem+=ins[start+i];
			steps++;
			if(tem>vis[start+i][steps])
			{
				vis[start+i][steps]=tem;
				dfs(start+i);
			}
			steps--;
			tem-=ins[start+i];
		}
	}
}

int main()
{
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		cin>>N>>A>>B>>K;
		for(int i=0;i!=N;i++)
			cin>>ins[i];
		res=0;
		tem=ins[0];
		steps=0;
		dfs(0);
		cout<<res<<endl;
	}
}
