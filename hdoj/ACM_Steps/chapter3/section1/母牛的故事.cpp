#include<iostream>
using namespace std;
long long res[55];

void table()
{
	res[1]=1;
	res[2]=2;
	res[3]=3;
	res[4]=4;
	for(int i=5;i!=55;++i)
	{
		res[i]=res[i-1]+res[i-3];
	}
}

int main()
{
	table();
	int n;
	while(cin>>n,n)
	{
		cout<<res[n]<<endl;
	}
} 
