#include<iostream>
#include<cstdio>
#include<string.h>
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

int main()
{
	int n=1,a;
	int res[MAX];
	while(cin>>a&&a!=-1)
	{
		memset(res,0,MAX*sizeof(int));
		int tem=a;
		res[MAX-1]=1;
		for(int i=1;i<a;++i)
		{
			xmultiply(res,4*(i+1)-2);
			xdivide(res,(i+1)+1);
		}
		int i;
		for(i=0;res[i]==0;++i);
		for(;i!=MAX;++i)
			cout<<res[i];
		cout<<endl;
	}
	return 0;
} 
