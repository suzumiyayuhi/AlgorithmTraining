#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
const int MAXN=100002;
char str[MAXN];
int res,tem,n;
int main()
{
	map<char,int> mp;
	while(scanf("%d",&n),n)
	{
		res=0;
		getchar(); 
		gets(str);
		int len=strlen(str);
		for(int i=0;i!=len;i++)
		{
			tem=0;
			mp.clear();
			int j=i;
			while(mp.size()<=n)
			{
				if(j==len)
					break;
				mp[str[j++]]++;
			}
			for(map<char,int>::iterator beg=mp.begin();beg!=mp.end();beg++)
			{
				tem+=beg->second;
			}
			res=res>tem?res:tem;
		}
		printf("%d\n",--res);
	}
}
