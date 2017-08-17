#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int pre[201];
int n,m;

struct road
{
	int a,b,time;
}roads[1001];

bool cmp(const road &a,const road &b)
{
	return a.time<b.time;
}

int get_root(int a)
{
	int t1=a,t2=a;
	while(a!=pre[a])
		a=pre[a];
	while(t1!=a)
	{
		t2=pre[t1];
		pre[t1]=a;
		t1=t2;
	}
	return a;
}

void merge(int a,int b)
{
	int ra=get_root(a);
	int rb=get_root(b);
	if(ra!=rb)
	{
		pre[ra]=rb;
	}
}

int main()
{
	while(cin>>n>>m)
	{
		int a,b,t;
		for(int i=0;i<m;i++)
			cin>>roads[i].a>>roads[i].b>>roads[i].time;
		sort(roads,roads+m,cmp);
		cin>>t;
		while(t--)
		{
			int res=0x3f3f3f;
			cin>>a>>b;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j!=201;j++)
					pre[j]=j;
				for(int j=i;j<m;j++)
				{
					merge(roads[j].a,roads[j].b);
					if(get_root(a)==get_root(b))
					{
						
						int tem=roads[j].time-roads[i].time;
							res=res<tem?res:tem;
					}
				}
			}
			if(res==0x3f3f3f)
				cout<<-1<<endl;
			else
				cout<<res<<endl;
		}
	}
}
