#include<iostream>
#include<string.h>
using namespace std;
int m[101][101];
int sum[101];

int main()
{
	int N,res,tem,max;
	while(cin>>N)
	{
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				cin>>m[i][j];
		res=-1000;
		for(int i=1;i<=N;i++)
		{
			memset(sum,0,sizeof(sum));
			for(int j=i;j<=N;j++)
			{
				for(int k=1;k<=N;k++)
					sum[k]+=m[j][k];
				tem=0;
				for(int k=1;k<=N;k++)
				{
					tem+=sum[k];
					if(res<tem)
						res=tem;
					if(tem<0)
						tem=0;
				}
			}
		}
		cout<<res<<endl;
	}
}
