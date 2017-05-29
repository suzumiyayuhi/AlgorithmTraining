#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI=acos(-1);
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		double r,R,H,V,res;
		cin>>r>>R>>H>>V;
		if(r==R)
			res=V/(PI*r*r);
		else if(r<R)
		{
			double h0=H*r/(R-r);
      		double v0=(PI*h0*r*r)/3;
    		res=h0*(pow((v0+V)/v0,1.0/3)-1);
		}
		if(res>H)
			res=H;
		printf("%.6f\n",res);
	}
}
