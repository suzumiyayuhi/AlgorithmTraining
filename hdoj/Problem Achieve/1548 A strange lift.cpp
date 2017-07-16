#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
bool vis[201];
int N,b,e,res,k[201];

struct point
{
	int x,time;
};

bool check(int a)
{
	if(a>=1&&a<=N)
		if(!vis[a])
			return true;
	return false;
}

bool bfs()
{
	queue<point> q;
	point cur,next;
	cur.x=b;cur.time=0;
	q.push(cur);
	vis[cur.x]=true;
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(cur.x==e)
		{
			res=cur.time;
			return true;
		}
		next.x=cur.x+k[cur.x];
		next.time=cur.time+1;
		
		if(check(next.x))
		{
			q.push(next);
			vis[next.x]=true;
		}
		next.x=cur.x-k[cur.x];
		if(check(next.x))
		{
			q.push(next);
			vis[next.x]=true;
		}
	}
	return false;
}

int main()
{
	while(cin>>N,N)
	{
		memset(vis,false,sizeof(vis));
		cin>>b>>e;
		for(int i=1;i<=N;i++)
			cin>>k[i];
		if(bfs())
			cout<<res<<endl;
		else
			cout<<-1<<endl;
	}
}
