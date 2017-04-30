#include<iostream>
using namespace std;
#define SZ 21
long long res[SZ][SZ];

void table()
{
	res[0][0]={0};
	for(int i=1;i!=SZ;++i)
	{
		res[i][0]=1;
		for(int j=1;j!=i+1;++j)
		{
			res[i][j]=res[i-1][j]+res[i][j-1];
		}
	}
}

int main()
{
	table();
	int m,n;
	while(cin>>m>>n)
	{
		if(m<n)
			cout<<0<<endl;
		else
		{
			cout<<res[m][n]<<endl;
		}
	}
	return 0;
}
