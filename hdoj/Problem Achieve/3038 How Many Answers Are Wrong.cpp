#include<cstdio>
const int MAXN=200001;
int pre[MAXN],dis[MAXN];
int N,M,A,B,X,res;

int get_root(int a)
{
	if(a!=pre[a])
	{
		int t=pre[a];
		pre[a]=get_root(pre[a]);
		dis[a]+=dis[t];
	}
	return pre[a];
}

void merge(int a,int b,int x)
{
	int ra=get_root(a);
	int rb=get_root(b);
	pre[rb]=ra;
	dis[rb]=dis[a]-dis[b]+x;
}

int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		res=0;
		for(int i=0;i<=N;i++)
		{
			pre[i]=i;
			dis[i]=0;
		}
		for(int i=0;i!=M;i++)
		{
			scanf("%d%d%d",&A,&B,&X);
			A--; 
			if(get_root(A)!=get_root(B))
				merge(A,B,X);
			else if(dis[A]+X!=dis[B])
				res++;
		}
		printf("%d\n",res);
	}
}
