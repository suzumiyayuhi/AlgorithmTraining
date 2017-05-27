#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;

double fun1(double x,double y)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}

double fun2(double x,double y)
{
	return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x-y;
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		double x1,x2,x3,y,y1;
		x1=0;x2=100;
		cin>>y;
		do
		{
			x3=(x1+x2)/2;
			y1=fun2(x3,y);
			if(y1>0)
				x2=x3;
			else
				x1=x3;
		}while(x2-x1>1e-6);//1e-4 is wrong.
		printf("%.4lf\n",fun1(x3,y));
	}
}
