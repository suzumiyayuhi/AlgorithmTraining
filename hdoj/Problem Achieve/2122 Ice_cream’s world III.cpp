#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10001;
int pre[MAXN];
int n,m;

struct road
{
	int from,to,cost;
}roads[MAXN];

bool cmp(const road &a,const road &b)
{
	return a.cost<b.cost;
}

int get_root(int a)
{
	while(a!=pre[a])
		a=pre[a];
	return a;
}

bool merge(int a,int b)
{
	int ra=get_root(a);
	int rb=get_root(b);
	if(ra!=rb)
	{
		pre[ra]=rb;
		return true;
	}
	return false;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int a,b,c,sum=0,num=1;
		for(int i=0;i<=n;i++)
			pre[i]=i;
		for(int i=0;i!=m;i++)
			scanf("%d%d%d",&roads[i].from,&roads[i].to,&roads[i].cost);
		sort(roads,roads+m,cmp);
		for(int i=0;i!=m;i++)
		{
			if(merge(roads[i].from,roads[i].to))
			{
				num++;
				sum+=roads[i].cost;
			}
		}
		if(num!=n)
			printf("impossible\n\n");
		else
			printf("%d\n\n",sum);
	}
}
