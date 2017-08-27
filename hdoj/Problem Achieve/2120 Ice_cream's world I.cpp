#include<cstdio>
const int MAXN=10001;
int n,m,res;
int pre[MAXN];

int get_root(int a)
{
	while(a!=pre[a])
		a=pre[a];
	return a;
}

void merge(int a,int b)
{
	int ra=get_root(a);
	int rb=get_root(b);
	if(ra!=rb)
		pre[ra]=rb;
	else
		res++;
} 

int main()
{
	int x,y;
	while(~scanf("%d%d",&n,&m))
	{
		res=0;
		for(int i=0;i<=n;i++)
			pre[i]=i;
		for(int i=0;i!=m;i++)
		{
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		printf("%d\n",res);
	}
} 
