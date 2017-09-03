#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int MAXN=10001;
const int MAXM=20001;

struct edge
{
	int a,b,len,next;
}edges[MAXM];

int dis[MAXN],d1[MAXN],d2[MAXN],head[MAXN];
int n,edgenum;
bool vis[MAXN];

int bfs(int s)
{
	queue<int> q;
	memset(vis,false,sizeof(vis));
	memset(dis,0,sizeof(dis));
	vis[s]=true;
	q.push(s);
	int node=s,res=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=edges[i].next)
		{
			edge e=edges[i];
			if(!vis[e.b]&&dis[e.b]<dis[u]+e.len)
			{
				vis[e.b]=true;
				dis[e.b]=dis[u]+e.len;
				if(dis[e.b]>res)
				{
					res=dis[e.b];
					node=e.b;
				}
				q.push(e.b);
			}
		}
	}
	return node;
}

void join(int a,int b,int c)
{
	edges[edgenum].a=a;
	edges[edgenum].b=b;
	edges[edgenum].len=c;
	edges[edgenum].next=head[a];
	head[a]=edgenum++;
}

int main()
{
	while(~scanf("%d",&n))
	{
		edgenum=0;
		memset(head,-1,sizeof(head));
		for(int i=2;i<=n;i++)
		{
			int b,l;
			scanf("%d%d",&b,&l);
			join(i,b,l);
			join(b,i,l);
		}
		int S=bfs(1);
		int T=bfs(S);
		for(int i=1;i<=n;i++)
			d1[i]=dis[i];
		bfs(T);
		for(int i=1;i<=n;i++)
		{
			d2[i]=dis[i];
			int ans=d1[i]>d2[i]?d1[i]:d2[i];
			printf("%d\n",ans);
		}
	}
}
