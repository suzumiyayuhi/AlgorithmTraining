#include<iostream>
#include<cmath>
using namespace std;
const double PI=acos(-1);
double x,y,l,w;

double cal(double cta)
{
	double s=l*cos(cta)+w*sin(cta)-x;
    double h=s*tan(cta)+w*cos(cta);
    return h;
}

int main()
{
	while(cin>>x>>y>>l>>w)
	{
		double left=0,right=PI/2,mid1,mid2;
		while(right-left>1e-9)
		{
			mid1=(2*left+right)/3;
			mid2=(left+2*right)/3;
			if(cal(mid1)>=cal(mid2))
				right=mid2;
			else
				left=mid1;
		}
		if(cal(mid1)<=y)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
} 
