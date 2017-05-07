#include<iostream>
using namespace std;
#define SZ 1001
#define MAX 300
int res[SZ][MAX];
void xadd(int a[],int b[])
{
	int tem=0;
	for(int i=MAX-1;i!=-1;i--)
	{
		tem=tem+a[i]+b[i];
		a[i]=tem%10;
		tem/=10;
	}
}

void table()
{
	res[1][MAX-1]=1;
	res[2][MAX-1]=2;
	res[3][MAX-1]=4;
	res[4][MAX-1]=7;
	for(int i=5;i!=SZ;++i)
	{
		xadd(res[i],res[i-1]);
		xadd(res[i],res[i-2]);
		xadd(res[i],res[i-4]);
	}
}

int main()
{
	res[SZ][MAX]={0};
	table();
	int n;
	while(cin>>n)
	{
		int i;
		for(i=0;res[n][i]==0;i++);
		for(;i!=MAX;i++)
		{
			cout<<res[n][i];
		}
		cout<<endl;
	}
}
