#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int l,m;
struct X
{
	int a[4][4];
};

X origin={1,0,1,1,
			  1,0,0,0,
			  0,1,0,0,
			  0,0,1,0};

X xmultiply(X a,X b)
{
	X c;
	for(int i=0;i!=4;++i)
	{
		for(int j=0;j!=4;++j)
		{
			c.a[i][j]=0;
			for(int k=0;k!=4;++k)
				c.a[i][j]+=a.a[i][k]*b.a[k][j]%m;
			c.a[i][j]%=m;
		}
	}
	return c;
}
/*
X xpow(X a,int n)
{
	X c=a;
	for(int i=0;i!=n-1;++i)
	{
		c=xmultiply(c,a);
	}
	return c;
}
*/
X E;
void init()
{
   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
     E.a[i][j]=(i==j);
}

X xpow(X a,int n)
{
	X c=a,d=origin;
	while(n){
        if(n&1){
            c=xmultiply(c,d);
            n--;
        }
        n>>=1;
        d=xmultiply(d,d);
    }
    return c;
}

int main()
{
	init();
	while(cin>>l>>m)
	{
		int res[4]={1,2,4,6};
		if(l<4)
		{
			cout<<res[l]%m<<endl;
		}
		else
		{
			X tem=xpow(origin,l-4);
			int ans=0;
			for(int i=0;i!=4;++i)
			{
				ans+=tem.a[0][i]*res[4-i-1];
			}
			cout<<ans%m<<endl;
		}
	}
	return 0;
}
