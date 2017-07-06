#include<iostream>
#include<queue>
#include<string.h>
#include<cstdio>
using namespace std;
char palace[11][11][3];
bool flag[11][11][3];
int N,M,T,ex,ey,ez;

struct point
{
	int x,y,z,time;
}person;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool check(point a)
{
	if(a.x>=1&&a.x<=N&&a.y>=1&&a.y<=M)
		if(palace[a.x][a.y][a.z]!='*')
			if(!flag[a.x][a.y][a.z])
				return true;
	return false;
}

bool bfs()
{
	queue<point> q;
	q.push(person);
	point cur,next;
	while(!q.empty())
	{
		cur=q.front();
		flag[cur.x][cur.y][cur.z]=true;
		q.pop();
		if(cur.x==ex&&cur.y==ey&&cur.z==ez&&cur.time<=T)
			return true;
		if(cur.time>T)
			return false;
		if(palace[cur.x][cur.y][cur.z]=='#')
		{
			next=cur;
			if(next.z==1)
				next.z=2;
			else
				next.z=1;
			if(check(next))
				q.push(next);
		}
		else
		{
			for(int i=0;i!=4;i++)
			{	
				next.x=cur.x+dx[i];
				next.y=cur.y+dy[i];
				next.z=cur.z;
				next.time=cur.time+1;
				if(check(next))
					q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	int cc;
	cin>>cc;
	while(cc--)
	{
		cin>>N>>M>>T;
		memset(flag,false,sizeof(flag));
		for(int z=1;z!=3;z++)
		{
			for(int x=1;x<=N;x++)
			{
				for(int y=1;y<=M;y++)
				{
					cin>>palace[x][y][z];
					if(palace[x][y][z]=='S')
					{
						person.x=x;
						person.y=y;
						person.z=z;
						person.time=0;
						flag[x][y][z]=true;
					}
					else if(palace[x][y][z]=='P')
					{
						ex=x;
						ey=y;
						ez=z;
					}
				}
			}
		}
		for(int j=1;j<=N;j++)
		{
			for(int k=1;k<=M;k++)
			{
				if(palace[j][k][1]=='#'&&palace[j][k][2]=='#')
				{
					palace[j][k][1]='*';
					palace[j][k][2]='*';
				}
				else if(palace[j][k][1]=='#'&&palace[j][k][2]=='*')
				{
					palace[j][k][1]='*';
				}
				else if(palace[j][k][2]=='#'&&palace[j][k][1]=='*')
				{
					palace[j][k][2]='*';
				}
			}
		}
		if(bfs())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
