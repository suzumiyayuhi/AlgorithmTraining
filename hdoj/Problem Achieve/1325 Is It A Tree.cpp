#include<cstdio>
int pre[10000],lev[10000];
bool flag;

int get_parent(int a)
{
	int tem=a;
	while(pre[tem]!=tem)
		tem=pre[tem];
	return tem;
}

void merge(int a,int b)
{
	int na=get_parent(a);
	int nb=get_parent(b);
	lev[na]=1;
	lev[nb]=1;
	if(na==nb||nb!=b)
		flag=true;
	else
		pre[b]=a;
}

int main()
{
	int z=0,m,n;
	while(scanf("%d%d",&m,&n)!=EOF&&m>=0&&n>=0)
	{
		if(m==0&&n==0)
		{
			printf("Case %d is a tree.\n",++z);
			continue;
		}
		for(int i=1;i!=10000;i++)
		{
			pre[i]=i;
			lev[i]=0;
		}
		flag=false;
		merge(m,n);
		while(scanf("%d%d",&m,&n)&&(m+n))
			merge(m,n);
		if(flag)
			printf("Case %d is not a tree.\n",++z);
		else
		{
			int res=0;
			for(int i=1;i!=10000;i++)
				if(pre[i]==i&&lev[i])
					res++;
			if(res==1)
				printf("Case %d is a tree.\n",++z);
			else
				printf("Case %d is not a tree.\n",++z);
		}
	}
}
