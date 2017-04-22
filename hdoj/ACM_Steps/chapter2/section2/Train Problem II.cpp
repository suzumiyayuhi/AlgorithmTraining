//wrote it after i had watched http://blog.csdn.net/lishuhuakai/article/details/8034075 
#include <iostream>  
#include<cstdio>  
#include<memory.h>
#define MAX 101
#define BASE 10000
using namespace std;
int res[101][MAX];

void multiply(int a[],int sz,int b)
{
	int tem=0;
	for(int i=sz-1;i>=0;--i)
	{
		tem+=b*a[i];
		a[i]=tem%BASE;
		tem/=BASE;
	}
}

void divide(int a[],int sz,int b)
{
	int tem=0;
	for(int i=0;i!=sz;++i)
	{
		tem=tem*BASE+a[i];
		a[i]=tem/b;
		tem%=b;
	}
}

void table()
{
	memset(res,0,101*sizeof(int));
	res[1][MAX-1]=1;
	for(int i=2;i!=101;++i)
	{  
    	memcpy(res[i],res[i-1],MAX*sizeof(int));
        multiply(res[i],MAX,4*i-2);
        divide(res[i],MAX,i+1);    
    }
}

int main()
{
	table();
	int a;
	while(cin>>a)
	{
		int i=0;
		for(;i<MAX&&res[a][i]==0;++i);//there is a ";"
			cout<<res[a][i++];
			for(;i<MAX;++i)
			{
				printf("%04d",res[a][i]);
			}
		cout<<endl;
	}
	return 0;
} 
