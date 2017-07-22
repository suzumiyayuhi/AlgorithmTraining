#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
char pal[81][81];
bool vis[81][81][81];
int n,m,t,p,bx,by;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct point
{
	int x,y,time,power;
};

bool operator<(const point &a,const point &b)
{
	return a.time>b.time;
}

bool check(int a,int b)
{
	if(a>=1&&a<=n&&b>=1&&b<=m&&pal[a][b]!='#')
		return true;
	return false;
}

int bfs()
{
	priority_queue<point> q;
	point cur,next;
	cur.x=bx;
	cur.y=by;
	cur.time=0;
	cur.power=p;
	vis[bx][by][p]=true;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.top();
		q.pop();
		if(cur.time>t)
			return 0;
		if(pal[cur.x][cur.y]=='L')
			return cur.time;
		for(int i=0;i!=4;i++)
		{
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];
			if(check(next.x,next.y))
			{
				if(cur.power>0&&!vis[next.x][next.y][cur.power-1])
				{
					vis[next.x][next.y][cur.power-1]=true;
					next.power=cur.power-1;
					next.time=cur.time+1;
					q.push(next);
				}
				if(pal[cur.x][cur.y]!='@'&&pal[next.x][next.y]!='@'&&!vis[next.x][next.y][cur.power])
				{
					vis[next.x][next.y][cur.power]=true;
					next.power=cur.power;
					next.time=cur.time+2;
					q.push(next);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int aa=0,res;
	while(cin>>n>>m>>t>>p)
	{
		memset(vis,false,sizeof(vis));
		cout<<"Case "<<++aa<<":\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>pal[i][j];
				if(pal[i][j]=='Y')
				{
					bx=i;
					by=j;
				}
			}
		}
		res=bfs();
		if(res)
			cout<<"Yes, Yifenfei will kill Lemon at "<<res<<" sec."<<endl;
		else
			cout<<"Poor Yifenfei, he has to wait another ten thousand years."<<endl;
	} 
}
