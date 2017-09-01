#include<cstring>
#include<cstdio>
const int MAXN=1000001;
int n,res,dif,tem;
char str[MAXN];
int count[256];
int main()
{
	while(scanf("%d",&n),n)
	{
		getchar();
		gets(str);
		dif=0;res=0;tem=0;
		int len=strlen(str);
		int start=0;
		for(int i=start;i!=len;i++)
		{
			count[str[i]]++;
			if(count[str[i]]==1)
			{
				dif++;
				if(dif>n)
				{
					dif=1;tem=0;
					memset(count,0,sizeof(count));
					count[str[i]]=1;
					i=++start;
				}
			}
			tem++;
			res=res>=tem?res:tem;
		}
		printf("%d\n",--res);
	}
}