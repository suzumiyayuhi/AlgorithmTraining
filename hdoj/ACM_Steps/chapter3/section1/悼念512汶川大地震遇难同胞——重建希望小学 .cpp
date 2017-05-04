#include<iostream>
using namespace std;
long long res[31];
void table()
{
	res[0]=0;
	res[1]=1;
	res[2]=3;
	for(int i=3;i!=31;++i)
	{
		res[i]=res[i-1]+2*res[i-2];
	}
}

int main()
{
	table();
	int a,n;
	cin>>n;
	while(n--)
	{
		cin>>a;
		cout<<res[a]<<endl;
	}
} 
