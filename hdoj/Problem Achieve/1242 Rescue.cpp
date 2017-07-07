#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
char palace[201][201];
bool f[201][201];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N,M,bx,by;
struct point
{
	int x,y,time;
}person;

bool operator<(const point &a,const point &b)
{
	return a.time>b.time;
}

bool check(point a)
{
	if(a.x<=N&&a.x>=1&&a.y<=M&&a.y>=1)
		if(palace[a.x][a.y]!='#')
			if(!f[a.x][a.y])
				return true;
	return false;
}

void bfs()
{
	bool flag=false;
	priority_queue<point> q;
	q.push(person);
	point cur,next;
	while(!q.empty())
	{
		cur=q.top();
		q.pop();
		if(palace[cur.x][cur.y]=='r')
		{
			flag=true;
			cout<<cur.time<<endl;
			break;
		}
		for(int i=0;i!=4;i++)
		{
			next.x=cur.x+dx[i];
			next.y=cur.y+dy[i];
			if(palace[next.x][next.y]=='x')
				next.time=cur.time+2;
			else
				next.time=cur.time+1;
			if(check(next))
			{
				q.push(next);
				f[next.x][next.y]=true;
			}
		}
	}
	if(!flag)
		cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
}

int main()
{
	while(cin>>N>>M)
	{
		memset(f,false,sizeof(f));
		for(int x=1;x<=N;x++)
			for(int y=1;y<=M;y++)
			{
				cin>>palace[x][y];
				if(palace[x][y]=='a')
				{
					person.x=x;
					person.y=y;
					person.time=0;
					f[x][y]=true;
				}
			}
		bfs();
	}
}
