#include<iostream>
using namespace std;
bool map[11][11];
int res[11];
int t;
long long tem;

bool check(int x,int y,int n)
{
	if(x<1||x>n||y<1||y>n)
		return false;
	if(map[x][y])
		return false;
	for(int i=1;i!=n+1;i++)
		if(map[i][y]||map[x][i])
			return false;
	for(int i=1;i<n;i++)
	{
		if(x-i>=1&&x-i<=n&&y-i>=1&&y-i<=n)
			if(map[x-i][y-i])
				return false;
		if(x-i>=1&&x-i<=n&&y+i>=1&&y+i<=n)
			if(map[x-i][y+i])
				return false;
		if(x+i>=1&&x+i<=n&&y-i>=1&&y-i<=n)
			if(map[x+i][y-i])
				return false;
		if(x+i>=1&&x+i<=n&&y+i>=1&&y+i<=n)
			if(map[x+i][y+i])
				return false;
	}
	return true;
}

void dfs(int a,int n)
{
	if(a>n)
	{
		tem++;
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(check(i,j,n))
				{
					map[i][j]=true;
					dfs(a+1,n);
					map[i][j]=false;
				}
			}
	}
}

int f(int a)
{
	int tem1=a,ans=1;
	for(int i=1;i<=a;i++)
		ans*=(tem1--);
	return ans;
}

int main()
{
	for(int i=1;i!=11;i++)
	{
		tem=0;
		memset(map,false,sizeof(map));
		dfs(1,i);
		res[i]=tem/f(i);
	}
	while(cin>>t)
		cout<<res[t]<<endl;
}
