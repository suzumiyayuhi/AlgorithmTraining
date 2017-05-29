#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI=acos(-1);
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		double r,R,H,V,res,left,right,mid;
		cin>>r>>R>>H>>V;
		left=0;right=H;
		while(right-left>1e-7)
		{
			mid=(left+right)/2;
			double tem=(R-r)*mid/H+r;
			tem=PI*mid*(pow(r,2)+pow(tem,2)+r*tem)/3;
			if(tem-V<1e-7)
				left=mid;
			else
				right=mid;
		}
		printf("%.6f\n",mid);
	}
}
