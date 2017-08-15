#include<cstdio>
const int MAXN=100002;
int root[MAXN];
int x,y,t,f;
bool vis[MAXN];
bool flag;

int get_root(int a)
{
	while(root[a]!=a)
		a=root[a];
	return a;
}

void merge(int a,int b)
{
	int ra=get_root(a);
	int rb=get_root(b);
	vis[a]=true;
	vis[b]=true;
	if(ra>rb)
		root[ra]=rb;
	else if(rb>ra)
		root[b]=ra;
}

int main()
{
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		
		if(x==-1&&y==-1)
			break;
		if(x==0&&y==0)
		{
			printf("Yes\n");
			continue;
		}
		for(int i=1;i!=MAXN;i++)
		{
			root[i]=i;
			vis[i]=false;
		}
		flag=true;
		merge(x,y);
		t=1;
		while(scanf("%d%d",&x,&y)!=EOF&&(x+y))
		{
			if(!vis[x])
			{
				t++;
				vis[x]=true;
			}
			if(!vis[y])
			{
				t++;
				vis[y]=true;
			}
			if(get_root(x)==get_root(y))
				flag=false;
			else
				t--;
			merge(x,y);
		}
		if(flag&&t==1)
			printf("Yes\n");
		else
			printf("No\n");
	/*
		if(flag)
			printf("No\n");
		else
		{
			int res=0;
			for(int i=1;i!=MAXN;i++)
				if(vis[i]&&root[i]==i)
					res++;
			if(res==1)
				printf("Yes\n");
			else
				printf("No\n");
		}
		*/
	}
}
