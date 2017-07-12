#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int T;
double fun(double x)
{
	return pow(x,4)*8+pow(x,3)*7+pow(x,2)*2+3*x+6;
}

int main()
{
	cin>>T;
	while(T--)
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
			while(fabs(y1-y2)>=1e-5)
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
			printf("%.4f\n",x1);
		}
	}
}
