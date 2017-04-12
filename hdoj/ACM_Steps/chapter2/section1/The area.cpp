#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int num;
	cin>>num;
	while(num--)
	{
		double x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		double k=(y3-y2)/(x3-x2);
		double h=y2-k*x2;
		double a=((y2-y1)/(x2-x1)-k)/(x1-x3);
		double b=((y2-y1)/(x2-x1)-a*(x1+x2));
		double c=y3-(a*x3*x3+b*x3);
		double res=((a/3)*x3*x3*x3+(b-k)/2*x3*x3+(c-h)*x3)
					-((a/3)*x2*x2*x2+(b-k)/2*x2*x2+(c-h)*x2);
	//	cout<<res<<endl;
	printf("%.2f\n",res);
	}
}
