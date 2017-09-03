#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct point
{
	int pos,num,steps;
};
const int MAXN=201;
int ins[MAXN],vis[MAXN][MAXN];
int T,N,A,B,K,res;

void bfs()
{
	queue<point> q;
	point cur,next;
	cur.pos=0;
	cur.num=ins[0];
	cur.steps=0;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
	//	if(cur.steps==K)
		if(cur.steps==K||cur.pos>=N)
		{
			res=res>cur.num?res:cur.num;
			continue;
		}
		for(int i=A;i<=B;i++)
		{
			next=cur;
			next.pos+=i;
			next.num+=ins[next.pos];
			next.steps++;
			if(vis[next.pos][next.steps]<next.num)
			{
				q.push(next);
				vis[next.pos][next.steps]=next.num;
			}
		}
	}
}

int main()
{
	cin>>T;
	memset(vis,0,sizeof(vis));
	memset(ins,0,sizeof(ins));
	while(T--)
	{
		cin>>N>>A>>B>>K;
		for(int i=0;i!=N;i++)
			cin>>ins[i];
		res=0;
		bfs();
		cout<<res<<endl;
	}
}
