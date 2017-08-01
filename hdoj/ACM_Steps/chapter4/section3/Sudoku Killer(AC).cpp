#include<iostream>
using namespace std;

struct point
{
	int x,y;
}points[82];
int map[9][9];
int num;

bool check(int n,int time)
{
	
	for(int i=0;i!=9;i++)
		if(map[points[time].x][i]==n||map[i][points[time].y]==n)
			return false;	
	int x1=(points[time].x/3)*3;
	int y1=(points[time].y/3)*3;
	for(int i=x1;i!=x1+3;i++)
		for(int j=y1;j!=y1+3;j++)
			if(map[i][j]==n)
				return false;
	return true;
}

void dfs(int time)
{
	if(time==num)
	{
		for(int i=0;i!=9;i++)
		{
			for(int j=0;j!=8;j++)
				cout<<map[i][j]<<" ";
			cout<<map[i][8]<<endl;
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
	int aa=0;
	char s;
	while(cin>>s)
	{
		num=0;
		bool flag=true;
		if(s=='?')
		{
			points[0].x=0;
			points[0].y=0;
			map[0][0]=0;
			num++;
		}
		else
			map[0][0]=s-'0';
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=8;j++)
			{
				if(i==0&&j==0)continue;
				cin>>s;
				if(s=='?')
				{
					points[num].x=i;
					points[num].y=j;
					num++;
					map[i][j]=0;
				}
				else
					map[i][j]=s-'0';
			}
		}
		if(aa++)
			cout<<endl;	
		dfs(0);
	}
	return 0;
} 
