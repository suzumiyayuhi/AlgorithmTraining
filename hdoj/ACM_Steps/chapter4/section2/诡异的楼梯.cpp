#include<iostream>
#include<queue>
#include<cstdio>
#include<string.h>
using namespace std;
const int maxn=21;
char maze[maxn][maxn];
int m,n,si,sj,ti,tj;
bool visited[maxn][maxn];
int dir[][2] = {{0,-1},{1,0},{0,1},{-1,0}};
struct point
{
	int x,y,t;	
};

bool check(int a,int b)
{
	if(a>=1&&a<=m&&b>=1&&b<=n&&maze[a][b]!='*'&&visited[a][b]==false)
		return true;
	return false;
}

bool canThrough(int i,int j,int dir,int step)
{
	int tem;
	if(maze[i][j]=='|')
		tem=1;
	else
		tem=0;
	if(step%2)
		tem++;
	if((tem+dir)%2==0)
		return true;
	return false;
}

void BFS()
{
	queue<point> Q;
	point p1,p2;
	p1.x=si,p1.y=sj,p1.t=0;
	Q.push(p1);
	memset(visited,false,sizeof(visited));
	visited[si][sj]=true;
	while(!Q.empty())
	{
		p1=Q.front();
		Q.pop();
		if(p1.x==ti&&p1.y==tj)
		{
			cout<<p1.t<<endl;
			return;
		}
		for(int i=0;i<4;i++)
		{
			p2.x = p1.x+dir[i][0],p2.y=p1.y+dir[i][1],p2.t=p1.t+1;
			if(check(p2.x,p2.y))
			{
				if(maze[p2.x][p2.y]=='.'||maze[p2.x][p2.y]=='T')
					Q.push(p2),visited[p2.x][p2.y]=true;
				else
				{
					if(canThrough(p2.x,p2.y,i,p1.t))
					{
						p2.x+=dir[i][0],p2.y+=dir[i][1];
						if(check(p2.x,p2.y))
							Q.push(p2),visited[p2.x][p2.y]=true;
					}
					else
					{
						p2.x+=dir[i][0],p2.y+=dir[i][1];
						if(check(p2.x,p2.y))
							p1.t++,Q.push(p1);
					}
				}
			}
		}
	}
}

int main()
{
	while(cin>>m>>n)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				cin>>maze[i][j];
				if(maze[i][j]=='S')
					si=i,sj=j;
				if(maze[i][j]=='T')
					ti=i,tj=j;
			}
		BFS();
	}
}
