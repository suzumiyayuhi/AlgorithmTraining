#include<iostream>
using namespace std;

struct point
{
	int x,y;
}points[82];
int map[10][10];
int num;

bool check(int n,int time)
{
	for(int i=1;i!=10;i++)
		if(map[points[n].x][i]==n||map[i][points[n].y]==n)
			return false;		
	int x1=(points[n].x/3)*3+1;
	int y1=(points[n].y/3)*3+1;
	for(int i=x1;i!=x1+3;i++)
		for(int j=y1;j!=y1+3;j++)
			if(map[i][j]==n)
				return false;
	return true;
}

void dfs(int time)
{
	cout<<time<<endl;
	if(time>num)
	{
		for(int i=1;i!=10;i++)
		{
			for(int j=1;j!=9;j++)
				cout<<map[i][j]<<" ";
			cout<<map[i][9]<<endl;
		}
		return;
	}
	else
	{
		for(int i=1;i!=10;i++)
			if(check(i,time))
			{
				map[points[time].x][points[time].y]=i;
				dfs(time+1);
				map[points[time].x][points[time].y]=0;
			}
	}
}

int main()
{
	char s;
	while(cin>>s)
	{
		num=0;
		bool flag=true;
		if(s=='?')
		{
			points[1].x=1;
			points[1].y=1;
			map[1][1]=0;
			num++;
		}
		else
			map[1][1]=s-'0';
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				if(flag)
				{
					flag=false;
					continue;
				}
				cin>>s;
				if(s=='?')
				{
					num++;
					points[num].x=i;
					points[num].y=j;
					map[i][j]=0;
				}
				else
					map[i][j]=s-'0';
			}
		}
		dfs(1);
	}
} 
