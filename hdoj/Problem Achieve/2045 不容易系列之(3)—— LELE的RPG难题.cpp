#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	long long res[51];
	int N;
	res[1]=3;
	res[2]=6;
	res[3]=6;
	for(int i=4;i!=51;i++)
		res[i]=res[i-1]+2*res[i-2];
	while(~scanf("%d",&N))
	{
		cout<<res[N]<<endl;
	}
	return 0;
}
