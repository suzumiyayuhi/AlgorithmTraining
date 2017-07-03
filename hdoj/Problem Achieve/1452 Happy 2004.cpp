#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int qp(int a,int b)
{
	int z=a;
	for(int i=1;i<b;i++)
		z=z*a%29;
	return z;
}

int main()
{
	int res,a,b,c,x;
	while(cin>>x,x)
	{
		x%=28;
		a=(qp(2,2*x+1)-1)%29;
//		b=(qp(3,x+1)-1)/2%29;
//		c=(qp(167,x+1)-1)/166%29;
		b=(qp(3,x+1)-1)*15%29;
		c=(qp(22,x+1)-1)*18%29;
		res=a*b*c%29;
		cout<<res<<endl;
	}
}
