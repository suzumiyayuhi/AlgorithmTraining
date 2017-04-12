#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a<b)
	{
		swap(a,b);
	}
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a+b-gcd(a,b)<<endl;
	}
	return 0;
} 
