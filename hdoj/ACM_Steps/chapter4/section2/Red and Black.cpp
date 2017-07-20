#include<iostream>
#include<string.h>
using namespace std;
int res,M,N;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
char pal[21][21];
bool vis[21][21];

bool check(int a,int b)
{
	if(a>=1&&a<=N&&b>=1&&b<=M&&pal[a][b]!='#')
		if(!vis[a][b])
			return true;
	return false;
}

int dfs(int bx,int by)
{
	int nx,ny;
	for(int i=0;i!=4;i++)
	{
		nx=bx+dir[i][0];
		ny=by+dir[i][1];
		if(check(nx,ny))
		{
			res++;
			vis[nx][ny]=true;
			dfs(nx,ny);
		}
	}
}

int main()
{
	while(cin>>M>>N,M+N)
	{
		int bx,by;
		memset(vis,false,sizeof(vis));
		res=1;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				cin>>pal[i][j];
				if(pal[i][j]=='@')
				{
					bx=i;
					by=j;
				}
			}
		}
		vis[bx][by]=true;
		dfs(bx,by);
		cout<<res<<endl;
	}
} 
