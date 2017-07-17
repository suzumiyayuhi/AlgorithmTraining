#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
bool vis[9][9];
int dir[8][2]={1,2,1,-2,-1,2,-1,-2,
			   2,1,2,-1,-2,1,-2,-1};
int bx,by,ex,ey;
struct point
{
	int x,y,time;
};

bool check(point a)
{
	if(a.x>=1&&a.x<=8&&a.y>=1&&a.y<=8)
		if(!vis[a.x][a.y])
			return true;
	return false;
}

int bfs()
{
	queue<point> q;
	point cur,next;
	vis[bx][by]=true;
	cur.x=bx;
	cur.y=by;
	cur.time=0;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(cur.x==ex&&cur.y==ey)
			return cur.time;
		for(int i=0;i!=8;i++)
		{
			next.x=cur.x+dir[i][0];
			next.y=cur.y+dir[i][1];
			next.time=cur.time+1;
			if(check(next))
			{
				vis[next.x][next.y]=true;
				q.push(next);
			}
		}
	}
	return 0;
}

int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		bx=a[0]-'a'+1;
		by=a[1]-'0';
		ex=b[0]-'a'+1;
		ey=b[1]-'0';
		memset(vis,false,sizeof(vis));
		cout<<"To get from "<<a<<" to "<<b<<" takes "<<bfs()<<" knight moves."<<endl;
	}
}
