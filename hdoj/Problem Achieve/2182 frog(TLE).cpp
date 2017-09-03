#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=101;
int T,N,A,B,K,res,tem,steps;
int ins[MAXN];

void dfs(int start)
{
	if(steps==K)
	{
		tem+=ins[start];
		res=res>tem?res:tem;
		tem-=ins[start];
		return;
	}
	for(int i=A;i<=B;i++)
	{
		if(start+i<N)
		{
			tem+=ins[start];
			steps++;
			dfs(start+i);
			steps--;
			tem-=ins[start];
		}
	}
}

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>A>>B>>K;
		for(int i=0;i!=N;i++)
			cin>>ins[i];
		res=0;
		steps=0;
		dfs(0);
		cout<<res<<endl;
	}
}
