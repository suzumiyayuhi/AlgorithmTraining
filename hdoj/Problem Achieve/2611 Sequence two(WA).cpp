#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,p,len,cnt;
int res[101];

struct point
{
	int id,val;
}points[101];

bool cmp(const point &a,const point &b)
{
	if(a.val==b.val)
		return a.id<b.id;
	return a.val<b.val;
}
/*
bool dfs(int time,int pos,int re)
{
	if(time==len)
	{
		cnt++;
		for(int i=0;i!=time-1;i++)
			cout<<res[i]<<" ";
		cout<<res[time-1]<<endl;
		if(cnt==p)
			return true;
		return false;
	}
	else
	{
		bool flag=false;
		int tem;
		for(int i=pos;i<=n;i++)
		{
			if(points[i].id>re)
			{
				if(!flag)
				{
					flag=true;
					tem=points[i].val;
				}
				else if(tem==points[i].val)
					continue;
				res[time]=points[i].val;
				if(dfs(time+1,i+1,points[i].id))
					return true;
			}
		}
	}
	return false;
}*/


bool dfs(int time,int pos,int re)
{
	if(time==len)
	{
		cnt++;
		for(int i=0;i!=time-1;i++)
			cout<<res[i]<<" ";
		cout<<res[time-1]<<endl;
		if(cnt==p)
			return true;
		return false;
	}
	else
	{
		bool flag=false;
		int tem;
		for(int i=pos;i<=n;i++)
		{
			if(points[i].id>re)
			{
				if(!flag)
				{
					flag=true;
					tem=points[i].val;
				}
				else if(tem==points[i].val)
					continue;
			//	tem=A[i].n;
				res[time]=points[i].val;
				if(dfs(time+1,i+1,points[i].id))
					return true;
			}
		}
	}
	return false;
}
/*
int main()
{
	while(cin>>n>>p)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>points[i].val;
			points[i].id=i;
		}
		sort(points+1,points+1+n,cmp);
		for(len=1;len<n;len++)
		{
			if(dfs(0,0,0))
				break;
		}
		
	}
} */

int main()
{
	int i;
	while(cin>>n>>p)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&points[i].val);
			points[i].id=i;
		}
		sort(points+1,points+1+n,cmp);
		cnt=0;
		for(i=1;i<n;i++)
		{
			len=i;
			if(dfs(0,1,0))break;
		}
		printf("\n");
	}
	return 0;
}
