#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int tem=(pow(n,3)+5*n)/6+1;
		cout<<tem;
	}
	return 0;
}
