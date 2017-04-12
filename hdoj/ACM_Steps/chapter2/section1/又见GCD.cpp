#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}

int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		int a,b,c;
		cin>>a>>b;
		c=2*b;
		while(gcd(a,c)!=b)
		{
			c+=b;
		}
		cout<<c<<endl;
	}
	return 0;
}
