#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
struct point
{
	int x,y,time;
	int bx[3],by[3];
};

bool vis[9][9][9][9][9][9][9][9];
char pal[9][9];
int m,n;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
point origin;

bool check(point a)
{
	if(a.x>=1&&a.x<=m&&a.y>=1&&a.y<=n&&pal[a.x][a.y]!='#')
		return true;
	return false;
}

int bfs()
{
	queue<point> q;
	memset(vis,false,sizeof(vis));
	point cur,next;
	cur=origin;
	q.push(cur);
	vis[cur.x][cur.y][cur.bx[0]][cur.by[0]][cur.bx[1]][cur.by[1]][cur.bx[2]][cur.by[2]]=true;
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(pal[cur.bx[0]][cur.by[0]]=='@'&&pal[cur.bx[1]][cur.by[1]]=='@'&&pal[cur.bx[2]][cur.by[2]]=='@')
			return cur.time;
		for(int i=0;i!=4;i++)
		{
			next=cur;
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];
			next.time++;
			if(check(next))
			{
				int flag=1;
				for(int j=0;j!=3;j++)
				{
					if(next.x==next.bx[j]&&next.y==next.by[j])
					{
						next.bx[j]+=dir[i][0];
						next.by[j]+=dir[i][1];
						for(int k=0;k!=3;k++)
						{
							if(next.bx[j]==cur.bx[k]&&next.by[j]==cur.by[k])
								flag=0;
						}
						if(next.bx[j]<1||next.by[j]<1||next.bx[j]>m||next.by[j]>n)
							flag=0;
						break;
					}
				}
				if(flag)
					if(!vis[next.x][next.y][next.bx[0]][next.by[0]][next.bx[1]][next.by[1]][next.bx[2]][next.by[2]])
					{
						vis[next.x][next.y][next.bx[0]][next.by[0]][next.bx[1]][next.by[1]][next.bx[2]][next.by[2]]=true;
						q.push(next);
					}
			}
		}
	}
	return -1;
}

int main()
{
	int k;
	while(cin>>m>>n)
	{
		k=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				cin>>pal[i][j];
				if(pal[i][j]=='X')
				{
					origin.x=i;origin.y=j;origin.time=0;
				}
				if(pal[i][j]=='*')
				{
					origin.bx[k]=i;origin.by[k]=j;
					k++;
					
				}
			}
		cout<<bfs()<<endl;
	}
}
