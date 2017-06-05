#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int ns[5000];
int main()
{
	int A,B,N;
	ns[0]=ns[1]=ns[2]=1;
	while(cin>>A>>B>>N,A+B+N)
	{
		//memset(ns,1,sizeof(ns)); it is wrong
		int beg,end;
		bool flag=false;
		for(int i=3;i<=N&&!flag;i++)
		{
			ns[i]=(A*ns[i-1]+B*ns[i-2])%7;
			for(int j=2;j!=i;j++)
			{
				if(ns[i]==ns[j]&&ns[i-1]==ns[j-1])
				{	
					beg=j,end=i;
					flag=true;
					break;
				}	
			}
		}
		if(flag)
			cout<<ns[beg+(N-end)%(end-beg)]<<endl;
		else
			cout<<ns[N]<<endl;
	}
}
