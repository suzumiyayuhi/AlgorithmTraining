#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double G=9.8;
const double PI=acos(-1);
int main()
{
	int T;
	double x,y,v;
	bool flag;
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>v;
		double mid1,mid2,left=0.,right=PI/2,a1,a2,t1,t2;
		bool flag=false;
		
		while(right-left>1e-10)
		{
			mid1=(left+right)/2;
			t1=x/(v*cos(mid1));
			a1=v*sin(mid1)*t1-G*t1*t1*0.5;
			if(a1<y)
				left=mid1;
			else if(a1>y||v*sin(mid1)/G<t1)
			{
				flag=true;
				right=mid1;
			}
			else
				flag=true;
		}
		if(!flag)
			cout<<-1<<endl;
		else
			printf("%.6f\n",left);
	}
} 
