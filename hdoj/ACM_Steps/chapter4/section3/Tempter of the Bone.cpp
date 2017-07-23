#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int m,n,t,ex,ey;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
char pal[8][8];
bool flag;

bool check(int a,int b)
{
	if(a>=1&&a<=m&&b>=1&&b<=n&&pal[a][b]!='X')
		return true;
	return false; 
}

void dfs(int bx,int by,int cnt)
{
	if(flag||cnt>t)
		return;
	if(check(bx,by))
	{	
	//	if(cnt==t&&pal[bx][by]=='D') ³¬Ê±µã 
		if(cnt==t&&ex==bx&&ey==by)
		{
			flag=true;
			return;
		}
		for(int i=0;i!=4;i++)
		{
			pal[bx][by]='X';
			int nx=bx+dir[i][0];
			int ny=by+dir[i][1];
			dfs(nx,ny,cnt+1);
			pal[bx][by]='.';
		}
	}
}

int main()
{
	int bx,by;
	while(cin>>m>>n>>t,m+n+t)
	{
		flag=false;
		int cnt=0,wall=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>pal[i][j];
				if(pal[i][j]=='S')
				{
					bx=i;
					by=j;
				}
				else if(pal[i][j]=='D')
				{
					ex=i;
					ey=j;
				}
				else if(pal[i][j]=='X')
					wall++;
			}
		}
		
		if((t-((int)abs(ex-bx)+(int)abs(ey-by)))&1||n*m-wall<=t)
			cout<<"NO"<<endl;
		else
		{
			dfs(bx,by,cnt);
			if(flag)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}
