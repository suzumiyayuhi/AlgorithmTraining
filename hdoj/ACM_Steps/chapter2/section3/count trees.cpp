#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
#define MAX 300
#define SZ 102
int res[MAX];
void xmultiply(int a[],int b)
{
	int tem=0,i;
	for(i=MAX-1;i!=-1;--i)
	{
		tem=tem+a[i]*b;
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

void xfactorial(int a[],int n)
{
	for(int i=2;i<=n;++i)
	{
		xmultiply(a,i);
	}
}

int main()
{
	int n;
	while(cin>>n,n)
	{
		memset(res,0,MAX*sizeof(int));
		res[MAX-1]=1;
		for(int i=1;i<n;++i)
		{
			xmultiply(res,4*(i+1)-2);
			xdivide(res,(i+1)+1);
		}
		xfactorial(res,n);
		int i=0;
		for(i=0;res[i]==0;++i);
		while(i!=MAX)
		{
			cout<<res[i++];
		}
		cout<<endl;
	}
}
