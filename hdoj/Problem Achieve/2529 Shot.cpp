#include<cstdio>
#include<iostream>
using namespace std;
const double g=9.8;
int main()
{
    double h,l,v;
    while(cin>>h>>l>>v,h+l+v)
    {
           h+=0.5*v*v/g-0.5*g*l*l/(v*v);
           printf("%.2lf\n",h);
    }
    return 0;
}
