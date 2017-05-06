#include<iostream>
using namespace std;
long long res[51];
void table()
{
	res[1]=3;
	res[2]=6;
	res[3]=6;
	for(int i=4;i!=51;++i)
	{
		res[i]=res[i-1]+2*res[i-2];
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
