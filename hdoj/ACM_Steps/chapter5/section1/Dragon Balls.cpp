#include<cstdio>
const int MAXN=10001;
int pre[MAXN],count[MAXN],time[MAXN];
int n,q,t;

int get_root(int a)
{/*
	while(a!=pre[a])
		a=pre[a];
		*/
	if(a!=pre[a])
	{
		int g=pre[a];
		pre[a]=get_root(pre[a]);
		time[a]+=time[g];
	}
	return pre[a];
}

void merge(int a,int b)
{
	int ra=get_root(a);
	int rb=get_root(b);
	if(ra!=rb) 
	{
		pre[ra]=rb;
		count[rb]+=count[ra];
		time[ra]++;
	}
}

int main()
{
	scanf("%d",&t);
	int k=0;
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			pre[i]=i;
			count[i]=1;
			time[i]=0;
		}
		char a;
		int b,c;
		printf("Case %d:\n",++k);
		for(int i=0;i!=q;i++)
		{
			scanf("%s",&a);
			if(a=='T')
			{
				scanf("%d%d",&b,&c);
				merge(b,c);
			}	
			else
			{
				scanf("%d",&b);
				int t=get_root(b);
			//	cout<<get_root(b)<<" "<<count[get_root(b)]<<" "<<time[b]<<endl;
			//	cout<<t<<" "<<count[t]<<" "<<time[b]<<endl;
				printf("%d %d %d\n",t,count[t],time[b]);
			}
		}
	}
}
