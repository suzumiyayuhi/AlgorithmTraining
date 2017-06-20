#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int MAXN=1000002;
int main()
{
	bool res[MAXN];
	memset(res,false,sizeof(res));
	for(int i=1;i!=MAXN;i++)
	{
		int tem1=i,tem2=0;
		while(tem1)
		{
			tem2+=tem1%10;
			tem1/=10;
		}
		tem2+=i;
		if(tem2<MAXN)
			res[tem2]=true;
	}
	for(int i=1;i!=MAXN;i++)
		if(!res[i])
			printf("%d\n",i);
} 
