#include<iostream>
using namespace std;
long long res[21];
void table()
{
	res[1]=3;
	res[2]=7;
	for(int i=3;i!=21;++i)
	{
		res[i]=2*res[i-1]+res[i-2];
	}
}

int main()
{
	table();
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		cout<<res[a]<<endl;
	}
	return 0;
} 
