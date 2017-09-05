#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=3001;
const int INF=0x3f3f3f3f;
struct point
{
	int x,y,spd;
}mans[MAXN],umb[MAXN];
int T,CT,N,M,TIME,dis;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN];
int dx[MAXN],dy[MAXN];
bool vis[MAXN];

double get_dis(const point &a,const point &b)
{
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*x+y*y);
}

bool searchPath()
{
	queue<int> q;
	dis=INF;
	memset(dx,-1,sizeof(dx));
	memset(dy,-1,sizeof(dy));
	for(int i=0;i<N;i++)
	{
		if(Mx[i]==-1)
		{
			q.push(i);
			dx[i]=0;
		}
	}
	while(!q.empty())
	{
		int tem=q.front();
		q.pop();
		if(dx[tem]>dis)
			break;
		for(int i=0;i<M;i++)
		{
			if(g[tem][i]&&dy[i]==-1)
			{
				dy[i]=dx[tem]+1;
				if(My[i]==-1)
					dis=dy[i];
				else
				{
					dx[My[i]]=dy[i]+1;
					q.push(My[i]);
				}
			}
		}
	}
	return dis!=INF;
}

bool dfs(int a)
{
	for(int i=0;i<M;i++)
	{
		if(!vis[i]&&g[a][i]&&dy[i]==dx[a]+1)
		{
			vis[i]=true;
			if(My[i]!=-1&&dy[i]==dis)
				continue;
			if(My[i]==-1||dfs(My[i]))
			{
				My[i]=a;
				Mx[a]=i;
				return true;
			}
		}
	}
	return false;
}

int maxmatch()
{
	int res=0;
	memset(Mx,-1,sizeof(Mx));
	memset(My,-1,sizeof(My));
	while(searchPath())
	{
		memset(vis,false,sizeof(vis));
		for(int i=0;i<N;i++)
			if(Mx[i]==-1&&dfs(i))
				res++;
	}
	return res;
}


int main()
{
	cin>>T;
	CT=0;
	while(T--)
	{
		cin>>TIME>>N;
		for(int i=0;i!=N;i++)
			cin>>mans[i].x>>mans[i].y>>mans[i].spd;
		cin>>M;
		for(int i=0;i!=M;i++)
			cin>>umb[i].x>>umb[i].y;
		memset(g,0,sizeof(g));
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(get_dis(mans[i],umb[j])/mans[i].spd-TIME<1e-6)
					g[i][j]=1;
		cout<<"Scenario #"<<++CT<<":"<<endl;
		cout<<maxmatch()<<endl<<endl;
	}
} 
