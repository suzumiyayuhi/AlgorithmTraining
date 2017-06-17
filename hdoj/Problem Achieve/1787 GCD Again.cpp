#include<iostream>
#include<cmath>
using namespace std;
int euler(int a)
{
	int b=a;
	for(int i=2;i<(int)sqrt(a)+1;i++)
	{
		if(a%i==0)
		{
			b=b/i*(i-1);
			while(a%i==0)
				a/=i;
		}
	}
	if(a>1)
		b=b/a*(a-1);
	return b;
}
int main()
{
	int n;
	while(cin>>n,n)
	{
		cout<<n-euler(n)-1<<endl;
	}
} 
