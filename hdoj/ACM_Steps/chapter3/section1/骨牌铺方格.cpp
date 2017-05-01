#include<iostream>
using namespace std;
long long res[51];
void table()
{
	res[1]=1;
	res[2]=2;
	for(int i=3;i!=51;++i)
	{
		res[i]=res[i-1]+res[i-2];
	}
}

int main() 
{
	int a;
	table();
	while(cin>>a)
	{
		cout<<res[a]<<endl;
	}
	return 0;
}
