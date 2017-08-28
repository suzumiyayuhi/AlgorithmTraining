#include<cstdio>
#include<string.h>
#define INF 0x3f3f3f3f
struct edge
{
	int from,to,cost;
};

const int MAXM=20005;
const int MAXN=1005;
int N,M,sum,res,start;
int pre[MAXN],in[MAXN],id[MAXN],vis[MAXN];//id记录节点所在环ID 
edge edges[MAXM];

void zhuliu(int root,int n,int a)
{
	while(1)
	{
		for(int i=0;i<n;i++)
			in[i]=INF;
		for(int i=0;i<a;i++)
		{
			edge e=edges[i];
			if(e.from!=e.to&&e.cost<in[e.to])
			{
				pre[e.to]=e.from;
				if(e.from==root)
					start=i;
				in[e.to]=e.cost;
			}
		}
		for(int i=0;i<n;i++)
			if(i!=root&&in[i]==INF)
				res=-1;
			
		int tn=0;
		memset(id,-1,sizeof(id));
		memset(vis,-1,sizeof(vis));
		in[root]=0;
		for(int i=0;i<n;i++)
		{
			res+=in[i];
			int tem1=i;
			while(vis[tem1]!=i&&id[tem1]==-1&&tem1!=root)
			{
				vis[tem1]=i;
				tem1=pre[tem1];
			}
			if(tem1!=root&&id[tem1]==-1)
			{
				int tem2=pre[tem1];
				while(tem2!=tem1)
				{
					id[tem2]=tn;
					tem2=pre[tem2];
				}
				id[tem1]=tn++;
			}
		}
		if(tn==0)
			break;
		for(int i=0;i<n;i++)
			if(id[i]==-1)
				id[i]=tn++;
		//对有向环缩点
		for(int i=0;i<a;i++)
		{
			int tem3=edges[i].to;
			edges[i].from=id[edges[i].from];
			edges[i].to=id[edges[i].to];
			if(edges[i].from!=edges[i].to)
				edges[i].cost-=in[tem3];
		}
		n=tn;
		root=id[root];
	}
}

int main()
{
	while(~scanf("%d%d",&N,&M))
	{
		sum=0;
		res=0;
		for(int i=0;i!=M;i++)
		{
			scanf("%d%d%d",&edges[i].from,&edges[i].to,&edges[i].cost);
			sum+=edges[i].cost;
			if(edges[i].from==edges[i].to)
				edges[i].cost=INF;
		}
		sum++;
		for(int i=M;i<M+N;i++)
		{
			edges[i].from=N;//
			edges[i].to=i-M;
			edges[i].cost=sum;
		}
		zhuliu(N,N+1,N+M);
		if(res==-1||res>=2*sum)
			printf("impossible\n");
		else
			printf("%d %d\n",res-sum,start-M);
		printf("\n");
	}
} 
