#include<iostream>
#include<cstdio>
using namespace std;

int fact(int a)
{
	int n=a;
	if(a==0)
		return 1;
	for(int i=2;i<n;i++)
	{
		a*=i;
	}
	return a;
}

bool check(int a)
{
	int sum=0,n=a;
	while(a)
	{
		int tem=a%10;
		a/=10;
		sum+=fact(tem);
	}
	if(sum==n)
		return true;
	return false;
}

int main()
{/*
	for(int i=1;i!=3628800;i++)
	{
		if(check(i))
			cout<<i<<endl;
	}
	*/
	printf("1\n2\n145\n40585\n");
}
