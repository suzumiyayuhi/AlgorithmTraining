#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int h,w;
char pal[81][81];
bool vis[81][81][4];

struct point
{
	int x,y,time,route;
};

bool check(int a,int b,int c)
{
	if(a>=1&&a<=h&&b>=1&&b<=w&&pal[a][b]!='#')
		if(!vis[a][b][c])
			return true;
	return false;
}

int bfs(int bx,int by)
{
	queue<point> q;
	point cur,next;
	int dir[4][2]={1,0,-1,0,0,1,0,-1};
	cur.x=bx;cur.y=by;cur.time=0;
	if(cur.x==1||cur.x==h||cur.y==1||cur.y==w)
			return cur.time;
	for(int i=0;i!=4;i++)
	{
		vis[cur.x][cur.y][i]=true;
		next.x=cur.x+dir[i][0];
		next.y=cur.y+dir[i][1];
		next.time=cur.time+1;
		next.route=i;
		if(check(next.x,next.y,i))
		{
			vis[next.x][next.y][i]=true;
			q.push(next);
		}
	}
	while(!q.empty())
	{
		bool flag=false;
		cur=q.front();
		q.pop();
		if(cur.x==1||cur.x==h||cur.y==1||cur.y==w)
			return cur.time;
		for(int i=0;i!=4;i++)
		{
			if(i!=cur.route&&(dir[i][0]+dir[cur.route][0]||dir[i][1]+dir[cur.route][1]))
				if(check(cur.x+dir[i][0],cur.y+dir[i][1],i))
					flag=true;
		}
		if(flag)
		{
			for(int i=0;i!=4;i++)
			{
				if(i!=cur.route&&(dir[i][0]+dir[cur.route][0]||dir[i][1]+dir[cur.route][1]))
				{
					next.x=cur.x+dir[i][0];
					next.y=cur.y+dir[i][1];
					next.time=cur.time+1;
					next.route=i;
					if(check(next.x,next.y,i))
						q.push(next);
				}
			}
		}
		else
		{
			next.x=cur.x+dir[cur.route][0];
			next.y=cur.y+dir[cur.route][1];
			next.time=cur.time+1;
			next.route=cur.route;
			if(check(next.x,next.y,next.route))
				q.push(next);
		}
	}
	return -1;
}

int main()
{
	int T,bx,by;
	cin>>T;
	while(T--)
	{
		memset(vis,false,sizeof(vis));
		cin>>h>>w;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				cin>>pal[i][j];
				if(pal[i][j]=='@')
				{
					bx=i;
					by=j;
				}
			}
		}
		cout<<bfs(bx,by)<<endl;
	}
} 