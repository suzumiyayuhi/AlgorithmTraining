#include<iostream>
#include<cstdio>
#include<stdio.h>
#define MAX 500
using namespace std;

void xmultiply(int a[],int b)
{
	int tem=0,i;
	for(i=MAX-1;i!=-1;--i)
	{
		tem+=a[i]*b;
		a[i]=tem%10;
		tem/=10;
	}
	while(tem!=0)
	{
		a[i--]=tem%10;
		tem/=10; 
	}
}

void xdivide(int a[],int b)
{
	int tem=0;
	for(int i=0;i!=MAX;++i)
	{
		tem=tem*10+a[i];
		a[i]=tem/b;
		tem%=b;
	}
}

void factorial(int a[],int n)
{
	for(int i=2;i<=n;++i)
	{
		xmultiply(a,i);
	}
}

int main()
{
	int n=1,a,b;
	int res[MAX];
	while(cin>>a>>b&&(a!=0||b!=0))
	{
		cout<<"Test #"<<n++<<":"<<endl;
		if(a>=b)
		{
			memset(res,0,MAX*sizeof(int));
			int tem=a+b;
			for(int i=1;tem!=0;++i)
			{
				res[MAX-i]=tem%10;
				tem/=10;
			}
			factorial(res,a+b-1);
			xmultiply(res,a-b+1);
			xdivide(res,a+1);
			
			int i;
			for(i=0;res[i]==0;++i);
			for(;i!=MAX;++i)
				cout<<res[i];
		}
		else
		{
			cout<<0;
		}
		cout<<endl;
	}
	return 0;
} 
