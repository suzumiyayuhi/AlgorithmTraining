#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1001;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int pal[MAXN][MAXN];
int n,m,q,x1,y1,x2,y2,curve,cx,cy;
bool vis[MAXN][MAXN];

int sol(int x,int y)
{
	
	if(x==x2&&y==y2&&curve<=2)
		return 1;
	if(curve>2)
		return 0;
	for(int i=0;i!=4;i++)
	{
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(nx>n||ny>m||nx<=0||ny<=0)
			continue;
		if(pal[nx][ny]!=0||vis[nx][ny])
			if(nx!=x2||ny!=y2)
				continue;
		vis[nx][ny]=true;
		if(nx!=cx&&ny!=cy)
		{
			curve++;
			int temx=cx;
			int temy=cy;
			cx=x;
			cy=y;
			if(sol(nx,ny))
				return 1;
			curve--;
			cx=temx;
			cy=temy;
			vis[nx][ny]=false;
		}
		else
		{
			if(sol(nx,ny))
				return 1;
			vis[nx][ny]=false;
		}
	}
	return 0;
}

int main()
{
	while(cin>>n>>m,n+m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>pal[i][j];
		cin>>q;
		for(int i=0;i!=q;i++)
		{
			cin>>x1>>y1>>x2>>y2;
			if(pal[x1][y1]!=pal[x2][y2]||(x1==x2&&y1==y2)||(pal[x1][y1]==0&&pal[x2][y2]==0))
			{
				cout<<"NO"<<endl;
				continue;
			}
			memset(vis,false,sizeof(vis));
			vis[x1][y1]=true;
			cx=x1;cy=y1;curve=0;
			if(sol(x1,y1))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}
