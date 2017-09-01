#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int n,res,dif,tem,start;
char str[1100047];
int count[256];
int main()
{
	while(cin>>n,n)
	{
		
		getchar();
		gets(str);
		dif=0;res=0;start=0;
		long long len=strlen(str);
		memset(count,0,sizeof(count));
		for(int i=0;i<len;i++)
		{
			count[str[i]]++;
			if(count[str[i]]==1)
			{
				dif++;
				if(dif>n)
				{
					while(--count[str[start++]]>0);
					dif--;
				}
			}
			long long tem=i-start+1;
			res=res>=tem?res:tem;
		}
		cout<<res<<endl;
	}
}
