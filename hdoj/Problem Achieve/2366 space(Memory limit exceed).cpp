#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=101;
int xi[MAXN],yi[MAXN];
int n,l,res;

void check(int a)
{
	for(int i=a+1;i<=n;i++)
	{
		int tx=xi[i]-xi[a];
		int ty=yi[i]-yi[a];
		double tem=sqrt(tx*tx+ty*ty);
		if(tem<l)
			res++;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		res=0;
		cin>>n>>l;
		for(int i=1;i<=n;i++)
			cin>>xi[i]>>yi[i];
		for(int i=1;i<n;i++)
			check(i);
		cout<<res<<endl;
	}
}
