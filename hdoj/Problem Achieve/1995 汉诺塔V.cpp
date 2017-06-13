#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		long long res=pow(2,a-b);
		cout<<res<<endl;
	}
} 
