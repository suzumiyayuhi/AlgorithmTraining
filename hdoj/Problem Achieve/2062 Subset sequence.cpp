#include<iostream>
#include<string.h>
using namespace std;
long long tab[21],n,m,tem;
int num[21];
void table()
{
	tab[1]=1;
	tab[2]=2;
	for(int i=3;i!=21;i++)
		tab[i]=(i-1)*tab[i-1]+1;
}

int main()
{
	table();
	while(cin>>n>>m)
	{
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
			num[i]=i;
		tem=n;
		
		while(n--)
		{
			int a=m%tab[n+1]? m/tab[n+1]+1: m/tab[n+1];
			if(num[a]==0)
				break;
			if(tem-1==n)
				cout<<num[a];
			else
				cout<<" "<<num[a];
			for(int i=a;i<=n;i++)
				num[i]=num[i+1];
			m=(m-(tab[n+1]*(a-1)+1));
		}
		cout<<endl;
	}
} 
