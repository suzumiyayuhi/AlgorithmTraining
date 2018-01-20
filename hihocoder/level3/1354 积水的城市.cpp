#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1002;
const int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool vis[MAXN][MAXN];
int pal[MAXN][MAXN];
int xlen[MAXN],ylen[MAXN];
int n,m,k,t,x1,x2,y1,y2;
int sx1=0,sx2=MAXN,sy1=0,sy2=MAXN;
int bfs(); 
struct point
{
	int x,y,length;
};

bool operator<(point a,point b)
{
	return a.length>b.length;
}

int main()
{
	int tem1,tem2;
	cin>>n>>m;
	xlen[1]=0;
	ylen[1]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>ylen[i];
		ylen[i]+=ylen[i-1];
	}
	for(int i=2;i<=m;i++)
	{
		cin>>xlen[i];
		xlen[i]+=xlen[i-1];
	}
	memset(pal,0,sizeof(pal));
	cin>>k;
	for(int i=0;i!=k;i++)
	{
		cin>>tem1>>tem2;
		pal[tem1][tem2]=1;
	}
	cin>>t;
	while(t--)
	{
		memset(vis,false,sizeof(vis));
		cin>>y1>>x1>>y2>>x2;
		cout<<bfs()<<endl;
	}
}

int bfs()
{
	priority_queue<point> q;
	point cur,pre;
	cur.x=x1;
	cur.y=y1;
	cur.length=0;
	vis[y1][x1]=true;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.top();
		q.pop();
		for(int i=0;i!=4;i++)
		{
			pre.x=cur.x+dir[i][0];
			pre.y=cur.y+dir[i][1];
			if(pre.x>0&&pre.x<=m&&pre.y>0&&pre.y<=n)
			{
				int temlen;
				if(i==0||i==1)
				{
					temlen=ylen[cur.y]-ylen[pre.y];
					if(temlen<0)
						temlen=0-temlen;
				}
				else if(i==2||i==3)
				{
					temlen=xlen[cur.x]-xlen[pre.x];
					if(temlen<0)
						temlen=0-temlen;
				}
				pre.length=cur.length+temlen;
				if(pre.x==x2&&pre.y==y2)
				{
					
					return pre.length;
				}
					
				else if(pal[pre.y][pre.x]==0&&vis[pre.y][pre.x]!=true)
				{
					q.push(pre);
					vis[pre.y][pre.x]=true;
				}	
			}
		}
	}
	return -1;
}
