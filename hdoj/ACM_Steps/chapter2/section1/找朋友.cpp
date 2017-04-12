#include<iostream>
using namespace std;

int Eular(int a)
{
	int res=1;
	for(int i=2;i*i<=a;++i)
	{
		if(a%i==0)
		{
			a/=i;
			res*=(i-1);
		}
		while(a%i==0)
		{
			a/=i;
			res*=i;
		}
	}
	if(a>1)
		res*=(a-1);
	return res;
}

int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		int a;
		cin>>a;
		cout<<Eular(a)<<endl;
	}
	return 0;
} 
