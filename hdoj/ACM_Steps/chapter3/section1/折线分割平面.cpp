#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		int tem=pow(a,2);
		cout<<2*tem-a+1<<endl;
	}
	return 0;
} 
