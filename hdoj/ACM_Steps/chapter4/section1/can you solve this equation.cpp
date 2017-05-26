#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double fun(double x)
{
	return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		double x1,x2,x3,y,y1,y2,y3;
		cin>>y;
		x1=0;x2=100;
		y1=fun(x1)-y;
		y2=fun(x2)-y;
		if(y1>0||y2<0)
			cout<<"No solution!"<<endl;
		else
		{
			while(fabs(y1-y2)>=0.0001)
			{
				x3=(x1+x2)/2;
				y3=fun(x3)-y;
				if(y3>=0)
					x2=x3;
				else
					x1=x3;
				y1=fun(x1)-y;
				y2=fun(x2)-y;
			}
			printf("%0.4f\n",x3);
		}
	}
}
